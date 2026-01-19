#include "fubon_c.h"
#include "sdk.hpp"
#include <memory>
#include <stdexcept>
#include <cstring>
#include <cstdlib>

// Include helper functions
#include "helpers.cpp"

// ============================================================================
// SDK Lifecycle Implementation
// ============================================================================

FubonSDK fubon_sdk_new(void) {
    try {
        auto* sdk = new fubon::FubonSDK();
        return static_cast<void*>(sdk);
    } catch (const std::exception& e) {
        // Log error or handle as needed
        return nullptr;
    }
}

FubonSDK fubon_sdk_new_with_config(uint64_t pong_interval, int64_t missed_count, const char* url) {
    try {
        std::string url_str = url ? std::string(url) : "wss://neoapi.fbs.com.tw/TASP/XCPXWS";
        auto* sdk = new fubon::FubonSDK(
            std::optional<uint64_t>(pong_interval),
            std::optional<int64_t>(missed_count),
            url_str
        );
        return static_cast<void*>(sdk);
    } catch (const std::exception& e) {
        return nullptr;
    }
}

void fubon_sdk_free(FubonSDK sdk) {
    if (sdk) {
        auto* cpp_sdk = static_cast<fubon::FubonSDK*>(sdk);
        delete cpp_sdk;
    }
}

// ============================================================================
// Authentication Implementation
// ============================================================================

FubonLoginResult* fubon_login(
    FubonSDK sdk,
    const char* personal_id,
    const char* password,
    const char* cert_path,
    const char* cert_pass
) {
    auto* result = new FubonLoginResult();

    if (!sdk || !personal_id || !password || !cert_path) {
        result->is_success = false;
        result->error_message = strdup_from_cpp("Invalid parameters: SDK, personal_id, password, and cert_path are required");
        result->accounts = nullptr;
        return result;
    }

    try {
        auto* cpp_sdk = static_cast<fubon::FubonSDK*>(sdk);

        // Call C++ SDK login
        fubon::LoginResponse response = cpp_sdk->login(
            std::string(personal_id),
            std::string(password),
            std::string(cert_path),
            cert_pass ? std::string(cert_pass) : ""
        );

        result->is_success = response.is_success;

        // Handle error message
        if (response.message.has_value()) {
            result->error_message = strdup_from_cpp(response.message.value());
        } else {
            result->error_message = nullptr;
        }

        // Handle account data
        if (response.is_success && response.data.has_value()) {
            auto& accounts_vec = response.data.value();

            // Allocate account array
            auto* account_array = new FubonAccountArray();
            account_array->count = static_cast<int32_t>(accounts_vec.size());
            account_array->items = (FubonAccount*)malloc(sizeof(FubonAccount) * accounts_vec.size());

            // Convert each account
            for (size_t i = 0; i < accounts_vec.size(); i++) {
                account_array->items[i].name = strdup_from_cpp(accounts_vec[i].name);
                account_array->items[i].branch_no = strdup_from_cpp(accounts_vec[i].branch_no);
                account_array->items[i].account = strdup_from_cpp(accounts_vec[i].account);
                account_array->items[i].account_type = strdup_from_cpp(accounts_vec[i].account_type);
            }

            result->accounts = account_array;
        } else {
            result->accounts = nullptr;
        }

    } catch (const std::exception& e) {
        result->is_success = false;
        result->error_message = strdup_from_cpp(std::string("Exception: ") + e.what());
        result->accounts = nullptr;
    }

    return result;
}

