#pragma once

#include <algorithm>
#include <bit>
#include <cstdint>
#include <exception>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <streambuf>
#include <type_traits>
#include <variant>
#include <vector>

#include "fubon_scaffolding.hpp"

namespace fubon {
struct Accounting;
struct FubonCore;
struct FugleRealtime;
struct FutOptAccounting;
struct FutOptFunctions;
struct StockFunctions;
struct Account;
struct AccountRes;
struct BankRemain;
struct BankRemainResponse;
struct BatchResponse;
struct BatchResult;
struct CancelResult;
struct CloseRecord;
struct Condition;
struct ConditionDayTrade;
struct ConditionDetail;
struct ConditionDetailResult;
struct ConditionOrder;
struct ConditionOrderResult;
struct ConditionOrderResultResponse;
struct ConditionResult;
struct DayTradeStockInfo;
struct DayTradeStockInfoResponse;
struct Equity;
struct EstimateMargin;
struct EstimateMarginResponse;
struct FilledData;
struct FilledResponse;
struct FutOptConditionOrder;
struct FutOptFilledData;
struct FutOptModifyLot;
struct FutOptModifyPrice;
struct FutOptOrder;
struct FutOptOrderDetail;
struct FutOptOrderResponse;
struct FutOptOrderResult;
struct FutOptTPSLOrder;
struct FutOptTPSLWrapper;
struct FutOptTrailOrder;
struct HybridPosition;
struct Inventory;
struct InventoryOdd;
struct InventoryResponse;
struct LoginResponse;
struct MaintenanceData;
struct MaintenanceDetail;
struct MaintenanceResponse;
struct MaintenanceSummary;
struct MarginShortQuota;
struct MarginShortQuotaResponse;
struct ModifyPrice;
struct ModifyQuantity;
struct Order;
struct OrderDetail;
struct OrderResponse;
struct OrderResult;
struct ParentChildRecord;
struct Position;
struct Realized;
struct RealizedResponse;
struct RealizedSummary;
struct RealizedSummaryResponse;
struct Recover;
struct Reply;
struct SdkRef;
struct Settlement;
struct SettlementData;
struct SettlementResponse;
struct SplitDescription;
struct SpreadPosition;
struct StringResponse;
struct SymbolQuote;
struct SymbolQuoteResponse;
struct TPSLOrder;
struct TPSLWrapper;
struct TrailOrder;
struct UnRealizedResponse;
struct Unrealized;
struct VecCloseRecordResponse;
struct VecConditionDetailResponse;
struct VecEquityResponse;
struct VecFutOptFilledResponse;
struct VecFutOptHybridPositionResponse;
struct VecFutOptOrderResponse;
struct VecFutOptPositionResponse;
struct VecOrderResponse;
struct VecRecoverResponse;
struct VecSymbolQuoteResponse;
enum class BSAction;
enum class CallPut;
enum class ConditionMarketType;
enum class ConditionOrderType;
enum class ConditionPriceType;
enum class ConditionStatus;
enum class Direction;
struct FubonError;
enum class FutOptConditionMarketType;
enum class FutOptConditionOrderType;
enum class FutOptConditionPriceType;
enum class FutOptMarketType;
enum class FutOptOrderType;
enum class FutOptPriceType;
enum class HistoryStatus;
enum class MarketType;
enum class Operator;
enum class OrderType;
enum class PriceType;
enum class StockType;
enum class StopSign;
enum class TimeInForce;
enum class TimeSliceOrderType;
enum class TradingType;
enum class TriggerContent;
struct Callback;

namespace uniffi {
    struct FfiConverterFutOptFunctions;
} // namespace uniffi

struct FutOptFunctions {
    friend uniffi::FfiConverterFutOptFunctions;

    FutOptFunctions() = delete;

    FutOptFunctions(const FutOptFunctions &) = delete;
    FutOptFunctions(FutOptFunctions &&) = delete;

    FutOptFunctions &operator=(const FutOptFunctions &) = delete;
    FutOptFunctions &operator=(FutOptFunctions &&) = delete;

    ~FutOptFunctions();
    /**
     * Batch cancel active order <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * target_order ( FutOptOrderResult list ) : Order list to be cancel <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * <br/>
     * A list contains one or more modified order information <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data =[ <br/>
     *         FutOptOrderResult { <br/>
     *             functionType = 30, <br/>
     *             date = 2024/03/25, <br/>
     *             seqNo = 00110212609, <br/>
     *             branchNo = 15901, <br/>
     *             account = 1234567, <br/>
     *             orderNo = C0002, <br/>
     *             assetType = 1, <br/>
     *             ... <br/>
     *         }, <br/>
     *         FutOptOrderResult { <br/>
     *             functionType = 30, <br/>
     *             date = 2024/03/25, <br/>
     *             seqNo = 00110212609, <br/>
     *             branchNo = 15901, <br/>
     *             account = 1234567, <br/>
     *             orderNo = C0002, <br/>
     *             assetType = 1, <br/>
     *             ... <br/>
     *         } <br/>
     *     ] <br/>
     * } <br/>
     */
    VecFutOptOrderResponse batch_cancel_order(const Account &account, const std::vector<FutOptOrderResult> &orders);
    /**
     * Batch modify order lot <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * FutOptModifyLot ( list of object ) : Object list for lot adjustment <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * <br/>
     * A list contains one or more modified order information <br/>
     * <br/>
     * For Example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data =[ <br/>
     *         FutOptOrderResult{ <br/>
     *             function_type = 15, <br/>
     *             date = 2024/03/25, <br/>
     *             seqNo = 00110212664, <br/>
     *             ... <br/>
     *         }, <br/>
     * } <br/>
     */
    VecFutOptOrderResponse batch_modify_lot(const Account &account, const std::vector<FutOptModifyLot> &orders);
    /**
     * Batch Modify order price <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * FutOptModifyPrice ( list of object ) : Object list for price <br/>
     * adjustment <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * A list contains one or more modified order information <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data =[///         FutOptOrderResult{ <br/> <br/>
     *             function_type = 15, <br/>
     *             date = 2024/03/25, <br/>
     *             seq_no = 00110212664, <br/>
     *             branch_no = 15901, <br/>
     *             account = 1234567, <br/>
     *             order_no = C0006, <br/>
     *             asset_type = 1, <br/>
     *             market = TAIMEX, <br/>
     *             market_type = Future, <br/>
     *             ... <br/>
     *         } <br/>
     *     ] <br/>
     * } <br/>
     */
    VecFutOptOrderResponse batch_modify_price(const Account &account, const std::vector<FutOptModifyPrice> &orders);
    /**
     * Check execution status of batch list <br/>
     * <br/>
     * Args <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * Batch order list ( BatchResult ) : Query batch result <br/>
     * <br/>
     * Return <br/>
     * <br/>
     * A list contains one or more BatchResult objects <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = [ FutOptOrderResult{ <br/>
     *         functionType = , <br/>
     *         date = 2024/03/25, <br/>
     *         seqNo = 00110222608, <br/>
     *         branchNo = 15901, <br/>
     *         account = 1234567, <br/>
     *         orderNo = C0101, <br/>
     *         assetType = 1, <br/>
     *         market = TAIMEX, <br/>
     *         ... <br/>
     *     }, <br/>
     *     ... <br/>
     *     ] <br/>
     * } <br/>
     */
    VecFutOptOrderResponse batch_order_detail(const Account &account, const BatchResult &batch);
    /**
     * Get batch order record list <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * A list contains one or more BatchResult objects <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = [ <br/>
     *         BatchResult{ <br/>
     *             functionType = 0, <br/>
     *             date = 2023/10/04, <br/>
     *             branchNo = 6460, <br/>
     *             account = 26, <br/>
     *             batchSeqNo = 11EE626533D072228000000C29304663 <br/>
     *         }, <br/>
     *         ... <br/>
     *     ] <br/>
     * } <br/>
     */
    BatchResponse batch_order_lists(const Account &account);
    /**
     * Send in a new batch order <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * orderObject ( OrderObject list ) : The order list content <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * <br/>
     * A list contains one or more order result objects <br/>
     * <br/>
     * Usage function example: <br/>
     * Can define order like this <br/>
     * <br/>
     * var orders = new FutOptOrder[]{ <br/>
     *     new FutOptOrder( <br/>
     *         BSAction.Buy, <br/>
     *         "TXO20000E4", <br/>
     *         "530", <br/>
     *         1, <br/>
     *         FutOptMarketType.Option, <br/>
     *         FutOptPriceType.Limit, <br/>
     *         TimeInForce.Rod, <br/>
     *         FutOptOrderType.Auto, <br/>
     *         "From csharp" // optional field <br/>
     *     ), new FutOptOrder( <br/>
     *         BSAction.Buy, <br/>
     *         "TXO20000E4", <br/>
     *         "530", <br/>
     *         1, <br/>
     *         FutOptMarketType.Option, <br/>
     *         FutOptPriceType.Limit, <br/>
     *         TimeInForce.Rod, <br/>
     *         FutOptOrderType.Auto, <br/>
     *         "From csharp" // optional field <br/>
     *     ) <br/>
     * }; <br/>
     * <br/>
     * sdk.Futopt.BatchPlaceOrder(account,orders.ToList()); <br/>
     * <br/>
     */
    VecFutOptOrderResponse batch_place_order(const Account &account, const std::vector<FutOptOrder> &orders);
    StringResponse cancel_condition_orders(const Account &account, const std::string &guid, std::optional<FutOptConditionMarketType> market_type);
    /**
     * Cancel an active order <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * target_order ( FutOptOrderResult ) : Order to be deleted <br/>
     * <br/>
     * unblock ( bool ) ( optional ) : Using unblock mode ; default : False <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * An object contains modified order information <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = FutOptOrderResult { <br/>
     *         functionType = 30, <br/>
     *         date = 2024/03/25, <br/>
     *         seqNo = 00110212608, <br/>
     *         branchNo = 15901, <br/>
     *         account = 1234567, <br/>
     *         orderNo = C0001, <br/>
     *         assetType = 1, <br/>
     *         market = TAIMEX, <br/>
     *         marketType = Future, <br/>
     *         ... <br/>
     *     } <br/>
     * } <br/>
     */
    FutOptOrderResponse cancel_order(const Account &account, const FutOptOrderResult &order_res, std::optional<bool> unblock);
    /**
     * Convert symbol to order or subscribe marketdata <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * symbol ( string ) : Symbol from accounting return <br/>
     * <br/>
     * expiryDate ( string ) : Symbol's expiry date <br/>
     * <br/>
     * strikePrice ( float ) : Symbol's strike price ( only option) <br/>
     * <br/>
     * callPut ( float ) : Symbol's call / put ( only option) <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * Order Symbol in string <br/>
     */
    std::string convert_symbol(const std::string &stock_symbol, const std::string &expiry_date, std::optional<double> strike_price, std::optional<CallPut> call_put);
    /**
     * Retrieve filled data in the record <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Query specify account <br/>
     * <br/>
     * marketType ( FutOptMarketType ) : Query record market type <br/>
     * <br/>
     * startDate ( string ) : Query record start date <br/>
     * <br/>
     * endDate ( string ) ( optional ) : Query record end date ( if empty will <br/>
     * fill in today automatically) <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * A list contains one or more filled data objects <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = [ <br/>
     *         FutOptFilledData{ <br/>
     *             date = 2023/09/15, <br/>
     *             branchNo = 6460, <br/>
     *             account = 26, <br/>
     *             orderNo = bA422, <br/>
     *             seqNo = , <br/>
     *             symbol = FITX, <br/>
     *             expiryDate = 202404, <br/>
     *             strikePrice = , <br/>
     *             callPut = , <br/>
     *             buySell = Buy, <br/>
     *             symbolLeg2 = , <br/>
     *             expiryDateLeg2 = , <br/>
     *             strikePriceLeg2 = , <br/>
     *             callPutLeg2 = , <br/>
     *             buySellLeg2 = , <br/>
     *             filledNo = 00000000001, <br/>
     *             filledAvgPrice = 20890.0, <br/>
     *             filledLots = 1, <br/>
     *             filledPrice = 20890.0, <br/>
     *             orderType = New, <br/>
     *             filledTime = 10:31:00.931, <br/>
     *             userDef = <br/>
     *         }, <br/>
     *         ... <br/>
     *     ] <br/>
     * } <br/>
     */
    VecFutOptFilledResponse filled_history(const Account &account, const FutOptMarketType &market_type, const std::string &start_date, std::optional<std::string> end_date);
    VecConditionDetailResponse get_condition_history(const Account &account, const std::string &start_date, const std::string &end_date, std::optional<FutOptConditionMarketType> market_type, std::optional<HistoryStatus> history_type);
    VecConditionDetailResponse get_condition_order(const Account &account, std::optional<FutOptConditionMarketType> market_type, std::optional<ConditionStatus> condition_status);
    VecConditionDetailResponse get_condition_order_by_id(const Account &account, const std::string &guid, std::optional<FutOptConditionMarketType> market_type);
    /**
     * Get today's all orders; active, canceled, or filled. <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : The account want to query <br/>
     * <br/>
     * marketType ( FutOptMarketType ) : The market type want to query <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * A list contains one or more result objects <br/>
     * <br/>
     * For Example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = FutOptOrderResult { <br/>
     *         functionType = 0, <br/>
     *         date = 2024/03/25, <br/>
     *         seqNo = 00230177010, <br/>
     *         branchNo = 15901, <br/>
     *         account = 1234567, <br/>
     *         orderNo = C0002, <br/>
     *         assetType = 2, <br/>
     *         ... <br/>
     *     } <br/>
     * } <br/>
     */
    VecFutOptOrderResponse get_order_results(const Account &account, std::optional<FutOptMarketType> market_type);
    /**
     * Get today’s all orders; active, canceled, or filled (include order process). <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : The account want to query <br/>
     * <br/>
     * marketType ( FutOptMarketType ) : The market type want to query <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * A list contains one or more result objects <br/>
     * <br/>
     * For Example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = FutOptOrderResult { <br/>
     *         functionType = 0, <br/>
     *         date = 2024/03/25, <br/>
     *         seqNo = 00230177010, <br/>
     *         branchNo = 15901, <br/>
     *         account = 1234567, <br/>
     *         orderNo = C0002, <br/>
     *         assetType = 2, <br/>
     *         ... <br/>
     *     } <br/>
     * } <br/>
     */
    VecFutOptOrderResponse get_order_results_detail(const Account &account, std::optional<FutOptMarketType> market_type);
    VecConditionDetailResponse get_time_slice_order(const Account &account, const std::string &batch_no, std::optional<FutOptConditionMarketType> market_type);
    VecConditionDetailResponse get_trail_history(const Account &account, const std::string &start_date, const std::string &end_date, std::optional<FutOptConditionMarketType> market_type);
    VecConditionDetailResponse get_trail_order(const Account &account, std::optional<FutOptConditionMarketType> market_type);
    /**
     * Set lot change for order <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * target_order ( FutOptOrderResult ) : Order for lot adjustment <br/>
     * <br/>
     * lot ( int ) : Modify lot <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * An object contains the order are prepared modify lot <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * 1. Using GetOrderResults retrieve FutOptOrderResult <br/>
     * <br/>
     * 2. Designate order to modify <br/>
     * <br/>
     * order_res = <br/>
     * sdk.FutOpt.GetOrderResults(accounts.data[0,FutOptMarketType.FutureNight) <br/>
     * <br/>
     * target_order = order_res.data[0] <br/>
     * <br/>
     * modifyLot_obj = sdk.FutOpt.MakeModifyLotObj(target_order, 2) <br/>
     * <br/>
     */
    FutOptModifyLot make_modify_lot_obj(const FutOptOrderResult &order, int64_t lot);
    /**
     * Set price change for order <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * targetOrder ( FutOptOrderResult ) : Order to be modified <br/>
     * <br/>
     * price ( string ) ( optional ) : Modify price ( If the 'priceType' <br/>
     * field is entered, this field should be None or empty) <br/>
     * <br/>
     * priceType ( FutOptPriceType ) ( optional ) : Modify price type ( If <br/>
     * the 'price' field is entered, this field should be None or empty ) <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * An object contains the order are prepared modify price <br/>
     * <br/>
     * For Example: <br/>
     * <br/>
     * 1. Using GetOrderResult retrieve FutOptOrderResult <br/>
     * <br/>
     * 2. Designate order to modify <br/>
     * <br/>
     * order_res = sdk.FutOpt.GetOrderResults(accounts.data[0]) <br/>
     * <br/>
     * target_order = order_res.data[0] <br/>
     * <br/>
     * modifyPrice_obj = sdk.FutOpt.MakeModifyPriceObj(target_order, "500") <br/>
     */
    FutOptModifyPrice make_modify_price_obj(const FutOptOrderResult &order, std::optional<std::string> price, std::optional<FutOptPriceType> price_type);
    /**
     * Modify order lot <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * FutOptModifyLot ( object ) : Object for lot adjustment <br/>
     * <br/>
     * unblock ( bool ) ( optional ) : Using unblock mode ; default : False <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * <br/>
     * An object contains modified order information <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = FutOptOrderResult{ <br/>
     *         functionType = 20, <br/>
     *         date = 2024/03/25, <br/>
     *         seqNo = 03100161319, <br/>
     *         branchNo = 15901, <br/>
     *         account = 1234567, <br/>
     *         orderNo = l001D, <br/>
     *         assetType = 1, <br/>
     *         ... <br/>
     *     } <br/>
     * } <br/>
     */
    FutOptOrderResponse modify_lot(const Account &account, const FutOptModifyLot &modify_obj, std::optional<bool> unblock);
    /**
     * Modify order price <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * FutOptModifyPrice ( object ) : Object for price adjustment <br/>
     * <br/>
     * unblock ( bool ) ( optional ) : Using unblock mode ; default : False <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * An object contains modified order information <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = FutOptOrderResult { <br/>
     *         functionType = 15, <br/>
     *         date = 2024/03/25, <br/>
     *         seqNo = 00110212663, <br/>
     *         branchNo = 15901, <br/>
     *         account = 1234567, <br/>
     *         orderNo = C0005, <br/>
     *         ... <br/>
     *     } <br/>
     * } <br/>
     */
    FutOptOrderResponse modify_price(const Account &account, const FutOptModifyPrice &modify_obj, std::optional<bool> unblock);
    ConditionOrderResultResponse multi_condition(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const std::vector<Condition> &conditions, const FutOptConditionOrder &order, std::optional<FutOptTPSLWrapper> child_info);
    /**
     * Retrieve order in the record <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * startDate ( string ) : Query record start date <br/>
     * <br/>
     * endDate ( string ) : Query record end date ( if empty will <br/>
     * fill in today automatically) <br/>
     * <br/>
     * marketType ( FutOptMarketType ) ( optional ) : Query record market type <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * A list contains one or more result objects <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = [ <br/>
     *         FutOptOrderResult{ <br/>
     *             functionType = , <br/>
     *             date = 2024/04/11, <br/>
     *             seqNo = 00230177314, <br/>
     *             branchNo = 15000, <br/>
     *             account = 9974825, <br/>
     *             orderNo = C0020, <br/>
     *             ... <br/>
     *         }, <br/>
     *         FutOptOrderResult{ <br/>
     *             functionType = , <br/>
     *             date = 2024/04/11, <br/>
     *             seqNo = 00230177314, <br/>
     *             branchNo = 15000, <br/>
     *             account = 9974825, <br/>
     *             orderNo = C0020, <br/>
     *             ... <br/>
     *         } <br/>
     *     ] <br/>
     * } <br/>
     */
    VecFutOptOrderResponse order_history(const Account &account, const std::string &start_date, const std::string &end_date, std::optional<FutOptMarketType> market_type);
    /**
     * Send in a new order <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * order ( OrderObject ) : The order content <br/>
     * unblock ( bool ) ( optional ) : Using unblock mode ; default : False <br/>
     * <br/>
     * Return: <br/>
     * An object contains order information. ( if using unblock mode, the <br/>
     * order result may not contain whole information.) <br/>
     * <br/>
     * Usage function example <br/>
     * <br/>
     * Can define order like this <br/>
     * <br/>
     * order = FutOptOrder( <br/>
     *     BSAction.Buy, <br/>
     *     "TXO20000E4", <br/>
     *     null, <br/>
     *     null, <br/>
     *     "500", <br/>
     *     1, <br/>
     *     FutOptMarketType.Option, <br/>
     *     FutOptPriceType.Limit, <br/>
     *     TimeInForce.Rod, <br/>
     *     FutOptOrderType.Auto, <br/>
     *     "From csharp" <br/>
     * ) <br/>
     * <br/>
     * sdk.FutOpt.PlaceOrder(account, order) <br/>
     */
    FutOptOrderResponse place_order(const Account &account, const FutOptOrder &order, std::optional<bool> unblock);
    /**
     * Query symbol require margin <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Query specify account <br/>
     * <br/>
     * orderObject ( OrderObject ) : Query record market type <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * A object contains estimate margin data <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = EstimateMargin{ <br/>
     *         date = 2024/04/10, <br/>
     *         currency = TWD, <br/>
     *         estimateMargin = 179000 <br/>
     *     } <br/>
     * } <br/>
     */
    EstimateMarginResponse query_estimate_margin(const Account &account, const FutOptOrder &order);
    ConditionOrderResultResponse single_condition(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const Condition &condition, const FutOptConditionOrder &order, std::optional<FutOptTPSLWrapper> child_info);
    ConditionOrderResultResponse time_slice_order(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const SplitDescription &split_description, const FutOptConditionOrder &order);
    ConditionOrderResultResponse trail_profit(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const FutOptTrailOrder &trail_order);

private:
    FutOptFunctions(void *);

