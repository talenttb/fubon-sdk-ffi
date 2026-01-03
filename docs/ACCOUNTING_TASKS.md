# Accounting 模組實作任務分割

**目標**: 將 Accounting 模組的 7 個 API 拆分成可並行實作的獨立任務

---

## 任務分割策略

### 分組原則

1. **依賴關係**：Task 1（基礎設施）必須先完成
2. **複雜度漸進**：簡單 API → 陣列處理 → 複雜嵌套 → Optional 密集
3. **獨立性**：Task 2-6 可以並行實作
4. **可測試性**：每個任務都包含測試程式

---

## Task 1: 基礎設施（必須先完成）

**優先級**: P0（最高）
**預估工時**: 1-2 小時
**依賴**: 無
**並行**: ❌ 必須單獨完成

### 交付物

#### 1.1 目錄結構

```
c_wrapper/
├── include/
│   └── fubon_c.h          # C ABI 標頭檔
├── src/
│   ├── fubon_c.cpp        # SDK 管理與 login 實作
│   └── helpers.cpp        # 字串轉換輔助函數
├── test/
│   └── test_sdk.c         # SDK 與 login 測試
└── CMakeLists.txt         # 編譯配置
```

#### 1.2 fubon_c.h 核心定義

```c
#ifndef FUBON_C_H
#define FUBON_C_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// Opaque handle
typedef void* FubonSDK;

// Account structure
typedef struct {
    char* name;
    char* branch_no;
    char* account;
    char* account_type;
} FubonAccount;

// Account array
typedef struct {
    FubonAccount* items;
    int32_t count;
} FubonAccountArray;

// Login result
typedef struct {
    bool is_success;
    char* error_message;
    FubonAccountArray* accounts;
} FubonLoginResult;

// SDK lifecycle
FubonSDK fubon_sdk_new(void);
FubonSDK fubon_sdk_new_with_config(uint64_t pong_interval, int64_t missed_count, const char* url);
void fubon_sdk_free(FubonSDK sdk);

// Authentication
FubonLoginResult* fubon_login(FubonSDK sdk, const char* personal_id, const char* password, const char* cert_path, const char* cert_pass);
FubonLoginResult* fubon_dma_login(FubonSDK sdk, const char* personal_id, const char* password);
void fubon_free_login_result(FubonLoginResult* result);

#ifdef __cplusplus
}
#endif

#endif // FUBON_C_H
```

#### 1.3 helpers.cpp 輔助函數

```cpp
#include <cstring>
#include <string>
#include <optional>

// 複製 std::string 到 C string
static char* strdup_from_cpp(const std::string& str) {
    if (str.empty()) {
        char* result = (char*)malloc(1);
        if (result) result[0] = '\0';
        return result;
    }
    char* result = (char*)malloc(str.length() + 1);
    if (result) {
        strcpy(result, str.c_str());
    }
    return result;
}

// 複製 optional string
static char* strdup_from_optional(const std::optional<std::string>& opt) {
    return opt.has_value() ? strdup_from_cpp(opt.value()) : nullptr;
}
```

#### 1.4 CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.17)
project(fubon_c_wrapper)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include C++ SDK
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/../fubon-cpp-sdk/bindings
)

link_directories(${CMAKE_SOURCE_DIR}/../fubon-cpp-sdk/bindings)

# C wrapper library
add_library(fubon_c SHARED
    src/fubon_c.cpp
    src/helpers.cpp
)

target_link_libraries(fubon_c fubon)

# Test program
add_executable(test_sdk test/test_sdk.c)
target_link_libraries(test_sdk fubon_c)
```

### 驗收標準

- [ ] SDK 可以成功初始化和釋放
- [ ] Login 可以成功返回 Account 陣列
- [ ] 測試程式可以編譯執行
- [ ] 無記憶體洩漏（valgrind/leaks 檢測）
- [ ] 錯誤處理正確（異常轉錯誤訊息）

---

## Task 2: bank_remain（最簡單的 API）

**優先級**: P0
**預估工時**: 1 小時
**依賴**: Task 1
**並行**: ✅ 可與 Task 3-6 並行

### 數據結構分析

**C++ 定義**（fubon.hpp:1034-1042）：
```cpp
struct BankRemain {
    std::string branch_no;
    std::string account;
    std::string currency;
    int64_t balance;
    int64_t available_balance;
};
```

**特點**：
- ✅ 簡單結構（5 個欄位）
- ✅ 無 optional 欄位
- ✅ 無嵌套結構
- ✅ 無陣列

### 交付物

#### 2.1 fubon_c.h 新增定義

```c
// BankRemain structure
typedef struct {
    char* branch_no;
    char* account;
    char* currency;
    int64_t balance;
    int64_t available_balance;
} FubonBankRemain;

