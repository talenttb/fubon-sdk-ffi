# fubon-sdk-ffi

富邦證券 C++ SDK 的 C ABI 包裝專案，將 C++ SDK 包裝成標準 C 介面，讓任何支援 FFI 的語言都能呼叫。

## 專案目標

將富邦證券的 C++ SDK 包裝成標準 C ABI 介面。

**本專案提供**：
- 符合標準的 C ABI 介面設計與實作
- C++ 與 C 之間的資料轉換處理
- 完整的記憶體管理機制
- 跨平台相容性（macOS、Linux、Windows）

---

## 專案架構

```
Rust Core (UniFFI)
    ↓
libfubon.dylib          (C ABI - 現有)
    ↓
C++ Wrapper             (現有)
    ↓
C ABI Wrapper           (我們要實作的)
    ↓
FFI 綁定                (各種語言)
```

---

## 前置需求

### 編譯環境
- **CMake** 3.17 或以上
- **C++ 編譯器** 支援 C++20
  - macOS: Clang (Xcode Command Line Tools)
  - Linux: GCC 10+ 或 Clang 10+
  - Windows: MSVC 2019+ 或 MinGW

### 執行環境
- **動態庫**：專案已包含預編譯的 SDK 動態庫
  - macOS: `fubon-cpp-sdk/bindings/libfubon.dylib`
  - Linux: `fubon-cpp-sdk/bindings/libfubon.so`
  - Windows: `fubon-cpp-sdk/bindings/fubon.dll`

---

## 快速開始

### 1. 下載專案

```bash
git clone <repository-url>
cd fubon-sdk-ffi
```

### 2. 編譯 C++ SDK 範例（測試環境）

```bash
cd fubon-cpp-sdk
mkdir build
cd build
cmake ..
make
```

### 3. 執行範例程式

```bash
# macOS / Linux
DYLD_LIBRARY_PATH=../bindings ./fubon_example    # macOS
# 或
LD_LIBRARY_PATH=../bindings ./fubon_example      # Linux

# Windows
.\fubon_example.exe
```

### 4. 使用 C ABI Wrapper（待實作）

未來的使用方式：

```bash
# 編譯 C wrapper
cd c_wrapper
mkdir build
cd build
cmake ..
make

# 產出：libfubon_c.dylib (或 .so / .dll)
```

---

## C ABI 介面設計原則

### 設計原則

1. **所有函數使用 `extern "C"`**，確保 C 語言相容性
2. **簡單資料型別**：使用 C 基本型別（int, char*, void*）
3. **明確的記憶體管理**：每個配置函數都有對應的釋放函數
4. **統一的錯誤處理**：使用結構體回傳成功/失敗狀態
5. **跨平台相容**：支援 macOS、Linux、Windows

### 輸出產物

- **標頭檔**：`fubon_c.h` - 完整的 C ABI 函數宣告
- **動態庫**：
  - macOS: `libfubon_c.dylib`
  - Linux: `libfubon_c.so`
  - Windows: `fubon_c.dll`
- **測試程式**：C 語言範例，驗證 ABI 正確性

---

## 開發狀態

- [x] 專案架構設計
- [x] C++ SDK 整合
- [ ] C ABI 介面設計
- [ ] C ABI wrapper 實作
- [ ] C 語言測試程式
- [ ] 跨平台編譯驗證

---

## 環境變數設定

### macOS
```bash
export DYLD_LIBRARY_PATH=/path/to/fubon-sdk-ffi/fubon-cpp-sdk/bindings:$DYLD_LIBRARY_PATH
```

### Linux
```bash
export LD_LIBRARY_PATH=/path/to/fubon-sdk-ffi/fubon-cpp-sdk/bindings:$LD_LIBRARY_PATH
```

### Windows
將 `fubon-cpp-sdk\bindings` 加入 PATH 或將 DLL 放在執行檔相同目錄。

---

## 技術細節

詳細的設計文件請參考：[CLAUDE.md](./CLAUDE.md)

包含：
- 完整架構說明
- C ABI 設計原則
- 記憶體管理策略
- 錯誤處理機制
- Callback 處理方式

---

## 授權

本專案採用 Apache License 2.0，詳見 [LICENSE](./LICENSE)

---

## 貢獻

歡迎提交 Issue 和 Pull Request！