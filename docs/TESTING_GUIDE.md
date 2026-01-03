# C ABI Wrapper 測試準則

**適用對象**: 所有實作 C ABI wrapper 的開發者
**必讀**: 每實作一個 API 都必須撰寫對應的測試

---

## 為什麼需要測試

### 測試目標

您實作的 C ABI wrapper 是**包裝層**，負責：
- 將 C++ 型別轉換為 C 型別
- 管理記憶體配置與釋放
- 處理錯誤與異常

**測試目的**：確保這一層的轉換邏輯正確，而非測試底層 SDK 功能（那是富邦的責任）

### 我們測試什麼

✅ **需要測試**：
1. C++ → C 型別轉換是否正確
2. 記憶體是否正確配置與釋放
3. Optional 欄位的 flag 是否正確設置
4. 陣列的 count 和每個元素是否正確
5. 錯誤處理是否正確（異常 → 錯誤訊息）

❌ **不需要測試**：
- 底層 SDK 的商業邏輯（富邦已測試）
- 網路連線功能
- WebSocket 通訊
- 真實的登入/交易功能

---

## 測試策略：使用 Fake SDK

### 核心概念

**隔離測試**：創建假的 C++ SDK 回應，測試您的轉換邏輯

```
真實環境：
C Wrapper → C++ SDK → Rust Core → WebSocket → 富邦伺服器
   ↑
 我們實作的

測試環境：
C Wrapper → Fake C++ SDK (返回固定測試數據)
   ↑
只測試這層
```

### 優點

- ⚡ **快速**：不需要網路連線、憑證
- 🎯 **精確**：只測試轉換邏輯
- 🔄 **可重複**：每次測試結果一致
- 🛡️ **安全**：不會影響生產環境

---

## 測試框架設定

### 工具鏈

- **GoogleTest**：C++ 測試框架
- **AddressSanitizer (ASan)**：自動檢測記憶體洩漏
- **Fake SDK**：模擬 C++ SDK 回應

### CMakeLists.txt 配置

```cmake
enable_testing()
find_package(GTest REQUIRED)

# 編譯 wrapper（暴露內部轉換函數供測試）
add_library(fubon_c_testable SHARED
    src/fubon_c.cpp
    src/helpers.cpp
)
target_compile_definitions(fubon_c_testable PRIVATE ENABLE_TEST_EXPORTS)

# 測試程式
add_executable(wrapper_tests
    test/test_bank_remain.cpp
    test/test_inventories.cpp
    test/test_maintenance.cpp
)

target_include_directories(wrapper_tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/test
    ${CMAKE_SOURCE_DIR}/../fubon-cpp-sdk/bindings
)

target_link_libraries(wrapper_tests
    GTest::GTest
    GTest::Main
    fubon_c_testable
)

# 啟用 AddressSanitizer
target_compile_options(wrapper_tests PRIVATE -fsanitize=address -g)
target_link_options(wrapper_tests PRIVATE -fsanitize=address)

add_test(NAME WrapperTests COMMAND wrapper_tests)
```

---

## Fake SDK 實作

### 目錄結構

```
c_wrapper/test/
├── fakes/
│   ├── fake_sdk.hpp       # Fake SDK 定義
│   └── test_data.hpp      # 測試數據常量
├── test_bank_remain.cpp
├── test_inventories.cpp
└── ...
```

### Fake SDK 範例

```cpp
// test/fakes/fake_sdk.hpp
#ifndef FAKE_SDK_HPP
#define FAKE_SDK_HPP

#include "fubon.hpp"

namespace fubon {

class FakeAccounting : public Accounting {
public:
    // 返回固定的測試數據
    BankRemainResponse bank_remain(const Account& account) override {
        BankRemainResponse response;
        response.is_success = true;

        BankRemain data;
        data.branch_no = "9999";
        data.account = "TEST123";
        data.currency = "TWD";
        data.balance = 1000000;
        data.available_balance = 500000;

        response.data = data;
        return response;
    }

    // 測試錯誤情境
    BankRemainResponse bank_remain_error(const Account& account) {
        BankRemainResponse response;
        response.is_success = false;
        response.message = "Test error: Connection timeout";
        return response;
    }
};

} // namespace fubon

#endif
```