    void *instance;
};


enum class TimeSliceOrderType: int32_t {
    TYPE1 = 1,
    TYPE2 = 2,
    TYPE3 = 3,
    TYPE4 = 4,
    TYPE5 = 5,
    TYPE6 = 6,
    TYPE7 = 7
};


enum class ConditionOrderType: int32_t {
    STOCK = 1,
    MARGIN = 2,
    SHORT = 3,
    DAY_TRADE = 4
};


enum class FutOptConditionMarketType: int32_t {
    FUTURE = 1,
    OPTION = 2,
    FUTURE_NIGHT = 3,
    OPTION_NIGHT = 4
};


enum class FutOptOrderType: int32_t {
    NEW = 1,
    CLOSE = 2,
    AUTO = 3,
    FDAY_TRADE = 4,
    UN_SUPPORTED = 5,
    UN_DEFINED = 6
};


struct OrderDetail {
    std::optional<int32_t> function_type;
    std::string modified_time;
    std::optional<int64_t> before_qty;
    std::optional<int64_t> after_qty;
    std::optional<double> before_price;
    std::optional<double> after_price;
    std::optional<double> filled_money;
    std::optional<int32_t> status;
    std::optional<std::string> err_msg;
};

namespace uniffi {
    struct FfiConverterFutOptAccounting;
} // namespace uniffi

struct FutOptAccounting {
    friend uniffi::FfiConverterFutOptAccounting;

    FutOptAccounting() = delete;

    FutOptAccounting(const FutOptAccounting &) = delete;
    FutOptAccounting(FutOptAccounting &&) = delete;

    FutOptAccounting &operator=(const FutOptAccounting &) = delete;
    FutOptAccounting &operator=(FutOptAccounting &&) = delete;

    ~FutOptAccounting();
    /**
     * Check account closing position record <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * startDate ( string ) : Query record start date <br/>
     * <br/>
     * endDate ( string ) ( optional ) : Query record end date ( if empty will <br/>
     * fill in today automatically) <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * A list contains one or more CloseRecord objects <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = [ <br/>
     *         CloseRecord { <br/>
     *             date =2024/04/10, <br/>
     *             branchNo = 15000, <br/>
     *             account = 9974825, <br/>
     *             positionKind = 1, <br/>
     *             orderNo = 15001-0000, <br/>
     *             market = TAIMEX, <br/>
     *             symbol = FITX, <br/>
     *             expiryDate = 202404, <br/>
     *             strikePrice = , <br/>
     *             callPut = , <br/>
     *             buySell = Buy, <br/>
     *             price = 20847.0, <br/>
     *             origLots = 1, <br/>
     *             transactionFee = 40.0, <br/>
     *             tax = 83.0, <br/>
     *         }, <br/>
     *         ... <br/>
     *     ] <br/>
     * } <br/>
     */
    VecCloseRecordResponse close_position_record(const Account &account, const std::string &start_date, std::optional<std::string> end_date);
    /**
     * Check account position contain spread and single <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * Return <br/>
     * <br/>
     * A list contains one or more HybridPosition objects <br/>
     * <br/>
     * For example: <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = [ <br/>
     *         HybridPosition { <br/>
     *             date = 2024/04/08, <br/>
     *             branchNo = 15901, <br/>
     *             account = 1234567, <br/>
     *             isSpread = false, <br/>
     *             positionKind = 1, <br/>
     *             symbol = FITX, <br/>
     *             ... <br/>
     *         }, <br/>
     *         HybridPosition { <br/>
     *             date = 2024/04/08, <br/>
     *             branchNo = 15901, <br/>
     *             account = 1234567, <br/>
     *             isSpread = false, <br/>
     *             positionKind = 1, <br/>
     *             symbol = FIMTX, <br/>
     *             ... <br/>
     *         } <br/>
     *     ] <br/>
     * } <br/>
     */
    VecFutOptHybridPositionResponse query_hybrid_position(const Account &account);
    /**
     * Check account margin equity's amount <br/>
     * <br/>
     * Args: <br/>
     * <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * Return: <br/>
     * <br/>
     * A list contains one or more Equity objects <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *     isSuccess = True, <br/>
     *     message = , <br/>
     *     data = [ <br/>
     *         Equity{ <br/>
     *             date = 2024/04/08, <br/>
     *             branchNo = 15901, <br/>
     *             account = 1234567, <br/>
     *             currency = NTD, <br/>
     *             yesterdayBalance = 22435152.4, <br/>
     *             todayBalance = 22434910.4, <br/>
     *             initialMargin = 1114946.0, <br/>
     *             maintenanceMargin = 939214.0 <br/>
     *             clearingMargin = 915760.0, <br/>
     *             initialMarginAllSingle = 0.0, <br/>
     *             todayEquity = 22694910.4, <br/>
     *             withhold = 126402.0, <br/>
     *             availableMargin = 21453562.4, <br/>
     *             riskIndex = 0.0, <br/>
     *             disgorgement = 0.0, <br/>
     *             optPnl = -248600.0, <br/>
     *             optValue = -193100.0, <br/>
     *             optLongValue = 311900.0, <br/>
     *             optShortValue = 505000.0, <br/>
     *             futRealizedPnl = 0.0, <br/>
     *             futUnrealizedPnl = 60700.0, <br/>
     *             yesterdayEquity = 22634452.4, <br/>
     *             buyLot = 22, <br/>
     *             sellLot = 7, <br/>
     *         }, <br/>
     *         ... <br/>
     *     ] <br/>
     * } <br/>
     */
    VecEquityResponse query_margin_equity(const Account &account);
    /**
     * Check account position in single  <br/>
     *  <br/>
     * Args:  <br/>
     *  <br/>
     * account ( Account ) : Ordering account  <br/>
     *  <br/>
     * Return:  <br/>
     *  <br/>
     * A list contains one or more Position objects  <br/>
     *  <br/>
     * For Example:  <br/>
     *  <br/>
     * {  <br/>
     *     isSuccess = True,  <br/>
     *     message = ,  <br/>
     *     data = [  <br/>
     *         Position {  <br/>
     *             date = 2024/04/08,  <br/>
     *             branchNo = 15901,  <br/>
     *             account = 1234567,  <br/>
     *             orderNo = l0001-0000,  <br/>
     *             positionKind = 1,  <br/>
     *             symbol = FITX,  <br/>
     *             expiryDate = 202404,  <br/>
     *             strikePrice =,  <br/>
     *             callPut =,  <br/>
     *         },  <br/>
     *         ...  <br/>
     *     ]  <br/>
     * }  <br/>
     */
    VecFutOptPositionResponse query_single_position(const Account &account);

private:
    FutOptAccounting(void *);

    void *instance;
};


struct AccountRes {
    std::string account;
    std::string branch_no;
};


enum class ConditionMarketType: int32_t {
    COMMON = 1,
    FIXING = 2,
    ODD = 3,
    INTRADAY_ODD = 4
};


struct Equity {
    std::string date;
    std::string branch_no;
    std::string account;
    std::string currency;
    double yesterday_balance;
    double today_balance;
    double initial_margin;
    double maintenance_margin;
    double clearing_margin;
    double today_equity;
    double today_deposit;
    double today_withdrawal;
    double today_trading_fee;
    double today_trading_tax;
    double receivable_premium;
    double payable_premium;
    double excess_margin;
    double available_margin;
    double disgorgement;
    double opt_pnl;
    double opt_value;
    double opt_long_value;
    double opt_short_value;
    double fut_realized_pnl;
    double fut_unrealized_pnl;
    double buy_lot;
    double sell_lot;
};


struct Reply {
    std::string reply_code;
    std::string advisory;
};


enum class BsAction: int32_t {
    BUY = 1,
    SELL = 2,
    UN_SUPPORTED = 3,
    UN_DEFINED = 4
};


enum class FutOptMarketType: int32_t {
    FUTURE = 1,
    OPTION = 2,
    FUTURE_NIGHT = 3,
    OPTION_NIGHT = 4,
    UN_SUPPORTED = 5,
    UN_DEFINED = 6
};


struct MaintenanceSummary {
    int64_t margin_value;
    int64_t shortsell_value;
    std::optional<int64_t> shortsell_margin;
    std::optional<int64_t> collateral;
    int64_t margin_loan_amt;
    double maintenance_ratio;
};


enum class FutOptConditionOrderType: int32_t {
    NEW = 1,
    CLOSE = 2
};


struct MarginShortQuota {
    std::optional<std::string> stock_no;
    std::string date;
    std::optional<int64_t> shortsell_orig_quota;
    std::optional<int64_t> shortsell_tradable_quota;
    std::optional<int64_t> margin_orig_quota;
    std::optional<int64_t> margin_tradable_quota;
    std::optional<int32_t> margin_ratio;
    std::optional<int32_t> short_ratio;
};


struct DayTradeStockInfo {
    std::optional<std::string> stock_no;
    std::string date;
    std::optional<int64_t> daytrade_orig_quota;
    std::optional<int64_t> daytrade_tradable_quota;
    std::optional<int64_t> precollect_single;
    std::optional<int64_t> precollect_accumulate;
    std::optional<int32_t> status;
    std::optional<std::string> disposition_status;
};


struct BatchResult {
    int32_t function_type;
    std::string date;
    std::string branch_no;
    std::string account;
    std::string batch_seq_no;
};

namespace uniffi {
    struct FfiConverterStockFunctions;
} // namespace uniffi

struct StockFunctions {
    friend uniffi::FfiConverterStockFunctions;

    StockFunctions() = delete;

    StockFunctions(const StockFunctions &) = delete;
    StockFunctions(StockFunctions &&) = delete;

    StockFunctions &operator=(const StockFunctions &) = delete;
    StockFunctions &operator=(StockFunctions &&) = delete;

