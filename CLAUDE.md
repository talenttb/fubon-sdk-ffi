# 富邦證券 C++ SDK → C ABI 包裝專案

## 專案目標

將富邦證券的 C++ SDK 包裝成標準 C ABI 介面，讓各種語言透過 FFI 呼叫。

---

## 架構概覽

```
Rust Core (UniFFI)
    ↓ (C ABI - extern "C")
libfubon.dylib
    ↓ (C++ Wrapper - 現有)
fubon.hpp / sdk.hpp
    ↓ (C Wrapper - 我們要做的)
libfubon_c.dylib
    ↓ (FFI)
任何支援 C FFI 的語言
```

---

## 技術決策

### 1. Callback 處理策略

**C wrapper 層處理序列化**

```c
// C wrapper 提供簡化的 callback 介面
typedef void (*OrderCallback)(
    const char* error,
    const char* order_no,
    const char* stock_no,
    int quantity,
    double price
);

void fubon_register_order_callback(void* sdk, OrderCallback callback);
```

**設計優勢：**
- C wrapper 處理 Rust 序列化格式
- 使用語言只需處理簡單的 C 結構
- 降低 FFI 綁定複雜度

### 2. 資源生命週期管理

**C wrapper 資源管理策略：**

- SDK 實例：由呼叫端持有，直到明確呼叫 `fubon_sdk_free()`
- Callback：與 SDK 同生命週期，在 SDK 釋放時一併清理
- API 結果：呼叫端使用後必須呼叫對應的 `fubon_free_*()` 函數

**呼叫端責任：**
- 確保 SDK 實例在使用期間不被釋放
- 使用完 API 結果後立即釋放記憶體
- 程式結束前呼叫 `fubon_sdk_free()` 清理資源

---

## C Wrapper 設計原則

### 1. 記憶體管理

**規則：C wrapper 負責配置，提供 free 函數**

```c
// 配置
FubonLoginResult* fubon_login(void* sdk, ...);

// 釋放（使用完畢後呼叫）
void fubon_free_login_result(FubonLoginResult* result);
```

### 2. 錯誤處理

**統一的錯誤回傳格式**

```c
typedef struct {
    int is_success;           // 0 = 失敗, 1 = 成功
    char* message;            // 錯誤訊息（成功時為 NULL）
    void* data;               // 實際資料（失敗時為 NULL）
} FubonResult;
```

### 3. 字串處理

**所有字串使用 UTF-8 編碼的 null-terminated C string**

```c
// 輸入：const char* (呼叫端傳入)
// 輸出：char* (呼叫端需要 free)
```

### 4. 陣列處理

**使用結構體包裝陣列 + 長度**

```c
typedef struct {
    FubonAccount* items;
    int count;
} FubonAccountArray;
```

---

## SDK 底層分析

### 已知資訊

1. **底層是 Rust + UniFFI**
   - 所有函數都是 `extern "C"`
   - 參數/回傳值使用 `RustBuffer` (序列化格式)

2. **現有的 C++ wrapper**
   - 位置：`bindings/fubon.hpp`, `bindings/sdk.hpp`
   - 已處理 RustBuffer 的序列化/反序列化
   - 提供物件導向的 C++ 介面

3. **WebSocket 連線**
   - ✅ 由 Rust 層內部管理
   - ✅ 在 `login()` 時建立連線
   - ✅ 呼叫端不需要處理 WebSocket

4. **Callback 機制**
   - 底層使用 `ForeignCallback` typedef
   - 參數是序列化的 binary data
   - 需要在 C wrapper 層反序列化

---

## 工作流程

### 開發模式：漸進式、需求驅動

```
用戶定義需求           Claude 實作
    ↓                      ↓
"我需要登入功能"    → 查 SDK 文件
                          ↓
                    設計 C ABI 介面
                          ↓
                    實作 C wrapper
                          ↓
                    提供 header + 實作
    ↓                      ↓
審查 & 反饋         → 迭代調整
    ↓
確認無誤，下一個功能
```

**流程特點：**
- 漸進式開發，Focus 在實際需要的功能
- 即時反饋和調整
- 發揮各自專長（業務 vs 技術）

---

## 核心 API 清單

### 已確認需要的功能

#### 1. SDK 管理
- [ ] `fubon_sdk_new()` - 初始化 SDK
- [ ] `fubon_sdk_free()` - 釋放 SDK
- [ ] `fubon_login()` - 登入
- [ ] `fubon_logout()` - 登出