FubonLoginResult* fubon_dma_login(
    FubonSDK sdk,
    const char* personal_id,
    const char* password
) {
    auto* result = new FubonLoginResult();

    if (!sdk || !personal_id || !password) {
        result->is_success = false;
        result->error_message = strdup_from_cpp("Invalid parameters: SDK, personal_id, and password are required");
        result->accounts = nullptr;
        return result;
    }

    try {
        auto* cpp_sdk = static_cast<fubon::FubonSDK*>(sdk);

        // Call C++ SDK DMA login
        fubon::LoginResponse response = cpp_sdk->dma_login(
            std::string(personal_id),
            std::string(password)
        );

        result->is_success = response.is_success;

        // Handle error message
        if (response.message.has_value()) {
            result->error_message = strdup_from_cpp(response.message.value());
        } else {
            result->error_message = nullptr;
        }

        // Handle account data
        if (response.is_success && response.data.has_value()) {
            auto& accounts_vec = response.data.value();

            // Allocate account array
            auto* account_array = new FubonAccountArray();
            account_array->count = static_cast<int32_t>(accounts_vec.size());
            account_array->items = (FubonAccount*)malloc(sizeof(FubonAccount) * accounts_vec.size());

            // Convert each account
            for (size_t i = 0; i < accounts_vec.size(); i++) {
                account_array->items[i].name = strdup_from_cpp(accounts_vec[i].name);
                account_array->items[i].branch_no = strdup_from_cpp(accounts_vec[i].branch_no);
                account_array->items[i].account = strdup_from_cpp(accounts_vec[i].account);
                account_array->items[i].account_type = strdup_from_cpp(accounts_vec[i].account_type);
            }

            result->accounts = account_array;
        } else {
            result->accounts = nullptr;
        }

    } catch (const std::exception& e) {
        result->is_success = false;
        result->error_message = strdup_from_cpp(std::string("Exception: ") + e.what());
        result->accounts = nullptr;
    }

    return result;
}

void fubon_free_login_result(FubonLoginResult* result) {
    if (!result) return;

    // Free error message
    if (result->error_message) {
        free(result->error_message);
    }

    // Free accounts array
    if (result->accounts) {
        if (result->accounts->items) {
            for (int32_t i = 0; i < result->accounts->count; i++) {
                free(result->accounts->items[i].name);
                free(result->accounts->items[i].branch_no);
                free(result->accounts->items[i].account);
                free(result->accounts->items[i].account_type);
            }
            free(result->accounts->items);
        }
        delete result->accounts;
    }

    // Free result structure
    delete result;
}

// ============================================================================
// Accounting Functions (Task 2: bank_remain)
// ============================================================================

FubonBankRemainResult* fubon_bank_remain(FubonSDK sdk, const FubonAccount* account) {
    auto* result = new FubonBankRemainResult();

    if (!sdk || !account) {
        result->is_success = false;
        result->error_message = strdup_from_cpp("Invalid parameters: SDK and account are required");
        result->data = nullptr;
        return result;
    }

    try {
        auto* cpp_sdk = static_cast<fubon::FubonSDK*>(sdk);

        // Convert C account to C++ account
        fubon::Account cpp_account;
        cpp_account.name = account->name ? std::string(account->name) : "";
        cpp_account.branch_no = account->branch_no ? std::string(account->branch_no) : "";
        cpp_account.account = account->account ? std::string(account->account) : "";
        cpp_account.account_type = account->account_type ? std::string(account->account_type) : "";

        // Call C++ SDK bank_remain
        fubon::BankRemainResponse response = cpp_sdk->accounting->bank_remain(cpp_account);

        result->is_success = response.is_success;

        // Handle error message
        if (response.message.has_value()) {
            result->error_message = strdup_from_cpp(response.message.value());
        } else {
            result->error_message = nullptr;
        }

        // Handle bank remain data
        if (response.is_success && response.data.has_value()) {
            auto& bank_data = response.data.value();

            // Allocate bank remain structure
            auto* bank_remain = new FubonBankRemain();
            bank_remain->branch_no = strdup_from_cpp(bank_data.branch_no);
            bank_remain->account = strdup_from_cpp(bank_data.account);
            bank_remain->currency = strdup_from_cpp(bank_data.currency);
            bank_remain->balance = bank_data.balance;
            bank_remain->available_balance = bank_data.available_balance;

            result->data = bank_remain;
        } else {
            result->data = nullptr;
        }

    } catch (const std::exception& e) {
        result->is_success = false;
        result->error_message = strdup_from_cpp(std::string("Exception: ") + e.what());
        result->data = nullptr;
    }

    return result;
}

void fubon_free_bank_remain_result(FubonBankRemainResult* result) {
    if (!result) return;

    // Free error message
    if (result->error_message) {
        free(result->error_message);
    }

    // Free bank remain data
    if (result->data) {
        free(result->data->branch_no);
        free(result->data->account);
        free(result->data->currency);
        delete result->data;
    }

    // Free result structure
    delete result;
}

// ============================================================================
// Accounting Functions: inventories
// ============================================================================