    ~StockFunctions();
    /**
     * Batch cancel  active order <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * target_order ( OrderResult array ) : Order array to be cancel <br/>
     * <br/>
     * Return: <br/>
     * A list contains one or more modified order information <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *      OrderResult{ <br/>
     *        functionType = 30, <br/>
     *        date = 2024/03/08, <br/>
     *        ... <br/>
     *        stockNo = 1101, <br/>
     *        buySell = Sell, <br/>
     *        priceType = Limit, <br/>
     *        price = 41.2, <br/>
     *        quantity = 5000, <br/>
     *        timeInForce = ROD, <br/>
     *        orderType = Stock, <br/>
     *        isPreOrder = False, <br/>
     *        status = 30, <br/>
     *        afterPriceType = Limit, <br/>
     *        afterPrice = 41.2, <br/>
     *        ... <br/>
     *        beforeQty = 5000, <br/>
     *        beforePrice = 41.2, <br/>
     *        userDef = 12345678, <br/>
     *        lastTime = 16:53:57.536, <br/>
     *        errorMessage =  <br/>
     *      }, <br/>
     *      OrderResult{ <br/>
     *        functionType = 30, <br/>
     *        date = 2024/03/08, <br/>
     *        ..., <br/>
     *        stockNo = 1101, <br/>
     *        buySell = Sell, <br/>
     *        priceType = Limit, <br/>
     *        price = 41.2, <br/>
     *        quantity = 5000, <br/>
     *        timeInForce = ROD, <br/>
     *        orderType = Stock, <br/>
     *        isPreOrder = False, <br/>
     *        status = 30, <br/>
     *        ... <br/>
     *      } <br/>
     *    ] <br/>
     * } <br/>
     */
    VecOrderResponse batch_cancel_order(const Account &account, const std::vector<OrderResult> &orders);
    /**
     * Batch Modify order price <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * ModifyPriceObj  ( array of object ) : Object list for price adjustment <br/>
     * <br/>
     * Return: <br/>
     * A list contains one or more modified order information <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = [ <br/>
     *      OrderResult({ <br/>
     *        functionType = 15, <br/>
     *        date = 2023/11/22, <br/>
     *        ... <br/>
     *        stockNo = 1101, <br/>
     *        buySell = Sell, <br/>
     *        priceType = Limit, <br/>
     *        price = 41.2, <br/>
     *        quantity = 5000, <br/>
     *        timeInForce = ROD, <br/>
     *        orderType = Stock, <br/>
     *        isPreOrder = False, <br/>
     *        status = 10, <br/>
     *        afterPriceType = Limit, <br/>
     *        afterPrice = 41.1, <br/>
     *        ... <br/>
     *        beforePrice = 41.3, <br/>
     *        userDef = 12345678, <br/>
     *        lastTime = 10:56:57.713, <br/>
     *        errorMessage =  <br/>
     *      }), <br/>
     *      OrderResult({ <br/>
     *        functionType = 15, <br/>
     *        date = 2023/11/22, <br/>
     *        ... <br/>
     *        stockNo = 1101, <br/>
     *        buySell = Sell, <br/>
     *        priceType = Limit, <br/>
     *        price = 41.2, <br/>
     *        quantity = 5000, <br/>
     *        timeInForce = ROD, <br/>
     *        orderType = Stock, <br/>
     *        isPreOrder = False, <br/>
     *        status = 10, <br/>
     *        ... <br/>
     *      }) <br/>
     *    ] <br/>
     * } <br/>
     */
    VecOrderResponse batch_modify_price(const Account &account, const std::vector<ModifyPrice> &orders);
    /**
     * Batch modify order quantity <br/>
     * <br/>
     * 	Args: <br/>
     * 	account ( Account ) : Ordering account <br/>
     * ModifyQuantityObj  ( array of object ) : Object array for quantity adjustment <br/>
     * <br/>
     * Return: <br/>
     * A list contains one or more modified order information <br/>
     * <br/>
     * For Example <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = [ <br/>
     *      OrderResult{ <br/>
     *        functionType = 20, <br/>
     *        date = 2024/03/08, <br/>
     *        ... <br/>
     *        stockNo = 2881, <br/>
     *        buySell = Buy, <br/>
     *        priceType = Limit, <br/>
     *        price = 66, <br/>
     *        quantity = 2000, <br/>
     *        timeInForce = ROD, <br/>
     *        orderType = Stock, <br/>
     *        isPreOrder = False, <br/>
     *        status = 10, <br/>
     *        ... <br/>
     *        afterQty = 1000, <br/>
     *        filledQty = 0, <br/>
     *        filledMoney = 0, <br/>
     *        beforeQty = 2000, <br/>
     *        beforePrice = , <br/>
     *        userDef = batch 2, <br/>
     *        lastTime = 12:21:51.023, <br/>
     *        errorMessage =  <br/>
     *      }, <br/>
     *      OrderResult{ <br/>
     *        functionType = 20, <br/>
     *        date = 2024/03/08, <br/>
     *        ... <br/>
     *        stockNo = 2881, <br/>
     *        buySell = Buy, <br/>
     *        priceType = Limit, <br/>
     *        price = 66, <br/>
     *        quantity = 2000, <br/>
     *        timeInForce = ROD, <br/>
     *        orderType = Stock, <br/>
     *        isPreOrder = False, <br/>
     *        status = 10, <br/>
     *        afterPriceType = , <br/>
     *        afterPrice = 66, <br/>
     *        ... <br/>
     *   }] <br/>
     * } <br/>
     */
    VecOrderResponse batch_modify_quantity(const Account &account, const std::vector<ModifyQuantity> &orders);
    /**
     * Check execution status of  batch list <br/>
     * <br/>
     * Args <br/>
     * account ( Account ) : Ordering account <br/>
     * Batch order list ( BatchResult ) : Query batch result <br/>
     * <br/>
     * Return <br/>
     * A list contains one or more BatchResult objects <br/>
     * <br/>
     *     For example <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = <br/>
     * [ <br/>
     *   OrderResult{ <br/>
     *     functionType = , <br/>
     *     date = 2023/10/16, <br/>
     *     seqNo = 00000000001, <br/>
     *     branchNo = 6460, <br/>
     *     … <br/>
     *   }, <br/>
     *   OrderResult{ <br/>
     *     functionType = , <br/>
     *     date = 2023/10/16, <br/>
     *     seqNo = 00000000002, <br/>
     *     branchNo = 6460, <br/>
     *   ... <br/>
     *   }, <br/>
     * <br/>
     * ] <br/>
     * } <br/>
     */
    VecOrderResponse batch_order_detail(const Account &account, const BatchResult &batch);
    /**
     * Get batch order record list <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) :   Ordering account <br/>
     * <br/>
     * Return: <br/>
     * A list contains one or more BatchResult objects <br/>
     * <br/>
     *    For example <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = <br/>
     *      BatchResult[ <br/>
     *         { <br/>
     *             functionType = 0, <br/>
     *             date = 2023/10/04, <br/>
     *             branchNo = 6460, <br/>
     *             account = 26, <br/>
     *             batchSeqNo = 11EE626533D072228000000C29304663 <br/>
     *         }, <br/>
     *         ... <br/>
     *      ] <br/>
     * } <br/>
     */
    BatchResponse batch_order_lists(const Account &account);
    /**
     * Send in a new batch order <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * order_object ( OrderObject array ) :  The order array content <br/>
     * <br/>
     * Return: <br/>
     * 	An object contains one or more order result objects <br/>
     * <br/>
     * 	Usage function example: <br/>
     * 	Can define order like this <br/>
     * var orders = new Order[]{ <br/>
     *   new Order( <br/>
     *    BsAction.BUY, <br/>
     *    "2888", <br/>
     *    "8.90", <br/>
     *     2000, <br/>
     *    MarketType.COMMON, <br/>
     *    PriceType.LIMIT, <br/>
     *    TimeInForce.ROD, <br/>
     *    OrderType.STOCK, <br/>
     *    null <br/>
     * ), new Order( <br/>
     *    BsAction.BUY, <br/>
     *    "2888", <br/>
     *    "8.90", <br/>
     *     2000, <br/>
     *    MarketType.COMMON, <br/>
     *    PriceType.LIMIT, <br/>
     *    TimeInForce.ROD, <br/>
     *    OrderType.STOCK, <br/>
     *    null <br/>
     * )}; <br/>
     * <br/>
     * sdk.Stock.BatchPlaceOrder(target_user, orders, false) <br/>
     */
    VecOrderResponse batch_place_order(const Account &account, const std::vector<Order> &orders);
    StringResponse cancel_condition_orders(const Account &account, const std::string &guid);
    /**
     * Cancel an active order <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * target_order ( OrderResult ) : Order to be deleted <br/>
     * unblock ( bool ) ( optional ) : Using unblock mode ; <br/>
     * <br/>
     * Return: <br/>
     * An object contains modified order information <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = <br/>
     *    OrderResultt{ <br/>
     *      functionType = 30, <br/>
     *      date = 2024/03/08, <br/>
     *      seqNo = 00000308948, <br/>
     *      branchNo = 6460, <br/>
     *      account = 26, <br/>
     *      orderNo = x0023, <br/>
     *      assetType = 0, <br/>
     *      market = TAIEX, <br/>
     *      marketType = Common, <br/>
     *      stockNo = 1101, <br/>
     *      buySell = Sell, <br/>
     *      priceType = Limit, <br/>
     *      price = 41.2, <br/>
     *      quantity = 5000, <br/>
     *      timeInForce = ROD, <br/>
     *      orderType = Stock, <br/>
     *      isPreOrder = false, <br/>
     *      status = 30, <br/>
     *      afterPriceType = Limit, <br/>
     *      afterPrice = 41.2, <br/>
     *      unit = 1000, <br/>
     *      afterQty = 0, <br/>
     *      filledQty = 0, <br/>
     *      filledMoney = 0, <br/>
     *      beforeQty = 5000, <br/>
     *      beforePrice = 41.2, <br/>
     *      userDef = 12345678, <br/>
     *      lastTime = 16:53:57.536 <br/>
     *      errorMessage = <br/>
     *   } <br/>
     * } <br/>
     */
    OrderResponse cancel_order(const Account &account, const OrderResult &order_res, std::optional<bool> unblock);
    /**
     * Check available day trade quota and pre-collected information <br/>
     * <br/>
     * <br/>
     * Args: <br/>
     * account ( Account )  : Ordering account <br/>
     * stock_no ( string ) : Query for stock ID <br/>
     * <br/>
     * Return: <br/>
     * An object contains day trade quota and pre-collected information <br/>
     * <br/>
     * For example: <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = <br/>
     *      DayTradeStockInfo{ <br/>
     *        stockNo= 2330, <br/>
     *        date= 2023/10/16, <br/>
     *        daytradeOrigQuota= 0, <br/>
     *        daytradeTradableQuota= 0, <br/>
     *        precollectSingle= null, <br/>
     *        precollectAccumulate= null, <br/>
     *        status= 0 <br/>
     *      } <br/>
     *  } <br/>
     */
    DayTradeStockInfoResponse daytrade_and_stock_info(const Account &account, const std::string &stock_no);
    /**
     * Retrieve filled data in the record <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Query specify account <br/>
     * start_date ( string ) :  Query record start date <br/>
     * end_date ( string )  ( optional ) : Query record end date ( if empty will fill in today automatically) <br/>
     * <br/>
     * Return: <br/>
     * A list contains one or more filled data objects <br/>
     * <br/>
     * For example: <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *      FillData { <br/>
     *         date= 2023/09/15, <br/>
     *            ... <br/>
     *         filledNo= 00000000001, <br/>
     *         filledAvgPrice= 35.2, <br/>
     *         filledQty= 1000, <br/>
     *         filledPrice= 35.2, <br/>
     *         orderType= STOCK, <br/>
     *         filledTime= 10:31:00.931 <br/>
     *       }, <br/>
     *      FillData { <br/>
     *         date= 2023/09/15, <br/>
     *           ... <br/>
     *         filledNo= 00000000003, <br/>
     *         filledAvgPrice= 35.2, <br/>
     *         filledQty= 1000, <br/>
     *         filledPrice= 35.2, <br/>
     *         orderType= STOCK, <br/>
     *         filledTime= 10:33:00.931 <br/>
     *       } <br/>
     *     ] <br/>
     *  } <br/>
     */
    FilledResponse filled_history(const Account &account, std::optional<std::string> start_date, std::optional<std::string> end_date);
    VecConditionDetailResponse get_condition_daytrade_by_id(const Account &account, const std::string &guid);
    VecConditionDetailResponse get_condition_history(const Account &account, const std::string &start_date, const std::string &end_date, std::optional<HistoryStatus> history_type);
    VecConditionDetailResponse get_condition_order(const Account &account, std::optional<ConditionStatus> condition_status);
    VecConditionDetailResponse get_condition_order_by_id(const Account &account, const std::string &guid);
    /**
     * Get today’s all orders; active, canceled, or filled. <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * Return: <br/>
     * A list contains one or more result objects <br/>
     * <br/>
     * For Example: <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *   { <br/>
     *     date = 2023/10/16, <br/>
     *     seqNo = 00000000001, <br/>
     *     branchNo = 6460, <br/>
     *       ... <br/>
     *   }, <br/>
     *   { <br/>
     *     date = 2023/10/16, <br/>
     *     seqNo = 00000000002, <br/>
     *     branchNo = 6460, <br/>
     *       ... <br/>
     *   } <br/>
     *       ] <br/>
     * } <br/>
     */
    VecOrderResponse get_order_results(const Account &account);
    /**
     * Get today’s all orders; active, canceled, or filled (include order process). <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * Return: <br/>
     * A list contains one or more result objects <br/>
     * <br/>
     * For Example: <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *   { <br/>
     *     date = 2023/10/16, <br/>
     *     seqNo = 00000000001, <br/>
     *     branchNo = 6460, <br/>
     *       ... <br/>
     *   }, <br/>
     *   { <br/>
     *     date = 2023/10/16, <br/>
     *     seqNo = 00000000002, <br/>
     *     branchNo = 6460, <br/>
     *       ... <br/>
     *   } <br/>
     *       ] <br/>
     * } <br/>
     */
    VecOrderResponse get_order_results_detail(const Account &account);
    VecConditionDetailResponse get_time_slice_order(const Account &account, const std::string &batch_no);
    VecConditionDetailResponse get_trail_history(const Account &account, const std::string &start_date, const std::string &end_date);
    VecConditionDetailResponse get_trail_order(const Account &account);
    /**
     * Set price change for order <br/>
     * <br/>
     * Args: <br/>
     * target_order ( OrderResult ) : Order to be modified <br/>
     * price ( string ) ( optional ) : Modify price ( If the 'priceType' field is entered, this field should be None or empty) <br/>
     * priceType ( priceType ) ( optional ) : Modify price type  ( If the 'price' field is entered, this field should be None or empty ) <br/>
     * <br/>
     * Return: <br/>
     * An object contains the order are prepared modify price <br/>
     * <br/>
     * <br/>
     * For Example: <br/>
     * <br/>
     * 1. Using getOrderResult retrieve OrderResult <br/>
     * 2. Designate order to modify <br/>
     * <br/>
     * <br/>
     * order_res = sdk.Stock.GetOrderResults(accounts.data[0]) <br/>
     * target_order = order_res.data[0] <br/>
     * modify_price_obj = sdk.Stock.MakeModifyPriceObj(target_order, "65") <br/>
     */
    ModifyPrice make_modify_price_obj(const OrderResult &order, std::optional<std::string> price, std::optional<PriceType> price_type);
    /**
     * Set quantity change for order <br/>
     * <br/>
     * 	Args: <br/>
     * 	target_order ( OrderResult ) : Order for quantity adjustment <br/>
     * quantity ( int )  : Modify quantity <br/>
     * <br/>
     * Return: <br/>
     * An object contains the order are prepared modify quantity <br/>
     * <br/>
     *   For example: <br/>
     * <br/>
     * 1. Using GetOrderResults retrieve OrderResult <br/>
     * 2. Designate order to modify <br/>
     * <br/>
     *   order_res = sdk.Stock.GetOrderResults(accounts.data[0]) <br/>
     *   target_order = order_res.data[0] <br/>
     * modify_quantity_obj = sdk.Stock.MakeModifyQuantityObj(target_order, 1000) <br/>
     */
    ModifyQuantity make_modify_quantity_obj(const OrderResult &order, int64_t quantity);
    /**
     * Check available margin quota <br/>
     * <br/>
     * Args: <br/>
     * account ( Account )  : Ordering account <br/>
     * stock_no ( string ) : Query for stock ID <br/>
     * <br/>
     * Return: <br/>
     * An object contains margin and shortsell quota <br/>
     * <br/>
     * For example: <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = <br/>
     *      MarginShortQuota{ <br/>
     *        stockNo= 2330, <br/>
     *        date= 2023/10/20, <br/>
     *        shortsellOrigQuota= null, <br/>
     *        shortsellTradableQuota= 10, <br/>
     *        marginOrigQuota= null, <br/>
     *        marginTradableQuota= 10, <br/>
     *        marginRatio= 60, <br/>
     *        shortRatio= 90 <br/>
     *      } <br/>
     * } <br/>
     */
    MarginShortQuotaResponse margin_quota(const Account &account, const std::string &stock_no);
    /**
     * Modify order price <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * ModifyPriceObj  ( object ) : Object for price adjustment <br/>
     * unblock ( bool ) ( optional ) : Using unblock mode ; <br/>
     * <br/>
     * Return: <br/>
     * An object contains modified order information <br/>
     * <br/>
     * For example: <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    OrderResult{ <br/>
     *      function_type = 15, <br/>
     *      date = 2023/11/22, <br/>
     *      seqNo = 00000308866, <br/>
     *      branchNo = 6460, <br/>
     *      account = 26, <br/>
     *      orderNo = x0011, <br/>
     *      assetYype = 0, <br/>
     *      market = TAIEX, <br/>
     *      marketType = Common, <br/>
     *      stockNo = 1101, <br/>
     *      buySell = Sell, <br/>
     *      priceType = Limit, <br/>
     *      price = 41.2, <br/>
     *      quantity = 5000, <br/>
     *      timeInForce = ROD, <br/>
     *      orderType = Stock, <br/>
     *      isPreOrder = False, <br/>
     *      status = 10, <br/>
     *      afterPriceType = Limit, <br/>
     *      afterPrice = 41.1, <br/>
     *      unit = 1000, <br/>
     *      afterQty = 2000, <br/>
     *      filledQty = 0, <br/>
     *      filledMoney = 0, <br/>
     *      beforeQty = , <br/>
     *      beforePrice = 41.3, <br/>
     *      userDef = 12345678, <br/>
     *      lastTime = 13:56:57.713, <br/>
     *      errorMessage =  <br/>
     *   } <br/>
     * } <br/>
     */
    OrderResponse modify_price(const Account &account, const ModifyPrice &modify_obj, std::optional<bool> unblock);
    /**
     * Modify order quantity <br/>
     * <br/>
     * 	Args: <br/>
     * 	account ( Account ) : Ordering account <br/>
     * ModifyQuantityObj  ( object ) : Object for quantity adjustment <br/>
     * unblock ( bool ) ( optional ) : Using unblock mode ; <br/>
     * <br/>
     * Return: <br/>
     * An object contains modified order information <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = <br/>
     *    OrderResult{ <br/>
     *      functionType = 20, <br/>
     *      date = 2024/03/08, <br/>
     *      seqNo = 00000308866, <br/>
     *      branchNo = 6460, <br/>
     *      account = 26, <br/>
     *      orderNo = x0011, <br/>
     *      assetType = 0, <br/>
     *      market = TAIEX, <br/>
     *      marketType = Common, <br/>
     *      stockNo = 1101, <br/>
     *      buySell = Sell, <br/>
     *      priceType = Limit, <br/>
     *      price = 41.2, <br/>
     *      quantity = 5000, <br/>
     *      timeInForce = ROD, <br/>
     *      orderType = Stock, <br/>
     *      isPreOrder = False, <br/>
     *      status = 10, <br/>
     *      afterPriceType = Limit, <br/>
     *      afterPrice = 41.3, <br/>
     *      unit = 1000, <br/>
     *      afterQty = 2000, <br/>
     *      filledQty = 0, <br/>
     *      filledMoney = 0, <br/>
     *      beforeQty = 3000, <br/>
     *      beforePrice = 41.2, <br/>
     *      userDef = 12345678, <br/>
     *      lastTime = 13:56:28.966, <br/>
     *      errorMessage =  <br/>
     *   } <br/>
     * } <br/>
     */
    OrderResponse modify_quantity(const Account &account, const ModifyQuantity &modify_obj, std::optional<bool> unblock);
    ConditionOrderResultResponse multi_condition(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const std::vector<Condition> &conditions, const ConditionOrder &order, std::optional<TPSLWrapper> child_info);
    ConditionOrderResultResponse multi_condition_day_trade(const Account &account, const StopSign &stop_sign, const std::string &end_time, const std::vector<Condition> &conditions, const ConditionOrder &order, const ConditionDayTrade &condition_day_trade, std::optional<TPSLWrapper> child_info, std::optional<bool> fix_session);
    ConditionOrderResultResponse multi_condition_stop(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const std::vector<Condition> &conditions, const ConditionOrder &order, const std::vector<Condition> &stop_conditions, std::optional<std::vector<Condition>> second_stop_conditions, std::optional<TPSLWrapper> child_info);
    /**
     * Retrieve order in the record <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * start_date ( string ) :  Query record start date <br/>
     * end_date ( string )  ( optional ) : Query record end date ( if empty will fill in today automatically) <br/>
     * <br/>
     * Return: <br/>
     * A list contains one or more result objects <br/>
     * <br/>
     * For example <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *      OrderResult { <br/>
     *        functionType = , <br/>
     *        date= 2023/10/16, <br/>
     *        seqNo= 00000000001, <br/>
     *        branchNo= 6460, <br/>
     *         …. <br/>
     *      }, <br/>
     *      OrderResult{ <br/>
     *        functionType = , <br/>
     *        date= 2023/10/16, <br/>
     *        seqNo= 00000000002, <br/>
     *        branchNo= 6460, <br/>
     *         …. <br/>
     *      } <br/>
     *    ] <br/>
     *  } <br/>
     */
    VecOrderResponse order_history(const Account &account, const std::string &start_date, std::optional<std::string> end_date);
    /**
     * Send in a new order<br/>
     * <br/>
     * Args:<br/>
     * account ( Account ) : Ordering account<br/>
     * order ( OrderObject ) : The order content<br/>
     * unblock  ( bool ) ( optional ) : Using unblock mode<br/>
     * <br/>
     * Return:<br/>
     * An object contains order information. ( if using unblock mode, the order result may not contain whole information.)<br/>
     * <br/>
     * Usage function example<br/>
     * <br/>
     * Can define order like this<br/>
     * var order = new Order(<br/>
     *            BsAction.BUY,<br/>
     *            "2881",<br/>
     *            "66",<br/>
     *             2000,<br/>
     *            MarketType.COMMON,<br/>
     *            PriceType.LIMIT,<br/>
     *            TimeInForce.ROD,<br/>
     *            OrderType.STOCK,<br/>
     *            null   // User_def<br/>
     * );<br/>
     * <br/>
     * <br/>
     * <br/>
     * sdk.Stock.PlaceOrder(account, order, false)<br/>
     */
    OrderResponse place_order(const Account &account, const Order &order, std::optional<bool> unblock);
    /**
     * Query symbol quote information for a single stock
     *
     * Args:
     * account (Account): Query account
     * symbol (string): Stock symbol to query
     * market_type (MarketType): Market type (optional)
     *
     * Return:
     * Symbol quote response containing stock quote information
     */
    SymbolQuoteResponse query_symbol_quote(const Account &account, const std::string &symbol, std::optional<MarketType> market_type);
    /**
     * Query symbol snapshot information for multiple stocks with filtering
     *
     * Args:
     * account (Account): Query account
     * market_type (MarketType): Market type (optional)
     * stock_types (sequence<StockType>): Stock types to filter (optional)
     *
     * Return:
     * Symbol snapshot response containing multiple stock information
     */
    VecSymbolQuoteResponse query_symbol_snapshot(const Account &account, std::optional<MarketType> market_type, std::optional<std::vector<StockType>> stock_types);
    ConditionOrderResultResponse single_condition(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const Condition &condition, const ConditionOrder &order, std::optional<TPSLWrapper> child_info);
    ConditionOrderResultResponse single_condition_day_trade(const Account &account, const StopSign &stop_sign, const std::string &end_time, const Condition &condition, const ConditionOrder &order, const ConditionDayTrade &condition_day_trade, std::optional<TPSLWrapper> child_info, std::optional<bool> fix_session);
    ConditionOrderResultResponse single_condition_stop(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const Condition &condition, const ConditionOrder &order, const std::vector<Condition> &stop_conditions, std::optional<std::vector<Condition>> second_stop_conditions, std::optional<TPSLWrapper> child_info);
    ConditionOrderResultResponse time_slice_order(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const SplitDescription &split_description, const ConditionOrder &order);
    ConditionOrderResultResponse trail_profit(const Account &account, const std::string &start_date, const std::string &end_date, const StopSign &stop_sign, const TrailOrder &trail_order);

private:
    StockFunctions(void *);

    void *instance;
};


enum class MarketType: int32_t {
    COMMON = 1,
    FIXING = 2,
    ODD = 3,
    INTRADAY_ODD = 4,
    EMG = 5,
    EMG_ODD = 6,
    UN_SUPPORTED = 7,
    UN_DEFINED = 8
};


enum class CallPut: int32_t {
    CALL = 1,
    PUT = 2,
    UN_SUPPORTED = 3,
    UN_DEFINED = 4
};


enum class Operator: int32_t {
    GREATER_THAN_OR_EQUAL = 1,
    LESS_THAN_OR_EQUAL = 2,
    GREATER_THAN = 3,
    LESS_THAN = 4
};


enum class StopSign: int32_t {
    FULL = 1,
    PARTIAL = 2,
    UNTIL_END = 3
};


struct EstimateMargin {
    std::string date;
    std::string currency;
    double estimate_margin;
};


struct Settlement {
    std::string date;
    std::optional<std::string> settlement_date;
    std::optional<int64_t> buy_value;
    std::optional<int64_t> buy_fee;
    std::optional<int64_t> buy_settlement;
    std::optional<int64_t> buy_tax;
    std::optional<int64_t> sell_value;
    std::optional<int64_t> sell_fee;
    std::optional<int64_t> sell_settlement;
    std::optional<int64_t> sell_tax;
    std::optional<int64_t> total_bs_value;
    std::optional<int64_t> total_fee;
    std::optional<int64_t> total_tax;
    std::optional<int64_t> total_settlement_amount;
    std::optional<std::string> currency;
};


struct FutOptOrderDetail {
    std::optional<int32_t> function_type;
    std::string modified_time;
    std::optional<int64_t> before_lot;
    std::optional<int64_t> after_lot;
    std::optional<double> before_price;
    std::optional<double> after_price;
    std::optional<double> filled_money;
    std::optional<std::string> error_message;
    std::optional<int32_t> status;
    std::optional<std::string> err_msg;
};


enum class ConditionPriceType: int32_t {
    LIMIT = 1,
    MARKET = 2,
    BID_PRICE = 3,
    ASK_PRICE = 4,
    MATCHED_PRICE = 5,
    LIMIT_UP = 6,
    LIMIT_DOWN = 7,
    REFERENCE = 8
};


enum class PriceType: int32_t {
    LIMIT = 1,
    MARKET = 2,
    LIMIT_UP = 3,
    LIMIT_DOWN = 4,
    REFERENCE = 5,
    UN_SUPPORTED = 6,
    UN_DEFINED = 7
};


struct Recover {
    std::string branch_no;
    std::string account;
    std::string account_type;
    std::string recover_type;
    int64_t recover_count;
};

namespace uniffi {
    struct FfiConverterAccounting;
} // namespace uniffi

struct Accounting {
    friend uniffi::FfiConverterAccounting;

    Accounting() = delete;

    Accounting(const Accounting &) = delete;
    Accounting(Accounting &&) = delete;

    Accounting &operator=(const Accounting &) = delete;
    Accounting &operator=(Accounting &&) = delete;

