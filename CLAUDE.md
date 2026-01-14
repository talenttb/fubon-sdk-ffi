# 富邦證券 C++ SDK → C ABI 包裝專案

## 專案目標

將富邦證券的 C++ SDK 包裝成標準 C ABI 介面，讓各種語言透過 FFI 呼叫。

```
Rust Core (UniFFI)
    ↓ (C ABI)
libfubon.dylib (C++ SDK)
    ↓ (C Wrapper - 我們的工作)
libfubon_c.dylib
    ↓ (FFI)
任何支援 C FFI 的語言 (Clojure, Python, Rust...)
```

---

## 新增 API 的標準開發流程

**⚠️ 重要：每個步驟都必須完成，特別是測試！**

### 1. 設計 C ABI 介面
在 `c_wrapper/include/fubon_c.h` 定義結構和函數

```c
// 定義資料結構
typedef struct { ... } FubonXxx;

// 定義結果結構（統一格式）
typedef struct {
    bool is_success;
    char* error_message;
    FubonXxx* data;  // NULL if error
} FubonXxxResult;

// 定義函數
FubonXxxResult* fubon_xxx(FubonSDK sdk, ...);
void fubon_free_xxx_result(FubonXxxResult* result);
```

### 2. 實作 C Wrapper
在 `c_wrapper/src/fubon_c.cpp` 實作

- 處理 C++ ↔ C 的類型轉換
- 使用 `strdup_from_cpp()` 轉換字串
- 使用 `new` 配置記憶體
- 實作對應的 `fubon_free_*()` 函數

### 3. 📝 撰寫 C 測試 ⬅️ **必須！**
在 `c_wrapper/test/test_sdk.c` 添加測試

```c
void test_xxx_conversion() {
    // Test 1: 正常情況
    FubonXxxResult* result = fubon_xxx(...);
    TEST_ASSERT(result != NULL, "Result allocated");

    // Test 2: 驗證轉換
    if (result->is_success) {
        TEST_ASSERT(result->data != NULL, "Data converted");
        // 驗證欄位...
    }

    // Test 3: NULL 參數處理
    FubonXxxResult* result2 = fubon_xxx(NULL, ...);
    TEST_ASSERT(!result2->is_success, "NULL handled");

    // 記憶體釋放
    fubon_free_xxx_result(result);
    fubon_free_xxx_result(result2);
}
```

**測試必須包含：**
- ✅ 正常情況測試
- ✅ 錯誤處理測試
- ✅ NULL 參數測試
- ✅ 記憶體釋放驗證

### 4. 編譯並執行測試

```bash
cd c_wrapper
cmake --build build
DYLD_LIBRARY_PATH=../fubon-cpp-sdk/bindings ./build/test_sdk
```

---

## C Wrapper 設計原則

### 記憶體管理

**規則：C wrapper 配置，呼叫端釋放**

```c
// ✅ 正確使用
FubonXxxResult* result = fubon_xxx(...);
// ... 使用 result ...
fubon_free_xxx_result(result);  // 必須呼叫！

// ❌ 錯誤：忘記釋放 → 記憶體洩漏
FubonXxxResult* result = fubon_xxx(...);
// ... 使用後沒有呼叫 free ...
```

### 錯誤處理

**統一的錯誤回傳格式**

```c
typedef struct {
    bool is_success;        // true = 成功, false = 失敗
    char* error_message;    // 錯誤訊息（成功時為 NULL）
    void* data;             // 實際資料（失敗時為 NULL）
} FubonResult;
```

### 字串處理

- 所有字串使用 UTF-8 編碼的 null-terminated C string
- 輸入：`const char*` (呼叫端傳入)
- 輸出：`char*` (呼叫端需要 free)

### Optional 欄位處理

- `optional<double>`: 使用 `NAN` 表示 None
- `optional<int64_t>`: 使用 `-1` 表示 None
- `optional<string>`: 使用 `NULL` 表示 None

---

## 常用指令

### 編譯 C Wrapper

```bash
cd c_wrapper
mkdir -p build
cd build
cmake ..
make
```

### 執行測試

```bash
# 基本測試
DYLD_LIBRARY_PATH=../fubon-cpp-sdk/bindings ./build/test_sdk

# 記憶體洩漏檢查（macOS）
leaks --atExit -- env DYLD_LIBRARY_PATH=../fubon-cpp-sdk/bindings ./build/test_sdk
```

---

## 為什麼測試很重要

1. **C 層錯誤會導致 segfault**，難以在 APP 層調試
2. **記憶體洩漏**會在長時間運行時累積
3. **FFI 邊界**是最容易出錯的地方（型別轉換、NULL 處理）
4. **測試即文檔**，展示正確的使用方式

---

## 專案結構

```
fubon-sdk-ffi/
├── c_wrapper/
│   ├── include/fubon_c.h       # C ABI header
│   ├── src/fubon_c.cpp         # C wrapper 實作
│   ├── src/helpers.cpp         # 輔助函數
│   └── test/test_sdk.c         # C 測試
├── fubon-cpp-sdk/bindings/
│   ├── libfubon.dylib          # Rust core
│   ├── fubon.hpp               # C++ wrapper
│   └── sdk.hpp                 # SDK 入口
└── docs/
    └── SDK_API_CATALOG.md      # SDK API 完整清單
```

---

## 開發提醒

- ⚠️ **每次新增 API 都要寫測試**
- ⚠️ **記得呼叫所有 `fubon_free_*()` 函數**
- ⚠️ **測試 NULL 參數處理**
- ⚠️ **執行 100 次調用測試記憶體洩漏**