FubonInventoryResult* fubon_inventories(FubonSDK sdk, const FubonAccount* account) {
    auto* result = new FubonInventoryResult();

    if (!sdk || !account) {
        result->is_success = false;
        result->error_message = strdup_from_cpp("Invalid parameters: SDK and account are required");
        result->data = nullptr;
        return result;
    }

    try {
        auto* cpp_sdk = static_cast<fubon::FubonSDK*>(sdk);

        // Convert C account to C++ account
        fubon::Account cpp_account;
        cpp_account.name = account->name ? std::string(account->name) : "";
        cpp_account.branch_no = account->branch_no ? std::string(account->branch_no) : "";
        cpp_account.account = account->account ? std::string(account->account) : "";
        cpp_account.account_type = account->account_type ? std::string(account->account_type) : "";

        // Call C++ SDK inventories
        fubon::InventoryResponse response = cpp_sdk->accounting->inventories(cpp_account);

        result->is_success = response.is_success;

        // Handle error message
        if (response.message.has_value()) {
            result->error_message = strdup_from_cpp(response.message.value());
        } else {
            result->error_message = nullptr;
        }

        // Handle inventory data
        if (response.is_success && response.data.has_value()) {
            auto& inventories_vec = response.data.value();

            // Allocate inventory array
            auto* inventory_array = new FubonInventoryArray();
            inventory_array->count = static_cast<int32_t>(inventories_vec.size());
            inventory_array->items = (FubonInventory*)malloc(sizeof(FubonInventory) * inventories_vec.size());

            // Convert each inventory
            for (size_t i = 0; i < inventories_vec.size(); i++) {
                auto& inv = inventories_vec[i];

                inventory_array->items[i].date = strdup_from_cpp(inv.date);
                inventory_array->items[i].account = strdup_from_cpp(inv.account);
                inventory_array->items[i].branch_no = strdup_from_cpp(inv.branch_no);
                inventory_array->items[i].stock_no = strdup_from_cpp(inv.stock_no);

                // Convert OrderType enum
                inventory_array->items[i].order_type = static_cast<FubonOrderType>(static_cast<int32_t>(inv.order_type));

                // Copy quantities and values
                inventory_array->items[i].lastday_qty = inv.lastday_qty;
                inventory_array->items[i].buy_qty = inv.buy_qty;
                inventory_array->items[i].buy_filled_qty = inv.buy_filled_qty;
                inventory_array->items[i].buy_value = inv.buy_value;
                inventory_array->items[i].today_qty = inv.today_qty;
                inventory_array->items[i].tradable_qty = inv.tradable_qty;
                inventory_array->items[i].sell_qty = inv.sell_qty;
                inventory_array->items[i].sell_filled_qty = inv.sell_filled_qty;
                inventory_array->items[i].sell_value = inv.sell_value;

                // Copy odd lot data
                inventory_array->items[i].odd.lastday_qty = inv.odd.lastday_qty;
                inventory_array->items[i].odd.buy_qty = inv.odd.buy_qty;
                inventory_array->items[i].odd.buy_filled_qty = inv.odd.buy_filled_qty;
                inventory_array->items[i].odd.buy_value = inv.odd.buy_value;
                inventory_array->items[i].odd.today_qty = inv.odd.today_qty;
                inventory_array->items[i].odd.tradable_qty = inv.odd.tradable_qty;
                inventory_array->items[i].odd.sell_qty = inv.odd.sell_qty;
                inventory_array->items[i].odd.sell_filled_qty = inv.odd.sell_filled_qty;
                inventory_array->items[i].odd.sell_value = inv.odd.sell_value;
            }

            result->data = inventory_array;
        } else {
            result->data = nullptr;
        }

    } catch (const std::exception& e) {
        result->is_success = false;
        result->error_message = strdup_from_cpp(std::string("Exception: ") + e.what());
        result->data = nullptr;
    }

    return result;
}

void fubon_free_inventory_result(FubonInventoryResult* result) {
    if (!result) return;

    // Free error message
    if (result->error_message) {
        free(result->error_message);
    }

    // Free inventory data
    if (result->data) {
        if (result->data->items) {
            for (int32_t i = 0; i < result->data->count; i++) {
                free(result->data->items[i].date);
                free(result->data->items[i].account);
                free(result->data->items[i].branch_no);
                free(result->data->items[i].stock_no);
                // Note: odd struct is embedded, no need to free
            }
            free(result->data->items);
        }
        delete result->data;
    }

    // Free result structure
    delete result;
}

// ============================================================================
// Symbol Quote Implementation (Task 4 - query_symbol_quote)
// ============================================================================