    ~Accounting();
    /**
     * Query bank remains balance <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * Return: <br/>
     * An object contains bank remains balance data <br/>
     * <br/>
     * For example <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = <br/>
     *      BankRemain{ <br/>
     *          branchNo = 6460, <br/>
     *          account = 26, <br/>
     *          currency = TWD, <br/>
     *          balance = 666666, <br/>
     *          availableBalance = 123456 <br/>
     *      } <br/>
     *    } <br/>
     * } <br/>
     */
    BankRemainResponse bank_remain(const Account &account);
    /**
     * Check your inventories data and transactions record <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * Return: <br/>
     * An object contains one or more inventory objects <br/>
     * <br/>
     * For Example: <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *       Inventory { <br/>
     *          date= 2023/10/16, <br/>
     *          account= 26, <br/>
     *          branchNo= 6460, <br/>
     *          stockNo= 1101, <br/>
     *             ... <br/>
     *          tradableQty= 2000, <br/>
     *          sellQty= 0, <br/>
     *          sellFilledQty= 0, <br/>
     *          sellValue= 0, <br/>
     *          odd= { <br/>
     *            lastdayQty= 0, <br/>
     *            buyQty= 0, <br/>
     *            buyFilledQty= 0, <br/>
     *            buyValue= 0, <br/>
     *              ... <br/>
     *          } <br/>
     *        }, <br/>
     *      Inventory  { <br/>
     *          date= 2023/10/16, <br/>
     *          account= 26, <br/>
     *          branchNo= 6460, <br/>
     *          stockNo= 1101, <br/>
     *             ... <br/>
     *          tradableQty= 2000, <br/>
     *          sellQty= 0, <br/>
     *          sellFilledQty= 0, <br/>
     *          sellValue= 0, <br/>
     *          odd= { <br/>
     *            lastdayQty= 0, <br/>
     *            buyQty= 0, <br/>
     *            buyFilledQty= 0, <br/>
     *            buyValue= 0, <br/>
     *              ... <br/>
     *          } <br/>
     *        } <br/>
     *      ] <br/>
     *  } <br/>
     */
    InventoryResponse inventories(const Account &account);
    /**
     * Check account's maintenance data <br/>
     * 	Args: <br/>
     * 	account ( Account ) :   Ordering account <br/>
     * <br/>
     * 	Return <br/>
     * 	An object contains account maintenance information and inventory maintenance data <br/>
     * <br/>
     * 	For Example <br/>
     *  { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = <br/>
     *      MaintenanceData { <br/>
     *          date= 2023/10/18, <br/>
     *          branchNo= 6460, <br/>
     *          account= 26, <br/>
     *          maintenanceSummary= { <br/>
     *            marginValue= 1051000, <br/>
     *            shortsellValue= 97800, <br/>
     *            shortsellMargin= 154000, <br/>
     *            collateral= 154300, <br/>
     *            marginLoanAmt= 723000, <br/>
     *            maintenanceRatio= 165.6067 <br/>
     *          }, <br/>
     *          maintenanceDetail= [ <br/>
     *            { <br/>
     *              stockNo= 2303, <br/>
     *              orderNo= y0002, <br/>
     *              orderType= MARGIN, <br/>
     *              quantity= 1000, <br/>
     *              price= 48.8, <br/>
     *              costPrice= 50, <br/>
     *              marketValue= 48800, <br/>
     *              shortsellMargin= 0, <br/>
     *              collateral= 0, <br/>
     *              marginLoanAmt= 30000, <br/>
     *              maintenanceRatio= 162.6667, <br/>
     *              marginOrShortRatio= 60.0 <br/>
     *            } <br/>
     *          ] <br/>
     *        } <br/>
     *  } <br/>
     * <br/>
     */
    MaintenanceResponse maintenance(const Account &account);
    /**
     * Check account's settlement amount <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) :   Ordering account <br/>
     * range ( string ) : Time range , valid value `0d` and `3d` <br/>
     * <br/>
     * Return: <br/>
     * An object contains account settlement data <br/>
     * <br/>
     * For example <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data = <br/>
     *    SettlementData{ <br/>
     *      account = AccountRes { <br/>
     *          account = 26, <br/>
     *          branchNo = 6460 <br/>
     *      }, <br/>
     *      details = [ <br/>
     *          { <br/>
     *            date = 2023/09/08, <br/>
     *            settlementDate = 2023/09/12, <br/>
     *            buyValue = 735500, <br/>
     *            buyFee = 313, <br/>
     *            buySettlement = -1429513, <br/>
     *            buyTax = 0, <br/>
     *            sellValue = 770500, <br/>
     *            sellFee = 320, <br/>
     *             sellSettlement = 0, <br/>
     *             sellTax = 2309, <br/>
     *             totalBsValue = 1506000, <br/>
     *             totalFee = 633, <br/>
     *             totalSettlementAmount = -1429513, <br/>
     *             totalTax = 2309, <br/>
     *             currency = TWD <br/>
     * <br/>
     *          } <br/>
     *      ] <br/>
     *   } <br/>
     * } <br/>
     */
    SettlementResponse query_settlement(const Account &account, const std::string &range);
    /**
     * Check account realized gain and loss summary <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) :   Ordering account <br/>
     * <br/>
     * Return: <br/>
     * A list contains one or more RealizedSummary objects <br/>
     * <br/>
     *     For Example <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *      RealizedSummary{ <br/>
     *        startDate= 20231011, <br/>
     *        endDate= 20231018, <br/>
     *        branchNo= 6460, <br/>
     *        account= 26, <br/>
     *        stockNo= 1101, <br/>
     *        buySell= SELL, <br/>
     *        orderType= STOCK, <br/>
     *        filledQty= 1000, <br/>
     *        filledAvgPrice= 35.0, <br/>
     *        realizedProfitAndLoss= -203 <br/>
     *      }, <br/>
     *      ... <br/>
     *   ] <br/>
     * } <br/>
     */
    RealizedResponse realized_gains_and_loses(const Account &account);
    /**
     * Check account realized gain and loss detail <br/>
     * <br/>
     * Args: <br/>
     * account ( Account ) :  Ordering account <br/>
     * <br/>
     * Return: <br/>
     * An object contains one or more Realized objects <br/>
     * <br/>
     * For example <br/>
     * <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *      Realized { <br/>
     *         date= 2023/10/17, <br/>
     *         branchNo= 6460, <br/>
     *         account= 26, <br/>
     *         orderNo= bA669, <br/>
     *         stockNo= 1101, <br/>
     *         buySell= SELL, <br/>
     *         filledQty= 1000, <br/>
     *         filledPrice= 35.0, <br/>
     *         orderType= STOCK, <br/>
     *         realizedProfit= 0, <br/>
     *         realizedLoss= 203 <br/>
     *       }, <br/>
     *       ... <br/>
     *    ] <br/>
     * } <br/>
     */
    RealizedSummaryResponse realized_gains_and_loses_summary(const Account &account);
    /**
     * Check your unrealized gain and loss detail <br/>
     * Args: <br/>
     * account ( Account ) : Ordering account <br/>
     * <br/>
     * <br/>
     * Return <br/>
     * A list contains one or more UnrealizedData objects <br/>
     * <br/>
     *     For example <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *      UnrealizedData { <br/>
     *         date= 2021/08/09, <br/>
     *         account= 26, <br/>
     *         branchNo= 6460, <br/>
     *         stockNo= 2303, <br/>
     *         buySell= BUY, <br/>
     *         orderType= MARGIN, <br/>
     *         costPrice= 50.0, <br/>
     *         tradableQty= 1000, <br/>
     *         todayQty= 1000, <br/>
     *         unrealizedProfit= 48650, <br/>
     *         unrealizedLoss= 0 <br/>
     *       }, <br/>
     *           ... <br/>
     *    ] <br/>
     * } <br/>
     */
    UnRealizedResponse unrealized_gains_and_loses(const Account &account);

private:
    Accounting(void *);

    void *instance;
};


struct ParentChildRecord {
    std::optional<std::string> guid;
    std::string account;
    std::string condition_content;
    std::string action;
    std::string condition_buy_sell;
    std::string condition_symbol;
    std::string condition_price;
    std::string condition_volume;
    std::string condition_filled_volume;
    std::string start_date;
    std::string status;
    std::string error_message;
};


enum class FutOptConditionPriceType: int32_t {
    LIMIT = 1,
    MARKET = 2,
    BID_PRICE = 3,
    ASK_PRICE = 4,
    MATCHED_PRICE = 5,
    LIMIT_UP = 6,
    LIMIT_DOWN = 7,
    REFERENCE = 8,
    RANGE_MARKET = 9
};


enum class OrderType: int32_t {
    STOCK = 1,
    MARGIN = 2,
    SHORT = 3,
    SBL = 4,
    DAY_TRADE = 5,
    UN_SUPPORTED = 6,
    UN_DEFINED = 7
};


enum class FutOptPriceType: int32_t {
    LIMIT = 1,
    MARKET = 2,
    RANGE_MARKET = 3,
    REFERENCE = 4,
    UN_SUPPORTED = 5,
    UN_DEFINED = 6
};


struct ConditionOrderResult {
    std::optional<std::string> guid;
};


struct BankRemain {
    std::string branch_no;
    std::string account;
    std::string currency;
    int64_t balance;
    int64_t available_balance;
};


enum class Direction: int32_t {
    UP = 1,
    DOWN = 2
};


enum class TriggerContent: int32_t {
    BID_PRICE = 1,
    ASK_PRICE = 2,
    MATCHED_PRICE = 3,
    TOTAL_QUANTITY = 4,
    TIME = 5,
    TOTAL_VALUE = 6
};


struct Account {
    std::string name;
    std::string branch_no;
    std::string account;
    std::string account_type;
};


enum class TimeInForce: int32_t {
    ROD = 1,
    FOK = 2,
    IOC = 3,
    UN_SUPPORTED = 4,
    UN_DEFINED = 5
};


struct InventoryOdd {
    int32_t lastday_qty;
    int32_t buy_qty;
    int32_t buy_filled_qty;
    int32_t buy_value;
    int32_t today_qty;
    int32_t tradable_qty;
    int32_t sell_qty;
    int32_t sell_filled_qty;
    int32_t sell_value;
};


enum class TradingType: int32_t {
    REFERENCE = 1,
    INDEX = 2,
    SCHEDULED = 3
};


struct SymbolQuote {
    std::string market;
    std::string symbol;
    bool istib_or_psb;
    MarketType market_type;
    std::optional<int32_t> status;
    std::optional<double> reference_price;
    int32_t unit;
    std::string update_time;
    std::optional<double> limitup_price;
    std::optional<double> limitdown_price;
    std::optional<double> open_price;
    std::optional<double> high_price;
    std::optional<double> low_price;
    std::optional<double> last_price;
    std::optional<int64_t> total_volume;
    std::optional<int64_t> total_transaction;
    std::optional<int64_t> total_value;
    std::optional<int64_t> last_size;
    std::optional<int64_t> last_transaction;
    std::optional<int64_t> last_value;
    std::optional<double> bid_price;
    std::optional<int64_t> bid_volume;
    std::optional<double> ask_price;
    std::optional<int64_t> ask_volume;
};


struct CancelResult {
    Reply reply;
};


struct LoginResponse {
    bool is_success;
    std::optional<std::vector<Account>> data;
    std::optional<std::string> message;
};


struct ConditionDayTrade {
    std::string day_trade_end_time;
    bool auto_cancel;
    std::optional<std::string> price;
    ConditionPriceType price_type;
};


struct SettlementData {
    AccountRes account;
    std::optional<std::vector<Settlement>> details;
};


struct Inventory {
    std::string date;
    std::string account;
    std::string branch_no;
    std::string stock_no;
    OrderType order_type;
    int32_t lastday_qty;
    int32_t buy_qty;
    int32_t buy_filled_qty;
    int32_t buy_value;
    int32_t today_qty;
    int32_t tradable_qty;
    int32_t sell_qty;
    int32_t sell_filled_qty;
    int32_t sell_value;
    InventoryOdd odd;
};


struct Condition {
    TradingType market_type;
    std::string symbol;
    TriggerContent trigger;
    std::string trigger_value;
    Operator comparison;
};


struct FutOptModifyPrice {
    /**
     * 委託單號
     */
    std::string txse;
    /**
     * 委託書號
     */
    std::string order_no;
    /**
     * 日期
     */
    std::string date;
    /**
     * 資產類別
     */
    std::string asty;
    FutOptMarketType market_type;
    FutOptPriceType price_type;
    /**
     * 商品代碼
     */
    std::string stock_no;
    /**
     * 異動後有效價格
     */
    std::optional<std::string> new_price;
    /**
     * 價格別異動
     */
    std::optional<FutOptPriceType> new_price_type;
};


struct VecRecoverResponse {
    bool is_success;
    std::optional<std::vector<Recover>> data;
    std::optional<std::string> message;
};


struct MaintenanceDetail {
    std::string stock_no;
    std::string order_no;
    std::optional<OrderType> order_type;
    std::optional<int64_t> quantity;
    std::optional<double> price;
    std::optional<double> cost_price;
    std::optional<int64_t> shortsell_margin;
    std::optional<double> collateral;
    std::optional<int64_t> margin_loan_amt;
    std::optional<double> maintenance_ratio;
    std::optional<double> collateral_interest;
    std::optional<double> margin_interest;
    std::optional<double> shortsell_interest;
};


struct MarginShortQuotaResponse {
    bool is_success;
    std::optional<MarginShortQuota> data;
    std::optional<std::string> message;
};


struct ConditionOrder {
    BsAction buy_sell;
    std::string symbol;
    std::optional<std::string> price;
    int64_t quantity;
    ConditionMarketType market_type;
    ConditionPriceType price_type;
    TimeInForce time_in_force;
    ConditionOrderType order_type;
};


struct SpreadPosition {
    std::string date;
    std::string branch_no;
    std::string account;
    int32_t position_kind;
    std::string symbol;
    std::string expiry_date;
    std::optional<double> strike_price;
    std::optional<CallPut> call_put;
    BsAction buy_sell;
    std::optional<double> price;
    int64_t orig_lots;
    int64_t tradable_lot;
    std::optional<FutOptOrderType> order_type;
    std::optional<std::string> currency;
    std::string market_price;
    double initial_margin;
    double maintenance_margin;
    double clearing_margin;
    double initial_margin_all_single;
    double opt_value;
    double opt_long_value;
    double opt_short_value;
    double profit_or_loss;
    double premium;
};


struct OrderResult {
    std::optional<int32_t> function_type;
    std::string date;
    std::string seq_no;
    std::string branch_no;
    std::string account;
    std::optional<std::string> order_no;
    std::optional<int32_t> asset_type;
    std::optional<std::string> market;
    MarketType market_type;
    std::optional<std::string> stock_no;
    std::optional<BsAction> buy_sell;
    std::optional<PriceType> price_type;
    std::optional<double> price;
    std::optional<int64_t> quantity;
    std::optional<TimeInForce> time_in_force;
    std::optional<OrderType> order_type;
    bool is_pre_order;
    std::optional<int32_t> status;
    std::optional<PriceType> after_price_type;
    std::optional<double> after_price;
    std::optional<int32_t> unit;
    std::optional<int32_t> after_qty;
    std::optional<int32_t> filled_qty;
    std::optional<int64_t> filled_money;
    std::optional<int32_t> before_qty;
    std::optional<double> before_price;
    std::optional<std::string> user_def;
    std::string last_time;
    std::optional<std::string> error_message;
    std::optional<std::vector<OrderDetail>> details;
};


struct FutOptTpslOrder {
    /**
     * ROD/FOK/IOC
     */
    TimeInForce time_in_force;
    /**
     * 價格別
     */
    FutOptConditionPriceType price_type;
    /**
     * 交易別
     */
    FutOptConditionOrderType order_type;
    /**
     * 價格
     */
    std::string target_price;
    /**
     * 價格
     */
    std::optional<std::string> price;
    std::optional<TriggerContent> trigger;
};


struct SdkRef {
    std::shared_ptr<StockFunctions> stock;
    std::shared_ptr<Accounting> accounting;
    std::shared_ptr<FutOptFunctions> futopt;
    std::shared_ptr<FutOptAccounting> futopt_accounting;
};


struct ConditionOrderResultResponse {
    bool is_success;
    std::optional<ConditionOrderResult> data;
    std::optional<std::string> message;
};


struct FilledData {
    std::string date;
    std::string branch_no;
    std::string account;
    std::string order_no;
    std::optional<std::string> seq_no;
    std::string stock_no;
    BsAction buy_sell;
    std::string filled_no;
    double filled_avg_price;
    int32_t filled_qty;
    double filled_price;
    OrderType order_type;
    std::string filled_time;
    std::optional<std::string> user_def;
};


struct TrailOrder {
    std::string symbol;
    std::string price;
    Direction direction;
    int32_t percentage;
    BsAction buy_sell;
    int64_t quantity;
    ConditionPriceType price_type;
    int32_t diff;
    TimeInForce time_in_force;
    ConditionOrderType order_type;
};


struct ModifyQuantity {
    /**
     * 委託單號
     */
    std::string txse;
    /**
     * 委託書號
     */
    std::string order_no;
    /**
     * 日期
     */
    std::string date;
    MarketType market_type;
    /**
     * 資產類別
     */
    std::string asty;
    std::string stock_no;
    int64_t new_quantity;
};


struct FutOptFilledData {
    std::string date;
    std::string branch_no;
    std::string account;
    std::string order_no;
    std::optional<std::string> seq_no;
    std::string symbol;
    BsAction buy_sell;
    std::string filled_no;
    double filled_avg_price;
    int32_t filled_lot;
    double filled_price;
    FutOptOrderType order_type;
    std::string filled_time;
    std::optional<std::string> expiry_date;
    std::optional<double> strike_price;
    std::optional<CallPut> call_put;
    std::optional<std::string> symbol_leg2;
    std::optional<std::string> expiry_date_leg2;
    std::optional<double> strike_price_leg2;
    std::optional<CallPut> call_put_leg2;
    std::optional<BsAction> buy_sell_leg2;
    std::optional<std::string> user_def;
};


struct FutOptOrder {
    BsAction buy_sell;
    std::string symbol;
    std::optional<BsAction> buy_sell2;
    std::optional<std::string> symbol2;
    std::optional<std::string> price;
    int64_t lot;
    FutOptMarketType market_type;
    FutOptPriceType price_type;
    TimeInForce time_in_force;
    FutOptOrderType order_type;
    std::optional<std::string> user_def;
};


struct RealizedSummary {
    std::string start_date;
    std::string end_date;
    std::string branch_no;
    std::string account;
    std::string stock_no;
    BsAction buy_sell;
    OrderType order_type;
    int32_t filled_qty;
    double filled_avg_price;
    int64_t realized_profit_and_loss;
};


struct BankRemainResponse {
    bool is_success;
    std::optional<BankRemain> data;
    std::optional<std::string> message;
};


struct BatchResponse {
    bool is_success;
    std::optional<std::vector<BatchResult>> data;
    std::optional<std::string> message;
};


struct CloseRecord {
    std::string date;
    std::string branch_no;
    std::string account;
    int32_t position_kind;
    std::string order_no;
    FutOptOrderType order_type;
    std::string market;
    std::string symbol;
    std::string expiry_date;
    std::optional<double> strike_price;
    std::optional<CallPut> call_put;
    BsAction buy_sell;
    double price;
    int32_t orig_lots;
    std::optional<double> transaction_fee;
    std::optional<double> tax;
};


struct Position {
    std::string date;
    std::string branch_no;
    std::string account;
    int32_t position_kind;
    std::string order_no;
    std::string symbol;
    std::string expiry_date;
    std::optional<double> strike_price;
    std::optional<CallPut> call_put;
    BsAction buy_sell;
    std::optional<double> price;
    int64_t orig_lots;
    int64_t tradable_lot;
    std::optional<FutOptOrderType> order_type;
    std::optional<std::string> currency;
    double profit_or_loss;
    std::string market_price;
    double initial_margin;
    double maintenance_margin;
    double clearing_margin;
    double premium;
};


struct SplitDescription {
    TimeSliceOrderType method;
    int32_t interval;
    int64_t single_quantity;
    std::optional<int64_t> total_quantity;
    std::string start_time;
    std::optional<std::string> end_time;
};


struct ConditionDetail {
    std::string guid;
    std::string batch_no;
    std::string order_level;
    std::string last_time;
    std::optional<std::string> condition_type;
    std::optional<std::string> parent_guid;
    std::string symbol;
    std::string order_amount;
    std::string child_batch_no;
    std::string account;
    std::string condition_content;
    std::string action;
    std::string condition_buy_sell;
    std::string condition_symbol;
    std::string condition_price;
    std::string condition_volume;
    std::string condition_filled_volume;
    std::string create_time;
    std::string start_date;
    std::string status;
    std::optional<std::string> error_message;
    std::string detail_records_count;
    std::string tpsl_count;
    std::vector<ParentChildRecord> detail_records;
    std::vector<ParentChildRecord> tpsl_record;
};


struct Unrealized {
    std::string date;
    std::string account;
    std::string branch_no;
    std::string stock_no;
    BsAction buy_sell;
    OrderType order_type;
    double cost_price;
    int64_t tradable_qty;
    int64_t today_qty;
    int32_t unrealized_profit;
    int32_t unrealized_loss;
};


struct ConditionResult {
    ConditionOrderResult smart_order_response;
    Reply reply;
};


struct FutOptTrailOrder {
    std::string symbol;
    std::string price;
    Direction direction;
    int32_t tick_num;
    BsAction buy_sell;
    int64_t lot;
    FutOptConditionPriceType price_type;
    int32_t diff;
    TimeInForce time_in_force;
    FutOptConditionOrderType order_type;
};


struct FutOptOrderResult {
    std::optional<int32_t> function_type;
    std::string date;
    std::string seq_no;
    std::string branch_no;
    std::string account;
    std::optional<std::string> order_no;
    std::optional<int32_t> asset_type;
    std::optional<std::string> market;
    FutOptMarketType market_type;
    std::optional<std::string> symbol;
    std::optional<int32_t> unit;
    std::optional<std::string> currency;
    std::optional<std::string> expiry_date;
    std::optional<double> strike_price;
    std::optional<CallPut> call_put;
    std::optional<BsAction> buy_sell;
    std::optional<std::string> symbol_leg2;
    std::optional<std::string> expiry_date_leg2;
    std::optional<double> strike_price_leg2;
    std::optional<CallPut> call_put_leg2;
    std::optional<BsAction> buy_sell_leg2;
    std::optional<FutOptPriceType> price_type;
    std::optional<double> price;
    std::optional<double> after_price;
    std::optional<int64_t> lot;
    std::optional<int32_t> after_lot;
    std::optional<TimeInForce> time_in_force;
    std::optional<FutOptOrderType> order_type;
    std::optional<int32_t> status;
    bool is_pre_order;
    std::optional<FutOptPriceType> after_price_type;
    std::optional<int32_t> filled_lot;
    std::optional<double> filled_money;
    std::optional<int32_t> before_lot;
    std::optional<double> before_price;
    std::optional<std::string> user_def;
    std::string last_time;
    std::optional<std::string> error_message;
    std::optional<std::vector<FutOptOrderDetail>> details;
};


struct Order {
    BsAction buy_sell;
    std::string symbol;
    std::optional<std::string> price;
    int64_t quantity;
    MarketType market_type;
    PriceType price_type;
    TimeInForce time_in_force;
    OrderType order_type;
    std::optional<std::string> user_def;
};


struct TpslOrder {
    /**
     * ROD/FOK/IOC
     */
    TimeInForce time_in_force;
    /**
     * 價格別
     */
    ConditionPriceType price_type;
    /**
     * 交易別
     */
    ConditionOrderType order_type;
    /**
     * 價格
     */
    std::string target_price;
    /**
     * 價格
     */
    std::optional<std::string> price;
    std::optional<TriggerContent> trigger;
};


struct FutOptConditionOrder {
    BsAction buy_sell;
    std::string symbol;
    std::optional<std::string> price;
    std::optional<int64_t> lot;
    FutOptConditionMarketType market_type;
    FutOptConditionPriceType price_type;
    TimeInForce time_in_force;
    FutOptConditionOrderType order_type;
};


struct Realized {
    std::string date;
    std::string branch_no;
    std::string account;
    std::string stock_no;
    BsAction buy_sell;
    int32_t filled_qty;
    double filled_price;
    OrderType order_type;
    int32_t realized_profit;
    int32_t realized_loss;
};


struct EstimateMarginResponse {
    bool is_success;
    std::optional<EstimateMargin> data;
    std::optional<std::string> message;
};


struct DayTradeStockInfoResponse {
    bool is_success;
    std::optional<DayTradeStockInfo> data;
    std::optional<std::string> message;
};


struct FutOptModifyLot {
    /**
     * 委託單號
     */
    std::string txse;
    /**
     * 委託書號
     */
    std::string order_no;
    /**
     * 日期
     */
    std::string date;
    FutOptMarketType market_type;
    /**
     * 資產類別
     */
    std::string asty;
    std::string symbol;
    int64_t new_quantity;
};


struct VecEquityResponse {
    bool is_success;
    std::optional<std::vector<Equity>> data;
    std::optional<std::string> message;
};


struct ModifyPrice {
    /**
     * 委託單號
     */
    std::string txse;
    /**
     * 委託書號
     */
    std::string order_no;
    /**
     * 日期
     */
    std::string date;
    /**
     * 資產類別
     */
    std::string asty;
    PriceType price_type;
    /**
     * 商品代碼
     */
    std::string stock_no;
    /**
     * 異動後有效價格
     */
    std::optional<std::string> new_price;
    /**
     * 價格別異動
     */
    std::optional<PriceType> new_price_type;
};


struct VecFutOptPositionResponse {
    bool is_success;
    std::optional<std::vector<Position>> data;
    std::optional<std::string> message;
};


struct VecFutOptFilledResponse {
    bool is_success;
    std::optional<std::vector<FutOptFilledData>> data;
    std::optional<std::string> message;
};


struct SymbolQuoteResponse {
    bool is_success;
    std::optional<SymbolQuote> data;
    std::optional<std::string> message;
};


struct FutOptOrderResponse {
    bool is_success;
    std::optional<FutOptOrderResult> data;
    std::optional<std::string> message;
};


struct RealizedResponse {
    bool is_success;
    std::optional<std::vector<Realized>> data;
    std::optional<std::string> message;
};


struct SettlementResponse {
    bool is_success;
    std::optional<SettlementData> data;
    std::optional<std::string> message;
};


struct OrderResponse {
    bool is_success;
    std::optional<OrderResult> data;
    std::optional<std::string> message;
};


struct UnRealizedResponse {
    bool is_success;
    std::optional<std::vector<Unrealized>> data;
    std::optional<std::string> message;
};


struct VecCloseRecordResponse {
    bool is_success;
    std::optional<std::vector<CloseRecord>> data;
    std::optional<std::string> message;
};


struct VecOrderResponse {
    bool is_success;
    std::optional<std::vector<OrderResult>> data;
    std::optional<std::string> message;
};


struct VecConditionDetailResponse {
    bool is_success;
    std::optional<std::vector<ConditionDetail>> data;
    std::optional<std::string> message;
};


struct VecSymbolQuoteResponse {
    bool is_success;
    std::optional<std::vector<SymbolQuote>> data;
    std::optional<std::string> message;
};


struct VecFutOptOrderResponse {
    bool is_success;
    std::optional<std::vector<FutOptOrderResult>> data;
    std::optional<std::string> message;
};


struct FilledResponse {
    bool is_success;
    std::optional<std::vector<FilledData>> data;
    std::optional<std::string> message;
};


struct InventoryResponse {
    bool is_success;
    std::optional<std::vector<Inventory>> data;
    std::optional<std::string> message;
};


struct MaintenanceData {
    std::string date;
    std::string branch_no;
    std::string account;
    MaintenanceSummary maintenance_summary;
    std::vector<MaintenanceDetail> maintenance_detail;
};


struct HybridPosition {
    std::string date;
    std::string branch_no;
    std::string account;
    bool is_spread;
    int32_t position_kind;
    std::string symbol;
    std::string expiry_date;
    std::optional<double> strike_price;
    std::optional<CallPut> call_put;
    BsAction buy_sell;
    std::optional<double> price;
    int64_t orig_lots;
    int64_t tradable_lot;
    std::optional<FutOptOrderType> order_type;
    std::optional<std::string> currency;
    std::string market_price;
    double initial_margin;
    double maintenance_margin;
    double clearing_margin;
    double initial_margin_all_single;
    double opt_value;
    double opt_long_value;
    double opt_short_value;
    double profit_or_loss;
    double premium;
    std::optional<std::vector<SpreadPosition>> spreads;
};


struct RealizedSummaryResponse {
    bool is_success;
    std::optional<std::vector<RealizedSummary>> data;
    std::optional<std::string> message;
};


struct FutOptTPSLWrapper {
    StopSign stop_sign;
    std::optional<FutOptTpslOrder> tp;
    std::optional<FutOptTpslOrder> sl;
    std::optional<std::string> end_date;
    std::optional<bool> intraday;
};


struct ConditionDetailResult {
    std::optional<std::vector<ConditionDetail>> responses;
    Reply reply;
};


struct TPSLWrapper {
    StopSign stop_sign;
    std::optional<TpslOrder> tp;
    std::optional<TpslOrder> sl;
    std::optional<std::string> end_date;
    std::optional<bool> intraday;
};


struct MaintenanceResponse {
    bool is_success;
    std::optional<MaintenanceData> data;
    std::optional<std::string> message;
};


struct VecFutOptHybridPositionResponse {
    bool is_success;
    std::optional<std::vector<HybridPosition>> data;
    std::optional<std::string> message;
};

namespace uniffi {
    struct FfiConverterFubonCore;
} // namespace uniffi

struct FubonCore {
    friend uniffi::FfiConverterFubonCore;

