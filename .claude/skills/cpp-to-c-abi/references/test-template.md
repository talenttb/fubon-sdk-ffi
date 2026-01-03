# Test Template

Template for `test_{libname}_wrapper.cpp` using Catch2:

```cpp
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "{libname}_wrapper.h"

#include <cstring>
#include <cmath>
#include <vector>

/* ============================================================================
 * Lifecycle Tests
 * ========================================================================== */

TEST_CASE("{ClassName} create and destroy", "[lifecycle]") {
    {Libname}{ClassName}Handle handle = nullptr;
    
    SECTION("create with valid params succeeds") {
        int err = {libname}_{classname}_create(42, "test", &handle);
        REQUIRE(err == {LIBNAME}_OK);
        REQUIRE(handle != nullptr);
        
        {libname}_{classname}_destroy(handle);
    }
    
    SECTION("create with null out_handle fails") {
        int err = {libname}_{classname}_create(42, "test", nullptr);
        REQUIRE(err == {LIBNAME}_ERROR_INVALID_ARGUMENT);
    }
    
    SECTION("destroy null handle is safe") {
        {libname}_{classname}_destroy(nullptr);  // Should not crash
    }
}

/* ============================================================================
 * Basic Operation Tests
 * ========================================================================== */

TEST_CASE("{ClassName} basic operations", "[operations]") {
    {Libname}{ClassName}Handle handle = nullptr;
    REQUIRE({libname}_{classname}_create(42, "test", &handle) == {LIBNAME}_OK);
    
    SECTION("get_value returns expected value") {
        int value = {libname}_{classname}_get_value(handle);
        REQUIRE(value >= 0);  // Adjust based on actual semantics
    }
    
    SECTION("compute produces result") {
        double result = 0.0;
        int err = {libname}_{classname}_compute(handle, &result);
        REQUIRE(err == {LIBNAME}_OK);
        // Add specific assertions based on expected behavior
    }
    
    {libname}_{classname}_destroy(handle);
}

/* ============================================================================
 * String Handling Tests
 * ========================================================================== */

TEST_CASE("{ClassName} string operations", "[strings]") {
    {Libname}{ClassName}Handle handle = nullptr;
    REQUIRE({libname}_{classname}_create(42, "test_name", &handle) == {LIBNAME}_OK);
    
    SECTION("get_name with sufficient buffer") {
        char buf[256];
        size_t len = 0;
        
        int err = {libname}_{classname}_get_name(handle, buf, sizeof(buf), &len);
        REQUIRE(err == {LIBNAME}_OK);
        REQUIRE(len > 0);
        REQUIRE(std::strlen(buf) == len);
    }
    
    SECTION("get_name with small buffer returns error") {
        char buf[2];
        size_t len = 0;
        
        int err = {libname}_{classname}_get_name(handle, buf, sizeof(buf), &len);
        REQUIRE(err == {LIBNAME}_ERROR_BUFFER_TOO_SMALL);
        REQUIRE(len > sizeof(buf));  // out_len tells us required size
    }
    
    SECTION("get_name with null buffer just returns length") {
        size_t len = 0;
        int err = {libname}_{classname}_get_name(handle, nullptr, 0, &len);
        REQUIRE(err == {LIBNAME}_OK);
        REQUIRE(len > 0);
    }
    
    {libname}_{classname}_destroy(handle);
}

/* ============================================================================
 * Array Handling Tests
 * ========================================================================== */

TEST_CASE("{ClassName} array operations", "[arrays]") {
    {Libname}{ClassName}Handle handle = nullptr;
    REQUIRE({libname}_{classname}_create(42, "test", &handle) == {LIBNAME}_OK);
    
    SECTION("get_data returns valid pointer") {
        const float* data = {libname}_{classname}_get_data(handle);
        size_t size = {libname}_{classname}_get_data_size(handle);
        
        if (size > 0) {
            REQUIRE(data != nullptr);
            // Can safely access data[0..size-1]
        }
    }
    
    SECTION("get_data with null handle returns null") {
        const float* data = {libname}_{classname}_get_data(nullptr);
        REQUIRE(data == nullptr);
    }
    
    SECTION("get_data_size with null handle returns 0") {
        size_t size = {libname}_{classname}_get_data_size(nullptr);
        REQUIRE(size == 0);
    }
    
    {libname}_{classname}_destroy(handle);
}

/* ============================================================================
 * Error Handling Tests
 * ========================================================================== */

TEST_CASE("Error handling", "[errors]") {
    SECTION("null handle returns appropriate error") {
        double result;
        int err = {libname}_{classname}_compute(nullptr, &result);
        REQUIRE(err == {LIBNAME}_ERROR_NULL_HANDLE);
    }
    
    SECTION("null out param returns error") {
        {Libname}{ClassName}Handle handle = nullptr;
        REQUIRE({libname}_{classname}_create(42, "test", &handle) == {LIBNAME}_OK);
        
        int err = {libname}_{classname}_compute(handle, nullptr);
        REQUIRE(err == {LIBNAME}_ERROR_INVALID_ARGUMENT);
        
        {libname}_{classname}_destroy(handle);
    }
    
    SECTION("error_string returns valid strings") {
        REQUIRE(std::strlen({libname}_error_string({LIBNAME}_OK)) > 0);
        REQUIRE(std::strlen({libname}_error_string({LIBNAME}_ERROR_NULL_HANDLE)) > 0);
        REQUIRE(std::strlen({libname}_error_string({LIBNAME}_ERROR_UNKNOWN)) > 0);
        REQUIRE(std::strlen({libname}_error_string(9999)) > 0);  // Unknown code
    }
}

/* ============================================================================
 * Callback Tests (if applicable)
 * ========================================================================== */

TEST_CASE("{ClassName} callbacks", "[callbacks]") {
    {Libname}{ClassName}Handle handle = nullptr;
    REQUIRE({libname}_{classname}_create(42, "test", &handle) == {LIBNAME}_OK);
    
    static int callback_count = 0;
    static int last_event = -1;
    
    auto test_callback = [](int event, void* user_data) {
        callback_count++;
        last_event = event;
        int* counter = static_cast<int*>(user_data);
        if (counter) (*counter)++;
    };
    
    SECTION("set callback succeeds") {
        int user_counter = 0;
        int err = {libname}_{classname}_set_callback(handle, test_callback, &user_counter);
        REQUIRE(err == {LIBNAME}_OK);
        
        // Trigger callback somehow (depends on library)
        // REQUIRE(user_counter > 0);
    }
    
    SECTION("set null callback to unregister") {
        int err = {libname}_{classname}_set_callback(handle, nullptr, nullptr);
        REQUIRE(err == {LIBNAME}_OK);
    }
    
    {libname}_{classname}_destroy(handle);
}

/* ============================================================================
 * Input/Output Verification Tests
 * ========================================================================== */

TEST_CASE("{ClassName} input/output verification", "[io]") {
    SECTION("input parameters are correctly passed to C++ layer") {
        {Libname}{ClassName}Handle handle = nullptr;
        
        // Create with specific values
        int err = {libname}_{classname}_create(123, "specific_name", &handle);
        REQUIRE(err == {LIBNAME}_OK);
        
        // Verify the values were correctly passed through
        REQUIRE({libname}_{classname}_get_value(handle) == 123);
        
        char buf[256];
        size_t len;
        {libname}_{classname}_get_name(handle, buf, sizeof(buf), &len);
        REQUIRE(std::string(buf) == "specific_name");
        
        {libname}_{classname}_destroy(handle);
    }
    
    SECTION("output parameters receive correct values") {
        {Libname}{ClassName}Handle handle = nullptr;
        REQUIRE({libname}_{classname}_create(42, "test", &handle) == {LIBNAME}_OK);
        
        // Test out parameter receives value
        double result = -999.0;  // sentinel value
        int err = {libname}_{classname}_compute(handle, &result);
        REQUIRE(err == {LIBNAME}_OK);
        REQUIRE(result != -999.0);  // Value was written
        
        // Test out_len receives correct length
        size_t len = 0;
        {libname}_{classname}_get_name(handle, nullptr, 0, &len);
        REQUIRE(len > 0);
        
        {libname}_{classname}_destroy(handle);
    }
    
    SECTION("array data matches expected content") {
        {Libname}{ClassName}Handle handle = nullptr;
        REQUIRE({libname}_{classname}_create(42, "test", &handle) == {LIBNAME}_OK);
        
        const float* data = {libname}_{classname}_get_data(handle);
        size_t size = {libname}_{classname}_get_data_size(handle);
        
        // Verify data is accessible and valid
        if (size > 0) {
            REQUIRE(data != nullptr);
            for (size_t i = 0; i < size; i++) {
                REQUIRE(std::isfinite(data[i]));  // No NaN or Inf
            }
        }
        
        {libname}_{classname}_destroy(handle);
    }
}

/* ============================================================================
 * Memory Leak Tests
 * ========================================================================== */

// Note: Run these tests with Valgrind (Linux) or Leaks (macOS) for full verification
// Linux:  valgrind --leak-check=full ./test_{libname}_wrapper
// macOS:  leaks --atExit -- ./test_{libname}_wrapper

TEST_CASE("{ClassName} memory leak prevention", "[memory]") {
    SECTION("create/destroy cycle does not leak") {
        for (int i = 0; i < 100; i++) {
            {Libname}{ClassName}Handle handle = nullptr;
            REQUIRE({libname}_{classname}_create(i, "test", &handle) == {LIBNAME}_OK);
            REQUIRE(handle != nullptr);
            {libname}_{classname}_destroy(handle);
        }
        // If this leaks, Valgrind/Leaks will report it
    }
    
    SECTION("failed create does not leak") {
        {Libname}{ClassName}Handle handle = nullptr;
        
        // Attempt create with invalid params that should fail
        // (adjust based on what actually causes failure)
        int err = {libname}_{classname}_create(-1, nullptr, &handle);
        
        if (err != {LIBNAME}_OK) {
            // On failure, handle should be nullptr, nothing to clean up
            REQUIRE(handle == nullptr);
        } else {
            // If it succeeded anyway, clean up
            {libname}_{classname}_destroy(handle);
        }
    }
    
    SECTION("multiple operations do not leak") {
        {Libname}{ClassName}Handle handle = nullptr;
        REQUIRE({libname}_{classname}_create(42, "test", &handle) == {LIBNAME}_OK);
        
        // Perform many operations
        for (int i = 0; i < 100; i++) {
            char buf[256];
            size_t len;
            {libname}_{classname}_get_name(handle, buf, sizeof(buf), &len);
            
            double result;
            {libname}_{classname}_compute(handle, &result);
            
            {libname}_{classname}_get_data(handle);
            {libname}_{classname}_get_data_size(handle);
        }
        
        {libname}_{classname}_destroy(handle);
    }
    
    SECTION("string buffer operations do not leak") {
        {Libname}{ClassName}Handle handle = nullptr;
        REQUIRE({libname}_{classname}_create(42, "test", &handle) == {LIBNAME}_OK);
        
        // Query length only
        for (int i = 0; i < 50; i++) {
            size_t len;
            {libname}_{classname}_get_name(handle, nullptr, 0, &len);
        }
        
        // Small buffer (causes BUFFER_TOO_SMALL)
        for (int i = 0; i < 50; i++) {
            char buf[2];
            size_t len;
            {libname}_{classname}_get_name(handle, buf, sizeof(buf), &len);
        }
        
        {libname}_{classname}_destroy(handle);
    }
}

/* ============================================================================
 * RAII Helper for Tests (optional)
 * ========================================================================== */

// Helper class for cleaner test code
class {ClassName}Guard {
public:
    {Libname}{ClassName}Handle handle = nullptr;
    
    {ClassName}Guard(int param1, const char* param2) {
        {libname}_{classname}_create(param1, param2, &handle);
    }
    
    ~{ClassName}Guard() {
        if (handle) {
            {libname}_{classname}_destroy(handle);
        }
    }
    
    operator {Libname}{ClassName}Handle() { return handle; }
    bool valid() const { return handle != nullptr; }
};

TEST_CASE("Using RAII guard", "[helper]") {
    {ClassName}Guard obj(42, "test");
    REQUIRE(obj.valid());
    
    int value = {libname}_{classname}_get_value(obj);
    REQUIRE(value >= 0);
    // handle automatically destroyed when obj goes out of scope
}
```