// Helper function to convert FubonMarketType to C++ MarketType
static fubon::MarketType convert_market_type(FubonMarketType mt) {
    switch (mt) {
        case FUBON_MARKET_TYPE_COMMON:
            return fubon::MarketType::COMMON;
        case FUBON_MARKET_TYPE_FIXING:
            return fubon::MarketType::FIXING;
        case FUBON_MARKET_TYPE_ODD:
            return fubon::MarketType::ODD;
        case FUBON_MARKET_TYPE_INTRADAY_ODD:
            return fubon::MarketType::INTRADAY_ODD;
        case FUBON_MARKET_TYPE_EMG:
            return fubon::MarketType::EMG;
        case FUBON_MARKET_TYPE_EMG_ODD:
            return fubon::MarketType::EMG_ODD;
        case FUBON_MARKET_TYPE_UN_SUPPORTED:
            return fubon::MarketType::UN_SUPPORTED;
        case FUBON_MARKET_TYPE_UN_DEFINED:
        default:
            return fubon::MarketType::UN_DEFINED;
    }
}

// Helper function to convert C++ MarketType to FubonMarketType
static FubonMarketType convert_to_c_market_type(fubon::MarketType mt) {
    switch (mt) {
        case fubon::MarketType::COMMON:
            return FUBON_MARKET_TYPE_COMMON;
        case fubon::MarketType::FIXING:
            return FUBON_MARKET_TYPE_FIXING;
        case fubon::MarketType::ODD:
            return FUBON_MARKET_TYPE_ODD;
        case fubon::MarketType::INTRADAY_ODD:
            return FUBON_MARKET_TYPE_INTRADAY_ODD;
        case fubon::MarketType::EMG:
            return FUBON_MARKET_TYPE_EMG;
        case fubon::MarketType::EMG_ODD:
            return FUBON_MARKET_TYPE_EMG_ODD;
        case fubon::MarketType::UN_SUPPORTED:
            return FUBON_MARKET_TYPE_UN_SUPPORTED;
        case fubon::MarketType::UN_DEFINED:
        default:
            return FUBON_MARKET_TYPE_UN_DEFINED;
    }
}

FubonSymbolQuoteResult* fubon_query_symbol_quote(
    FubonSDK sdk,
    const FubonAccount* account,
    const char* symbol,
    FubonMarketType market_type
) {
    auto* result = new FubonSymbolQuoteResult();

    if (!sdk || !account || !symbol) {
        result->is_success = false;
        result->error_message = strdup_from_cpp("Invalid parameters: SDK, account, and symbol are required");
        result->data = nullptr;
        return result;
    }

    try {
        auto* cpp_sdk = static_cast<fubon::FubonSDK*>(sdk);

        // Convert C account to C++ Account
        fubon::Account cpp_account;
        cpp_account.name = account->name ? std::string(account->name) : "";
        cpp_account.branch_no = std::string(account->branch_no);
        cpp_account.account = std::string(account->account);
        cpp_account.account_type = account->account_type ? std::string(account->account_type) : "";

        // Convert market_type to optional
        std::optional<fubon::MarketType> cpp_market_type;
        if (market_type != FUBON_MARKET_TYPE_UN_DEFINED) {
            cpp_market_type = convert_market_type(market_type);
        }

        // Call C++ SDK query_symbol_quote
        fubon::SymbolQuoteResponse response = cpp_sdk->stock->query_symbol_quote(
            cpp_account,
            std::string(symbol),
            cpp_market_type
        );

        result->is_success = response.is_success;

        // Handle error message
        if (response.message.has_value()) {
            result->error_message = strdup_from_cpp(response.message.value());
        } else {
            result->error_message = nullptr;
        }

        // Handle quote data
        if (response.is_success && response.data.has_value()) {
            auto& quote = response.data.value();

            // Allocate SymbolQuote structure
            auto* c_quote = new FubonSymbolQuote();

            // Convert required fields
            c_quote->market = strdup_from_cpp(quote.market);
            c_quote->symbol = strdup_from_cpp(quote.symbol);
            c_quote->istib_or_psb = quote.istib_or_psb;
            c_quote->market_type = convert_to_c_market_type(quote.market_type);
            c_quote->unit = quote.unit;
            c_quote->update_time = strdup_from_cpp(quote.update_time);

            // Convert optional fields (use -1 or NAN for None)
            c_quote->status = quote.status.value_or(-1);
            c_quote->reference_price = quote.reference_price.value_or(NAN);
            c_quote->limitup_price = quote.limitup_price.value_or(NAN);
            c_quote->limitdown_price = quote.limitdown_price.value_or(NAN);
            c_quote->open_price = quote.open_price.value_or(NAN);
            c_quote->high_price = quote.high_price.value_or(NAN);
            c_quote->low_price = quote.low_price.value_or(NAN);
            c_quote->last_price = quote.last_price.value_or(NAN);
            c_quote->total_volume = quote.total_volume.value_or(-1);
            c_quote->total_transaction = quote.total_transaction.value_or(-1);
            c_quote->total_value = quote.total_value.value_or(-1);
            c_quote->last_size = quote.last_size.value_or(-1);
            c_quote->last_transaction = quote.last_transaction.value_or(-1);
            c_quote->last_value = quote.last_value.value_or(-1);
            c_quote->bid_price = quote.bid_price.value_or(NAN);
            c_quote->bid_volume = quote.bid_volume.value_or(-1);
            c_quote->ask_price = quote.ask_price.value_or(NAN);
            c_quote->ask_volume = quote.ask_volume.value_or(-1);

            result->data = c_quote;
        } else {
            result->data = nullptr;
        }

    } catch (const std::exception& e) {
        result->is_success = false;
        result->error_message = strdup_from_cpp(std::string("Exception: ") + e.what());
        result->data = nullptr;
    }

    return result;
}