    FubonCore() = delete;

    FubonCore(const FubonCore &) = delete;
    FubonCore(FubonCore &&) = delete;

    FubonCore &operator=(const FubonCore &) = delete;
    FubonCore &operator=(FubonCore &&) = delete;

    ~FubonCore();
    static std::shared_ptr<FubonCore> init(std::optional<uint64_t> pong_inteval, std::optional<int64_t> missed_count, std::optional<std::string> url);
    LoginResponse dma_login(const std::string &personal_id, const std::string &password);
    std::string exchange_realtime_token();
    SdkRef get_ref();
    void inner_register_callback(const std::shared_ptr<Callback> &callback);
    /**
     * Login Fubon Neo with Your Account <br/>
     * <br/>
     * Args: <br/>
     * personalId ( string ) : Your fubon account ID. <br/>
     * password ( string ) : Your fubon account password <br/>
     * certPath ( string ) : Your certification path where you store <br/>
     * certPass ( string ) : Your certification password <br/>
     * <br/>
     * Returns: <br/>
     * A list  having account information ( if it  have multiple account, it will return multiple account) <br/>
     * <br/>
     * For example : <br/>
     * { <br/>
     *    isSuccess = True, <br/>
     *    message = , <br/>
     *    data =[ <br/>
     *   { <br/>
     *    name = 富邦Bill, <br/>
     *    account = 28, <br/>
     *    branchNo = 6460, <br/>
     *    accountType = stock <br/>
     *    }, <br/>
     *    { <br/>
     *         name = 富邦Angle, <br/>
     *    account = 26, <br/>
     *    branchNo = 6460, <br/>
     *    accountType = stock <br/>
     *    } <br/>
     * ] <br/>
     *    } <br/>
     * } <br/>
     */
    LoginResponse login(const std::string &personal_id, const std::string &password, const std::string &cert_path, std::optional<std::string> cert_pass);
    bool logout();
    VecRecoverResponse recover_event_data();

private:
    FubonCore(void *);

    void *instance;
};

namespace uniffi {
    struct FfiConverterFugleRealtime;
} // namespace uniffi

struct FugleRealtime {
    friend uniffi::FfiConverterFugleRealtime;

    FugleRealtime() = delete;

    FugleRealtime(const FugleRealtime &) = delete;
    FugleRealtime(FugleRealtime &&) = delete;

    FugleRealtime &operator=(const FugleRealtime &) = delete;
    FugleRealtime &operator=(FugleRealtime &&) = delete;

    ~FugleRealtime();
    static std::shared_ptr<FugleRealtime> init();
    std::string fubon_ws_url();
    std::string realtime_rest_url();
    std::string realtime_ws_normal_url();
    std::string realtime_ws_speed_url();

private:
    FugleRealtime(void *);

    void *instance;
};


struct StringResponse {
    bool is_success;
    std::optional<std::string> data;
    std::optional<std::string> message;
};


enum class ConditionStatus: int32_t {
    TYPE1 = 1,
    TYPE2 = 2,
    TYPE3 = 3,
    TYPE4 = 4,
    TYPE5 = 5,
    TYPE6 = 6,
    TYPE7 = 7,
    TYPE8 = 8,
    TYPE9 = 9,
    TYPE10 = 10,
    TYPE11 = 11
};

namespace uniffi {
struct FfiConverterTypeFubonError;
} // namespace uniffi

struct FubonError: std::runtime_error {
    friend uniffi::FfiConverterTypeFubonError;

    FubonError() : std::runtime_error("") {}
    FubonError(const std::string &what_arg) : std::runtime_error(what_arg) {}

    virtual void throw_underlying() = 0;

    virtual ~FubonError() = default;
protected:
    virtual int32_t get_variant_idx() const {
        return 0;
    };
};
/**
 * Contains variants of FubonError
 */
namespace fubon_error {

struct AccountTypeError: FubonError {

    AccountTypeError() : FubonError("") {}
    AccountTypeError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 1;
    }
};

struct ResponseError: FubonError {

    ResponseError() : FubonError("") {}
    ResponseError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 2;
    }
};

struct LoginError2: FubonError {

    LoginError2() : FubonError("") {}
    LoginError2(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 3;
    }
};

struct LoginError: FubonError {

    LoginError() : FubonError("") {}
    LoginError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 4;
    }
};

struct NotLoginError: FubonError {

    NotLoginError() : FubonError("") {}
    NotLoginError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 5;
    }
};

struct CertError: FubonError {

    CertError() : FubonError("") {}
    CertError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 6;
    }
};

struct OtherError: FubonError {

    OtherError() : FubonError("") {}
    OtherError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 7;
    }
};

struct ConfigUrlError: FubonError {

    ConfigUrlError() : FubonError("") {}
    ConfigUrlError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 8;
    }
};

struct TwoFactorLoginError: FubonError {

    TwoFactorLoginError() : FubonError("") {}
    TwoFactorLoginError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 9;
    }
};

struct OrderCheckError: FubonError {

    OrderCheckError() : FubonError("") {}
    OrderCheckError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 10;
    }
};

struct DmaError: FubonError {

    DmaError() : FubonError("") {}
    DmaError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 11;
    }
};

struct ResponseProtocalError: FubonError {

    ResponseProtocalError() : FubonError("") {}
    ResponseProtocalError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 12;
    }
};

struct NoDmaIpError: FubonError {

    NoDmaIpError() : FubonError("") {}
    NoDmaIpError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 13;
    }
};

struct RealtimeError: FubonError {

    RealtimeError() : FubonError("") {}
    RealtimeError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 14;
    }
};

struct MaintenanceDataFormatError: FubonError {

    MaintenanceDataFormatError() : FubonError("") {}
    MaintenanceDataFormatError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 15;
    }
};

struct EmptyTargetResponseError: FubonError {

    EmptyTargetResponseError() : FubonError("") {}
    EmptyTargetResponseError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 16;
    }
};

struct EmptyDataError: FubonError {

    EmptyDataError() : FubonError("") {}
    EmptyDataError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 17;
    }
};

struct ResponseParseError: FubonError {

    ResponseParseError() : FubonError("") {}
    ResponseParseError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 18;
    }
};

struct ResponseFormatError: FubonError {

    ResponseFormatError() : FubonError("") {}
    ResponseFormatError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 19;
    }
};

struct NoTradeAccountError: FubonError {

    NoTradeAccountError() : FubonError("") {}
    NoTradeAccountError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 20;
    }
};

struct CanNotModifyError: FubonError {

    CanNotModifyError() : FubonError("") {}
    CanNotModifyError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 21;
    }
};

struct ContractError: FubonError {

    ContractError() : FubonError("") {}
    ContractError(const std::string &what_arg) : FubonError(what_arg) {}

    void throw_underlying() override {
        throw *this;
    }

    int32_t get_variant_idx() const override {
        return 22;
    }
};
} // namespace fubon_error


enum class HistoryStatus: int32_t {
    TYPE1 = 1,
    TYPE2 = 2,
    TYPE3 = 3,
    TYPE4 = 4,
    TYPE5 = 5,
    TYPE6 = 6
};


enum class StockType: int32_t {
    STOCK = 1,
    COVERT_BOND = 2,
    ETF_AND_ETN = 3
};


struct Callback {
    
    virtual void on_order(std::optional<std::string> err, OrderResult data) = 0;
    
    virtual void on_order_changed(std::optional<std::string> err, OrderResult data) = 0;
    
    virtual void on_filled(std::optional<std::string> err, FilledData data) = 0;
    
    virtual void on_futopt_order(std::optional<std::string> err, FutOptOrderResult data) = 0;
    
    virtual void on_futopt_order_changed(std::optional<std::string> err, FutOptOrderResult data) = 0;
    
    virtual void on_futopt_filled(std::optional<std::string> err, FutOptFilledData data) = 0;
    
    virtual void on_event(std::string code, std::string data) = 0;

    virtual ~Callback() = default;
};

namespace uniffi {struct RustStreamBuffer: std::basic_streambuf<char> {
    RustStreamBuffer(RustBuffer *buf) {
        char* data = reinterpret_cast<char*>(buf->data);
        this->setg(data, data, data + buf->len);
        this->setp(data, data + buf->capacity);
    }
    ~RustStreamBuffer() = default;

private:
    RustStreamBuffer() = delete;
    RustStreamBuffer(const RustStreamBuffer &) = delete;
    RustStreamBuffer(RustStreamBuffer &&) = delete;

    RustStreamBuffer &operator=(const RustStreamBuffer &) = delete;
    RustStreamBuffer &operator=(RustStreamBuffer &&) = delete;
};

struct RustStream: std::basic_iostream<char> {
    RustStream(RustBuffer *buf):
        std::basic_iostream<char>(&streambuf), streambuf(RustStreamBuffer(buf)) { }

    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    RustStream &operator>>(T &val) {
        read(reinterpret_cast<char *>(&val), sizeof(T));

        if (std::endian::native != std::endian::big) {
            auto bytes = reinterpret_cast<char *>(&val);

            std::reverse(bytes, bytes + sizeof(T));
        }

        return *this;
    }