// BankRemain result
typedef struct {
    bool is_success;
    char* error_message;
    FubonBankRemain* data;
} FubonBankRemainResult;

// API function
FubonBankRemainResult* fubon_bank_remain(FubonSDK sdk, const FubonAccount* account);
void fubon_free_bank_remain_result(FubonBankRemainResult* result);
```

#### 2.2 實作重點

1. **C++ → C 轉換**：
   - 3 個字串：使用 `strdup_from_cpp()`
   - 2 個數值：直接賦值

2. **記憶體釋放**：
   - 釋放 3 個字串
   - 釋放 data 結構
   - 釋放 result 結構

#### 2.3 測試程式

```c
FubonBankRemainResult* bank = fubon_bank_remain(sdk, account);
if (bank->is_success) {
    printf("Balance: %lld\n", bank->data->balance);
    printf("Available: %lld\n", bank->data->available_balance);
    printf("Currency: %s\n", bank->data->currency);
} else {
    fprintf(stderr, "Error: %s\n", bank->error_message);
}
fubon_free_bank_remain_result(bank);
```

### 驗收標準

- [ ] 可以成功查詢銀行餘額
- [ ] 所有欄位正確映射
- [ ] 無記憶體洩漏
- [ ] 錯誤情境處理正確

---

## Task 3: inventories（陣列處理）

**優先級**: P0
**預估工時**: 1-2 小時
**依賴**: Task 1
**並行**: ✅ 可與 Task 2, 4-6 並行

### 數據結構分析

**C++ 定義**（fubon.hpp:2457-2476）：
```cpp
struct InventoryOdd {
    int32_t lastday_qty;
    int32_t buy_qty;
    int32_t buy_filled_qty;
    int32_t buy_value;
    int32_t today_qty;
    int32_t tradable_qty;
    int32_t sell_qty;
    int32_t sell_filled_qty;
    int32_t sell_value;
};

struct Inventory {
    std::string date;
    std::string account;
    std::string branch_no;
    std::string stock_no;
    OrderType order_type;
    int32_t lastday_qty;
    int32_t buy_qty;
    int32_t buy_filled_qty;
    int32_t buy_value;
    int32_t today_qty;
    int32_t tradable_qty;
    int32_t sell_qty;
    int32_t sell_filled_qty;
    int32_t sell_value;
    InventoryOdd odd;
};
```

**特點**：
- ⚠️ 嵌套結構（InventoryOdd）
- ⚠️ 包含列舉（OrderType）
- ⚠️ 返回陣列（vector<Inventory>）
- ✅ 無 optional 欄位

### 交付物

#### 3.1 fubon_c.h 新增定義

```c
// OrderType enum
typedef enum {
    FUBON_ORDER_TYPE_STOCK = 1,
    FUBON_ORDER_TYPE_MARGIN = 2,
    FUBON_ORDER_TYPE_SHORT = 3,
    FUBON_ORDER_TYPE_SBL = 4,
    FUBON_ORDER_TYPE_DAY_TRADE = 5,
    FUBON_ORDER_TYPE_UN_SUPPORTED = 6,
    FUBON_ORDER_TYPE_UN_DEFINED = 7
} FubonOrderType;

// InventoryOdd structure
typedef struct {
    int32_t lastday_qty;
    int32_t buy_qty;
    int32_t buy_filled_qty;
    int32_t buy_value;
    int32_t today_qty;
    int32_t tradable_qty;
    int32_t sell_qty;
    int32_t sell_filled_qty;
    int32_t sell_value;
} FubonInventoryOdd;

// Inventory structure
typedef struct {
    char* date;
    char* account;
    char* branch_no;
    char* stock_no;
    FubonOrderType order_type;
    int32_t lastday_qty;
    int32_t buy_qty;
    int32_t buy_filled_qty;
    int32_t buy_value;
    int32_t today_qty;
    int32_t tradable_qty;
    int32_t sell_qty;
    int32_t sell_filled_qty;
    int32_t sell_value;
    FubonInventoryOdd odd;  // 嵌入結構
} FubonInventory;

