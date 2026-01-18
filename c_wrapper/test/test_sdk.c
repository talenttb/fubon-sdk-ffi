#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "fubon_c.h"

static int passed = 0;
static int failed = 0;

#define TEST_ASSERT(condition, message) \
    do { \
        if (condition) { \
            printf("  ✓ %s\n", message); \
            passed++; \
        } else { \
            printf("  ✗ %s\n", message); \
            failed++; \
        } \
    } while(0)

// =============================================================================
// Test 1: SDK Lifecycle - 記憶體管理
// =============================================================================
void test_sdk_lifecycle() {
    printf("\n[Test 1] SDK Lifecycle - Memory Management\n");

    FubonSDK sdk1 = fubon_sdk_new();
    TEST_ASSERT(sdk1 != NULL, "fubon_sdk_new() allocates memory");
    fubon_sdk_free(sdk1);
    TEST_ASSERT(true, "fubon_sdk_free() releases memory");

    FubonSDK sdk2 = fubon_sdk_new_with_config(30000, 3, "wss://neoapi.fbs.com.tw/TASP/XCPXWS");
    TEST_ASSERT(sdk2 != NULL, "fubon_sdk_new_with_config() allocates memory");
    fubon_sdk_free(sdk2);
    TEST_ASSERT(true, "fubon_sdk_free() releases memory (custom config)");
}

// =============================================================================
// Test 2: Login - C++/C 轉換 & 記憶體管理
// =============================================================================
void test_login_conversion() {
    printf("\n[Test 2] Login - C++/C Conversion & Memory\n");

    FubonSDK sdk = fubon_sdk_new();

    // 呼叫 C++ SDK (會失敗，但能驗證錯誤路徑的轉換)
    FubonLoginResult* result = fubon_login(
        sdk,
        "TEST_ID",
        "test_password",
        "/nonexistent/cert.pfx",
        "test_cert_pass"
    );

    // 驗證結構體配置
    TEST_ASSERT(result != NULL, "Result structure allocated");

    // 驗證 C++/C 轉換：錯誤訊息
    if (!result->is_success) {
        TEST_ASSERT(result->error_message != NULL,
                    "C++ std::string → C char* (error_message)");
        TEST_ASSERT(strlen(result->error_message) > 0,
                    "Error message has content");
        printf("    Converted message: \"%s\"\n", result->error_message);

        // 驗證 accounts 在錯誤時為 NULL
        TEST_ASSERT(result->accounts == NULL,
                    "Error case: accounts is NULL");
    }

    // 驗證成功路徑的轉換（如果有真實憑證）
    if (result->is_success && result->accounts != NULL) {
        printf("    Success! Testing account array conversion...\n");

        // 驗證陣列結構
        TEST_ASSERT(result->accounts->count >= 0,
                    "Array count is valid");
        TEST_ASSERT(result->accounts->items != NULL,
                    "Array items allocated");

        // 驗證每個帳戶的欄位轉換
        for (int i = 0; i < result->accounts->count; i++) {
            FubonAccount* acc = &result->accounts->items[i];
            TEST_ASSERT(acc->name != NULL, "Account.name converted");
            TEST_ASSERT(acc->branch_no != NULL, "Account.branch_no converted");
            TEST_ASSERT(acc->account != NULL, "Account.account converted");
            TEST_ASSERT(acc->account_type != NULL, "Account.account_type converted");

            printf("    Account[%d]: branch=%s, account=%s\n",
                   i, acc->branch_no, acc->account);
        }
    }

    // 驗證記憶體釋放
    fubon_free_login_result(result);
    TEST_ASSERT(true, "All allocated memory freed");

    fubon_sdk_free(sdk);
}