    template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
    RustStream &operator<<(T val) {
        if (std::endian::native != std::endian::big) {
            auto bytes = reinterpret_cast<char *>(&val);

            std::reverse(bytes, bytes + sizeof(T));
        }

        write(reinterpret_cast<char *>(&val), sizeof(T));

        return *this;
    }
private:
    RustStreamBuffer streambuf;
};


RustBuffer rustbuffer_alloc(int32_t);
RustBuffer rustbuffer_from_bytes(const ForeignBytes &);
void rustbuffer_free(RustBuffer);template <typename T> struct HandleMap {
    HandleMap() = default;

    std::shared_ptr<T> at(uint64_t handle) {
        std::lock_guard<std::mutex> guard(this->mutex);

        return this->map.at(handle);
    }

    uint64_t insert(std::shared_ptr<T> impl) {
        std::lock_guard<std::mutex> guard(this->mutex);

        auto handle = this->cur_handle;

        this->map.insert({ handle, impl });
        this->cur_handle += 1;

        return handle;
    }

    void erase(uint64_t handle) {
        std::lock_guard<std::mutex> guard(this->mutex);

        this->map.erase(handle);
    }
    private:
        HandleMap(const HandleMap<T> &) = delete;
        HandleMap(HandleMap<T> &&) = delete;

        HandleMap<T> &operator=(const HandleMap<T> &) = delete;
        HandleMap<T> &operator=(HandleMap<T> &&) = delete;

        std::mutex mutex;
        uint64_t cur_handle = 0;
        std::map<uint64_t, std::shared_ptr<T>> map;
};

struct FfiConverterInt32 {
    static int32_t lift(int32_t);
    static int32_t lower(int32_t);
    static int32_t read(RustStream &);
    static void write(RustStream &, int32_t);
    static int32_t allocation_size(int32_t);
};

struct FfiConverterUInt64 {
    static uint64_t lift(uint64_t);
    static uint64_t lower(uint64_t);
    static uint64_t read(RustStream &);
    static void write(RustStream &, uint64_t);
    static int32_t allocation_size(uint64_t);
};

struct FfiConverterInt64 {
    static int64_t lift(int64_t);
    static int64_t lower(int64_t);
    static int64_t read(RustStream &);
    static void write(RustStream &, int64_t);
    static int32_t allocation_size(int64_t);
};

struct FfiConverterDouble {
    static double lift(double);
    static double lower(double);
    static double read(RustStream &);
    static void write(RustStream &, double);
    static int32_t allocation_size(double);
};

struct FfiConverterBool {
    static bool lift(uint8_t);
    static uint8_t lower(bool);
    static bool read(RustStream &);
    static void write(RustStream &, bool);
    static int32_t allocation_size(bool);
};
struct FfiConverterString {
    static std::string lift(RustBuffer buf);
    static RustBuffer lower(const std::string &);
    static std::string read(RustStream &);
    static void write(RustStream &, const std::string &);
    static int32_t allocation_size(const std::string &);
};

struct FfiConverterAccounting {
    static std::shared_ptr<Accounting> lift(void *);
    static void *lower(const std::shared_ptr<Accounting> &);
    static std::shared_ptr<Accounting> read(RustStream &);
    static void write(RustStream &, const std::shared_ptr<Accounting> &);
    static int32_t allocation_size(const std::shared_ptr<Accounting> &);
};

struct FfiConverterFubonCore {
    static std::shared_ptr<FubonCore> lift(void *);
    static void *lower(const std::shared_ptr<FubonCore> &);
    static std::shared_ptr<FubonCore> read(RustStream &);
    static void write(RustStream &, const std::shared_ptr<FubonCore> &);
    static int32_t allocation_size(const std::shared_ptr<FubonCore> &);
};

struct FfiConverterFugleRealtime {
    static std::shared_ptr<FugleRealtime> lift(void *);
    static void *lower(const std::shared_ptr<FugleRealtime> &);
    static std::shared_ptr<FugleRealtime> read(RustStream &);
    static void write(RustStream &, const std::shared_ptr<FugleRealtime> &);
    static int32_t allocation_size(const std::shared_ptr<FugleRealtime> &);
};

struct FfiConverterFutOptAccounting {
    static std::shared_ptr<FutOptAccounting> lift(void *);
    static void *lower(const std::shared_ptr<FutOptAccounting> &);
    static std::shared_ptr<FutOptAccounting> read(RustStream &);
    static void write(RustStream &, const std::shared_ptr<FutOptAccounting> &);
    static int32_t allocation_size(const std::shared_ptr<FutOptAccounting> &);
};

struct FfiConverterFutOptFunctions {
    static std::shared_ptr<FutOptFunctions> lift(void *);
    static void *lower(const std::shared_ptr<FutOptFunctions> &);
    static std::shared_ptr<FutOptFunctions> read(RustStream &);
    static void write(RustStream &, const std::shared_ptr<FutOptFunctions> &);
    static int32_t allocation_size(const std::shared_ptr<FutOptFunctions> &);
};

struct FfiConverterStockFunctions {
    static std::shared_ptr<StockFunctions> lift(void *);
    static void *lower(const std::shared_ptr<StockFunctions> &);
    static std::shared_ptr<StockFunctions> read(RustStream &);
    static void write(RustStream &, const std::shared_ptr<StockFunctions> &);
    static int32_t allocation_size(const std::shared_ptr<StockFunctions> &);
};

struct FfiConverterTypeAccount {
    static Account lift(RustBuffer);
    static RustBuffer lower(const Account &);
    static Account read(RustStream &);
    static void write(RustStream &, const Account &);
    static int32_t allocation_size(const Account &);
};

struct FfiConverterTypeAccountRes {
    static AccountRes lift(RustBuffer);
    static RustBuffer lower(const AccountRes &);
    static AccountRes read(RustStream &);
    static void write(RustStream &, const AccountRes &);
    static int32_t allocation_size(const AccountRes &);
};

struct FfiConverterTypeBankRemain {
    static BankRemain lift(RustBuffer);
    static RustBuffer lower(const BankRemain &);
    static BankRemain read(RustStream &);
    static void write(RustStream &, const BankRemain &);
    static int32_t allocation_size(const BankRemain &);
};

struct FfiConverterTypeBankRemainResponse {
    static BankRemainResponse lift(RustBuffer);
    static RustBuffer lower(const BankRemainResponse &);
    static BankRemainResponse read(RustStream &);
    static void write(RustStream &, const BankRemainResponse &);
    static int32_t allocation_size(const BankRemainResponse &);
};

struct FfiConverterTypeBatchResponse {
    static BatchResponse lift(RustBuffer);
    static RustBuffer lower(const BatchResponse &);
    static BatchResponse read(RustStream &);
    static void write(RustStream &, const BatchResponse &);
    static int32_t allocation_size(const BatchResponse &);
};

struct FfiConverterTypeBatchResult {
    static BatchResult lift(RustBuffer);
    static RustBuffer lower(const BatchResult &);
    static BatchResult read(RustStream &);
    static void write(RustStream &, const BatchResult &);
    static int32_t allocation_size(const BatchResult &);
};

struct FfiConverterTypeCancelResult {
    static CancelResult lift(RustBuffer);
    static RustBuffer lower(const CancelResult &);
    static CancelResult read(RustStream &);
    static void write(RustStream &, const CancelResult &);
    static int32_t allocation_size(const CancelResult &);
};

struct FfiConverterTypeCloseRecord {
    static CloseRecord lift(RustBuffer);
    static RustBuffer lower(const CloseRecord &);
    static CloseRecord read(RustStream &);
    static void write(RustStream &, const CloseRecord &);
    static int32_t allocation_size(const CloseRecord &);
};

struct FfiConverterTypeCondition {
    static Condition lift(RustBuffer);
    static RustBuffer lower(const Condition &);
    static Condition read(RustStream &);
    static void write(RustStream &, const Condition &);
    static int32_t allocation_size(const Condition &);
};

struct FfiConverterTypeConditionDayTrade {
    static ConditionDayTrade lift(RustBuffer);
    static RustBuffer lower(const ConditionDayTrade &);
    static ConditionDayTrade read(RustStream &);
    static void write(RustStream &, const ConditionDayTrade &);
    static int32_t allocation_size(const ConditionDayTrade &);
};

struct FfiConverterTypeConditionDetail {
    static ConditionDetail lift(RustBuffer);
    static RustBuffer lower(const ConditionDetail &);
    static ConditionDetail read(RustStream &);
    static void write(RustStream &, const ConditionDetail &);
    static int32_t allocation_size(const ConditionDetail &);
};

struct FfiConverterTypeConditionDetailResult {
    static ConditionDetailResult lift(RustBuffer);
    static RustBuffer lower(const ConditionDetailResult &);
    static ConditionDetailResult read(RustStream &);
    static void write(RustStream &, const ConditionDetailResult &);
    static int32_t allocation_size(const ConditionDetailResult &);
};

struct FfiConverterTypeConditionOrder {
    static ConditionOrder lift(RustBuffer);
    static RustBuffer lower(const ConditionOrder &);
    static ConditionOrder read(RustStream &);
    static void write(RustStream &, const ConditionOrder &);
    static int32_t allocation_size(const ConditionOrder &);
};

struct FfiConverterTypeConditionOrderResult {
    static ConditionOrderResult lift(RustBuffer);
    static RustBuffer lower(const ConditionOrderResult &);
    static ConditionOrderResult read(RustStream &);
    static void write(RustStream &, const ConditionOrderResult &);
    static int32_t allocation_size(const ConditionOrderResult &);
};

struct FfiConverterTypeConditionOrderResultResponse {
    static ConditionOrderResultResponse lift(RustBuffer);
    static RustBuffer lower(const ConditionOrderResultResponse &);
    static ConditionOrderResultResponse read(RustStream &);
    static void write(RustStream &, const ConditionOrderResultResponse &);
    static int32_t allocation_size(const ConditionOrderResultResponse &);
};

struct FfiConverterTypeConditionResult {
    static ConditionResult lift(RustBuffer);
    static RustBuffer lower(const ConditionResult &);
    static ConditionResult read(RustStream &);
    static void write(RustStream &, const ConditionResult &);
    static int32_t allocation_size(const ConditionResult &);
};

struct FfiConverterTypeDayTradeStockInfo {
    static DayTradeStockInfo lift(RustBuffer);
    static RustBuffer lower(const DayTradeStockInfo &);
    static DayTradeStockInfo read(RustStream &);
    static void write(RustStream &, const DayTradeStockInfo &);
    static int32_t allocation_size(const DayTradeStockInfo &);
};

struct FfiConverterTypeDayTradeStockInfoResponse {
    static DayTradeStockInfoResponse lift(RustBuffer);
    static RustBuffer lower(const DayTradeStockInfoResponse &);
    static DayTradeStockInfoResponse read(RustStream &);
    static void write(RustStream &, const DayTradeStockInfoResponse &);
    static int32_t allocation_size(const DayTradeStockInfoResponse &);
};

struct FfiConverterTypeEquity {
    static Equity lift(RustBuffer);
    static RustBuffer lower(const Equity &);
    static Equity read(RustStream &);
    static void write(RustStream &, const Equity &);
    static int32_t allocation_size(const Equity &);
};

struct FfiConverterTypeEstimateMargin {
    static EstimateMargin lift(RustBuffer);
    static RustBuffer lower(const EstimateMargin &);
    static EstimateMargin read(RustStream &);
    static void write(RustStream &, const EstimateMargin &);
    static int32_t allocation_size(const EstimateMargin &);
};

struct FfiConverterTypeEstimateMarginResponse {
    static EstimateMarginResponse lift(RustBuffer);
    static RustBuffer lower(const EstimateMarginResponse &);
    static EstimateMarginResponse read(RustStream &);
    static void write(RustStream &, const EstimateMarginResponse &);
    static int32_t allocation_size(const EstimateMarginResponse &);
};

struct FfiConverterTypeFilledData {
    static FilledData lift(RustBuffer);
    static RustBuffer lower(const FilledData &);
    static FilledData read(RustStream &);
    static void write(RustStream &, const FilledData &);
    static int32_t allocation_size(const FilledData &);
};

struct FfiConverterTypeFilledResponse {
    static FilledResponse lift(RustBuffer);
    static RustBuffer lower(const FilledResponse &);
    static FilledResponse read(RustStream &);
    static void write(RustStream &, const FilledResponse &);
    static int32_t allocation_size(const FilledResponse &);
};

struct FfiConverterTypeFutOptConditionOrder {
    static FutOptConditionOrder lift(RustBuffer);
    static RustBuffer lower(const FutOptConditionOrder &);
    static FutOptConditionOrder read(RustStream &);
    static void write(RustStream &, const FutOptConditionOrder &);
    static int32_t allocation_size(const FutOptConditionOrder &);
};

struct FfiConverterTypeFutOptFilledData {
    static FutOptFilledData lift(RustBuffer);
    static RustBuffer lower(const FutOptFilledData &);
    static FutOptFilledData read(RustStream &);
    static void write(RustStream &, const FutOptFilledData &);
    static int32_t allocation_size(const FutOptFilledData &);
};

struct FfiConverterTypeFutOptModifyLot {
    static FutOptModifyLot lift(RustBuffer);
    static RustBuffer lower(const FutOptModifyLot &);
    static FutOptModifyLot read(RustStream &);
    static void write(RustStream &, const FutOptModifyLot &);
    static int32_t allocation_size(const FutOptModifyLot &);
};

struct FfiConverterTypeFutOptModifyPrice {
    static FutOptModifyPrice lift(RustBuffer);
    static RustBuffer lower(const FutOptModifyPrice &);
    static FutOptModifyPrice read(RustStream &);
    static void write(RustStream &, const FutOptModifyPrice &);
    static int32_t allocation_size(const FutOptModifyPrice &);
};

struct FfiConverterTypeFutOptOrder {
    static FutOptOrder lift(RustBuffer);
    static RustBuffer lower(const FutOptOrder &);
    static FutOptOrder read(RustStream &);
    static void write(RustStream &, const FutOptOrder &);
    static int32_t allocation_size(const FutOptOrder &);
};

struct FfiConverterTypeFutOptOrderDetail {
    static FutOptOrderDetail lift(RustBuffer);
    static RustBuffer lower(const FutOptOrderDetail &);
    static FutOptOrderDetail read(RustStream &);
    static void write(RustStream &, const FutOptOrderDetail &);
    static int32_t allocation_size(const FutOptOrderDetail &);
};

struct FfiConverterTypeFutOptOrderResponse {
    static FutOptOrderResponse lift(RustBuffer);
    static RustBuffer lower(const FutOptOrderResponse &);
    static FutOptOrderResponse read(RustStream &);
    static void write(RustStream &, const FutOptOrderResponse &);
    static int32_t allocation_size(const FutOptOrderResponse &);
};

struct FfiConverterTypeFutOptOrderResult {
    static FutOptOrderResult lift(RustBuffer);
    static RustBuffer lower(const FutOptOrderResult &);
    static FutOptOrderResult read(RustStream &);
    static void write(RustStream &, const FutOptOrderResult &);
    static int32_t allocation_size(const FutOptOrderResult &);
};

struct FfiConverterTypeFutOptTPSLOrder {
    static FutOptTpslOrder lift(RustBuffer);
    static RustBuffer lower(const FutOptTpslOrder &);
    static FutOptTpslOrder read(RustStream &);
    static void write(RustStream &, const FutOptTpslOrder &);
    static int32_t allocation_size(const FutOptTpslOrder &);
};

struct FfiConverterTypeFutOptTPSLWrapper {
    static FutOptTPSLWrapper lift(RustBuffer);
    static RustBuffer lower(const FutOptTPSLWrapper &);
    static FutOptTPSLWrapper read(RustStream &);
    static void write(RustStream &, const FutOptTPSLWrapper &);
    static int32_t allocation_size(const FutOptTPSLWrapper &);
};

struct FfiConverterTypeFutOptTrailOrder {
    static FutOptTrailOrder lift(RustBuffer);
    static RustBuffer lower(const FutOptTrailOrder &);
    static FutOptTrailOrder read(RustStream &);
    static void write(RustStream &, const FutOptTrailOrder &);
    static int32_t allocation_size(const FutOptTrailOrder &);
};

struct FfiConverterTypeHybridPosition {
    static HybridPosition lift(RustBuffer);
    static RustBuffer lower(const HybridPosition &);
    static HybridPosition read(RustStream &);
    static void write(RustStream &, const HybridPosition &);
    static int32_t allocation_size(const HybridPosition &);
};

struct FfiConverterTypeInventory {
    static Inventory lift(RustBuffer);
    static RustBuffer lower(const Inventory &);
    static Inventory read(RustStream &);
    static void write(RustStream &, const Inventory &);
    static int32_t allocation_size(const Inventory &);
};

struct FfiConverterTypeInventoryOdd {
    static InventoryOdd lift(RustBuffer);
    static RustBuffer lower(const InventoryOdd &);
    static InventoryOdd read(RustStream &);
    static void write(RustStream &, const InventoryOdd &);
    static int32_t allocation_size(const InventoryOdd &);
};

struct FfiConverterTypeInventoryResponse {
    static InventoryResponse lift(RustBuffer);
    static RustBuffer lower(const InventoryResponse &);
    static InventoryResponse read(RustStream &);
    static void write(RustStream &, const InventoryResponse &);
    static int32_t allocation_size(const InventoryResponse &);
};

struct FfiConverterTypeLoginResponse {
    static LoginResponse lift(RustBuffer);
    static RustBuffer lower(const LoginResponse &);
    static LoginResponse read(RustStream &);
    static void write(RustStream &, const LoginResponse &);
    static int32_t allocation_size(const LoginResponse &);
};

struct FfiConverterTypeMaintenanceData {
    static MaintenanceData lift(RustBuffer);
    static RustBuffer lower(const MaintenanceData &);
    static MaintenanceData read(RustStream &);
    static void write(RustStream &, const MaintenanceData &);
    static int32_t allocation_size(const MaintenanceData &);
};

struct FfiConverterTypeMaintenanceDetail {
    static MaintenanceDetail lift(RustBuffer);
    static RustBuffer lower(const MaintenanceDetail &);
    static MaintenanceDetail read(RustStream &);
    static void write(RustStream &, const MaintenanceDetail &);
    static int32_t allocation_size(const MaintenanceDetail &);
};

struct FfiConverterTypeMaintenanceResponse {
    static MaintenanceResponse lift(RustBuffer);
    static RustBuffer lower(const MaintenanceResponse &);
    static MaintenanceResponse read(RustStream &);
    static void write(RustStream &, const MaintenanceResponse &);
    static int32_t allocation_size(const MaintenanceResponse &);
};

struct FfiConverterTypeMaintenanceSummary {
    static MaintenanceSummary lift(RustBuffer);
    static RustBuffer lower(const MaintenanceSummary &);
    static MaintenanceSummary read(RustStream &);
    static void write(RustStream &, const MaintenanceSummary &);
    static int32_t allocation_size(const MaintenanceSummary &);
};

struct FfiConverterTypeMarginShortQuota {
    static MarginShortQuota lift(RustBuffer);
    static RustBuffer lower(const MarginShortQuota &);
    static MarginShortQuota read(RustStream &);
    static void write(RustStream &, const MarginShortQuota &);
    static int32_t allocation_size(const MarginShortQuota &);
};

struct FfiConverterTypeMarginShortQuotaResponse {
    static MarginShortQuotaResponse lift(RustBuffer);
    static RustBuffer lower(const MarginShortQuotaResponse &);
    static MarginShortQuotaResponse read(RustStream &);
    static void write(RustStream &, const MarginShortQuotaResponse &);
    static int32_t allocation_size(const MarginShortQuotaResponse &);
};

struct FfiConverterTypeModifyPrice {
    static ModifyPrice lift(RustBuffer);
    static RustBuffer lower(const ModifyPrice &);
    static ModifyPrice read(RustStream &);
    static void write(RustStream &, const ModifyPrice &);
    static int32_t allocation_size(const ModifyPrice &);
};

struct FfiConverterTypeModifyQuantity {
    static ModifyQuantity lift(RustBuffer);
    static RustBuffer lower(const ModifyQuantity &);
    static ModifyQuantity read(RustStream &);
    static void write(RustStream &, const ModifyQuantity &);
    static int32_t allocation_size(const ModifyQuantity &);
};

struct FfiConverterTypeOrder {
    static Order lift(RustBuffer);
    static RustBuffer lower(const Order &);
    static Order read(RustStream &);
    static void write(RustStream &, const Order &);
    static int32_t allocation_size(const Order &);
};

struct FfiConverterTypeOrderDetail {
    static OrderDetail lift(RustBuffer);
    static RustBuffer lower(const OrderDetail &);
    static OrderDetail read(RustStream &);
    static void write(RustStream &, const OrderDetail &);
    static int32_t allocation_size(const OrderDetail &);
};

struct FfiConverterTypeOrderResponse {
    static OrderResponse lift(RustBuffer);
    static RustBuffer lower(const OrderResponse &);
    static OrderResponse read(RustStream &);
    static void write(RustStream &, const OrderResponse &);
    static int32_t allocation_size(const OrderResponse &);
};

struct FfiConverterTypeOrderResult {
    static OrderResult lift(RustBuffer);
    static RustBuffer lower(const OrderResult &);
    static OrderResult read(RustStream &);
    static void write(RustStream &, const OrderResult &);
    static int32_t allocation_size(const OrderResult &);
};

struct FfiConverterTypeParentChildRecord {
    static ParentChildRecord lift(RustBuffer);
    static RustBuffer lower(const ParentChildRecord &);
    static ParentChildRecord read(RustStream &);
    static void write(RustStream &, const ParentChildRecord &);
    static int32_t allocation_size(const ParentChildRecord &);
};

struct FfiConverterTypePosition {
    static Position lift(RustBuffer);
    static RustBuffer lower(const Position &);
    static Position read(RustStream &);
    static void write(RustStream &, const Position &);
    static int32_t allocation_size(const Position &);
};

struct FfiConverterTypeRealized {
    static Realized lift(RustBuffer);
    static RustBuffer lower(const Realized &);
    static Realized read(RustStream &);
    static void write(RustStream &, const Realized &);
    static int32_t allocation_size(const Realized &);
};

struct FfiConverterTypeRealizedResponse {
    static RealizedResponse lift(RustBuffer);
    static RustBuffer lower(const RealizedResponse &);
    static RealizedResponse read(RustStream &);
    static void write(RustStream &, const RealizedResponse &);
    static int32_t allocation_size(const RealizedResponse &);
};

struct FfiConverterTypeRealizedSummary {
    static RealizedSummary lift(RustBuffer);
    static RustBuffer lower(const RealizedSummary &);
    static RealizedSummary read(RustStream &);
    static void write(RustStream &, const RealizedSummary &);
    static int32_t allocation_size(const RealizedSummary &);
};

struct FfiConverterTypeRealizedSummaryResponse {
    static RealizedSummaryResponse lift(RustBuffer);
    static RustBuffer lower(const RealizedSummaryResponse &);
    static RealizedSummaryResponse read(RustStream &);
    static void write(RustStream &, const RealizedSummaryResponse &);
    static int32_t allocation_size(const RealizedSummaryResponse &);
};

struct FfiConverterTypeRecover {
    static Recover lift(RustBuffer);
    static RustBuffer lower(const Recover &);
    static Recover read(RustStream &);
    static void write(RustStream &, const Recover &);
    static int32_t allocation_size(const Recover &);
};

struct FfiConverterTypeReply {
    static Reply lift(RustBuffer);
    static RustBuffer lower(const Reply &);
    static Reply read(RustStream &);
    static void write(RustStream &, const Reply &);
    static int32_t allocation_size(const Reply &);
};

struct FfiConverterTypeSdkRef {
    static SdkRef lift(RustBuffer);
    static RustBuffer lower(const SdkRef &);
    static SdkRef read(RustStream &);
    static void write(RustStream &, const SdkRef &);
    static int32_t allocation_size(const SdkRef &);
};

struct FfiConverterTypeSettlement {
    static Settlement lift(RustBuffer);
    static RustBuffer lower(const Settlement &);
    static Settlement read(RustStream &);
    static void write(RustStream &, const Settlement &);
    static int32_t allocation_size(const Settlement &);
};

struct FfiConverterTypeSettlementData {
    static SettlementData lift(RustBuffer);
    static RustBuffer lower(const SettlementData &);
    static SettlementData read(RustStream &);
    static void write(RustStream &, const SettlementData &);
    static int32_t allocation_size(const SettlementData &);
};

struct FfiConverterTypeSettlementResponse {
    static SettlementResponse lift(RustBuffer);
    static RustBuffer lower(const SettlementResponse &);
    static SettlementResponse read(RustStream &);
    static void write(RustStream &, const SettlementResponse &);
    static int32_t allocation_size(const SettlementResponse &);
};

struct FfiConverterTypeSplitDescription {
    static SplitDescription lift(RustBuffer);
    static RustBuffer lower(const SplitDescription &);
    static SplitDescription read(RustStream &);
    static void write(RustStream &, const SplitDescription &);
    static int32_t allocation_size(const SplitDescription &);
};

struct FfiConverterTypeSpreadPosition {
    static SpreadPosition lift(RustBuffer);
    static RustBuffer lower(const SpreadPosition &);
    static SpreadPosition read(RustStream &);
    static void write(RustStream &, const SpreadPosition &);
    static int32_t allocation_size(const SpreadPosition &);
};

struct FfiConverterTypeStringResponse {
    static StringResponse lift(RustBuffer);
    static RustBuffer lower(const StringResponse &);
    static StringResponse read(RustStream &);
    static void write(RustStream &, const StringResponse &);
    static int32_t allocation_size(const StringResponse &);
};

struct FfiConverterTypeSymbolQuote {
    static SymbolQuote lift(RustBuffer);
    static RustBuffer lower(const SymbolQuote &);
    static SymbolQuote read(RustStream &);
    static void write(RustStream &, const SymbolQuote &);
    static int32_t allocation_size(const SymbolQuote &);
};

struct FfiConverterTypeSymbolQuoteResponse {
    static SymbolQuoteResponse lift(RustBuffer);
    static RustBuffer lower(const SymbolQuoteResponse &);
    static SymbolQuoteResponse read(RustStream &);
    static void write(RustStream &, const SymbolQuoteResponse &);
    static int32_t allocation_size(const SymbolQuoteResponse &);
};

struct FfiConverterTypeTPSLOrder {
    static TpslOrder lift(RustBuffer);
    static RustBuffer lower(const TpslOrder &);
    static TpslOrder read(RustStream &);
    static void write(RustStream &, const TpslOrder &);
    static int32_t allocation_size(const TpslOrder &);
};

struct FfiConverterTypeTPSLWrapper {
    static TPSLWrapper lift(RustBuffer);
    static RustBuffer lower(const TPSLWrapper &);
    static TPSLWrapper read(RustStream &);
    static void write(RustStream &, const TPSLWrapper &);
    static int32_t allocation_size(const TPSLWrapper &);
};

struct FfiConverterTypeTrailOrder {
    static TrailOrder lift(RustBuffer);
    static RustBuffer lower(const TrailOrder &);
    static TrailOrder read(RustStream &);
    static void write(RustStream &, const TrailOrder &);
    static int32_t allocation_size(const TrailOrder &);
};

struct FfiConverterTypeUnRealizedResponse {
    static UnRealizedResponse lift(RustBuffer);
    static RustBuffer lower(const UnRealizedResponse &);
    static UnRealizedResponse read(RustStream &);
    static void write(RustStream &, const UnRealizedResponse &);
    static int32_t allocation_size(const UnRealizedResponse &);
};

struct FfiConverterTypeUnrealized {
    static Unrealized lift(RustBuffer);
    static RustBuffer lower(const Unrealized &);
    static Unrealized read(RustStream &);
    static void write(RustStream &, const Unrealized &);
    static int32_t allocation_size(const Unrealized &);
};

struct FfiConverterTypeVecCloseRecordResponse {
    static VecCloseRecordResponse lift(RustBuffer);
    static RustBuffer lower(const VecCloseRecordResponse &);
    static VecCloseRecordResponse read(RustStream &);
    static void write(RustStream &, const VecCloseRecordResponse &);
    static int32_t allocation_size(const VecCloseRecordResponse &);
};

struct FfiConverterTypeVecConditionDetailResponse {
    static VecConditionDetailResponse lift(RustBuffer);
    static RustBuffer lower(const VecConditionDetailResponse &);
    static VecConditionDetailResponse read(RustStream &);
    static void write(RustStream &, const VecConditionDetailResponse &);
    static int32_t allocation_size(const VecConditionDetailResponse &);
};

struct FfiConverterTypeVecEquityResponse {
    static VecEquityResponse lift(RustBuffer);
    static RustBuffer lower(const VecEquityResponse &);
    static VecEquityResponse read(RustStream &);
    static void write(RustStream &, const VecEquityResponse &);
    static int32_t allocation_size(const VecEquityResponse &);
};

struct FfiConverterTypeVecFutOptFilledResponse {
    static VecFutOptFilledResponse lift(RustBuffer);
    static RustBuffer lower(const VecFutOptFilledResponse &);
    static VecFutOptFilledResponse read(RustStream &);
    static void write(RustStream &, const VecFutOptFilledResponse &);
    static int32_t allocation_size(const VecFutOptFilledResponse &);
};

struct FfiConverterTypeVecFutOptHybridPositionResponse {
    static VecFutOptHybridPositionResponse lift(RustBuffer);
    static RustBuffer lower(const VecFutOptHybridPositionResponse &);
    static VecFutOptHybridPositionResponse read(RustStream &);
    static void write(RustStream &, const VecFutOptHybridPositionResponse &);
    static int32_t allocation_size(const VecFutOptHybridPositionResponse &);
};

struct FfiConverterTypeVecFutOptOrderResponse {
    static VecFutOptOrderResponse lift(RustBuffer);
    static RustBuffer lower(const VecFutOptOrderResponse &);
    static VecFutOptOrderResponse read(RustStream &);
    static void write(RustStream &, const VecFutOptOrderResponse &);
    static int32_t allocation_size(const VecFutOptOrderResponse &);
};

struct FfiConverterTypeVecFutOptPositionResponse {
    static VecFutOptPositionResponse lift(RustBuffer);
    static RustBuffer lower(const VecFutOptPositionResponse &);
    static VecFutOptPositionResponse read(RustStream &);
    static void write(RustStream &, const VecFutOptPositionResponse &);
    static int32_t allocation_size(const VecFutOptPositionResponse &);
};

struct FfiConverterTypeVecOrderResponse {
    static VecOrderResponse lift(RustBuffer);
    static RustBuffer lower(const VecOrderResponse &);
    static VecOrderResponse read(RustStream &);
    static void write(RustStream &, const VecOrderResponse &);
    static int32_t allocation_size(const VecOrderResponse &);
};

struct FfiConverterTypeVecRecoverResponse {
    static VecRecoverResponse lift(RustBuffer);
    static RustBuffer lower(const VecRecoverResponse &);
    static VecRecoverResponse read(RustStream &);
    static void write(RustStream &, const VecRecoverResponse &);
    static int32_t allocation_size(const VecRecoverResponse &);
};

struct FfiConverterTypeVecSymbolQuoteResponse {
    static VecSymbolQuoteResponse lift(RustBuffer);
    static RustBuffer lower(const VecSymbolQuoteResponse &);
    static VecSymbolQuoteResponse read(RustStream &);
    static void write(RustStream &, const VecSymbolQuoteResponse &);
    static int32_t allocation_size(const VecSymbolQuoteResponse &);
};

struct FfiConverterTypeBSAction {
    static BsAction lift(RustBuffer);
    static RustBuffer lower(const BsAction &);
    static BsAction read(RustStream &);
    static void write(RustStream &, const BsAction &);
    static int32_t allocation_size(const BsAction &);
};

struct FfiConverterTypeCallPut {
    static CallPut lift(RustBuffer);
    static RustBuffer lower(const CallPut &);
    static CallPut read(RustStream &);
    static void write(RustStream &, const CallPut &);
    static int32_t allocation_size(const CallPut &);
};

struct FfiConverterTypeConditionMarketType {
    static ConditionMarketType lift(RustBuffer);
    static RustBuffer lower(const ConditionMarketType &);
    static ConditionMarketType read(RustStream &);
    static void write(RustStream &, const ConditionMarketType &);
    static int32_t allocation_size(const ConditionMarketType &);
};

struct FfiConverterTypeConditionOrderType {
    static ConditionOrderType lift(RustBuffer);
    static RustBuffer lower(const ConditionOrderType &);
    static ConditionOrderType read(RustStream &);
    static void write(RustStream &, const ConditionOrderType &);
    static int32_t allocation_size(const ConditionOrderType &);
};

struct FfiConverterTypeConditionPriceType {
    static ConditionPriceType lift(RustBuffer);
    static RustBuffer lower(const ConditionPriceType &);
    static ConditionPriceType read(RustStream &);
    static void write(RustStream &, const ConditionPriceType &);
    static int32_t allocation_size(const ConditionPriceType &);
};

struct FfiConverterTypeConditionStatus {
    static ConditionStatus lift(RustBuffer);
    static RustBuffer lower(const ConditionStatus &);
    static ConditionStatus read(RustStream &);
    static void write(RustStream &, const ConditionStatus &);
    static int32_t allocation_size(const ConditionStatus &);
};

struct FfiConverterTypeDirection {
    static Direction lift(RustBuffer);
    static RustBuffer lower(const Direction &);
    static Direction read(RustStream &);
    static void write(RustStream &, const Direction &);
    static int32_t allocation_size(const Direction &);
};

struct FfiConverterTypeFubonError {
    static std::unique_ptr<FubonError> lift(RustBuffer buf);
    static RustBuffer lower(const FubonError &);
    static std::unique_ptr<FubonError> read(RustStream &stream);
    static void write(RustStream &stream, const FubonError &);
    static int32_t allocation_size(const FubonError &);
};

struct FfiConverterTypeFutOptConditionMarketType {
    static FutOptConditionMarketType lift(RustBuffer);
    static RustBuffer lower(const FutOptConditionMarketType &);
    static FutOptConditionMarketType read(RustStream &);
    static void write(RustStream &, const FutOptConditionMarketType &);
    static int32_t allocation_size(const FutOptConditionMarketType &);
};

struct FfiConverterTypeFutOptConditionOrderType {
    static FutOptConditionOrderType lift(RustBuffer);
    static RustBuffer lower(const FutOptConditionOrderType &);
    static FutOptConditionOrderType read(RustStream &);
    static void write(RustStream &, const FutOptConditionOrderType &);
    static int32_t allocation_size(const FutOptConditionOrderType &);
};

struct FfiConverterTypeFutOptConditionPriceType {
    static FutOptConditionPriceType lift(RustBuffer);
    static RustBuffer lower(const FutOptConditionPriceType &);
    static FutOptConditionPriceType read(RustStream &);
    static void write(RustStream &, const FutOptConditionPriceType &);
    static int32_t allocation_size(const FutOptConditionPriceType &);
};

struct FfiConverterTypeFutOptMarketType {
    static FutOptMarketType lift(RustBuffer);
    static RustBuffer lower(const FutOptMarketType &);
    static FutOptMarketType read(RustStream &);
    static void write(RustStream &, const FutOptMarketType &);
    static int32_t allocation_size(const FutOptMarketType &);
};

struct FfiConverterTypeFutOptOrderType {
    static FutOptOrderType lift(RustBuffer);
    static RustBuffer lower(const FutOptOrderType &);
    static FutOptOrderType read(RustStream &);
    static void write(RustStream &, const FutOptOrderType &);
    static int32_t allocation_size(const FutOptOrderType &);
};

struct FfiConverterTypeFutOptPriceType {
    static FutOptPriceType lift(RustBuffer);
    static RustBuffer lower(const FutOptPriceType &);
    static FutOptPriceType read(RustStream &);
    static void write(RustStream &, const FutOptPriceType &);
    static int32_t allocation_size(const FutOptPriceType &);
};

struct FfiConverterTypeHistoryStatus {
    static HistoryStatus lift(RustBuffer);
    static RustBuffer lower(const HistoryStatus &);
    static HistoryStatus read(RustStream &);
    static void write(RustStream &, const HistoryStatus &);
    static int32_t allocation_size(const HistoryStatus &);
};

struct FfiConverterTypeMarketType {
    static MarketType lift(RustBuffer);
    static RustBuffer lower(const MarketType &);
    static MarketType read(RustStream &);
    static void write(RustStream &, const MarketType &);
    static int32_t allocation_size(const MarketType &);
};

struct FfiConverterTypeOperator {
    static Operator lift(RustBuffer);
    static RustBuffer lower(const Operator &);
    static Operator read(RustStream &);
    static void write(RustStream &, const Operator &);
    static int32_t allocation_size(const Operator &);
};

struct FfiConverterTypeOrderType {
    static OrderType lift(RustBuffer);
    static RustBuffer lower(const OrderType &);
    static OrderType read(RustStream &);
    static void write(RustStream &, const OrderType &);
    static int32_t allocation_size(const OrderType &);
};

struct FfiConverterTypePriceType {
    static PriceType lift(RustBuffer);
    static RustBuffer lower(const PriceType &);
    static PriceType read(RustStream &);
    static void write(RustStream &, const PriceType &);
    static int32_t allocation_size(const PriceType &);
};

struct FfiConverterTypeStockType {
    static StockType lift(RustBuffer);
    static RustBuffer lower(const StockType &);
    static StockType read(RustStream &);
    static void write(RustStream &, const StockType &);
    static int32_t allocation_size(const StockType &);
};

struct FfiConverterTypeStopSign {
    static StopSign lift(RustBuffer);
    static RustBuffer lower(const StopSign &);
    static StopSign read(RustStream &);
    static void write(RustStream &, const StopSign &);
    static int32_t allocation_size(const StopSign &);
};

struct FfiConverterTypeTimeInForce {
    static TimeInForce lift(RustBuffer);
    static RustBuffer lower(const TimeInForce &);
    static TimeInForce read(RustStream &);
    static void write(RustStream &, const TimeInForce &);
    static int32_t allocation_size(const TimeInForce &);
};

struct FfiConverterTypeTimeSliceOrderType {
    static TimeSliceOrderType lift(RustBuffer);
    static RustBuffer lower(const TimeSliceOrderType &);
    static TimeSliceOrderType read(RustStream &);
    static void write(RustStream &, const TimeSliceOrderType &);
    static int32_t allocation_size(const TimeSliceOrderType &);
};

struct FfiConverterTypeTradingType {
    static TradingType lift(RustBuffer);
    static RustBuffer lower(const TradingType &);
    static TradingType read(RustStream &);
    static void write(RustStream &, const TradingType &);
    static int32_t allocation_size(const TradingType &);
};

struct FfiConverterTypeTriggerContent {
    static TriggerContent lift(RustBuffer);
    static RustBuffer lower(const TriggerContent &);
    static TriggerContent read(RustStream &);
    static void write(RustStream &, const TriggerContent &);
    static int32_t allocation_size(const TriggerContent &);
};

struct FfiConverterCallback {
    static std::shared_ptr<Callback> lift(uint64_t);
    static uint64_t lower(const std::shared_ptr<Callback> &);
    static std::shared_ptr<Callback> read(RustStream &);
    static void write(RustStream &, const std::shared_ptr<Callback> &);
    static int32_t allocation_size(const std::shared_ptr<Callback> &);
private:
    static int callback_stub(uint64_t, uint32_t, uint8_t *, int32_t, RustBuffer *);