// Inventory array
typedef struct {
    FubonInventory* items;
    int32_t count;
} FubonInventoryArray;

// Inventory result
typedef struct {
    bool is_success;
    char* error_message;
    FubonInventoryArray* data;
} FubonInventoryResult;

FubonInventoryResult* fubon_inventories(FubonSDK sdk, const FubonAccount* account);
void fubon_free_inventory_result(FubonInventoryResult* result);
```

#### 3.2 實作重點

1. **陣列配置**：
   ```cpp
   auto& cpp_vec = response.data.value();
   c_array->count = cpp_vec.size();
   c_array->items = (FubonInventory*)malloc(sizeof(FubonInventory) * cpp_vec.size());
   ```

2. **循環轉換**：
   ```cpp
   for (size_t i = 0; i < cpp_vec.size(); i++) {
       c_array->items[i].date = strdup_from_cpp(cpp_vec[i].date);
       // ... 其他欄位
       // 嵌套結構直接賦值
       c_array->items[i].odd.lastday_qty = cpp_vec[i].odd.lastday_qty;
   }
   ```

3. **釋放函數**：
   ```cpp
   for (int i = 0; i < result->data->count; i++) {
       free(result->data->items[i].date);
       free(result->data->items[i].account);
       free(result->data->items[i].branch_no);
       free(result->data->items[i].stock_no);
       // InventoryOdd 是嵌入的，不需要額外釋放
   }
   free(result->data->items);
   ```

### 驗收標準

- [ ] 可以成功查詢庫存陣列
- [ ] 陣列長度正確
- [ ] 每個元素的所有欄位正確
- [ ] 嵌套結構（odd）欄位正確
- [ ] 無記憶體洩漏
- [ ] 空陣列情境處理正確

---

## Task 4: maintenance（複雜嵌套結構）

**優先級**: P1
**預估工時**: 2-3 小時
**依賴**: Task 1
**並行**: ✅ 可與 Task 2, 3, 5, 6 並行

### 數據結構分析

**C++ 定義**（fubon.hpp:1048-1097）：
```cpp
struct MaintenanceSummary {
    int64_t margin_value;
    int64_t shortsell_value;
    std::optional<int64_t> shortsell_margin;
    std::optional<int64_t> collateral;
    int64_t margin_loan_amt;
    double maintenance_ratio;
};

struct MaintenanceDetail {
    std::string stock_no;
    std::string order_no;
    std::optional<OrderType> order_type;
    std::optional<int64_t> quantity;
    std::optional<double> price;
    std::optional<double> cost_price;
    std::optional<int64_t> shortsell_margin;
    std::optional<double> collateral;
    std::optional<int64_t> margin_loan_amt;
    std::optional<double> maintenance_ratio;
    std::optional<double> collateral_interest;
    std::optional<double> margin_interest;
    std::optional<double> shortsell_interest;
};

struct MaintenanceData {
    std::string date;
    std::string branch_no;
    std::string account;
    MaintenanceSummary maintenance_summary;
    std::vector<MaintenanceDetail> maintenance_details;
};
```

**特點**：
- ⚠️ 雙層嵌套（Summary + Details array）
- ⚠️ 多個 optional 欄位（11 個）
- ⚠️ Optional enum（OrderType）

### 交付物

#### 4.1 fubon_c.h 新增定義

```c
// MaintenanceSummary
typedef struct {
    int64_t margin_value;
    int64_t shortsell_value;
    bool has_shortsell_margin;
    int64_t shortsell_margin;
    bool has_collateral;
    int64_t collateral;
    int64_t margin_loan_amt;
    double maintenance_ratio;
} FubonMaintenanceSummary;

// MaintenanceDetail
typedef struct {
    char* stock_no;
    char* order_no;
    bool has_order_type;
    FubonOrderType order_type;
    bool has_quantity;
    int64_t quantity;
    bool has_price;
    double price;
    bool has_cost_price;
    double cost_price;
    bool has_shortsell_margin;
    int64_t shortsell_margin;
    bool has_collateral;
    double collateral;
    bool has_margin_loan_amt;
    int64_t margin_loan_amt;
    bool has_maintenance_ratio;
    double maintenance_ratio;
    bool has_collateral_interest;
    double collateral_interest;
    bool has_margin_interest;
    double margin_interest;
    bool has_shortsell_interest;
    double shortsell_interest;
} FubonMaintenanceDetail;