### 設計原則

1. **簡單明確**：返回固定的測試數據
2. **覆蓋邊界**：包含 optional 有值/無值的情況
3. **錯誤情境**：提供錯誤回應的測試方法

---

## 測試案例範本

### 範本 1：簡單結構（無 optional、無陣列）

**範例**：`bank_remain`

```cpp
// test/test_bank_remain.cpp
#include <gtest/gtest.h>
#include "fubon_c.h"
#include "fakes/fake_sdk.hpp"

// 暴露內部轉換函數供測試
extern "C" {
    FubonBankRemainResult* convert_bank_remain_response(
        const fubon::BankRemainResponse& cpp_response
    );
}

TEST(BankRemainTest, SuccessConversion) {
    // 1. 準備假數據
    fubon::FakeAccounting fake_accounting;
    fubon::Account cpp_account{"Test", "9999", "TEST123", "S"};

    // 2. 取得 C++ 回應
    auto cpp_response = fake_accounting.bank_remain(cpp_account);

    // 3. 測試轉換
    auto* c_result = convert_bank_remain_response(cpp_response);

    // 4. 驗證結果
    ASSERT_NE(c_result, nullptr);
    EXPECT_TRUE(c_result->is_success);
    EXPECT_EQ(c_result->error_message, nullptr);

    ASSERT_NE(c_result->data, nullptr);
    EXPECT_STREQ(c_result->data->branch_no, "9999");
    EXPECT_STREQ(c_result->data->account, "TEST123");
    EXPECT_STREQ(c_result->data->currency, "TWD");
    EXPECT_EQ(c_result->data->balance, 1000000);
    EXPECT_EQ(c_result->data->available_balance, 500000);

    // 5. 清理記憶體
    fubon_free_bank_remain_result(c_result);
}

TEST(BankRemainTest, ErrorHandling) {
    fubon::FakeAccounting fake_accounting;
    fubon::Account cpp_account{"Test", "9999", "TEST123", "S"};

    // 測試錯誤情境
    auto cpp_response = fake_accounting.bank_remain_error(cpp_account);
    auto* c_result = convert_bank_remain_response(cpp_response);

    EXPECT_FALSE(c_result->is_success);
    EXPECT_STREQ(c_result->error_message, "Test error: Connection timeout");
    EXPECT_EQ(c_result->data, nullptr);

    fubon_free_bank_remain_result(c_result);
}

TEST(BankRemainTest, MemoryManagement) {
    fubon::FakeAccounting fake_accounting;
    fubon::Account cpp_account{"Test", "9999", "TEST123", "S"};

    // 循環配置/釋放 1000 次
    for (int i = 0; i < 1000; i++) {
        auto cpp_response = fake_accounting.bank_remain(cpp_account);
        auto* c_result = convert_bank_remain_response(cpp_response);
        fubon_free_bank_remain_result(c_result);
    }

    // AddressSanitizer 會自動檢測洩漏
    // 如果有洩漏，測試會失敗
}
```

---

### 範本 2：陣列處理

**範例**：`inventories`