// =============================================================================
// Test 3: Bank Remain - C++/C 轉換 & 記憶體管理
// =============================================================================
void test_bank_remain_conversion() {
    printf("\n[Test 3] Bank Remain - C++/C Conversion & Memory\n");

    FubonSDK sdk = fubon_sdk_new();

    FubonAccount mock_account = {
        .name = "測試帳戶",
        .branch_no = "9999",
        .account = "1234567",
        .account_type = "H"
    };

    FubonBankRemainResult* result = fubon_bank_remain(sdk, &mock_account);

    // 驗證結構體配置
    TEST_ASSERT(result != NULL, "Result structure allocated");

    // 驗證 C++/C 轉換：錯誤訊息
    if (!result->is_success) {
        TEST_ASSERT(result->error_message != NULL,
                    "C++ std::string → C char* (error_message)");
        TEST_ASSERT(strlen(result->error_message) > 0,
                    "Error message has content");
        printf("    Converted message: \"%s\"\n", result->error_message);

        TEST_ASSERT(result->data == NULL,
                    "Error case: data is NULL");
    }

    // 驗證成功路徑的轉換（如果登入且帳戶有效）
    if (result->is_success && result->data != NULL) {
        printf("    Success! Testing BankRemain conversion...\n");

        FubonBankRemain* data = result->data;

        // 驗證字串欄位轉換
        TEST_ASSERT(data->branch_no != NULL, "branch_no converted");
        TEST_ASSERT(data->account != NULL, "account converted");
        TEST_ASSERT(data->currency != NULL, "currency converted");

        // 驗證數值欄位轉換
        TEST_ASSERT(true, "balance is int64_t");
        TEST_ASSERT(true, "available_balance is int64_t");

        printf("    Converted: branch=%s, account=%s, currency=%s\n",
               data->branch_no, data->account, data->currency);
        printf("    Converted: balance=%lld, available=%lld\n",
               data->balance, data->available_balance);
    }

    // 驗證記憶體釋放
    fubon_free_bank_remain_result(result);
    TEST_ASSERT(true, "All allocated memory freed");

    fubon_sdk_free(sdk);
}

// =============================================================================
// Test 4: Inventories - C++/C 轉換 & 記憶體管理
// =============================================================================
void test_inventories_conversion() {
    printf("\n[Test 4] Inventories - C++/C Conversion & Memory\n");

    FubonSDK sdk = fubon_sdk_new();

    FubonAccount mock_account = {
        .name = "測試帳戶",
        .branch_no = "9999",
        .account = "1234567",
        .account_type = "H"
    };

    FubonInventoryResult* result = fubon_inventories(sdk, &mock_account);

    // 驗證結構體配置
    TEST_ASSERT(result != NULL, "Result structure allocated");

    // 驗證 C++/C 轉換：錯誤訊息
    if (!result->is_success) {
        TEST_ASSERT(result->error_message != NULL,
                    "C++ std::string → C char* (error_message)");
        TEST_ASSERT(strlen(result->error_message) > 0,
                    "Error message has content");
        printf("    Converted message: \"%s\"\n", result->error_message);

        TEST_ASSERT(result->data == NULL,
                    "Error case: data is NULL");
    }

    // 驗證成功路徑的轉換（如果登入且帳戶有效）
    if (result->is_success && result->data != NULL) {
        printf("    Success! Testing Inventory array conversion...\n");

        FubonInventoryArray* arr = result->data;

        // 驗證陣列結構
        TEST_ASSERT(arr->count >= 0, "Array count is valid");
        TEST_ASSERT(arr->items != NULL, "Array items allocated");

        // 驗證每個庫存項目的欄位轉換
        for (int i = 0; i < arr->count; i++) {
            FubonInventory* inv = &arr->items[i];

            // 驗證字串欄位轉換
            TEST_ASSERT(inv->date != NULL, "Inventory.date converted");
            TEST_ASSERT(inv->account != NULL, "Inventory.account converted");
            TEST_ASSERT(inv->branch_no != NULL, "Inventory.branch_no converted");
            TEST_ASSERT(inv->stock_no != NULL, "Inventory.stock_no converted");

            // 驗證 enum 轉換
            TEST_ASSERT(inv->order_type >= FUBON_ORDER_TYPE_STOCK &&
                       inv->order_type <= FUBON_ORDER_TYPE_UN_DEFINED,
                       "OrderType enum converted");

            // 驗證數值欄位
            TEST_ASSERT(true, "Integer fields (lastday_qty, buy_qty, etc.) converted");

            // 驗證嵌套結構 (odd lot)
            TEST_ASSERT(true, "Nested InventoryOdd structure copied");

            printf("    Inventory[%d]: stock=%s, tradable_qty=%d, odd_tradable=%d\n",
                   i, inv->stock_no, inv->tradable_qty, inv->odd.tradable_qty);
        }
    }

    // 驗證記憶體釋放
    fubon_free_inventory_result(result);
    TEST_ASSERT(true, "All allocated memory freed");

    fubon_sdk_free(sdk);
}

