# C ABI Wrapper 實作準則

**適用對象**: 所有實作 C ABI wrapper 的 subagents
**必讀**: 開始任何實作前請完整閱讀本文檔

---

## 1. 設計原則

### 1.1 核心理念

> **目標**: 將 C++ SDK 的所有欄位完整映射到 C ABI，不遺漏、不簡化

**三大原則**：
1. **完整包裝（Bypass）**: SDK 有什麼欄位，C ABI 就暴露什麼欄位
2. **記憶體安全**: C wrapper 配置的記憶體，必須提供對應的 free 函數
3. **錯誤透明**: C++ 異常轉換為錯誤訊息，不隱藏任何錯誤資訊

### 1.2 非目標

❌ **不要做**：
- 簡化 API（不要合併、不要省略欄位）
- 設計新介面（照著 C++ SDK 映射即可）
- 自行決定哪些欄位重要（全部保留）
- 創建抽象層或包裝層（我們就是包裝層）

---

## 2. 型別映射規則

### 2.1 基本型別

| C++ 型別 | C 型別 | 說明 |
|---------|--------|------|
| `int32_t` | `int32_t` | 直接映射 |
| `int64_t` | `int64_t` | 直接映射 |
| `uint64_t` | `uint64_t` | 直接映射 |
| `double` | `double` | 直接映射 |
| `bool` | `bool` | 使用 C99 stdbool.h |

### 2.2 字串處理

| C++ 型別 | C 型別 | 配置方式 |
|---------|--------|----------|
| `std::string` | `char*` | C wrapper 使用 `malloc()` + `strcpy()` |
| `const std::string&` | `const char*` | 輸入參數，呼叫端持有 |

**重要規則**：
```cpp
// ✅ 正確：使用 malloc 配置
static char* strdup_from_cpp(const std::string& str) {
    char* result = (char*)malloc(str.length() + 1);
    if (result) {
        strcpy(result, str.c_str());
    }
    return result;
}

// ❌ 錯誤：不要用 strdup()，部分系統不支援
char* result = strdup(str.c_str());

// ❌ 錯誤：不要返回臨時指標
return str.c_str();  // 生命週期錯誤！
```

### 2.3 Optional 處理

**C++ `std::optional<T>` 映射為 C 的 flag + value**：

```c
// C++ 原始定義
struct Settlement {
    std::string date;
    std::optional<std::string> settlement_date;
    std::optional<int64_t> buy_value;
    std::optional<double> price;
};

// C 映射結果
typedef struct {
    char* date;                        // 必填欄位

    bool has_settlement_date;          // optional flag
    char* settlement_date;             // 僅在 has_settlement_date=true 時有效

    bool has_buy_value;
    int64_t buy_value;

    bool has_price;
    double price;
} FubonSettlement;
```

**實作範例**：
```cpp
// C++ → C 轉換
if (cpp_data.settlement_date.has_value()) {
    c_data->has_settlement_date = true;
    c_data->settlement_date = strdup_from_cpp(cpp_data.settlement_date.value());
} else {
    c_data->has_settlement_date = false;
    c_data->settlement_date = nullptr;
}

if (cpp_data.buy_value.has_value()) {
    c_data->has_buy_value = true;
    c_data->buy_value = cpp_data.buy_value.value();
} else {
    c_data->has_buy_value = false;
    c_data->buy_value = 0;  // 給預設值，但僅在 has_buy_value=true 時有效
}
```

### 2.4 陣列處理

**C++ `std::vector<T>` 映射為 C 的 array struct**：

```c
// C++ 原始定義
std::vector<Inventory> inventories;

// C 映射結果
typedef struct {
    FubonInventory* items;
    int32_t count;
} FubonInventoryArray;
```

**實作範例**：
```cpp
// C++ → C 轉換
auto& cpp_vec = response.data.value();
auto* c_array = new FubonInventoryArray{};
c_array->count = cpp_vec.size();
c_array->items = (FubonInventory*)malloc(sizeof(FubonInventory) * cpp_vec.size());

for (size_t i = 0; i < cpp_vec.size(); i++) {
    // 逐一轉換每個元素
    c_array->items[i].date = strdup_from_cpp(cpp_vec[i].date);
    c_array->items[i].account = strdup_from_cpp(cpp_vec[i].account);
    c_array->items[i].today_qty = cpp_vec[i].today_qty;
    // ... 其他欄位
}
```

### 2.5 列舉類型

**C++ `enum class` 映射為 C `enum` 並加上前綴**：

