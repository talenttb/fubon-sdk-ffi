# Fubon C Wrapper

富邦證券 C++ SDK 的 C ABI 包裝層，將 C++ 介面轉換為標準 C 介面。

## 專案結構

```
c_wrapper/
├── include/
│   └── fubon_c.h          # C ABI 標頭檔
├── src/
│   ├── fubon_c.cpp        # 轉換實作
│   └── helpers.cpp        # 輔助函數
├── test/
│   └── test_sdk.c         # 介面測試
└── CMakeLists.txt
```

## 已實作 API

### Task 1: 基礎設施
- `fubon_sdk_new` / `fubon_sdk_free`
- `fubon_login` / `fubon_dma_login`
- `fubon_free_login_result`

### Task 2: Accounting
- `fubon_bank_remain`
- `fubon_free_bank_remain_result`

## 編譯

```bash
cd c_wrapper
mkdir -p build && cd build
cmake ..
make
```

產生：
- `libfubon_c.dylib` - C wrapper 函式庫
- `test_sdk` - 測試程式

## macOS 動態函式庫處理

**首次使用前必須執行：**

```bash
# 移除 quarantine
xattr -d com.apple.quarantine ../fubon-cpp-sdk/bindings/libfubon.dylib

# 重新簽章
codesign --force --deep -s - ../fubon-cpp-sdk/bindings/libfubon.dylib
```

## 測試

```bash
cd build
DYLD_LIBRARY_PATH=../../fubon-cpp-sdk/bindings:. ./test_sdk
```

測試會驗證：
- C/C++ 資料結構轉換
- 記憶體管理
- 錯誤處理

預期結果：
```
[SUCCESS] All tests passed!
```

## 記憶體管理

**規則：wrapper 配置記憶體，呼叫方負責釋放**

| 函數 | 對應的釋放函數 |
|------|---------------|
| `fubon_sdk_new()` | `fubon_sdk_free()` |
| `fubon_login()` | `fubon_free_login_result()` |
| `fubon_dma_login()` | `fubon_free_login_result()` |
| `fubon_bank_remain()` | `fubon_free_bank_remain_result()` |

## 新增 API

1. 在 `include/fubon_c.h` 定義 C 結構與函數
2. 在 `src/fubon_c.cpp` 實作 C++/C 轉換
3. 在 `test/test_sdk.c` 新增測試
4. 更新此文件

## 故障排除

### `Library not loaded` 或 `code signature not valid`

執行動態函式庫處理步驟（見上方）。

### 編譯錯誤 `file not found`

確認 C++ SDK 位於 `../fubon-cpp-sdk/bindings/`
