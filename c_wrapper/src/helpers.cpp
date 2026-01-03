#include <cstring>
#include <cstdlib>
#include <string>
#include <optional>

// ============================================================================
// String Conversion Helpers
// ============================================================================

/**
 * Duplicate a C++ std::string to C string
 * Caller must free the returned pointer
 */
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

/**
 * Duplicate an optional std::string to C string
 * Returns nullptr if optional has no value
 * Caller must free the returned pointer if not nullptr
 */
static char* strdup_from_optional(const std::optional<std::string>& opt) {
    return opt.has_value() ? strdup_from_cpp(opt.value()) : nullptr;
}

/**
 * Convert C string to C++ std::string
 * Returns empty string if input is nullptr
 */
static std::string cpp_string_from_c(const char* str) {
    return str ? std::string(str) : std::string();
}

/**
 * Convert C string to optional std::string
 * Returns nullopt if input is nullptr
 */
static std::optional<std::string> optional_string_from_c(const char* str) {
    return str ? std::optional<std::string>(str) : std::nullopt;
}