```c
// C++ 原始定義
enum class OrderType: int32_t {
    STOCK = 1,
    MARGIN = 2,
    SHORT = 3,
    // ...
};

// C 映射結果（加上 FUBON_ 前綴避免衝突）
typedef enum {
    FUBON_ORDER_TYPE_STOCK = 1,
    FUBON_ORDER_TYPE_MARGIN = 2,
    FUBON_ORDER_TYPE_SHORT = 3,
    // ...
} FubonOrderType;
```

**轉換範例**：
```cpp
// C++ → C（直接 cast）
c_data->order_type = static_cast<FubonOrderType>(cpp_data.order_type);

// C → C++（直接 cast）
cpp_order.order_type = static_cast<fubon::OrderType>(c_order->order_type);
```

### 2.6 嵌套結構

**直接嵌入，不使用指標**：

```c
// C++ 原始定義
struct Inventory {
    std::string stock_no;
    InventoryOdd odd;  // 嵌套結構
};

// C 映射結果
typedef struct {
    int32_t lastday_qty;
    int32_t buy_qty;
    // ...
} FubonInventoryOdd;

typedef struct {
    char* stock_no;
    FubonInventoryOdd odd;  // ✅ 直接嵌入，不是指標
} FubonInventory;
```

---

## 3. 記憶體管理策略

### 3.1 配置與釋放原則

**黃金法則**: 誰配置，誰負責提供釋放函數

| 資源類型 | 配置者 | 釋放者 | 釋放時機 |
|---------|--------|--------|---------|
| SDK 實例 | `fubon_sdk_new()` | 呼叫端 | 程式結束前 |
| API 結果 | 各 API 函數 | 呼叫端 | 使用完畢後 |
| 內部字串/陣列 | C wrapper 內部 | C wrapper | free 函數遞迴釋放 |

### 3.2 結果結構模式

**所有 API 返回堆疊配置的結果指標**：

```c
typedef struct {
    bool is_success;           // 成功標誌
    char* error_message;       // 錯誤訊息（NULL if success）
    FubonBankRemain* data;     // 實際數據（NULL if failed）
} FubonBankRemainResult;

// API 簽名
FubonBankRemainResult* fubon_bank_remain(FubonSDK sdk, const FubonAccount* account);
void fubon_free_bank_remain_result(FubonBankRemainResult* result);
```

### 3.3 Free 函數實作模式

**遞迴釋放所有嵌套資源**：

```cpp
void fubon_free_bank_remain_result(FubonBankRemainResult* result) {
    if (!result) return;

    // 1. 釋放錯誤訊息
    if (result->error_message) {
        free(result->error_message);
    }

    // 2. 釋放數據及其內部字串
    if (result->data) {
        free(result->data->branch_no);
        free(result->data->account);
        free(result->data->currency);
        delete result->data;  // 數據本身用 new 配置
    }

    // 3. 釋放結果本身
    delete result;  // 用 new 配置
}
```

**陣列釋放範例**：

```cpp
void fubon_free_inventory_result(FubonInventoryResult* result) {
    if (!result) return;

    if (result->error_message) {
        free(result->error_message);
    }

    if (result->data) {
        // 循環釋放每個元素的字串
        for (int i = 0; i < result->data->count; i++) {
            FubonInventory* inv = &result->data->items[i];
            free(inv->date);
            free(inv->account);
            free(inv->branch_no);
            free(inv->stock_no);
            // InventoryOdd 是嵌入的，不需要釋放
        }

        // 釋放陣列本身
        free(result->data->items);

        // 釋放陣列結構
        delete result->data;
    }

    delete result;
}
```

### 3.4 記憶體洩漏檢查

**使用完畢後檢查**：
```bash
# macOS
leaks --atExit -- ./test_accounting

# Linux
valgrind --leak-check=full ./test_accounting

# 或使用 AddressSanitizer
clang++ -fsanitize=address -g test.cpp
```

---

## 4. 錯誤處理

### 4.1 異常轉錯誤訊息

**所有 C++ 異常必須 catch 並轉換為錯誤訊息**：

```cpp
FubonBankRemainResult* fubon_bank_remain(FubonSDK sdk, const FubonAccount* account) {
    auto* result = new FubonBankRemainResult{};
    result->is_success = false;
    result->error_message = nullptr;
    result->data = nullptr;

    try {
        auto* cpp_sdk = static_cast<fubon::FubonSDK*>(sdk);

        // ... 實作邏輯 ...

        result->is_success = true;

    } catch (const std::exception& e) {
        // ✅ 標準異常
        result->error_message = strdup_from_cpp(e.what());
    } catch (...) {
        // ✅ 未知異常
        result->error_message = strdup_from_cpp("Unknown error occurred");
    }

    return result;
}
```

