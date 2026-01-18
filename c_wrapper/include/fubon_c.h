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
// Inventory Structures
// ============================================================================

/**
 * Order type enumeration
 */
typedef enum {
    FUBON_ORDER_TYPE_STOCK = 1,
    FUBON_ORDER_TYPE_MARGIN = 2,
    FUBON_ORDER_TYPE_SHORT = 3,
    FUBON_ORDER_TYPE_SBL = 4,
    FUBON_ORDER_TYPE_DAY_TRADE = 5,
    FUBON_ORDER_TYPE_UN_SUPPORTED = 6,
    FUBON_ORDER_TYPE_UN_DEFINED = 7
} FubonOrderType;

/**
 * Odd lot inventory information
 */
typedef struct {
    int32_t lastday_qty;
    int32_t buy_qty;
    int32_t buy_filled_qty;
    int32_t buy_value;
    int32_t today_qty;
    int32_t tradable_qty;
    int32_t sell_qty;
    int32_t sell_filled_qty;
    int32_t sell_value;
} FubonInventoryOdd;

/**
 * Stock inventory information
 */
typedef struct {
    char* date;
    char* account;
    char* branch_no;
    char* stock_no;
    FubonOrderType order_type;
    int32_t lastday_qty;
    int32_t buy_qty;
    int32_t buy_filled_qty;
    int32_t buy_value;
    int32_t today_qty;
    int32_t tradable_qty;
    int32_t sell_qty;
    int32_t sell_filled_qty;
    int32_t sell_value;
    FubonInventoryOdd odd;
} FubonInventory;

/**
 * Array of inventories
 */
typedef struct {
    FubonInventory* items;
    int32_t count;
} FubonInventoryArray;

/**
 * Inventory query result
 */
typedef struct {
    bool is_success;
    char* error_message;
    FubonInventoryArray* data;
} FubonInventoryResult;

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

/**
 * Query stock inventories
 * @param sdk SDK handle
 * @param account Account to query
 * @return Inventory result, must be freed with fubon_free_inventory_result()
 */
FubonInventoryResult* fubon_inventories(FubonSDK sdk, const FubonAccount* account);

/**
 * Free inventory result and all associated memory
 * @param result Inventory result to free
 */
void fubon_free_inventory_result(FubonInventoryResult* result);

// ============================================================================
// Symbol Quote Structures (Task 4 - query_symbol_quote)
// ============================================================================

/**
 * Market type enumeration
 */
typedef enum {
    FUBON_MARKET_TYPE_COMMON = 1,
    FUBON_MARKET_TYPE_FIXING = 2,
    FUBON_MARKET_TYPE_ODD = 3,
    FUBON_MARKET_TYPE_INTRADAY_ODD = 4,
    FUBON_MARKET_TYPE_EMG = 5,
    FUBON_MARKET_TYPE_EMG_ODD = 6,
    FUBON_MARKET_TYPE_UN_SUPPORTED = 7,
    FUBON_MARKET_TYPE_UN_DEFINED = 8
} FubonMarketType;

/**
 * Symbol quote information
 * Note: optional fields use special values to indicate None:
 * - optional<double>: NAN indicates None
 * - optional<int64_t>: -1 indicates None
 * - optional<int32_t>: -1 indicates None
 */
typedef struct {
    char* market;
    char* symbol;
    bool istib_or_psb;
    FubonMarketType market_type;
    int32_t status;                    // -1 = None
    double reference_price;            // NAN = None
    int32_t unit;
    char* update_time;
    double limitup_price;              // NAN = None
    double limitdown_price;            // NAN = None
    double open_price;                 // NAN = None
    double high_price;                 // NAN = None
    double low_price;                  // NAN = None
    double last_price;                 // NAN = None
    int64_t total_volume;              // -1 = None
    int64_t total_transaction;         // -1 = None
    int64_t total_value;               // -1 = None
    int64_t last_size;                 // -1 = None
    int64_t last_transaction;          // -1 = None
    int64_t last_value;                // -1 = None
    double bid_price;                  // NAN = None
    int64_t bid_volume;                // -1 = None
    double ask_price;                  // NAN = None
    int64_t ask_volume;                // -1 = None
} FubonSymbolQuote;

/**
 * Symbol quote query result
 */
typedef struct {
    bool is_success;
    char* error_message;
    FubonSymbolQuote* data;            // NULL if no data
} FubonSymbolQuoteResult;

/**
 * Query symbol quote (individual stock price)
 * @param sdk SDK handle
 * @param account Account to query
 * @param symbol Stock symbol (e.g., "2330")
 * @param market_type Market type (pass FUBON_MARKET_TYPE_UN_DEFINED for None/default)
 * @return Symbol quote result, must be freed with fubon_free_symbol_quote_result()
 */
FubonSymbolQuoteResult* fubon_query_symbol_quote(
    FubonSDK sdk,
    const FubonAccount* account,
    const char* symbol,
    FubonMarketType market_type
);

/**
 * Free symbol quote result and all associated memory
 * @param result Symbol quote result to free
 */
void fubon_free_symbol_quote_result(FubonSymbolQuoteResult* result);

// ============================================================================
// Symbol Snapshot Structures (query_symbol_snapshot)
// ============================================================================

/**
 * Stock type enumeration
 */
typedef enum {
    FUBON_STOCK_TYPE_STOCK = 1,
    FUBON_STOCK_TYPE_COVERT_BOND = 2,
    FUBON_STOCK_TYPE_ETF_AND_ETN = 3
} FubonStockType;

/**
 * Array of symbol quotes
 */
typedef struct {
    FubonSymbolQuote* items;
    int32_t count;
} FubonSymbolQuoteArray;

/**
 * Symbol snapshot query result
 */
typedef struct {
    bool is_success;
    char* error_message;
    FubonSymbolQuoteArray* data;
} FubonSymbolSnapshotResult;

/**
 * Query symbol snapshot (market overview with multiple stocks)
 * @param sdk SDK handle
 * @param account Account to query
 * @param market_type Market type (pass FUBON_MARKET_TYPE_UN_DEFINED for None/default)
 * @param stock_types Array of stock types to filter (NULL for all)
 * @param stock_types_count Number of stock types in array (0 if NULL)
 * @return Symbol snapshot result, must be freed with fubon_free_symbol_snapshot_result()
 */
FubonSymbolSnapshotResult* fubon_query_symbol_snapshot(
    FubonSDK sdk,
    const FubonAccount* account,
    FubonMarketType market_type,
    const FubonStockType* stock_types,
    int32_t stock_types_count
);

/**
 * Free symbol snapshot result and all associated memory
 * @param result Symbol snapshot result to free
 */
void fubon_free_symbol_snapshot_result(FubonSymbolSnapshotResult* result);

#ifdef __cplusplus
}
#endif

#endif // FUBON_C_H