## Running Memory Checks

### Linux (Valgrind)
```bash
# Build with debug symbols
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .

# Run with Valgrind
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_{libname}_wrapper
```

### macOS (Leaks)
```bash
# Run with leaks tool
leaks --atExit -- ./test_{libname}_wrapper
```

### AddressSanitizer (Both platforms)
```bash
# Add to CMakeLists.txt or command line
cmake .. -DCMAKE_CXX_FLAGS="-fsanitize=address -fno-omit-frame-pointer" \
         -DCMAKE_EXE_LINKER_FLAGS="-fsanitize=address"
cmake --build .
./test_{libname}_wrapper
```

## Test Coverage Checklist

### Lifecycle
- [ ] Create with valid parameters
- [ ] Create with invalid parameters  
- [ ] Create with null out_handle
- [ ] Destroy valid handle
- [ ] Destroy null handle (should be no-op)

### Operations
- [ ] Each method with valid handle
- [ ] Each method with null handle
- [ ] String methods with sufficient buffer
- [ ] String methods with insufficient buffer
- [ ] String methods with null buffer (length query)
- [ ] Array methods return valid data
- [ ] Error codes are meaningful
- [ ] Callbacks register/unregister

### Input/Output Verification
- [ ] Input values correctly passed to C++ layer
- [ ] Output parameters receive correct values
- [ ] Array data is valid and accessible
- [ ] String data matches expected content

### Memory Safety
- [ ] Create/destroy cycles do not leak memory
- [ ] Failed operations do not leak memory
- [ ] Repeated operations do not accumulate leaks
- [ ] Valgrind/Leaks reports zero leaks
- [ ] AddressSanitizer finds no issues