### 4.2 錯誤情境處理

| 情境 | is_success | error_message | data |
|------|-----------|---------------|------|
| ✅ 成功 | true | NULL | 有效指標 |
| ❌ C++ 異常 | false | 異常訊息 | NULL |
| ❌ 無效參數 | false | "Invalid parameter" | NULL |
| ❌ SDK 未初始化 | false | "SDK not initialized" | NULL |
| ❌ 記憶體配置失敗 | false | "Memory allocation failed" | NULL |

### 4.3 參數驗證

**在進入 try block 前驗證參數**：

```cpp
FubonBankRemainResult* fubon_bank_remain(FubonSDK sdk, const FubonAccount* account) {
    auto* result = new FubonBankRemainResult{};
    result->is_success = false;
    result->data = nullptr;

    // ✅ 先驗證參數
    if (sdk == nullptr) {
        result->error_message = strdup_from_cpp("SDK is NULL");
        return result;
    }

    if (account == nullptr) {
        result->error_message = strdup_from_cpp("Account is NULL");
        return result;
    }

    result->error_message = nullptr;

    try {
        // ... 實作邏輯 ...
    } catch (...) {
        // ...
    }

    return result;
}
```

---

## 5. Header 檔案規範

### 5.1 檔案結構

```c
#ifndef FUBON_C_H
#define FUBON_C_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// OPAQUE HANDLE TYPES
// ============================================================================

typedef void* FubonSDK;

// ============================================================================
// ENUMERATIONS
// ============================================================================

typedef enum {
    FUBON_ORDER_TYPE_STOCK = 1,
    // ...
} FubonOrderType;

// ============================================================================
// BASIC STRUCTURES
// ============================================================================

typedef struct {
    char* name;
    // ...
} FubonAccount;

// ============================================================================
// RESPONSE STRUCTURES
// ============================================================================

typedef struct {
    bool is_success;
    char* error_message;
    FubonAccount* data;
} FubonAccountResult;

// ============================================================================
// SDK LIFECYCLE FUNCTIONS
// ============================================================================

FubonSDK fubon_sdk_new(void);
void fubon_sdk_free(FubonSDK sdk);

// ============================================================================
// API FUNCTIONS
// ============================================================================

FubonAccountResult* fubon_some_api(FubonSDK sdk, ...);

// ============================================================================
// MEMORY MANAGEMENT FUNCTIONS
// ============================================================================

void fubon_free_account_result(FubonAccountResult* result);

#ifdef __cplusplus
}
#endif

#endif // FUBON_C_H
```

### 5.2 命名規範

| 類型 | 規則 | 範例 |
|------|------|------|
| 函數 | `fubon_` 前綴 + 小寫 snake_case | `fubon_bank_remain()` |
| 結構體 | `Fubon` 前綴 + PascalCase | `FubonBankRemain` |
| 列舉 | `Fubon` 前綴 + PascalCase | `FubonOrderType` |
| 列舉值 | `FUBON_` 前綴 + 大寫 SNAKE_CASE | `FUBON_ORDER_TYPE_STOCK` |
| Free 函數 | `fubon_free_` + 類型名小寫 | `fubon_free_bank_remain_result()` |

---

## 6. 實作檢查清單

### 6.1 開始實作前

- [ ] 閱讀 C++ SDK 對應的結構定義（fubon.hpp）
- [ ] 確認所有欄位（包括 optional）
- [ ] 確認嵌套結構的層次
- [ ] 確認陣列欄位
- [ ] 檢查列舉類型

### 6.2 實作過程中

- [ ] 所有 `std::optional<T>` 都映射為 `bool has_xxx; T xxx;`
- [ ] 所有 `std::string` 都使用 `malloc()` + `strcpy()`
- [ ] 所有 `std::vector<T>` 都映射為 `{T* items; int32_t count;}`
- [ ] 所有函數都包在 `try-catch` 中
- [ ] 所有字串配置都檢查 NULL
- [ ] 參數驗證在 try block 之前

### 6.3 實作完成後

- [ ] 創建對應的 `fubon_free_*()` 函數
- [ ] Free 函數遞迴釋放所有字串
- [ ] Free 函數釋放所有陣列
- [ ] Free 函數處理 NULL 輸入
- [ ] 編寫測試程式驗證功能
- [ ] 運行記憶體洩漏檢測工具

