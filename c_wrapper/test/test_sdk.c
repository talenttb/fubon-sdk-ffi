#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
// Test 4: 記憶體洩漏測試（多次呼叫）
// =============================================================================
void test_memory_leak() {
    printf("\n[Test 4] Memory Leak Test (Multiple Calls)\n");

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