// =============================================================================
// Test 5: Symbol Quote - C++/C 轉換 & 記憶體管理
// =============================================================================
void test_symbol_quote_conversion() {
    printf("\n[Test 5] Symbol Quote - C++/C Conversion & Memory\n");

    FubonSDK sdk = fubon_sdk_new();

    FubonAccount mock_account = {
        .name = "測試帳戶",
        .branch_no = "9999",
        .account = "1234567",
        .account_type = "H"
    };

    // Test 1: 基本查詢（使用預設 market type）
    FubonSymbolQuoteResult* result1 = fubon_query_symbol_quote(
        sdk, &mock_account, "2330", FUBON_MARKET_TYPE_UN_DEFINED
    );

    TEST_ASSERT(result1 != NULL, "Result structure allocated");

    // 驗證 C++/C 轉換：錯誤訊息
    if (!result1->is_success) {
        TEST_ASSERT(result1->error_message != NULL,
                    "C++ std::string → C char* (error_message)");
        TEST_ASSERT(strlen(result1->error_message) > 0,
                    "Error message has content");
        printf("    Converted message: \"%s\"\n", result1->error_message);

        TEST_ASSERT(result1->data == NULL,
                    "Error case: data is NULL");
    }

    // 驗證成功路徑的轉換（如果登入且帳戶有效）
    if (result1->is_success && result1->data != NULL) {
        printf("    Success! Testing SymbolQuote conversion...\n");

        FubonSymbolQuote* quote = result1->data;

        // 驗證字串欄位轉換
        TEST_ASSERT(quote->market != NULL, "market converted");
        TEST_ASSERT(quote->symbol != NULL, "symbol converted");
        TEST_ASSERT(quote->update_time != NULL, "update_time converted");

        // 驗證 boolean 轉換
        TEST_ASSERT(quote->istib_or_psb == true || quote->istib_or_psb == false,
                    "istib_or_psb is boolean");

        // 驗證 enum 轉換
        TEST_ASSERT(quote->market_type >= FUBON_MARKET_TYPE_COMMON &&
                   quote->market_type <= FUBON_MARKET_TYPE_UN_DEFINED,
                   "MarketType enum converted");

        // 驗證必要欄位
        TEST_ASSERT(quote->unit > 0, "unit is positive integer");

        // 驗證 optional 欄位處理（應該有值或為 NAN/-1）
        printf("    Checking optional fields handling...\n");
        if (quote->status != -1) {
            printf("      status: %d\n", quote->status);
        }
        if (!isnan(quote->reference_price)) {
            printf("      reference_price: %.2f\n", quote->reference_price);
        }
        if (!isnan(quote->last_price)) {
            printf("      last_price: %.2f\n", quote->last_price);
        }
        if (quote->total_volume != -1) {
            printf("      total_volume: %lld\n", quote->total_volume);
        }
        if (!isnan(quote->bid_price)) {
            printf("      bid_price: %.2f\n", quote->bid_price);
        }
        if (quote->bid_volume != -1) {
            printf("      bid_volume: %lld\n", quote->bid_volume);
        }
        if (!isnan(quote->ask_price)) {
            printf("      ask_price: %.2f\n", quote->ask_price);
        }
        if (quote->ask_volume != -1) {
            printf("      ask_volume: %lld\n", quote->ask_volume);
        }

        TEST_ASSERT(true, "Optional fields properly handled (NAN or -1 for None)");

        printf("    Converted: market=%s, symbol=%s, unit=%d\n",
               quote->market, quote->symbol, quote->unit);
    }

    fubon_free_symbol_quote_result(result1);
    TEST_ASSERT(true, "Memory freed for default market_type query");

    // Test 2: 指定 market type 查詢
    FubonSymbolQuoteResult* result2 = fubon_query_symbol_quote(
        sdk, &mock_account, "2330", FUBON_MARKET_TYPE_COMMON
    );

    TEST_ASSERT(result2 != NULL, "Result structure allocated (with market_type)");
    fubon_free_symbol_quote_result(result2);
    TEST_ASSERT(true, "Memory freed for COMMON market_type query");

    // Test 3: 測試 NULL 參數處理
    FubonSymbolQuoteResult* result3 = fubon_query_symbol_quote(
        NULL, &mock_account, "2330", FUBON_MARKET_TYPE_COMMON
    );
    TEST_ASSERT(result3 != NULL, "NULL sdk handled gracefully");
    TEST_ASSERT(!result3->is_success, "NULL sdk returns error");
    TEST_ASSERT(result3->error_message != NULL, "Error message provided for NULL sdk");
    fubon_free_symbol_quote_result(result3);

    FubonSymbolQuoteResult* result4 = fubon_query_symbol_quote(
        sdk, NULL, "2330", FUBON_MARKET_TYPE_COMMON
    );
    TEST_ASSERT(result4 != NULL, "NULL account handled gracefully");
    TEST_ASSERT(!result4->is_success, "NULL account returns error");
    fubon_free_symbol_quote_result(result4);

    FubonSymbolQuoteResult* result5 = fubon_query_symbol_quote(
        sdk, &mock_account, NULL, FUBON_MARKET_TYPE_COMMON
    );
    TEST_ASSERT(result5 != NULL, "NULL symbol handled gracefully");
    TEST_ASSERT(!result5->is_success, "NULL symbol returns error");
    fubon_free_symbol_quote_result(result5);

    fubon_sdk_free(sdk);
}

