#ifndef FUBON_C_H
#define FUBON_C_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// Opaque SDK Handle
// ============================================================================
typedef void* FubonSDK;

// ============================================================================
// Account Structures
// ============================================================================
typedef struct {
    char* name;
    char* branch_no;
    char* account;
    char* account_type;
} FubonAccount;

typedef struct {
    FubonAccount* items;
    int32_t count;
} FubonAccountArray;

// ============================================================================
// Login Result
// ============================================================================
typedef struct {
    bool is_success;
    char* error_message;
    FubonAccountArray* accounts;
} FubonLoginResult;

// ============================================================================
// BankRemain Structures (Task 2)
// ============================================================================
typedef struct {
    char* branch_no;
    char* account;
    char* currency;
    int64_t balance;
    int64_t available_balance;
} FubonBankRemain;

typedef struct {
    bool is_success;
    char* error_message;
    FubonBankRemain* data;
} FubonBankRemainResult;

// ============================================================================
// SDK Lifecycle Functions
// ============================================================================

/**
 * Create a new Fubon SDK instance with default configuration
 * @return SDK handle, must be freed with fubon_sdk_free()
 */
FubonSDK fubon_sdk_new(void);

/**
 * Create a new Fubon SDK instance with custom configuration
 * @param pong_interval WebSocket pong interval in milliseconds
 * @param missed_count Maximum missed pong count before reconnection
 * @param url Custom WebSocket URL (NULL for default)
 * @return SDK handle, must be freed with fubon_sdk_free()
 */
FubonSDK fubon_sdk_new_with_config(uint64_t pong_interval, int64_t missed_count, const char* url);

/**
 * Free SDK instance and all associated resources
 * @param sdk SDK handle to free
 */
void fubon_sdk_free(FubonSDK sdk);

// ============================================================================
// Authentication Functions
// ============================================================================

/**
 * Login to Fubon securities account
 * @param sdk SDK handle
 * @param personal_id Personal ID (身份證字號)
 * @param password Password
 * @param cert_path Path to certificate file (.pfx)
 * @param cert_pass Certificate password
 * @return Login result with account array, must be freed with fubon_free_login_result()
 */
FubonLoginResult* fubon_login(
    FubonSDK sdk,
    const char* personal_id,
    const char* password,
    const char* cert_path,
    const char* cert_pass
);

/**
 * Login to Fubon securities account (DMA mode)
 * @param sdk SDK handle
 * @param personal_id Personal ID
 * @param password Password
 * @return Login result with account array, must be freed with fubon_free_login_result()
 */
FubonLoginResult* fubon_dma_login(
    FubonSDK sdk,
    const char* personal_id,
    const char* password
);

/**
 * Free login result and all associated memory
 * @param result Login result to free
 */
void fubon_free_login_result(FubonLoginResult* result);

// ============================================================================
// Accounting Functions (Task 2)
// ============================================================================

/**
 * Query bank account balance
 * @param sdk SDK handle
 * @param account Account to query
 * @return Bank balance result, must be freed with fubon_free_bank_remain_result()
 */
FubonBankRemainResult* fubon_bank_remain(FubonSDK sdk, const FubonAccount* account);

/**
 * Free bank remain result and all associated memory
 * @param result Bank remain result to free
 */
void fubon_free_bank_remain_result(FubonBankRemainResult* result);

#ifdef __cplusplus
}
#endif

#endif // FUBON_C_H