// MaintenanceDetail array
typedef struct {
    FubonMaintenanceDetail* items;
    int32_t count;
} FubonMaintenanceDetailArray;

// MaintenanceData
typedef struct {
    char* date;
    char* branch_no;
    char* account;
    FubonMaintenanceSummary maintenance_summary;
    FubonMaintenanceDetailArray maintenance_details;
} FubonMaintenanceData;

// Result
typedef struct {
    bool is_success;
    char* error_message;
    FubonMaintenanceData* data;
} FubonMaintenanceResult;

FubonMaintenanceResult* fubon_maintenance(FubonSDK sdk, const FubonAccount* account);
void fubon_free_maintenance_result(FubonMaintenanceResult* result);
```

#### 4.2 實作重點

1. **Optional 處理範例**：
   ```cpp
   // Summary optionals
   if (cpp_summary.shortsell_margin.has_value()) {
       c_summary->has_shortsell_margin = true;
       c_summary->shortsell_margin = cpp_summary.shortsell_margin.value();
   } else {
       c_summary->has_shortsell_margin = false;
       c_summary->shortsell_margin = 0;
   }
   ```

2. **Details 陣列**：每個元素有 11 個 optional 欄位需要處理

3. **釋放函數**：需要釋放 details 陣列中每個元素的字串

### 驗收標準

- [ ] Summary 欄位全部正確
- [ ] Details 陣列長度正確
- [ ] 所有 optional 欄位的 flag 正確設置
- [ ] Optional 值在 has_xxx=true 時正確
- [ ] 無記憶體洩漏

---

## Task 5: query_settlement（Optional 密集）

**優先級**: P1
**預估工時**: 2 小時
**依賴**: Task 1
**並行**: ✅ 可與 Task 2-4, 6 並行

### 數據結構分析

**C++ 定義**（fubon.hpp:1930-1951）：
```cpp
struct Settlement {
    std::string date;
    std::optional<std::string> settlement_date;
    std::optional<int64_t> buy_value;
    std::optional<int64_t> buy_fee;
    std::optional<int64_t> buy_settlement;
    std::optional<int64_t> buy_tax;
    std::optional<int64_t> sell_value;
    std::optional<int64_t> sell_fee;
    std::optional<int64_t> sell_settlement;
    std::optional<int64_t> sell_tax;
    std::optional<int64_t> total_bs_value;
    std::optional<int64_t> total_fee;
    std::optional<int64_t> total_tax;
    std::optional<int64_t> total_settlement_amount;
    std::optional<std::string> currency;
};

struct SettlementData {
    std::string account;
    std::string branch_no;
    std::vector<Settlement> details;
};
```

**特點**：
- ⚠️ 14 個 optional 欄位（1 個字串 + 13 個數值）
- ⚠️ 返回陣列（vector<Settlement>）

### 交付物

#### 5.1 fubon_c.h 新增定義

```c
// Settlement structure
typedef struct {
    char* date;

    bool has_settlement_date;
    char* settlement_date;

    bool has_buy_value;
    int64_t buy_value;

    bool has_buy_fee;
    int64_t buy_fee;

    bool has_buy_settlement;
    int64_t buy_settlement;

    bool has_buy_tax;
    int64_t buy_tax;

    bool has_sell_value;
    int64_t sell_value;

    bool has_sell_fee;
    int64_t sell_fee;

    bool has_sell_settlement;
    int64_t sell_settlement;

    bool has_sell_tax;
    int64_t sell_tax;

    bool has_total_bs_value;
    int64_t total_bs_value;

    bool has_total_fee;
    int64_t total_fee;

    bool has_total_tax;
    int64_t total_tax;

    bool has_total_settlement_amount;
    int64_t total_settlement_amount;

    bool has_currency;
    char* currency;
} FubonSettlement;

// Settlement array
typedef struct {
    FubonSettlement* items;
    int32_t count;
} FubonSettlementArray;

// SettlementData
typedef struct {
    char* account;
    char* branch_no;
    FubonSettlementArray settlements;
} FubonSettlementData;

// Result
typedef struct {
    bool is_success;
    char* error_message;
    FubonSettlementData* data;
} FubonSettlementResult;