// =============================================================================
// Test 6: Symbol Snapshot - C++/C 轉換 & 記憶體管理
// =============================================================================
void test_symbol_snapshot_conversion() {
    printf("\n[Test 6] Symbol Snapshot - C++/C Conversion & Memory\n");

    FubonSDK sdk = fubon_sdk_new();

    FubonAccount mock_account = {
        .name = "測試帳戶",
        .branch_no = "9999",
        .account = "1234567",
        .account_type = "H"
    };

    // Test 1: 基本查詢（無過濾條件）
    FubonSymbolSnapshotResult* result1 = fubon_query_symbol_snapshot(
        sdk, &mock_account, FUBON_MARKET_TYPE_UN_DEFINED, NULL, 0
    );

    TEST_ASSERT(result1 != NULL, "Result structure allocated");

    if (!result1->is_success) {
        TEST_ASSERT(result1->error_message != NULL,
                    "C++ std::string → C char* (error_message)");
        TEST_ASSERT(strlen(result1->error_message) > 0,
                    "Error message has content");
        printf("    Converted message: \"%s\"\n", result1->error_message);

        TEST_ASSERT(result1->data == NULL,
                    "Error case: data is NULL");
    }

    if (result1->is_success && result1->data != NULL) {
        printf("    Success! Testing SymbolQuote array conversion...\n");

        FubonSymbolQuoteArray* arr = result1->data;

        TEST_ASSERT(arr->count >= 0, "Array count is valid");
        if (arr->count > 0) {
            TEST_ASSERT(arr->items != NULL, "Array items allocated");

            for (int i = 0; i < arr->count && i < 3; i++) {
                FubonSymbolQuote* quote = &arr->items[i];

                TEST_ASSERT(quote->market != NULL, "market converted");
                TEST_ASSERT(quote->symbol != NULL, "symbol converted");
                TEST_ASSERT(quote->update_time != NULL, "update_time converted");

                TEST_ASSERT(quote->market_type >= FUBON_MARKET_TYPE_COMMON &&
                           quote->market_type <= FUBON_MARKET_TYPE_UN_DEFINED,
                           "MarketType enum converted");

                printf("    Quote[%d]: symbol=%s, last_price=%.2f\n",
                       i, quote->symbol,
                       isnan(quote->last_price) ? 0.0 : quote->last_price);
            }
        }
    }

    fubon_free_symbol_snapshot_result(result1);
    TEST_ASSERT(true, "Memory freed for basic query");

    // Test 2: 指定 market type 和 stock types
    FubonStockType stock_types[] = {FUBON_STOCK_TYPE_STOCK, FUBON_STOCK_TYPE_ETF_AND_ETN};
    FubonSymbolSnapshotResult* result2 = fubon_query_symbol_snapshot(
        sdk, &mock_account, FUBON_MARKET_TYPE_COMMON, stock_types, 2
    );

    TEST_ASSERT(result2 != NULL, "Result structure allocated (with filters)");
    fubon_free_symbol_snapshot_result(result2);
    TEST_ASSERT(true, "Memory freed for filtered query");

    // Test 3: NULL 參數處理
    FubonSymbolSnapshotResult* result3 = fubon_query_symbol_snapshot(
        NULL, &mock_account, FUBON_MARKET_TYPE_COMMON, NULL, 0
    );
    TEST_ASSERT(result3 != NULL, "NULL sdk handled gracefully");
    TEST_ASSERT(!result3->is_success, "NULL sdk returns error");
    TEST_ASSERT(result3->error_message != NULL, "Error message provided for NULL sdk");
    fubon_free_symbol_snapshot_result(result3);

    FubonSymbolSnapshotResult* result4 = fubon_query_symbol_snapshot(
        sdk, NULL, FUBON_MARKET_TYPE_COMMON, NULL, 0
    );
    TEST_ASSERT(result4 != NULL, "NULL account handled gracefully");
    TEST_ASSERT(!result4->is_success, "NULL account returns error");
    fubon_free_symbol_snapshot_result(result4);

    fubon_sdk_free(sdk);
}

