#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <optional>
#include <type_traits>
#include <iomanip>
#include "fubon.hpp"

namespace fubon {

// Helper functions for optional types
template<typename T>
inline std::string opt_str(const std::optional<T>& opt) {
    if (!opt.has_value()) return "<null>";
    if constexpr (std::is_arithmetic_v<T>) {
        return std::to_string(*opt);
    } else if constexpr (std::is_same_v<T, std::string>) {
        return *opt;
    } else {
        return "<complex_type>";
    }
}

template<>
inline std::string opt_str<std::string>(const std::optional<std::string>& opt) {
    return opt.value_or("<null>");
}

// Enum to string conversions
std::string to_string(BsAction value);
std::string to_string(CallPut value);
std::string to_string(ConditionMarketType value);
std::string to_string(ConditionOrderType value);
std::string to_string(ConditionPriceType value);
std::string to_string(ConditionStatus value);
std::string to_string(Direction value);
std::string to_string(FutOptConditionMarketType value);
std::string to_string(FutOptConditionOrderType value);
std::string to_string(FutOptConditionPriceType value);
std::string to_string(FutOptMarketType value);
std::string to_string(FutOptOrderType value);
std::string to_string(FutOptPriceType value);
std::string to_string(HistoryStatus value);
std::string to_string(MarketType value);
std::string to_string(Operator value);
std::string to_string(OrderType value);
std::string to_string(PriceType value);
std::string to_string(StockType value);
std::string to_string(StopSign value);
std::string to_string(TimeInForce value);
std::string to_string(TimeSliceOrderType value);
std::string to_string(TradingType value);
std::string to_string(TriggerContent value);

// Output operators for records
std::ostream& operator<<(std::ostream& os, const Account& obj);
std::ostream& operator<<(std::ostream& os, const AccountRes& obj);
std::ostream& operator<<(std::ostream& os, const BankRemain& obj);
std::ostream& operator<<(std::ostream& os, const BankRemainResponse& obj);
std::ostream& operator<<(std::ostream& os, const BatchResponse& obj);
std::ostream& operator<<(std::ostream& os, const BatchResult& obj);
std::ostream& operator<<(std::ostream& os, const CancelResult& obj);
std::ostream& operator<<(std::ostream& os, const CloseRecord& obj);
std::ostream& operator<<(std::ostream& os, const Condition& obj);
std::ostream& operator<<(std::ostream& os, const ConditionDayTrade& obj);
std::ostream& operator<<(std::ostream& os, const ConditionDetail& obj);
std::ostream& operator<<(std::ostream& os, const ConditionDetailResult& obj);
std::ostream& operator<<(std::ostream& os, const ConditionOrder& obj);
std::ostream& operator<<(std::ostream& os, const ConditionOrderResult& obj);
std::ostream& operator<<(std::ostream& os, const ConditionOrderResultResponse& obj);
std::ostream& operator<<(std::ostream& os, const ConditionResult& obj);
std::ostream& operator<<(std::ostream& os, const DayTradeStockInfo& obj);
std::ostream& operator<<(std::ostream& os, const DayTradeStockInfoResponse& obj);
std::ostream& operator<<(std::ostream& os, const Equity& obj);
std::ostream& operator<<(std::ostream& os, const EstimateMargin& obj);
std::ostream& operator<<(std::ostream& os, const EstimateMarginResponse& obj);
std::ostream& operator<<(std::ostream& os, const FilledData& obj);
std::ostream& operator<<(std::ostream& os, const FilledResponse& obj);
std::ostream& operator<<(std::ostream& os, const FutOptConditionOrder& obj);
std::ostream& operator<<(std::ostream& os, const FutOptFilledData& obj);
std::ostream& operator<<(std::ostream& os, const FutOptModifyLot& obj);
std::ostream& operator<<(std::ostream& os, const FutOptModifyPrice& obj);
std::ostream& operator<<(std::ostream& os, const FutOptOrder& obj);
std::ostream& operator<<(std::ostream& os, const FutOptOrderDetail& obj);
std::ostream& operator<<(std::ostream& os, const FutOptOrderResponse& obj);
std::ostream& operator<<(std::ostream& os, const FutOptOrderResult& obj);
std::ostream& operator<<(std::ostream& os, const FutOptTPSLWrapper& obj);
std::ostream& operator<<(std::ostream& os, const FutOptTrailOrder& obj);
std::ostream& operator<<(std::ostream& os, const HybridPosition& obj);
std::ostream& operator<<(std::ostream& os, const Inventory& obj);
std::ostream& operator<<(std::ostream& os, const InventoryOdd& obj);
std::ostream& operator<<(std::ostream& os, const InventoryResponse& obj);
std::ostream& operator<<(std::ostream& os, const LoginResponse& obj);
std::ostream& operator<<(std::ostream& os, const MaintenanceData& obj);
std::ostream& operator<<(std::ostream& os, const MaintenanceDetail& obj);
std::ostream& operator<<(std::ostream& os, const MaintenanceResponse& obj);
std::ostream& operator<<(std::ostream& os, const MaintenanceSummary& obj);
std::ostream& operator<<(std::ostream& os, const MarginShortQuota& obj);
std::ostream& operator<<(std::ostream& os, const MarginShortQuotaResponse& obj);
std::ostream& operator<<(std::ostream& os, const ModifyPrice& obj);
std::ostream& operator<<(std::ostream& os, const ModifyQuantity& obj);
std::ostream& operator<<(std::ostream& os, const Order& obj);
std::ostream& operator<<(std::ostream& os, const OrderDetail& obj);
std::ostream& operator<<(std::ostream& os, const OrderResponse& obj);
std::ostream& operator<<(std::ostream& os, const OrderResult& obj);
std::ostream& operator<<(std::ostream& os, const ParentChildRecord& obj);
std::ostream& operator<<(std::ostream& os, const Position& obj);
std::ostream& operator<<(std::ostream& os, const Realized& obj);
std::ostream& operator<<(std::ostream& os, const RealizedResponse& obj);
std::ostream& operator<<(std::ostream& os, const RealizedSummary& obj);
std::ostream& operator<<(std::ostream& os, const RealizedSummaryResponse& obj);
std::ostream& operator<<(std::ostream& os, const Recover& obj);
std::ostream& operator<<(std::ostream& os, const Reply& obj);
std::ostream& operator<<(std::ostream& os, const SdkRef& obj);
std::ostream& operator<<(std::ostream& os, const Settlement& obj);
std::ostream& operator<<(std::ostream& os, const SettlementData& obj);
std::ostream& operator<<(std::ostream& os, const SettlementResponse& obj);
std::ostream& operator<<(std::ostream& os, const SplitDescription& obj);
std::ostream& operator<<(std::ostream& os, const SpreadPosition& obj);
std::ostream& operator<<(std::ostream& os, const StringResponse& obj);
std::ostream& operator<<(std::ostream& os, const SymbolQuote& obj);
std::ostream& operator<<(std::ostream& os, const SymbolQuoteResponse& obj);
std::ostream& operator<<(std::ostream& os, const TPSLWrapper& obj);
std::ostream& operator<<(std::ostream& os, const TrailOrder& obj);
std::ostream& operator<<(std::ostream& os, const UnRealizedResponse& obj);
std::ostream& operator<<(std::ostream& os, const Unrealized& obj);
std::ostream& operator<<(std::ostream& os, const VecCloseRecordResponse& obj);
std::ostream& operator<<(std::ostream& os, const VecConditionDetailResponse& obj);
std::ostream& operator<<(std::ostream& os, const VecEquityResponse& obj);
std::ostream& operator<<(std::ostream& os, const VecFutOptFilledResponse& obj);
std::ostream& operator<<(std::ostream& os, const VecFutOptHybridPositionResponse& obj);
std::ostream& operator<<(std::ostream& os, const VecFutOptOrderResponse& obj);
std::ostream& operator<<(std::ostream& os, const VecFutOptPositionResponse& obj);
std::ostream& operator<<(std::ostream& os, const VecOrderResponse& obj);
std::ostream& operator<<(std::ostream& os, const VecRecoverResponse& obj);
std::ostream& operator<<(std::ostream& os, const VecSymbolQuoteResponse& obj);

} // namespace fubon