FubonSettlementResult* fubon_settlement(FubonSDK sdk, const FubonAccount* account, const char* range);
void fubon_free_settlement_result(FubonSettlementResult* result);
```

#### 5.2 實作重點

1. **大量 optional 處理**：需要處理 14 個 optional 欄位的 flag+value 設置

2. **Optional 字串處理**：
   ```cpp
   if (cpp_settlement.settlement_date.has_value()) {
       c_settlement->has_settlement_date = true;
       c_settlement->settlement_date = strdup_from_cpp(cpp_settlement.settlement_date.value());
   } else {
       c_settlement->has_settlement_date = false;
       c_settlement->settlement_date = nullptr;
   }
   ```

3. **釋放函數**：循環釋放陣列中每個元素的 2 個字串（date + optional currency）

### 驗收標準

- [ ] 所有 14 個 optional 欄位的 flag 正確
- [ ] Optional 值正確
- [ ] 陣列處理正確
- [ ] 無記憶體洩漏

---

## Task 6: 損益 API（三個相關 API）

**優先級**: P2
**預估工時**: 2-3 小時
**依賴**: Task 1
**並行**: ✅ 可與 Task 2-5 並行

### 包含 API

1. `realized_gains_and_loses()` - 已實現損益明細
2. `realized_gains_and_loses_summary()` - 已實現損益彙總
3. `unrealized_gains_and_loses()` - 未實現損益

### 數據結構分析

需要查看 `Realized`, `RealizedSummary`, `Unrealized` 的完整定義（從 fubon.hpp 搜索）

### 實作策略

1. 先讀取 C++ SDK 的數據結構定義
2. 按照標準模式映射（optional → flag+value, vector → array struct）
3. 實作轉換與記憶體管理

### 驗收標準

- [ ] 三個 API 都可以成功調用
- [ ] 所有欄位正確映射
- [ ] 無記憶體洩漏

---

## 並行實作建議

### 階段 1：序列執行

```
Task 1（基礎設施）
   ↓
編譯測試通過
```

### 階段 2：並行執行（選擇任意組合）

```
Task 2 (bank_remain)     ← 最簡單，建議先做
Task 3 (inventories)     ← 學習陣列處理
Task 4 (maintenance)     ← 學習 optional 處理
Task 5 (settlement)      ← Optional 密集
Task 6 (損益 APIs)       ← 三個一起做
```

**建議順序**（如果只有一個人）：
1. Task 1 → Task 2 → Task 3 → Task 4 → Task 5 → Task 6

**建議並行**（如果有多人/subagent）：
- Task 1 完成後
- 同時開工：Task 2 + Task 3
- 接著：Task 4 + Task 5
- 最後：Task 6

---

## 文件輸出要求

每個 Task 完成後應產出：

### 程式碼
- `c_wrapper/include/fubon_c.h` - 更新 header
- `c_wrapper/src/fubon_c.cpp` - 實作函數
- `c_wrapper/test/test_accounting.c` - 測試程式

### 文檔（可選）
- API 使用範例
- 已知問題與限制

---

## 整合測試

所有 Task 完成後，編寫完整測試：

```c
int main() {
    FubonSDK sdk = fubon_sdk_new();
    FubonLoginResult* login = fubon_login(sdk, ...);
    FubonAccount* account = &login->accounts->items[0];

    // 測試所有 7 個 API
    test_bank_remain(sdk, account);
    test_inventories(sdk, account);
    test_maintenance(sdk, account);
    test_settlement(sdk, account, "20260103");
    test_realized_gains_and_loses(sdk, account);
    test_realized_summary(sdk, account);
    test_unrealized_gains_and_loses(sdk, account);

    fubon_free_login_result(login);
    fubon_sdk_free(sdk);
    return 0;
}
```

---

## 檢查清單

### Task 1 完成檢查
- [ ] SDK new/free 正常
- [ ] Login 成功返回 Account 陣列
- [ ] CMakeLists.txt 可以編譯
- [ ] 測試程式運行成功
- [ ] 無記憶體洩漏

### Task 2-6 完成檢查（每個 Task）
- [ ] Header 定義完整
- [ ] 實作函數正確轉換所有欄位
- [ ] Free 函數遞迴釋放所有記憶體
- [ ] 測試程式驗證功能
- [ ] 無記憶體洩漏
- [ ] 錯誤處理正確

### 全部完成檢查
- [ ] 所有 7 個 Accounting API 可用
- [ ] 整合測試通過
- [ ] 記憶體洩漏檢測通過
- [ ] 可以被其他語言的 FFI 綁定調用
