---
name: cpp-to-c-abi
description: Generate C ABI wrappers for third-party C++ libraries, enabling FFI access from languages like Clojure (via Panama), Rust, Python, etc. Use when wrapping C++ classes/functions into C-compatible shared libraries (.dylib/.so), creating extern "C" interfaces, or building FFI-friendly APIs from C++ code.
---

# C++ to C ABI Wrapper Generator

Generate C ABI wrappers for third-party C++ libraries targeting Panama FFI consumption (Clojure, Java) on macOS and Linux.

## Conventions

### Naming
- Functions: `{libname}_{classname}_{method}` (e.g., `opencv_mat_create`)
- Types: `{Libname}{Classname}Handle` (e.g., `OpencvMatHandle`)
- Error codes enum: `{Libname}Error` (e.g., `OpencvError`)

### Error Handling
Return error code + out parameter pattern:

```c
// Returns: 0 = success, non-zero = error code
int opencv_mat_create(int rows, int cols, OpencvMatHandle* out_handle);

// Get error description
const char* opencv_error_string(int error_code);
```

### Memory Management
Strict create/destroy pairing:

```c
int opencv_mat_create(..., OpencvMatHandle* out);
void opencv_mat_destroy(OpencvMatHandle handle);
```

### Handle Types
Use incomplete struct for type safety:

```c
typedef struct OpencvMat_s* OpencvMatHandle;
```

### Strings
Caller provides buffer:

```c
int opencv_mat_get_name(OpencvMatHandle h, char* buf, size_t buf_size, size_t* out_len);
// Returns error if buffer too small, out_len contains required size
```

### Arrays
Pointer + separate size function:

```c
const float* opencv_mat_get_data(OpencvMatHandle h);
size_t opencv_mat_get_data_size(OpencvMatHandle h);
```

## File Structure

Generate this structure:

```
{libname}_wrapper/
├── include/
│   └── {libname}_wrapper.h
├── src/
│   └── {libname}_wrapper.cpp
├── test/
│   └── test_{libname}_wrapper.cpp
├── CMakeLists.txt
└── README.md
```

## Implementation Guide

### Step 1: Analyze the C++ API

Identify from the source library:
1. Classes to wrap
2. Public methods needed
3. Data types used (primitives, strings, arrays, callbacks)
4. Memory ownership semantics
5. Exception types thrown

### Step 2: Generate Header File

See `references/header-template.md` for complete template.

Key sections:
1. Include guards and extern "C"
2. Error codes enum
3. Handle typedefs (one per class)
4. Function declarations

### Step 3: Generate Implementation

See `references/impl-template.md` for complete template.

Key patterns:
1. Cast handle to C++ pointer
2. Wrap in try-catch, convert exceptions to error codes
3. Use out parameters for return values

### Step 4: Generate Tests

Use Catch2. See `references/test-template.md`.

Test categories:
1. Create/destroy lifecycle
2. Basic operations
3. Error conditions
4. Edge cases (null handles, buffer sizes)

### Step 5: Generate CMakeLists.txt

See `references/cmake-template.md`.

Requirements:
- C++20
- Shared library output
- Catch2 for tests
- Platform detection (macOS/Linux)

## Special Cases

### Callbacks

Convert C++ callbacks to C function pointers with user data:

```c
typedef void (*OpencvCallback)(int event, void* user_data);
int opencv_set_callback(OpencvHandle h, OpencvCallback cb, void* user_data);
```

### Inheritance

Flatten hierarchy - wrap each concrete class separately, no inheritance in C API.

### Templates

Generate concrete instantiations:

```c
// For std::vector<float> and std::vector<int>
typedef struct OpencvVecFloat_s* OpencvVecFloatHandle;
typedef struct OpencvVecInt_s* OpencvVecIntHandle;
```

### Smart Pointers

Handle internally - C API always uses raw handles, implementation manages shared_ptr/unique_ptr internally.

## Error Code Convention

```c
typedef enum {
    {LIBNAME}_OK = 0,
    {LIBNAME}_ERROR_NULL_HANDLE = 1,
    {LIBNAME}_ERROR_INVALID_ARGUMENT = 2,
    {LIBNAME}_ERROR_OUT_OF_MEMORY = 3,
    {LIBNAME}_ERROR_BUFFER_TOO_SMALL = 4,
    {LIBNAME}_ERROR_NOT_FOUND = 5,
    {LIBNAME}_ERROR_IO = 6,
    {LIBNAME}_ERROR_UNKNOWN = 99
} {Libname}Error;
```

## Checklist

Before completing:
- [ ] All public classes have handles
- [ ] All handles have create/destroy pairs
- [ ] All functions return error codes (except destroy and getters returning primitives)
- [ ] No C++ types exposed in header (no std::string, std::vector, etc.)
- [ ] All exceptions caught and converted to error codes
- [ ] Header is valid C (can compile with C compiler)
- [ ] Tests cover create/destroy, basic ops, error cases
- [ ] CMake builds on both macOS and Linux