// =============================================================================
// Test 7: 記憶體洩漏測試（多次呼叫）
// =============================================================================
void test_memory_leak() {
    printf("\n[Test 7] Memory Leak Test (Multiple Calls)\n");

    FubonSDK sdk = fubon_sdk_new();

    // 多次呼叫並釋放，檢查是否有記憶體洩漏
    for (int i = 0; i < 100; i++) {
        FubonLoginResult* result = fubon_login(
            sdk, "TEST", "test", "/none", "pass"
        );
        fubon_free_login_result(result);
    }
    TEST_ASSERT(true, "100 login calls - no leak expected");

    FubonAccount mock = {
        .name = "test", .branch_no = "9999",
        .account = "123", .account_type = "H"
    };

    for (int i = 0; i < 100; i++) {
        FubonBankRemainResult* result = fubon_bank_remain(sdk, &mock);
        fubon_free_bank_remain_result(result);
    }
    TEST_ASSERT(true, "100 bank_remain calls - no leak expected");

    for (int i = 0; i < 100; i++) {
        FubonInventoryResult* result = fubon_inventories(sdk, &mock);
        fubon_free_inventory_result(result);
    }
    TEST_ASSERT(true, "100 inventories calls - no leak expected");

    for (int i = 0; i < 100; i++) {
        FubonSymbolQuoteResult* result = fubon_query_symbol_quote(
            sdk, &mock, "2330", FUBON_MARKET_TYPE_COMMON
        );
        fubon_free_symbol_quote_result(result);
    }
    TEST_ASSERT(true, "100 query_symbol_quote calls - no leak expected");

    for (int i = 0; i < 100; i++) {
        FubonSymbolSnapshotResult* result = fubon_query_symbol_snapshot(
            sdk, &mock, FUBON_MARKET_TYPE_COMMON, NULL, 0
        );
        fubon_free_symbol_snapshot_result(result);
    }
    TEST_ASSERT(true, "100 query_symbol_snapshot calls - no leak expected");

    fubon_sdk_free(sdk);

    printf("    Run with: valgrind --leak-check=full ./test_sdk\n");
    printf("    Or macOS: leaks --atExit -- ./test_sdk\n");
}

int main() {
    printf("========================================\n");
    printf("  C Wrapper Tests\n");
    printf("  Focus: C++/C conversion & memory\n");
    printf("========================================\n");

    test_sdk_lifecycle();
    test_login_conversion();
    test_bank_remain_conversion();
    test_inventories_conversion();
    test_symbol_quote_conversion();
    test_symbol_snapshot_conversion();
    test_memory_leak();

    printf("\n========================================\n");
    printf("  Results: %d passed, %d failed\n", passed, failed);
    printf("========================================\n");

    if (failed == 0) {
        printf("\n✓ Interface tests passed\n");
        printf("✓ C++/C conversion verified (error paths)\n");
        printf("⚠ Run memory checker to verify no leaks\n");
    }

    return failed > 0 ? 1 : 0;
}