void fubon_free_symbol_quote_result(FubonSymbolQuoteResult* result) {
    if (!result) return;

    // Free error message
    if (result->error_message) {
        free(result->error_message);
    }

    // Free data
    if (result->data) {
        if (result->data->market) free(result->data->market);
        if (result->data->symbol) free(result->data->symbol);
        if (result->data->update_time) free(result->data->update_time);
        delete result->data;
    }

    // Free result structure
    delete result;
}

// ============================================================================
// Symbol Snapshot Implementation (query_symbol_snapshot)
// ============================================================================

static fubon::StockType convert_stock_type(FubonStockType st) {
    switch (st) {
        case FUBON_STOCK_TYPE_STOCK:
            return fubon::StockType::STOCK;
        case FUBON_STOCK_TYPE_COVERT_BOND:
            return fubon::StockType::COVERT_BOND;
        case FUBON_STOCK_TYPE_ETF_AND_ETN:
            return fubon::StockType::ETF_AND_ETN;
        default:
            return fubon::StockType::STOCK;
    }
}

static void fill_symbol_quote(FubonSymbolQuote* c_quote, const fubon::SymbolQuote& quote) {
    c_quote->market = strdup_from_cpp(quote.market);
    c_quote->symbol = strdup_from_cpp(quote.symbol);
    c_quote->istib_or_psb = quote.istib_or_psb;
    c_quote->market_type = convert_to_c_market_type(quote.market_type);
    c_quote->unit = quote.unit;
    c_quote->update_time = strdup_from_cpp(quote.update_time);

    c_quote->status = quote.status.value_or(-1);
    c_quote->reference_price = quote.reference_price.value_or(NAN);
    c_quote->limitup_price = quote.limitup_price.value_or(NAN);
    c_quote->limitdown_price = quote.limitdown_price.value_or(NAN);
    c_quote->open_price = quote.open_price.value_or(NAN);
    c_quote->high_price = quote.high_price.value_or(NAN);
    c_quote->low_price = quote.low_price.value_or(NAN);
    c_quote->last_price = quote.last_price.value_or(NAN);
    c_quote->total_volume = quote.total_volume.value_or(-1);
    c_quote->total_transaction = quote.total_transaction.value_or(-1);
    c_quote->total_value = quote.total_value.value_or(-1);
    c_quote->last_size = quote.last_size.value_or(-1);
    c_quote->last_transaction = quote.last_transaction.value_or(-1);
    c_quote->last_value = quote.last_value.value_or(-1);
    c_quote->bid_price = quote.bid_price.value_or(NAN);
    c_quote->bid_volume = quote.bid_volume.value_or(-1);
    c_quote->ask_price = quote.ask_price.value_or(NAN);
    c_quote->ask_volume = quote.ask_volume.value_or(-1);
}