```cpp
// test/test_inventories.cpp
#include <gtest/gtest.h>
#include "fubon_c.h"
#include "fakes/fake_sdk.hpp"

extern "C" {
    FubonInventoryResult* convert_inventories_response(
        const fubon::InventoryResponse& cpp_response
    );
}

TEST(InventoriesTest, ArrayConversion) {
    // Fake SDK 返回 2 個 inventory items
    fubon::FakeAccounting fake_accounting;
    fubon::Account cpp_account{"Test", "9999", "TEST123", "S"};

    auto cpp_response = fake_accounting.inventories(cpp_account);
    auto* c_result = convert_inventories_response(cpp_response);

    ASSERT_TRUE(c_result->is_success);
    ASSERT_NE(c_result->data, nullptr);

    // 驗證陣列長度
    EXPECT_EQ(c_result->data->count, 2);

    // 驗證第一個元素
    auto* inv1 = &c_result->data->items[0];
    EXPECT_STREQ(inv1->date, "2026/01/03");
    EXPECT_STREQ(inv1->stock_no, "2330");
    EXPECT_EQ(inv1->order_type, FUBON_ORDER_TYPE_STOCK);
    EXPECT_EQ(inv1->today_qty, 1000);
    EXPECT_EQ(inv1->tradable_qty, 800);

    // 驗證嵌套結構
    EXPECT_EQ(inv1->odd.lastday_qty, 100);
    EXPECT_EQ(inv1->odd.buy_qty, 50);

    // 驗證第二個元素
    auto* inv2 = &c_result->data->items[1];
    EXPECT_STREQ(inv2->stock_no, "2317");

    fubon_free_inventory_result(c_result);
}

TEST(InventoriesTest, EmptyArray) {
    // 測試空陣列情況
    fubon::InventoryResponse cpp_response;
    cpp_response.is_success = true;
    cpp_response.data = std::vector<fubon::Inventory>{};  // 空陣列

    auto* c_result = convert_inventories_response(cpp_response);

    EXPECT_TRUE(c_result->is_success);
    ASSERT_NE(c_result->data, nullptr);
    EXPECT_EQ(c_result->data->count, 0);
    EXPECT_NE(c_result->data->items, nullptr);  // 即使空陣列也應配置

    fubon_free_inventory_result(c_result);
}
```

---

### 範本 3：Optional 處理

**範例**：`maintenance`

```cpp
// test/test_maintenance.cpp
#include <gtest/gtest.h>
#include "fubon_c.h"
#include "fakes/fake_sdk.hpp"

extern "C" {
    FubonMaintenanceResult* convert_maintenance_response(
        const fubon::MaintenanceResponse& cpp_response
    );
}

TEST(MaintenanceTest, OptionalHandling) {
    fubon::FakeAccounting fake_accounting;
    fubon::Account cpp_account{"Test", "9999", "TEST123", "S"};

    auto cpp_response = fake_accounting.maintenance(cpp_account);
    auto* c_result = convert_maintenance_response(cpp_response);

    ASSERT_TRUE(c_result->is_success);
    ASSERT_NE(c_result->data, nullptr);

    // 測試 Summary 的 optional 欄位
    auto* summary = &c_result->data->maintenance_summary;

    // 有值的 optional
    EXPECT_TRUE(summary->has_shortsell_margin);
    EXPECT_EQ(summary->shortsell_margin, 50000);

    // 無值的 optional
    EXPECT_FALSE(summary->has_collateral);
    // collateral 的值無所謂（因為 has_collateral = false）

    // 測試 Details 的 optional 欄位
    ASSERT_EQ(c_result->data->maintenance_details.count, 1);
    auto* detail = &c_result->data->maintenance_details.items[0];

    // Optional enum 有值
    EXPECT_TRUE(detail->has_order_type);
    EXPECT_EQ(detail->order_type, FUBON_ORDER_TYPE_MARGIN);

    // Optional 數值有值
    EXPECT_TRUE(detail->has_quantity);
    EXPECT_EQ(detail->quantity, 1000);

    // Optional 數值無值
    EXPECT_FALSE(detail->has_price);

    fubon_free_maintenance_result(c_result);
}

TEST(MaintenanceTest, AllOptionalsEmpty) {
    // 測試所有 optional 都是 nullopt 的情況
    fubon::MaintenanceResponse cpp_response;
    cpp_response.is_success = true;

    fubon::MaintenanceData data;
    data.date = "2026/01/03";
    data.account = "TEST123";
    data.branch_no = "9999";

    // 所有 optional 都設為 nullopt
    data.maintenance_summary.shortsell_margin = std::nullopt;
    data.maintenance_summary.collateral = std::nullopt;

    cpp_response.data = data;

    auto* c_result = convert_maintenance_response(cpp_response);

    auto* summary = &c_result->data->maintenance_summary;
    EXPECT_FALSE(summary->has_shortsell_margin);
    EXPECT_FALSE(summary->has_collateral);

    fubon_free_maintenance_result(c_result);
}
```

