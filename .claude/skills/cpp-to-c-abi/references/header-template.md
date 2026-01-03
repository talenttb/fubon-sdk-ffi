# Header Template

Template for `{libname}_wrapper.h`:

```c
#ifndef {LIBNAME}_WRAPPER_H
#define {LIBNAME}_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

/* ============================================================================
 * Error Codes
 * ========================================================================== */

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

/**
 * Get human-readable error description.
 * Returns static string, do not free.
 */
const char* {libname}_error_string(int error_code);

/* ============================================================================
 * Handle Types
 * ========================================================================== */

/** Opaque handle for {ClassName} */
typedef struct {Libname}{ClassName}_s* {Libname}{ClassName}Handle;

/* ============================================================================
 * {ClassName} Functions
 * ========================================================================== */

/**
 * Create a new {ClassName} instance.
 *
 * @param param1      Description of param1
 * @param param2      Description of param2
 * @param out_handle  Output: newly created handle (caller must call destroy)
 * @return            {LIBNAME}_OK on success, error code otherwise
 */
int {libname}_{classname}_create(
    int param1,
    const char* param2,
    {Libname}{ClassName}Handle* out_handle
);

/**
 * Destroy a {ClassName} instance and free resources.
 * Safe to call with NULL handle (no-op).
 *
 * @param handle  Handle to destroy
 */
void {libname}_{classname}_destroy({Libname}{ClassName}Handle handle);

/**
 * Example method returning primitive.
 *
 * @param handle  Valid handle
 * @return        The value, or -1 if handle is NULL
 */
int {libname}_{classname}_get_value({Libname}{ClassName}Handle handle);

/**
 * Example method with out parameter.
 *
 * @param handle     Valid handle
 * @param out_value  Output: the result
 * @return           {LIBNAME}_OK on success, error code otherwise
 */
int {libname}_{classname}_compute(
    {Libname}{ClassName}Handle handle,
    double* out_value
);

/**
 * Example method returning string.
 *
 * @param handle    Valid handle
 * @param buf       Buffer to write string into
 * @param buf_size  Size of buffer
 * @param out_len   Output: actual string length (excluding null terminator)
 * @return          {LIBNAME}_OK on success,
 *                  {LIBNAME}_ERROR_BUFFER_TOO_SMALL if buffer too small
 */
int {libname}_{classname}_get_name(
    {Libname}{ClassName}Handle handle,
    char* buf,
    size_t buf_size,
    size_t* out_len
);

/**
 * Example method returning array data.
 * Returns pointer to internal data - valid until handle is modified or destroyed.
 *
 * @param handle  Valid handle
 * @return        Pointer to data, or NULL if handle is NULL
 */
const float* {libname}_{classname}_get_data({Libname}{ClassName}Handle handle);

/**
 * Get size of array returned by get_data.
 *
 * @param handle  Valid handle
 * @return        Number of elements, or 0 if handle is NULL
 */
size_t {libname}_{classname}_get_data_size({Libname}{ClassName}Handle handle);

/* ============================================================================
 * Callback Types (if needed)
 * ========================================================================== */

/**
 * Callback function type for events.
 *
 * @param event      Event code
 * @param user_data  User-provided context pointer
 */
typedef void (*{Libname}Callback)(int event, void* user_data);

/**
 * Register a callback.
 *
 * @param handle     Valid handle
 * @param callback   Callback function (NULL to unregister)
 * @param user_data  User context passed to callback
 * @return           {LIBNAME}_OK on success
 */
int {libname}_{classname}_set_callback(
    {Libname}{ClassName}Handle handle,
    {Libname}Callback callback,
    void* user_data
);

#ifdef __cplusplus
}
#endif

#endif /* {LIBNAME}_WRAPPER_H */
```

## Notes

1. Replace `{libname}`, `{LIBNAME}`, `{Libname}`, `{classname}`, `{ClassName}` with actual names
2. Add/remove functions based on actual C++ API
3. Document ownership and lifetime for all pointer returns
4. Keep error codes consistent across all functions