---

## 7. 常見錯誤與解決方案

### 7.1 記憶體錯誤

❌ **錯誤**：返回臨時字串指標
```cpp
return cpp_string.c_str();  // 危險！生命週期結束後指標無效
```

✅ **正確**：配置新記憶體
```cpp
return strdup_from_cpp(cpp_string);
```

---

❌ **錯誤**：忘記釋放嵌套字串
```cpp
void fubon_free_result(FubonResult* result) {
    delete result->data;  // ❌ data 內部的字串沒有釋放！
    delete result;
}
```

✅ **正確**：遞迴釋放
```cpp
void fubon_free_result(FubonResult* result) {
    if (result->data) {
        free(result->data->some_string);
        free(result->data->another_string);
        delete result->data;
    }
    delete result;
}
```

---

### 7.2 Optional 錯誤

❌ **錯誤**：忘記設置 flag
```cpp
if (cpp_data.price.has_value()) {
    c_data->price = cpp_data.price.value();
    // ❌ 忘記設置 has_price = true
}
```

✅ **正確**：flag 和 value 一起設置
```cpp
if (cpp_data.price.has_value()) {
    c_data->has_price = true;
    c_data->price = cpp_data.price.value();
} else {
    c_data->has_price = false;
    c_data->price = 0.0;  // 給預設值（雖然不會用到）
}
```

---

### 7.3 陣列錯誤

❌ **錯誤**：錯誤的陣列配置
```cpp
c_array->items = new FubonInventory[count];  // ❌ C 端不能用 new[]
```

✅ **正確**：使用 malloc
```cpp
c_array->items = (FubonInventory*)malloc(sizeof(FubonInventory) * count);
```

---

## 8. 測試要求

### 8.1 基本測試

每個 API 必須測試：
1. ✅ 成功情境（is_success = true）
2. ❌ 失敗情境（錯誤訊息正確）
3. 🔄 記憶體釋放（無洩漏）

### 8.2 測試程式範例

```c
#include "fubon_c.h"
#include <stdio.h>

int main() {
    FubonSDK sdk = fubon_sdk_new();
    if (!sdk) {
        fprintf(stderr, "Failed to create SDK\n");
        return 1;
    }

    // 測試 login
    FubonLoginResult* login = fubon_login(sdk, "id", "pass", "cert", "certpass");
    if (!login->is_success) {
        fprintf(stderr, "Login failed: %s\n", login->error_message);
        fubon_free_login_result(login);
        fubon_sdk_free(sdk);
        return 1;
    }

    printf("Login OK, accounts: %d\n", login->accounts->count);
    FubonAccount* account = &login->accounts->items[0];

    // 測試 bank_remain
    FubonBankRemainResult* bank = fubon_bank_remain(sdk, account);
    if (bank->is_success) {
        printf("Balance: %lld\n", bank->data->balance);
    } else {
        fprintf(stderr, "Error: %s\n", bank->error_message);
    }

    // 清理
    fubon_free_bank_remain_result(bank);
    fubon_free_login_result(login);
    fubon_sdk_free(sdk);

    return 0;
}
```

---

## 9. 參考資料

### 9.1 關鍵文件

- **`/Users/liyu/talenttb/fubon-sdk-ffi/fubon-cpp-sdk/bindings/fubon.hpp`** - 完整結構定義
- **`/Users/liyu/talenttb/fubon-sdk-ffi/fubon-cpp-sdk/bindings/sdk.hpp`** - FubonSDK 類別
- **`/Users/liyu/talenttb/fubon-sdk-ffi/CLAUDE.md`** - 專案架構文件
- **`/Users/liyu/talenttb/fubon-sdk-ffi/docs/SDK_API_CATALOG.md`** - 完整 API 清單

### 9.2 實作計劃

參考 `/Users/liyu/.claude/plans/staged-stirring-fountain.md` 了解整體實作流程

---

## 10. 尋求協助

如果遇到問題：

1. **不確定型別映射** → 參考本文檔第 2 節
2. **不確定記憶體管理** → 參考本文檔第 3 節
3. **不確定錯誤處理** → 參考本文檔第 4 節
4. **找不到 C++ 定義** → 搜索 fubon.hpp
5. **其他問題** → 詢問用戶或主 agent

---

**記住**: 我們的目標是完整、安全、可靠的 C ABI 包裝，不遺漏任何欄位，不產生記憶體洩漏。