---

## 實作步驟

### 步驟 1：暴露內部轉換函數

在您的實作中，使用條件編譯暴露測試函數：

```cpp
// src/fubon_c.cpp

#ifdef ENABLE_TEST_EXPORTS
extern "C" {
    // 測試專用：暴露內部轉換函數
    FubonBankRemainResult* convert_bank_remain_response(
        const fubon::BankRemainResponse& cpp_response
    ) {
        // ... 實際的轉換邏輯
    }
}
#endif

// 正常的 API 函數
extern "C" {
    FubonBankRemainResult* fubon_bank_remain(FubonSDK sdk, const FubonAccount* account) {
        // ...
        auto cpp_response = cpp_sdk->accounting->bank_remain(cpp_account);
        return convert_bank_remain_response(cpp_response);  // 呼叫內部函數
    }
}
```

### 步驟 2：創建 Fake SDK

為您實作的 API 在 Fake SDK 中提供測試數據：

```cpp
// test/fakes/fake_sdk.hpp

class FakeAccounting : public Accounting {
public:
    YourApiResponse your_api(const Account& account) override {
        YourApiResponse response;
        response.is_success = true;

        // 設置測試數據
        YourData data;
        data.field1 = "test_value";
        data.field2 = 12345;
        data.optional_field = std::nullopt;  // 測試 optional 無值

        response.data = data;
        return response;
    }
};
```

### 步驟 3：撰寫測試案例

至少包含以下測試：

1. **成功轉換測試**：驗證所有欄位正確
2. **錯誤處理測試**：驗證 is_success = false 情況
3. **記憶體管理測試**：循環配置/釋放
4. **邊界測試**：optional 無值、空陣列等

### 步驟 4：執行測試

```bash
cd c_wrapper/build
cmake ..
make

# 執行測試
./wrapper_tests

# 或使用 ctest
ctest -V

# 記憶體檢測（ASan 會自動執行）
# 如果有洩漏，測試會失敗並顯示錯誤位置
```

---

## 測試檢查清單

### 每個 API 實作完成後

- [ ] **創建 Fake SDK 方法**：返回測試數據
- [ ] **測試成功情境**：所有欄位正確轉換
- [ ] **測試錯誤情境**：is_success = false 處理正確
- [ ] **測試 Optional 欄位**：
  - [ ] 有值時 has_xxx = true，值正確
  - [ ] 無值時 has_xxx = false
- [ ] **測試陣列**：
  - [ ] count 正確
  - [ ] 每個元素正確
  - [ ] 空陣列處理正確
- [ ] **測試嵌套結構**：所有層級都正確
- [ ] **記憶體測試**：循環 1000 次無洩漏
- [ ] **所有測試通過**：`ctest` 全綠

---

## 記憶體測試方法

### 使用 AddressSanitizer

**自動檢測**：ASan 會在測試執行時自動檢測：
- 記憶體洩漏
- Use-after-free
- Double-free
- Buffer overflow

**使用方法**：

```cmake
# CMakeLists.txt 已配置
target_compile_options(wrapper_tests PRIVATE -fsanitize=address -g)
target_link_options(wrapper_tests PRIVATE -fsanitize=address)
```

執行測試時，如果有記憶體問題，ASan 會顯示詳細錯誤：

```
=================================================================
==12345==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 100 byte(s) in 1 object(s) allocated from:
    #0 0x... in malloc
    #1 0x... in strdup_from_cpp
    #2 0x... in convert_bank_remain_response

SUMMARY: AddressSanitizer: 100 byte(s) leaked in 1 allocation(s).
```

### 手動檢測（可選）

```bash
# macOS
leaks --atExit -- ./wrapper_tests

# Linux
valgrind --leak-check=full ./wrapper_tests
```

---

## 常見錯誤與解決

### 錯誤 1：忘記釋放字串