FubonSymbolSnapshotResult* fubon_query_symbol_snapshot(
    FubonSDK sdk,
    const FubonAccount* account,
    FubonMarketType market_type,
    const FubonStockType* stock_types,
    int32_t stock_types_count
) {
    auto* result = new FubonSymbolSnapshotResult();

    if (!sdk || !account) {
        result->is_success = false;
        result->error_message = strdup_from_cpp("Invalid parameters: SDK and account are required");
        result->data = nullptr;
        return result;
    }

    try {
        auto* cpp_sdk = static_cast<fubon::FubonSDK*>(sdk);

        fubon::Account cpp_account;
        cpp_account.name = account->name ? std::string(account->name) : "";
        cpp_account.branch_no = std::string(account->branch_no);
        cpp_account.account = std::string(account->account);
        cpp_account.account_type = account->account_type ? std::string(account->account_type) : "";

        std::optional<fubon::MarketType> cpp_market_type;
        if (market_type != FUBON_MARKET_TYPE_UN_DEFINED) {
            cpp_market_type = convert_market_type(market_type);
        }

        std::optional<std::vector<fubon::StockType>> cpp_stock_types;
        if (stock_types && stock_types_count > 0) {
            std::vector<fubon::StockType> types;
            for (int32_t i = 0; i < stock_types_count; i++) {
                types.push_back(convert_stock_type(stock_types[i]));
            }
            cpp_stock_types = types;
        }

        fubon::VecSymbolQuoteResponse response = cpp_sdk->stock->query_symbol_snapshot(
            cpp_account,
            cpp_market_type,
            cpp_stock_types
        );

        result->is_success = response.is_success;

        if (response.message.has_value()) {
            result->error_message = strdup_from_cpp(response.message.value());
        } else {
            result->error_message = nullptr;
        }

        if (response.is_success && response.data.has_value()) {
            auto& quotes_vec = response.data.value();

            auto* quote_array = new FubonSymbolQuoteArray();
            quote_array->count = static_cast<int32_t>(quotes_vec.size());
            quote_array->items = (FubonSymbolQuote*)malloc(sizeof(FubonSymbolQuote) * quotes_vec.size());

            for (size_t i = 0; i < quotes_vec.size(); i++) {
                fill_symbol_quote(&quote_array->items[i], quotes_vec[i]);
            }

            result->data = quote_array;
        } else {
            result->data = nullptr;
        }

    } catch (const std::exception& e) {
        result->is_success = false;
        result->error_message = strdup_from_cpp(std::string("Exception: ") + e.what());
        result->data = nullptr;
    }

    return result;
}

void fubon_free_symbol_snapshot_result(FubonSymbolSnapshotResult* result) {
    if (!result) return;

    if (result->error_message) {
        free(result->error_message);
    }

    if (result->data) {
        if (result->data->items) {
            for (int32_t i = 0; i < result->data->count; i++) {
                if (result->data->items[i].market) free(result->data->items[i].market);
                if (result->data->items[i].symbol) free(result->data->items[i].symbol);
                if (result->data->items[i].update_time) free(result->data->items[i].update_time);
            }
            free(result->data->items);
        }
        delete result->data;
    }

    delete result;
}

// ============================================================================
// Realtime Token & REST URL Implementation
// ============================================================================

FubonRealtimeTokenResult* fubon_exchange_realtime_token(FubonSDK sdk) {
    auto* result = new FubonRealtimeTokenResult();

    if (!sdk) {
        result->is_success = false;
        result->error_message = strdup_from_cpp("Invalid parameters: SDK is required");
        result->token = nullptr;
        return result;
    }

    try {
        auto* cpp_sdk = static_cast<fubon::FubonSDK*>(sdk);
        std::string token = cpp_sdk->exchange_realtime_token();
        result->is_success = true;
        result->token = strdup_from_cpp(token);
        result->error_message = nullptr;
    } catch (const std::exception& e) {
        result->is_success = false;
        result->token = nullptr;
        result->error_message = strdup_from_cpp(std::string("Exception: ") + e.what());
    }

    return result;
}

void fubon_free_realtime_token_result(FubonRealtimeTokenResult* result) {
    if (!result) return;

    if (result->error_message) {
        free(result->error_message);
    }

    if (result->token) {
        free(result->token);
    }

    delete result;
}

char* fubon_realtime_rest_url(void) {
    try {
        auto realtime = fubon::FugleRealtime::init();
        std::string url = realtime->realtime_rest_url();
        return strdup_from_cpp(url);
    } catch (const std::exception& e) {
        return nullptr;
    }
}

void fubon_free_string(char* str) {
    if (str) {
        free(str);
    }
}