    static std::once_flag once;
    static HandleMap<Callback> callbacks;
};

struct FfiConverterOptionalInt32 {
    static std::optional<int32_t> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<int32_t>& val);
    static std::optional<int32_t> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<int32_t>& value);
    static int32_t allocation_size(const std::optional<int32_t> &val);
};

struct FfiConverterOptionalUInt64 {
    static std::optional<uint64_t> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<uint64_t>& val);
    static std::optional<uint64_t> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<uint64_t>& value);
    static int32_t allocation_size(const std::optional<uint64_t> &val);
};

struct FfiConverterOptionalInt64 {
    static std::optional<int64_t> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<int64_t>& val);
    static std::optional<int64_t> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<int64_t>& value);
    static int32_t allocation_size(const std::optional<int64_t> &val);
};

struct FfiConverterOptionalDouble {
    static std::optional<double> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<double>& val);
    static std::optional<double> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<double>& value);
    static int32_t allocation_size(const std::optional<double> &val);
};

struct FfiConverterOptionalBool {
    static std::optional<bool> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<bool>& val);
    static std::optional<bool> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<bool>& value);
    static int32_t allocation_size(const std::optional<bool> &val);
};

struct FfiConverterOptionalString {
    static std::optional<std::string> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::string>& val);
    static std::optional<std::string> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::string>& value);
    static int32_t allocation_size(const std::optional<std::string> &val);
};

struct FfiConverterOptionalTypeBankRemain {
    static std::optional<BankRemain> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<BankRemain>& val);
    static std::optional<BankRemain> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<BankRemain>& value);
    static int32_t allocation_size(const std::optional<BankRemain> &val);
};

struct FfiConverterOptionalTypeConditionOrderResult {
    static std::optional<ConditionOrderResult> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<ConditionOrderResult>& val);
    static std::optional<ConditionOrderResult> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<ConditionOrderResult>& value);
    static int32_t allocation_size(const std::optional<ConditionOrderResult> &val);
};

struct FfiConverterOptionalTypeDayTradeStockInfo {
    static std::optional<DayTradeStockInfo> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<DayTradeStockInfo>& val);
    static std::optional<DayTradeStockInfo> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<DayTradeStockInfo>& value);
    static int32_t allocation_size(const std::optional<DayTradeStockInfo> &val);
};

struct FfiConverterOptionalTypeEstimateMargin {
    static std::optional<EstimateMargin> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<EstimateMargin>& val);
    static std::optional<EstimateMargin> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<EstimateMargin>& value);
    static int32_t allocation_size(const std::optional<EstimateMargin> &val);
};

struct FfiConverterOptionalTypeFutOptOrderResult {
    static std::optional<FutOptOrderResult> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<FutOptOrderResult>& val);
    static std::optional<FutOptOrderResult> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<FutOptOrderResult>& value);
    static int32_t allocation_size(const std::optional<FutOptOrderResult> &val);
};

struct FfiConverterOptionalTypeFutOptTPSLOrder {
    static std::optional<FutOptTpslOrder> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<FutOptTpslOrder>& val);
    static std::optional<FutOptTpslOrder> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<FutOptTpslOrder>& value);
    static int32_t allocation_size(const std::optional<FutOptTpslOrder> &val);
};

struct FfiConverterOptionalTypeFutOptTPSLWrapper {
    static std::optional<FutOptTPSLWrapper> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<FutOptTPSLWrapper>& val);
    static std::optional<FutOptTPSLWrapper> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<FutOptTPSLWrapper>& value);
    static int32_t allocation_size(const std::optional<FutOptTPSLWrapper> &val);
};

struct FfiConverterOptionalTypeMaintenanceData {
    static std::optional<MaintenanceData> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<MaintenanceData>& val);
    static std::optional<MaintenanceData> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<MaintenanceData>& value);
    static int32_t allocation_size(const std::optional<MaintenanceData> &val);
};

struct FfiConverterOptionalTypeMarginShortQuota {
    static std::optional<MarginShortQuota> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<MarginShortQuota>& val);
    static std::optional<MarginShortQuota> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<MarginShortQuota>& value);
    static int32_t allocation_size(const std::optional<MarginShortQuota> &val);
};

struct FfiConverterOptionalTypeOrderResult {
    static std::optional<OrderResult> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<OrderResult>& val);
    static std::optional<OrderResult> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<OrderResult>& value);
    static int32_t allocation_size(const std::optional<OrderResult> &val);
};

struct FfiConverterOptionalTypeSettlementData {
    static std::optional<SettlementData> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<SettlementData>& val);
    static std::optional<SettlementData> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<SettlementData>& value);
    static int32_t allocation_size(const std::optional<SettlementData> &val);
};

struct FfiConverterOptionalTypeSymbolQuote {
    static std::optional<SymbolQuote> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<SymbolQuote>& val);
    static std::optional<SymbolQuote> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<SymbolQuote>& value);
    static int32_t allocation_size(const std::optional<SymbolQuote> &val);
};

struct FfiConverterOptionalTypeTPSLOrder {
    static std::optional<TpslOrder> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<TpslOrder>& val);
    static std::optional<TpslOrder> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<TpslOrder>& value);
    static int32_t allocation_size(const std::optional<TpslOrder> &val);
};

struct FfiConverterOptionalTypeTPSLWrapper {
    static std::optional<TPSLWrapper> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<TPSLWrapper>& val);
    static std::optional<TPSLWrapper> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<TPSLWrapper>& value);
    static int32_t allocation_size(const std::optional<TPSLWrapper> &val);
};

struct FfiConverterOptionalTypeBSAction {
    static std::optional<BsAction> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<BsAction>& val);
    static std::optional<BsAction> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<BsAction>& value);
    static int32_t allocation_size(const std::optional<BsAction> &val);
};

struct FfiConverterOptionalTypeCallPut {
    static std::optional<CallPut> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<CallPut>& val);
    static std::optional<CallPut> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<CallPut>& value);
    static int32_t allocation_size(const std::optional<CallPut> &val);
};

struct FfiConverterOptionalTypeConditionStatus {
    static std::optional<ConditionStatus> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<ConditionStatus>& val);
    static std::optional<ConditionStatus> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<ConditionStatus>& value);
    static int32_t allocation_size(const std::optional<ConditionStatus> &val);
};

struct FfiConverterOptionalTypeFutOptConditionMarketType {
    static std::optional<FutOptConditionMarketType> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<FutOptConditionMarketType>& val);
    static std::optional<FutOptConditionMarketType> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<FutOptConditionMarketType>& value);
    static int32_t allocation_size(const std::optional<FutOptConditionMarketType> &val);
};