#### 2. 帳號資訊
- [ ] `fubon_bank_remain()` - 查詢銀行餘額
- [ ] `fubon_inventories()` - 查詢庫存
- [ ] `fubon_maintenance()` - 查詢維持率
- [ ] `fubon_settlement()` - 查詢交割資訊

#### 3. 下單（證券）
- [ ] `fubon_place_order()` - 下單
- [ ] `fubon_cancel_order()` - 取消委託
- [ ] `fubon_modify_order()` - 修改委託
- [ ] `fubon_get_order_results()` - 查詢委託

#### 4. 下單（期貨）
- [ ] `fubon_futopt_place_order()` - 期貨下單
- [ ] `fubon_futopt_cancel_order()` - 取消期貨委託

#### 5. Callback
- [ ] `fubon_register_order_callback()` - 訂單回報
- [ ] `fubon_register_filled_callback()` - 成交回報
- [ ] `fubon_register_event_callback()` - 事件通知

---

## 技術細節

### 動態庫位置

```bash
# macOS
/Users/liyu/project/fubon-cpp-sdk/bindings/libfubon.dylib

# 執行時需要設定 DYLD_LIBRARY_PATH
DYLD_LIBRARY_PATH=/path/to/bindings ./program
```

### 編譯環境

```bash
# 當前環境
- macOS (Darwin 23.6.0)
- Apple Silicon (arm64)
- CMake 3.17+
- C++ 20

# 編譯 C wrapper
mkdir build
cd build
cmake ..
make
```

---

## 環境配置

### 動態庫路徑設定

```bash
# 檢查動態庫連結
otool -L fubon_example

# 執行時設定 library path
DYLD_LIBRARY_PATH=/path/to/bindings ./program
```

### 憑證檔案配置

憑證檔案建議配置方式：
- 使用相對路徑：`./cert.pfx`
- 將憑證放置在執行檔目錄
- 或使用絕對路徑：`/full/path/to/cert.pfx`

---

## 參考資料

### SDK 內部結構

```cpp
// 主要類別
class FubonSDK {
    std::shared_ptr<StockFunctions> stock;
    std::shared_ptr<Accounting> accounting;
    std::shared_ptr<FutOptFunctions> futopt;
    std::shared_ptr<FutOptAccounting> futopt_accounting;
};

// Callback 介面
struct Callback {
    virtual void on_order(...) = 0;
    virtual void on_order_changed(...) = 0;
    virtual void on_filled(...) = 0;
    virtual void on_futopt_order(...) = 0;
    // ...
};
```

### 重要檔案

```
fubon-sdk-ffi/
├── CMakeLists.txt              # 編譯配置
├── CLAUDE.md                   # 專案架構文件
├── Example/
│   └── main.cpp                # 範例程式
├── fubon-cpp-sdk/              # 原始 C++ SDK
│   ├── bindings/
│   │   ├── libfubon.dylib      # Rust core (C ABI)
│   │   ├── fubon_scaffolding.hpp  # C 函數定義
│   │   ├── fubon.hpp           # C++ 類別定義
│   │   ├── sdk.hpp             # SDK 入口
│   │   ├── pretty_print.hpp    # 輸出格式化
│   │   └── fubon.cpp           # C++ wrapper 實作
└── c_wrapper/                  # C ABI wrapper（我們要實作的）
    ├── fubon_c.h
    └── fubon_c.cpp
```

---

## 下一步

1. **確認需要包裝的功能清單**
   - 從最基本的開始（初始化、登入、查詢）
   - 逐步增加複雜功能（下單、callback）

2. **設計第一版 C ABI**
   - 定義基本型別（FubonSDK, FubonAccount, FubonResult）
   - 實作核心函數（new, login, bank_remain）

3. **實作 C wrapper**
   - 處理 C++ 物件與 C 指標的轉換
   - 記憶體管理
   - 錯誤處理

4. **測試與驗證**
   - 編寫 C 測試程式
   - 驗證記憶體管理正確性
   - 提供各語言 FFI 綁定範例

---

## 更新日誌

- **2026-01-03**: 重構文件，專注 C ABI
  - 移除 Clojure 特定內容
  - 專注於通用 FFI 介面設計
  - 更新目標為支援各種語言的 FFI 綁定

- **2025-12-16**: 初始文件建立
  - 確認技術架構（Rust + UniFFI → C++ → C ABI → FFI）
  - 定義設計原則（記憶體管理、錯誤處理、資源生命週期）
  - 建立漸進式開發流程