```cpp
// ❌ 錯誤
void fubon_free_result(FubonResult* result) {
    delete result->data;  // 忘記釋放 data 內的字串！
    delete result;
}

// ✅ 正確
void fubon_free_result(FubonResult* result) {
    if (result->data) {
        free(result->data->some_string);  // 先釋放字串
        delete result->data;
    }
    delete result;
}
```

**測試會檢測到**：記憶體測試會失敗，ASan 顯示洩漏位置

---

### 錯誤 2：Optional flag 設置錯誤

```cpp
// ❌ 錯誤
if (cpp_data.price.has_value()) {
    c_data->price = cpp_data.price.value();
    // 忘記設置 has_price = true！
}

// ✅ 正確
if (cpp_data.price.has_value()) {
    c_data->has_price = true;
    c_data->price = cpp_data.price.value();
} else {
    c_data->has_price = false;
    c_data->price = 0.0;  // 預設值
}
```

**測試會檢測到**：Optional 測試會失敗

```cpp
TEST(YourTest, OptionalHandling) {
    // ...
    EXPECT_TRUE(detail->has_price);  // ❌ 失敗！實際是 false
}
```

---

### 錯誤 3：陣列長度錯誤

```cpp
// ❌ 錯誤
c_array->count = cpp_vec.size() + 1;  // 多算了一個！

// ✅ 正確
c_array->count = cpp_vec.size();
```

**測試會檢測到**：陣列測試會失敗或 crash

```cpp
TEST(YourTest, ArrayConversion) {
    // ...
    EXPECT_EQ(c_result->data->count, 2);  // ❌ 失敗！實際是 3
}
```

---

## 測試覆蓋目標

### 最低要求

每個 API 至少包含：
1. ✅ 成功轉換測試
2. ✅ 錯誤處理測試
3. ✅ 記憶體管理測試

### 建議覆蓋

- ✅ Optional 有值/無值
- ✅ 陣列 空/有元素
- ✅ 嵌套結構 所有層級
- ✅ 邊界情況（空字串、0 值等）

### 執行標準

所有測試必須通過，無記憶體洩漏：

```bash
$ ctest -V
Test project /path/to/c_wrapper/build
    Start 1: WrapperTests
1/1 Test #1: WrapperTests .....................   Passed    0.15 sec

100% tests passed, 0 tests failed out of 1
```

---

## 範例測試檔案結構

```
c_wrapper/test/
├── fakes/
│   ├── fake_sdk.hpp          # Fake Accounting + 其他模組
│   └── test_data.hpp         # 測試數據常量
│
├── test_bank_remain.cpp      # bank_remain 測試
│   ├── SuccessConversion
│   ├── ErrorHandling
│   └── MemoryManagement
│
├── test_inventories.cpp      # inventories 測試
│   ├── ArrayConversion
│   ├── EmptyArray
│   └── NestedStructure
│
├── test_maintenance.cpp      # maintenance 測試
│   ├── OptionalHandling
│   ├── AllOptionalsEmpty
│   └── DetailsArray
│
├── test_settlement.cpp       # settlement 測試
│   └── MultipleOptionals
│
└── test_memory.cpp           # 綜合記憶體測試
    └── NoLeaksOnMultipleCalls
```

---

## 總結

### 核心原則

1. **隔離測試**：使用 Fake SDK，不依賴真實連線
2. **測試轉換**：只測試 C++ → C 的轉換邏輯
3. **自動檢測**：讓 ASan 幫您找記憶體問題
4. **全面覆蓋**：成功/錯誤/optional/陣列 都要測

### 開發流程

```
實作 API
   ↓
創建 Fake SDK 方法
   ↓
撰寫測試案例
   ↓
執行測試
   ↓
修正錯誤
   ↓
所有測試通過 ✅
```

### 成功標準

- ✅ 所有測試通過（`ctest` 全綠）
- ✅ 無記憶體洩漏（ASan 無錯誤）
- ✅ 覆蓋所有情境（成功/錯誤/optional/陣列）

---

**記住**：測試是為了確保您的 wrapper 層正確，不是測試富邦的 SDK。使用 Fake SDK 讓測試快速、可靠、可重複！