struct FfiConverterOptionalTypeFutOptMarketType {
    static std::optional<FutOptMarketType> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<FutOptMarketType>& val);
    static std::optional<FutOptMarketType> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<FutOptMarketType>& value);
    static int32_t allocation_size(const std::optional<FutOptMarketType> &val);
};

struct FfiConverterOptionalTypeFutOptOrderType {
    static std::optional<FutOptOrderType> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<FutOptOrderType>& val);
    static std::optional<FutOptOrderType> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<FutOptOrderType>& value);
    static int32_t allocation_size(const std::optional<FutOptOrderType> &val);
};

struct FfiConverterOptionalTypeFutOptPriceType {
    static std::optional<FutOptPriceType> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<FutOptPriceType>& val);
    static std::optional<FutOptPriceType> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<FutOptPriceType>& value);
    static int32_t allocation_size(const std::optional<FutOptPriceType> &val);
};

struct FfiConverterOptionalTypeHistoryStatus {
    static std::optional<HistoryStatus> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<HistoryStatus>& val);
    static std::optional<HistoryStatus> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<HistoryStatus>& value);
    static int32_t allocation_size(const std::optional<HistoryStatus> &val);
};

struct FfiConverterOptionalTypeMarketType {
    static std::optional<MarketType> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<MarketType>& val);
    static std::optional<MarketType> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<MarketType>& value);
    static int32_t allocation_size(const std::optional<MarketType> &val);
};

struct FfiConverterOptionalTypeOrderType {
    static std::optional<OrderType> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<OrderType>& val);
    static std::optional<OrderType> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<OrderType>& value);
    static int32_t allocation_size(const std::optional<OrderType> &val);
};

struct FfiConverterOptionalTypePriceType {
    static std::optional<PriceType> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<PriceType>& val);
    static std::optional<PriceType> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<PriceType>& value);
    static int32_t allocation_size(const std::optional<PriceType> &val);
};

struct FfiConverterOptionalTypeTimeInForce {
    static std::optional<TimeInForce> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<TimeInForce>& val);
    static std::optional<TimeInForce> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<TimeInForce>& value);
    static int32_t allocation_size(const std::optional<TimeInForce> &val);
};

struct FfiConverterOptionalTypeTriggerContent {
    static std::optional<TriggerContent> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<TriggerContent>& val);
    static std::optional<TriggerContent> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<TriggerContent>& value);
    static int32_t allocation_size(const std::optional<TriggerContent> &val);
};

struct FfiConverterOptionalSequenceTypeAccount {
    static std::optional<std::vector<Account>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<Account>>& val);
    static std::optional<std::vector<Account>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<Account>>& value);
    static int32_t allocation_size(const std::optional<std::vector<Account>> &val);
};

struct FfiConverterOptionalSequenceTypeBatchResult {
    static std::optional<std::vector<BatchResult>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<BatchResult>>& val);
    static std::optional<std::vector<BatchResult>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<BatchResult>>& value);
    static int32_t allocation_size(const std::optional<std::vector<BatchResult>> &val);
};

struct FfiConverterOptionalSequenceTypeCloseRecord {
    static std::optional<std::vector<CloseRecord>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<CloseRecord>>& val);
    static std::optional<std::vector<CloseRecord>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<CloseRecord>>& value);
    static int32_t allocation_size(const std::optional<std::vector<CloseRecord>> &val);
};

struct FfiConverterOptionalSequenceTypeCondition {
    static std::optional<std::vector<Condition>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<Condition>>& val);
    static std::optional<std::vector<Condition>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<Condition>>& value);
    static int32_t allocation_size(const std::optional<std::vector<Condition>> &val);
};

struct FfiConverterOptionalSequenceTypeConditionDetail {
    static std::optional<std::vector<ConditionDetail>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<ConditionDetail>>& val);
    static std::optional<std::vector<ConditionDetail>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<ConditionDetail>>& value);
    static int32_t allocation_size(const std::optional<std::vector<ConditionDetail>> &val);
};

struct FfiConverterOptionalSequenceTypeEquity {
    static std::optional<std::vector<Equity>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<Equity>>& val);
    static std::optional<std::vector<Equity>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<Equity>>& value);
    static int32_t allocation_size(const std::optional<std::vector<Equity>> &val);
};

struct FfiConverterOptionalSequenceTypeFilledData {
    static std::optional<std::vector<FilledData>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<FilledData>>& val);
    static std::optional<std::vector<FilledData>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<FilledData>>& value);
    static int32_t allocation_size(const std::optional<std::vector<FilledData>> &val);
};

struct FfiConverterOptionalSequenceTypeFutOptFilledData {
    static std::optional<std::vector<FutOptFilledData>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<FutOptFilledData>>& val);
    static std::optional<std::vector<FutOptFilledData>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<FutOptFilledData>>& value);
    static int32_t allocation_size(const std::optional<std::vector<FutOptFilledData>> &val);
};

struct FfiConverterOptionalSequenceTypeFutOptOrderDetail {
    static std::optional<std::vector<FutOptOrderDetail>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<FutOptOrderDetail>>& val);
    static std::optional<std::vector<FutOptOrderDetail>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<FutOptOrderDetail>>& value);
    static int32_t allocation_size(const std::optional<std::vector<FutOptOrderDetail>> &val);
};

struct FfiConverterOptionalSequenceTypeFutOptOrderResult {
    static std::optional<std::vector<FutOptOrderResult>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<FutOptOrderResult>>& val);
    static std::optional<std::vector<FutOptOrderResult>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<FutOptOrderResult>>& value);
    static int32_t allocation_size(const std::optional<std::vector<FutOptOrderResult>> &val);
};

struct FfiConverterOptionalSequenceTypeHybridPosition {
    static std::optional<std::vector<HybridPosition>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<HybridPosition>>& val);
    static std::optional<std::vector<HybridPosition>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<HybridPosition>>& value);
    static int32_t allocation_size(const std::optional<std::vector<HybridPosition>> &val);
};

struct FfiConverterOptionalSequenceTypeInventory {
    static std::optional<std::vector<Inventory>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<Inventory>>& val);
    static std::optional<std::vector<Inventory>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<Inventory>>& value);
    static int32_t allocation_size(const std::optional<std::vector<Inventory>> &val);
};

struct FfiConverterOptionalSequenceTypeOrderDetail {
    static std::optional<std::vector<OrderDetail>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<OrderDetail>>& val);
    static std::optional<std::vector<OrderDetail>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<OrderDetail>>& value);
    static int32_t allocation_size(const std::optional<std::vector<OrderDetail>> &val);
};

struct FfiConverterOptionalSequenceTypeOrderResult {
    static std::optional<std::vector<OrderResult>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<OrderResult>>& val);
    static std::optional<std::vector<OrderResult>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<OrderResult>>& value);
    static int32_t allocation_size(const std::optional<std::vector<OrderResult>> &val);
};

struct FfiConverterOptionalSequenceTypePosition {
    static std::optional<std::vector<Position>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<Position>>& val);
    static std::optional<std::vector<Position>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<Position>>& value);
    static int32_t allocation_size(const std::optional<std::vector<Position>> &val);
};

struct FfiConverterOptionalSequenceTypeRealized {
    static std::optional<std::vector<Realized>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<Realized>>& val);
    static std::optional<std::vector<Realized>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<Realized>>& value);
    static int32_t allocation_size(const std::optional<std::vector<Realized>> &val);
};

struct FfiConverterOptionalSequenceTypeRealizedSummary {
    static std::optional<std::vector<RealizedSummary>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<RealizedSummary>>& val);
    static std::optional<std::vector<RealizedSummary>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<RealizedSummary>>& value);
    static int32_t allocation_size(const std::optional<std::vector<RealizedSummary>> &val);
};

struct FfiConverterOptionalSequenceTypeRecover {
    static std::optional<std::vector<Recover>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<Recover>>& val);
    static std::optional<std::vector<Recover>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<Recover>>& value);
    static int32_t allocation_size(const std::optional<std::vector<Recover>> &val);
};

struct FfiConverterOptionalSequenceTypeSettlement {
    static std::optional<std::vector<Settlement>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<Settlement>>& val);
    static std::optional<std::vector<Settlement>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<Settlement>>& value);
    static int32_t allocation_size(const std::optional<std::vector<Settlement>> &val);
};

struct FfiConverterOptionalSequenceTypeSpreadPosition {
    static std::optional<std::vector<SpreadPosition>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<SpreadPosition>>& val);
    static std::optional<std::vector<SpreadPosition>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<SpreadPosition>>& value);
    static int32_t allocation_size(const std::optional<std::vector<SpreadPosition>> &val);
};

struct FfiConverterOptionalSequenceTypeSymbolQuote {
    static std::optional<std::vector<SymbolQuote>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<SymbolQuote>>& val);
    static std::optional<std::vector<SymbolQuote>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<SymbolQuote>>& value);
    static int32_t allocation_size(const std::optional<std::vector<SymbolQuote>> &val);
};

struct FfiConverterOptionalSequenceTypeUnrealized {
    static std::optional<std::vector<Unrealized>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<Unrealized>>& val);
    static std::optional<std::vector<Unrealized>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<Unrealized>>& value);
    static int32_t allocation_size(const std::optional<std::vector<Unrealized>> &val);
};

struct FfiConverterOptionalSequenceTypeStockType {
    static std::optional<std::vector<StockType>> lift(RustBuffer buf);
    static RustBuffer lower(const std::optional<std::vector<StockType>>& val);
    static std::optional<std::vector<StockType>> read(RustStream &stream);
    static void write(RustStream &stream, const std::optional<std::vector<StockType>>& value);
    static int32_t allocation_size(const std::optional<std::vector<StockType>> &val);
};

struct FfiConverterSequenceTypeAccount {
    static std::vector<Account> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Account> &);
    static std::vector<Account> read(RustStream &);
    static void write(RustStream &, const std::vector<Account> &);
    static int32_t allocation_size(const std::vector<Account> &);
};

struct FfiConverterSequenceTypeBatchResult {
    static std::vector<BatchResult> lift(RustBuffer);
    static RustBuffer lower(const std::vector<BatchResult> &);
    static std::vector<BatchResult> read(RustStream &);
    static void write(RustStream &, const std::vector<BatchResult> &);
    static int32_t allocation_size(const std::vector<BatchResult> &);
};

struct FfiConverterSequenceTypeCloseRecord {
    static std::vector<CloseRecord> lift(RustBuffer);
    static RustBuffer lower(const std::vector<CloseRecord> &);
    static std::vector<CloseRecord> read(RustStream &);
    static void write(RustStream &, const std::vector<CloseRecord> &);
    static int32_t allocation_size(const std::vector<CloseRecord> &);
};

struct FfiConverterSequenceTypeCondition {
    static std::vector<Condition> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Condition> &);
    static std::vector<Condition> read(RustStream &);
    static void write(RustStream &, const std::vector<Condition> &);
    static int32_t allocation_size(const std::vector<Condition> &);
};

struct FfiConverterSequenceTypeConditionDetail {
    static std::vector<ConditionDetail> lift(RustBuffer);
    static RustBuffer lower(const std::vector<ConditionDetail> &);
    static std::vector<ConditionDetail> read(RustStream &);
    static void write(RustStream &, const std::vector<ConditionDetail> &);
    static int32_t allocation_size(const std::vector<ConditionDetail> &);
};

struct FfiConverterSequenceTypeEquity {
    static std::vector<Equity> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Equity> &);
    static std::vector<Equity> read(RustStream &);
    static void write(RustStream &, const std::vector<Equity> &);
    static int32_t allocation_size(const std::vector<Equity> &);
};

struct FfiConverterSequenceTypeFilledData {
    static std::vector<FilledData> lift(RustBuffer);
    static RustBuffer lower(const std::vector<FilledData> &);
    static std::vector<FilledData> read(RustStream &);
    static void write(RustStream &, const std::vector<FilledData> &);
    static int32_t allocation_size(const std::vector<FilledData> &);
};

struct FfiConverterSequenceTypeFutOptFilledData {
    static std::vector<FutOptFilledData> lift(RustBuffer);
    static RustBuffer lower(const std::vector<FutOptFilledData> &);
    static std::vector<FutOptFilledData> read(RustStream &);
    static void write(RustStream &, const std::vector<FutOptFilledData> &);
    static int32_t allocation_size(const std::vector<FutOptFilledData> &);
};

struct FfiConverterSequenceTypeFutOptModifyLot {
    static std::vector<FutOptModifyLot> lift(RustBuffer);
    static RustBuffer lower(const std::vector<FutOptModifyLot> &);
    static std::vector<FutOptModifyLot> read(RustStream &);
    static void write(RustStream &, const std::vector<FutOptModifyLot> &);
    static int32_t allocation_size(const std::vector<FutOptModifyLot> &);
};

struct FfiConverterSequenceTypeFutOptModifyPrice {
    static std::vector<FutOptModifyPrice> lift(RustBuffer);
    static RustBuffer lower(const std::vector<FutOptModifyPrice> &);
    static std::vector<FutOptModifyPrice> read(RustStream &);
    static void write(RustStream &, const std::vector<FutOptModifyPrice> &);
    static int32_t allocation_size(const std::vector<FutOptModifyPrice> &);
};

struct FfiConverterSequenceTypeFutOptOrder {
    static std::vector<FutOptOrder> lift(RustBuffer);
    static RustBuffer lower(const std::vector<FutOptOrder> &);
    static std::vector<FutOptOrder> read(RustStream &);
    static void write(RustStream &, const std::vector<FutOptOrder> &);
    static int32_t allocation_size(const std::vector<FutOptOrder> &);
};

struct FfiConverterSequenceTypeFutOptOrderDetail {
    static std::vector<FutOptOrderDetail> lift(RustBuffer);
    static RustBuffer lower(const std::vector<FutOptOrderDetail> &);
    static std::vector<FutOptOrderDetail> read(RustStream &);
    static void write(RustStream &, const std::vector<FutOptOrderDetail> &);
    static int32_t allocation_size(const std::vector<FutOptOrderDetail> &);
};

struct FfiConverterSequenceTypeFutOptOrderResult {
    static std::vector<FutOptOrderResult> lift(RustBuffer);
    static RustBuffer lower(const std::vector<FutOptOrderResult> &);
    static std::vector<FutOptOrderResult> read(RustStream &);
    static void write(RustStream &, const std::vector<FutOptOrderResult> &);
    static int32_t allocation_size(const std::vector<FutOptOrderResult> &);
};

struct FfiConverterSequenceTypeHybridPosition {
    static std::vector<HybridPosition> lift(RustBuffer);
    static RustBuffer lower(const std::vector<HybridPosition> &);
    static std::vector<HybridPosition> read(RustStream &);
    static void write(RustStream &, const std::vector<HybridPosition> &);
    static int32_t allocation_size(const std::vector<HybridPosition> &);
};

struct FfiConverterSequenceTypeInventory {
    static std::vector<Inventory> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Inventory> &);
    static std::vector<Inventory> read(RustStream &);
    static void write(RustStream &, const std::vector<Inventory> &);
    static int32_t allocation_size(const std::vector<Inventory> &);
};

struct FfiConverterSequenceTypeMaintenanceDetail {
    static std::vector<MaintenanceDetail> lift(RustBuffer);
    static RustBuffer lower(const std::vector<MaintenanceDetail> &);
    static std::vector<MaintenanceDetail> read(RustStream &);
    static void write(RustStream &, const std::vector<MaintenanceDetail> &);
    static int32_t allocation_size(const std::vector<MaintenanceDetail> &);
};

struct FfiConverterSequenceTypeModifyPrice {
    static std::vector<ModifyPrice> lift(RustBuffer);
    static RustBuffer lower(const std::vector<ModifyPrice> &);
    static std::vector<ModifyPrice> read(RustStream &);
    static void write(RustStream &, const std::vector<ModifyPrice> &);
    static int32_t allocation_size(const std::vector<ModifyPrice> &);
};

struct FfiConverterSequenceTypeModifyQuantity {
    static std::vector<ModifyQuantity> lift(RustBuffer);
    static RustBuffer lower(const std::vector<ModifyQuantity> &);
    static std::vector<ModifyQuantity> read(RustStream &);
    static void write(RustStream &, const std::vector<ModifyQuantity> &);
    static int32_t allocation_size(const std::vector<ModifyQuantity> &);
};

struct FfiConverterSequenceTypeOrder {
    static std::vector<Order> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Order> &);
    static std::vector<Order> read(RustStream &);
    static void write(RustStream &, const std::vector<Order> &);
    static int32_t allocation_size(const std::vector<Order> &);
};

struct FfiConverterSequenceTypeOrderDetail {
    static std::vector<OrderDetail> lift(RustBuffer);
    static RustBuffer lower(const std::vector<OrderDetail> &);
    static std::vector<OrderDetail> read(RustStream &);
    static void write(RustStream &, const std::vector<OrderDetail> &);
    static int32_t allocation_size(const std::vector<OrderDetail> &);
};

struct FfiConverterSequenceTypeOrderResult {
    static std::vector<OrderResult> lift(RustBuffer);
    static RustBuffer lower(const std::vector<OrderResult> &);
    static std::vector<OrderResult> read(RustStream &);
    static void write(RustStream &, const std::vector<OrderResult> &);
    static int32_t allocation_size(const std::vector<OrderResult> &);
};

struct FfiConverterSequenceTypeParentChildRecord {
    static std::vector<ParentChildRecord> lift(RustBuffer);
    static RustBuffer lower(const std::vector<ParentChildRecord> &);
    static std::vector<ParentChildRecord> read(RustStream &);
    static void write(RustStream &, const std::vector<ParentChildRecord> &);
    static int32_t allocation_size(const std::vector<ParentChildRecord> &);
};

struct FfiConverterSequenceTypePosition {
    static std::vector<Position> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Position> &);
    static std::vector<Position> read(RustStream &);
    static void write(RustStream &, const std::vector<Position> &);
    static int32_t allocation_size(const std::vector<Position> &);
};

struct FfiConverterSequenceTypeRealized {
    static std::vector<Realized> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Realized> &);
    static std::vector<Realized> read(RustStream &);
    static void write(RustStream &, const std::vector<Realized> &);
    static int32_t allocation_size(const std::vector<Realized> &);
};

struct FfiConverterSequenceTypeRealizedSummary {
    static std::vector<RealizedSummary> lift(RustBuffer);
    static RustBuffer lower(const std::vector<RealizedSummary> &);
    static std::vector<RealizedSummary> read(RustStream &);
    static void write(RustStream &, const std::vector<RealizedSummary> &);
    static int32_t allocation_size(const std::vector<RealizedSummary> &);
};

struct FfiConverterSequenceTypeRecover {
    static std::vector<Recover> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Recover> &);
    static std::vector<Recover> read(RustStream &);
    static void write(RustStream &, const std::vector<Recover> &);
    static int32_t allocation_size(const std::vector<Recover> &);
};

struct FfiConverterSequenceTypeSettlement {
    static std::vector<Settlement> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Settlement> &);
    static std::vector<Settlement> read(RustStream &);
    static void write(RustStream &, const std::vector<Settlement> &);
    static int32_t allocation_size(const std::vector<Settlement> &);
};

struct FfiConverterSequenceTypeSpreadPosition {
    static std::vector<SpreadPosition> lift(RustBuffer);
    static RustBuffer lower(const std::vector<SpreadPosition> &);
    static std::vector<SpreadPosition> read(RustStream &);
    static void write(RustStream &, const std::vector<SpreadPosition> &);
    static int32_t allocation_size(const std::vector<SpreadPosition> &);
};

struct FfiConverterSequenceTypeSymbolQuote {
    static std::vector<SymbolQuote> lift(RustBuffer);
    static RustBuffer lower(const std::vector<SymbolQuote> &);
    static std::vector<SymbolQuote> read(RustStream &);
    static void write(RustStream &, const std::vector<SymbolQuote> &);
    static int32_t allocation_size(const std::vector<SymbolQuote> &);
};

struct FfiConverterSequenceTypeUnrealized {
    static std::vector<Unrealized> lift(RustBuffer);
    static RustBuffer lower(const std::vector<Unrealized> &);
    static std::vector<Unrealized> read(RustStream &);
    static void write(RustStream &, const std::vector<Unrealized> &);
    static int32_t allocation_size(const std::vector<Unrealized> &);
};

struct FfiConverterSequenceTypeStockType {
    static std::vector<StockType> lift(RustBuffer);
    static RustBuffer lower(const std::vector<StockType> &);
    static std::vector<StockType> read(RustStream &);
    static void write(RustStream &, const std::vector<StockType> &);
    static int32_t allocation_size(const std::vector<StockType> &);
};
} // namespace uniffi

} // namespace fubon