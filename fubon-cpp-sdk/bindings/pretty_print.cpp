#include "pretty_print.hpp"

namespace fubon {

std::string to_string(BsAction value) {
    switch (value) {
    case BsAction::BUY: return "Buy";
    case BsAction::SELL: return "Sell";
    case BsAction::UN_SUPPORTED: return "UnSupported";
    case BsAction::UN_DEFINED: return "UnDefined";
    default: return "Unknown";
    }
}

std::string to_string(CallPut value) {
    switch (value) {
    case CallPut::CALL: return "Call";
    case CallPut::PUT: return "Put";
    case CallPut::UN_SUPPORTED: return "UnSupported";
    case CallPut::UN_DEFINED: return "UnDefined";
    default: return "Unknown";
    }
}

std::string to_string(ConditionMarketType value) {
    switch (value) {
    case ConditionMarketType::COMMON: return "Common";
    case ConditionMarketType::FIXING: return "Fixing";
    case ConditionMarketType::ODD: return "Odd";
    case ConditionMarketType::INTRADAY_ODD: return "IntradayOdd";
    default: return "Unknown";
    }
}

std::string to_string(ConditionOrderType value) {
    switch (value) {
    case ConditionOrderType::STOCK: return "Stock";
    case ConditionOrderType::MARGIN: return "Margin";
    case ConditionOrderType::SHORT: return "Short";
    case ConditionOrderType::DAY_TRADE: return "DayTrade";
    default: return "Unknown";
    }
}

std::string to_string(ConditionPriceType value) {
    switch (value) {
    case ConditionPriceType::LIMIT: return "Limit";
    case ConditionPriceType::MARKET: return "Market";
    case ConditionPriceType::BID_PRICE: return "BidPrice";
    case ConditionPriceType::ASK_PRICE: return "AskPrice";
    case ConditionPriceType::MATCHED_PRICE: return "MatchedPrice";
    case ConditionPriceType::LIMIT_UP: return "LimitUp";
    case ConditionPriceType::LIMIT_DOWN: return "LimitDown";
    case ConditionPriceType::REFERENCE: return "Reference";
    default: return "Unknown";
    }
}

std::string to_string(ConditionStatus value) {
    switch (value) {
    case ConditionStatus::TYPE1: return "Type1";
    case ConditionStatus::TYPE2: return "Type2";
    case ConditionStatus::TYPE3: return "Type3";
    case ConditionStatus::TYPE4: return "Type4";
    case ConditionStatus::TYPE5: return "Type5";
    case ConditionStatus::TYPE6: return "Type6";
    case ConditionStatus::TYPE7: return "Type7";
    case ConditionStatus::TYPE8: return "Type8";
    case ConditionStatus::TYPE9: return "Type9";
    case ConditionStatus::TYPE10: return "Type10";
    case ConditionStatus::TYPE11: return "Type11";
    default: return "Unknown";
    }
}

std::string to_string(Direction value) {
    switch (value) {
    case Direction::UP: return "Up";
    case Direction::DOWN: return "Down";
    default: return "Unknown";
    }
}

std::string to_string(FutOptConditionMarketType value) {
    switch (value) {
    case FutOptConditionMarketType::FUTURE: return "Future";
    case FutOptConditionMarketType::OPTION: return "Option";
    case FutOptConditionMarketType::FUTURE_NIGHT: return "FutureNight";
    case FutOptConditionMarketType::OPTION_NIGHT: return "OptionNight";
    default: return "Unknown";
    }
}

std::string to_string(FutOptConditionOrderType value) {
    switch (value) {
    case FutOptConditionOrderType::NEW: return "New";
    case FutOptConditionOrderType::CLOSE: return "Close";
    default: return "Unknown";
    }
}

std::string to_string(FutOptConditionPriceType value) {
    switch (value) {
    case FutOptConditionPriceType::LIMIT: return "Limit";
    case FutOptConditionPriceType::MARKET: return "Market";
    case FutOptConditionPriceType::BID_PRICE: return "BidPrice";
    case FutOptConditionPriceType::ASK_PRICE: return "AskPrice";
    case FutOptConditionPriceType::MATCHED_PRICE: return "MatchedPrice";
    case FutOptConditionPriceType::LIMIT_UP: return "LimitUp";
    case FutOptConditionPriceType::LIMIT_DOWN: return "LimitDown";
    case FutOptConditionPriceType::REFERENCE: return "Reference";
    case FutOptConditionPriceType::RANGE_MARKET: return "RangeMarket";
    default: return "Unknown";
    }
}

std::string to_string(FutOptMarketType value) {
    switch (value) {
    case FutOptMarketType::FUTURE: return "Future";
    case FutOptMarketType::OPTION: return "Option";
    case FutOptMarketType::FUTURE_NIGHT: return "FutureNight";
    case FutOptMarketType::OPTION_NIGHT: return "OptionNight";
    case FutOptMarketType::UN_SUPPORTED: return "UnSupported";
    case FutOptMarketType::UN_DEFINED: return "UnDefined";
    default: return "Unknown";
    }
}

std::string to_string(FutOptOrderType value) {
    switch (value) {
    case FutOptOrderType::NEW: return "New";
    case FutOptOrderType::CLOSE: return "Close";
    case FutOptOrderType::AUTO: return "Auto";
    case FutOptOrderType::FDAY_TRADE: return "FdayTrade";
    case FutOptOrderType::UN_SUPPORTED: return "UnSupported";
    case FutOptOrderType::UN_DEFINED: return "UnDefined";
    default: return "Unknown";
    }
}

std::string to_string(FutOptPriceType value) {
    switch (value) {
    case FutOptPriceType::LIMIT: return "Limit";
    case FutOptPriceType::MARKET: return "Market";
    case FutOptPriceType::RANGE_MARKET: return "RangeMarket";
    case FutOptPriceType::REFERENCE: return "Reference";
    case FutOptPriceType::UN_SUPPORTED: return "UnSupported";
    case FutOptPriceType::UN_DEFINED: return "UnDefined";
    default: return "Unknown";
    }
}

std::string to_string(HistoryStatus value) {
    switch (value) {
    case HistoryStatus::TYPE1: return "Type1";
    case HistoryStatus::TYPE2: return "Type2";
    case HistoryStatus::TYPE3: return "Type3";
    case HistoryStatus::TYPE4: return "Type4";
    case HistoryStatus::TYPE5: return "Type5";
    case HistoryStatus::TYPE6: return "Type6";
    default: return "Unknown";
    }
}

std::string to_string(MarketType value) {
    switch (value) {
    case MarketType::COMMON: return "Common";
    case MarketType::FIXING: return "Fixing";
    case MarketType::ODD: return "Odd";
    case MarketType::INTRADAY_ODD: return "IntradayOdd";
    case MarketType::EMG: return "Emg";
    case MarketType::EMG_ODD: return "EmgOdd";
    case MarketType::UN_SUPPORTED: return "UnSupported";
    case MarketType::UN_DEFINED: return "UnDefined";
    default: return "Unknown";
    }
}

std::string to_string(Operator value) {
    switch (value) {
    case Operator::GREATER_THAN_OR_EQUAL: return "GreaterThanOrEqual";
    case Operator::LESS_THAN_OR_EQUAL: return "LessThanOrEqual";
    case Operator::GREATER_THAN: return "GreaterThan";
    case Operator::LESS_THAN: return "LessThan";
    default: return "Unknown";
    }
}

std::string to_string(OrderType value) {
    switch (value) {
    case OrderType::STOCK: return "Stock";
    case OrderType::MARGIN: return "Margin";
    case OrderType::SHORT: return "Short";
    case OrderType::SBL: return "SBL";
    case OrderType::DAY_TRADE: return "DayTrade";
    case OrderType::UN_SUPPORTED: return "UnSupported";
    case OrderType::UN_DEFINED: return "UnDefined";
    default: return "Unknown";
    }
}

std::string to_string(PriceType value) {
    switch (value) {
    case PriceType::LIMIT: return "Limit";
    case PriceType::MARKET: return "Market";
    case PriceType::LIMIT_UP: return "LimitUp";
    case PriceType::LIMIT_DOWN: return "LimitDown";
    case PriceType::REFERENCE: return "Reference";
    case PriceType::UN_SUPPORTED: return "UnSupported";
    case PriceType::UN_DEFINED: return "UnDefined";
    default: return "Unknown";
    }
}

std::string to_string(StockType value) {
    switch (value) {
    case StockType::STOCK: return "Stock";
    case StockType::COVERT_BOND: return "CovertBond";
    case StockType::ETF_AND_ETN: return "EtfAndEtn";
    default: return "Unknown";
    }
}

std::string to_string(StopSign value) {
    switch (value) {
    case StopSign::FULL: return "Full";
    case StopSign::PARTIAL: return "Partial";
    case StopSign::UNTIL_END: return "UntilEnd";
    default: return "Unknown";
    }
}

std::string to_string(TimeInForce value) {
    switch (value) {
    case TimeInForce::ROD: return "ROD";
    case TimeInForce::FOK: return "FOK";
    case TimeInForce::IOC: return "IOC";
    case TimeInForce::UN_SUPPORTED: return "UnSupported";
    case TimeInForce::UN_DEFINED: return "UnDefined";
    default: return "Unknown";
    }
}

std::string to_string(TimeSliceOrderType value) {
    switch (value) {
    case TimeSliceOrderType::TYPE1: return "Type1";
    case TimeSliceOrderType::TYPE2: return "Type2";
    case TimeSliceOrderType::TYPE3: return "Type3";
    case TimeSliceOrderType::TYPE4: return "Type4";
    case TimeSliceOrderType::TYPE5: return "Type5";
    case TimeSliceOrderType::TYPE6: return "Type6";
    case TimeSliceOrderType::TYPE7: return "Type7";
    default: return "Unknown";
    }
}

std::string to_string(TradingType value) {
    switch (value) {
    case TradingType::REFERENCE: return "Reference";
    case TradingType::INDEX: return "Index";
    case TradingType::SCHEDULED: return "Scheduled";
    default: return "Unknown";
    }
}

std::string to_string(TriggerContent value) {
    switch (value) {
    case TriggerContent::BID_PRICE: return "BidPrice";
    case TriggerContent::ASK_PRICE: return "AskPrice";
    case TriggerContent::MATCHED_PRICE: return "MatchedPrice";
    case TriggerContent::TOTAL_QUANTITY: return "TotalQuantity";
    case TriggerContent::TIME: return "Time";
    case TriggerContent::TOTAL_VALUE: return "TotalValue";
    default: return "Unknown";
    }
}

std::ostream& operator<<(std::ostream& os, const Account& obj) {
    os << "[Account]\n";
    os << "  name: " << obj.name << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  account_type: " << obj.account_type << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const AccountRes& obj) {
    os << "[AccountRes]\n";
    os << "  account: " << obj.account << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const BankRemain& obj) {
    os << "[BankRemain]\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  currency: " << obj.currency << "\n";
    os << "  balance: " << obj.balance << "\n";
    os << "  available_balance: " << obj.available_balance << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const BankRemainResponse& obj) {
    os << "[BankRemainResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const BatchResponse& obj) {
    os << "[BatchResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const BatchResult& obj) {
    os << "[BatchResult]\n";
    os << "  function_type: " << obj.function_type << "\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  batch_seq_no: " << obj.batch_seq_no << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const CancelResult& obj) {
    os << "[CancelResult]\n";
    os << "  reply: " << obj.reply << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const CloseRecord& obj) {
    os << "[CloseRecord]\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  position_kind: " << obj.position_kind << "\n";
    os << "  order_no: " << obj.order_no << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    os << "  market: " << obj.market << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  expiry_date: " << obj.expiry_date << "\n";
    os << "  strike_price: " << opt_str(obj.strike_price) << "\n";
    os << "  call_put: " << (obj.call_put.has_value() ? to_string(*obj.call_put) : "<null>") << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  price: " << obj.price << "\n";
    os << "  orig_lots: " << obj.orig_lots << "\n";
    os << "  transaction_fee: " << opt_str(obj.transaction_fee) << "\n";
    os << "  tax: " << opt_str(obj.tax) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Condition& obj) {
    os << "[Condition]\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  trigger: " << to_string(obj.trigger) << "\n";
    os << "  trigger_value: " << obj.trigger_value << "\n";
    os << "  comparison: " << to_string(obj.comparison) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ConditionDayTrade& obj) {
    os << "[ConditionDayTrade]\n";
    os << "  day_trade_end_time: " << obj.day_trade_end_time << "\n";
    os << "  auto_cancel: " << obj.auto_cancel << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  price_type: " << to_string(obj.price_type) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ConditionDetail& obj) {
    os << "[ConditionDetail]\n";
    os << "  guid: " << obj.guid << "\n";
    os << "  batch_no: " << obj.batch_no << "\n";
    os << "  order_level: " << obj.order_level << "\n";
    os << "  last_time: " << obj.last_time << "\n";
    os << "  condition_type: " << opt_str(obj.condition_type) << "\n";
    os << "  parent_guid: " << opt_str(obj.parent_guid) << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  order_amount: " << obj.order_amount << "\n";
    os << "  child_batch_no: " << obj.child_batch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  condition_content: " << obj.condition_content << "\n";
    os << "  action: " << obj.action << "\n";
    os << "  condition_buy_sell: " << obj.condition_buy_sell << "\n";
    os << "  condition_symbol: " << obj.condition_symbol << "\n";
    os << "  condition_price: " << obj.condition_price << "\n";
    os << "  condition_volume: " << obj.condition_volume << "\n";
    os << "  condition_filled_volume: " << obj.condition_filled_volume << "\n";
    os << "  create_time: " << obj.create_time << "\n";
    os << "  start_date: " << obj.start_date << "\n";
    os << "  status: " << obj.status << "\n";
    os << "  error_message: " << opt_str(obj.error_message) << "\n";
    os << "  detail_records_count: " << obj.detail_records_count << "\n";
    os << "  tpsl_count: " << obj.tpsl_count << "\n";
    if (!obj.detail_records.empty()) {
        os << "  Detail Records:\n";
        for (size_t i = 0; i < obj.detail_records.size(); ++i) {
            os << "    [" << i << "]\n";
            std::stringstream ss;
            ss << obj.detail_records[i];
            std::string line;
            while (std::getline(ss, line)) {
                os << "      " << line << "\n";
            }
        }
    } else {
        os << "  Detail Records: <empty>\n";
    }
    if (!obj.tpsl_record.empty()) {
        os << "  TPSL Records:\n";
        for (size_t i = 0; i < obj.tpsl_record.size(); ++i) {
            os << "    [" << i << "]\n";
            std::stringstream ss;
            ss << obj.tpsl_record[i];
            std::string line;
            while (std::getline(ss, line)) {
                os << "      " << line << "\n";
            }
        }
    } else {
        os << "  TPSL Records: <empty>\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const ConditionDetailResult& obj) {
    os << "[ConditionDetailResult]\n";
    if (obj.responses.has_value()) {
        if (!obj.responses->empty()) {
            os << "  Responses:\n";
            for (size_t i = 0; i < obj.responses->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.responses->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Responses: <empty>\n";
        }
    } else {
        os << "  Responses: <null>\n";
    }
    os << "  reply: " << obj.reply << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ConditionOrder& obj) {
    os << "[ConditionOrder]\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  quantity: " << obj.quantity << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  price_type: " << to_string(obj.price_type) << "\n";
    os << "  time_in_force: " << to_string(obj.time_in_force) << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ConditionOrderResult& obj) {
    os << "[ConditionOrderResult]\n";
    os << "  guid: " << opt_str(obj.guid) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ConditionOrderResultResponse& obj) {
    os << "[ConditionOrderResultResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ConditionResult& obj) {
    os << "[ConditionResult]\n";
    os << "  smart_order_response: " << obj.smart_order_response << "\n";
    os << "  reply: " << obj.reply << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const DayTradeStockInfo& obj) {
    os << "[DayTradeStockInfo]\n";
    os << "  stock_no: " << opt_str(obj.stock_no) << "\n";
    os << "  date: " << obj.date << "\n";
    os << "  daytrade_orig_quota: " << opt_str(obj.daytrade_orig_quota) << "\n";
    os << "  daytrade_tradable_quota: " << opt_str(obj.daytrade_tradable_quota) << "\n";
    os << "  precollect_single: " << opt_str(obj.precollect_single) << "\n";
    os << "  precollect_accumulate: " << opt_str(obj.precollect_accumulate) << "\n";
    os << "  status: " << opt_str(obj.status) << "\n";
    os << "  disposition_status: " << opt_str(obj.disposition_status) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const DayTradeStockInfoResponse& obj) {
    os << "[DayTradeStockInfoResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Equity& obj) {
    os << std::fixed << std::setprecision(2);
    os << "[Equity]\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  currency: " << obj.currency << "\n";
    os << "  yesterday_balance: " << obj.yesterday_balance << "\n";
    os << "  today_balance: " << obj.today_balance << "\n";
    os << "  initial_margin: " << obj.initial_margin << "\n";
    os << "  maintenance_margin: " << obj.maintenance_margin << "\n";
    os << "  clearing_margin: " << obj.clearing_margin << "\n";
    os << "  today_equity: " << obj.today_equity << "\n";
    os << "  today_deposit: " << obj.today_deposit << "\n";
    os << "  today_withdrawal: " << obj.today_withdrawal << "\n";
    os << "  today_trading_fee: " << obj.today_trading_fee << "\n";
    os << "  today_trading_tax: " << obj.today_trading_tax << "\n";
    os << "  receivable_premium: " << obj.receivable_premium << "\n";
    os << "  payable_premium: " << obj.payable_premium << "\n";
    os << "  excess_margin: " << obj.excess_margin << "\n";
    os << "  available_margin: " << obj.available_margin << "\n";
    os << "  disgorgement: " << obj.disgorgement << "\n";
    os << "  opt_pnl: " << obj.opt_pnl << "\n";
    os << "  opt_value: " << obj.opt_value << "\n";
    os << "  opt_long_value: " << obj.opt_long_value << "\n";
    os << "  opt_short_value: " << obj.opt_short_value << "\n";
    os << "  fut_realized_pnl: " << obj.fut_realized_pnl << "\n";
    os << "  fut_unrealized_pnl: " << obj.fut_unrealized_pnl << "\n";
    os << "  buy_lot: " << obj.buy_lot << "\n";
    os << "  sell_lot: " << obj.sell_lot << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const EstimateMargin& obj) {
    os << "[EstimateMargin]\n";
    os << "  date: " << obj.date << "\n";
    os << "  currency: " << obj.currency << "\n";
    os << "  estimate_margin: " << obj.estimate_margin << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const EstimateMarginResponse& obj) {
    os << "[EstimateMarginResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FilledData& obj) {
    os << "[FilledData]\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  order_no: " << obj.order_no << "\n";
    os << "  seq_no: " << opt_str(obj.seq_no) << "\n";
    os << "  stock_no: " << obj.stock_no << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  filled_no: " << obj.filled_no << "\n";
    os << "  filled_avg_price: " << obj.filled_avg_price << "\n";
    os << "  filled_qty: " << obj.filled_qty << "\n";
    os << "  filled_price: " << obj.filled_price << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    os << "  filled_time: " << obj.filled_time << "\n";
    os << "  user_def: " << opt_str(obj.user_def) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FilledResponse& obj) {
    os << "[FilledResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptConditionOrder& obj) {
    os << "[FutOptConditionOrder]\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  lot: " << opt_str(obj.lot) << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  price_type: " << to_string(obj.price_type) << "\n";
    os << "  time_in_force: " << to_string(obj.time_in_force) << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptFilledData& obj) {
    os << "[FutOptFilledData]\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  order_no: " << obj.order_no << "\n";
    os << "  seq_no: " << opt_str(obj.seq_no) << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  filled_no: " << obj.filled_no << "\n";
    os << "  filled_avg_price: " << obj.filled_avg_price << "\n";
    os << "  filled_lot: " << obj.filled_lot << "\n";
    os << "  filled_price: " << obj.filled_price << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    os << "  filled_time: " << obj.filled_time << "\n";
    os << "  expiry_date: " << opt_str(obj.expiry_date) << "\n";
    os << "  strike_price: " << opt_str(obj.strike_price) << "\n";
    os << "  call_put: " << (obj.call_put.has_value() ? to_string(*obj.call_put) : "<null>") << "\n";
    os << "  symbol_leg2: " << opt_str(obj.symbol_leg2) << "\n";
    os << "  expiry_date_leg2: " << opt_str(obj.expiry_date_leg2) << "\n";
    os << "  strike_price_leg2: " << opt_str(obj.strike_price_leg2) << "\n";
    os << "  call_put_leg2: " << (obj.call_put_leg2.has_value() ? to_string(*obj.call_put_leg2) : "<null>") << "\n";
    os << "  buy_sell_leg2: " << (obj.buy_sell_leg2.has_value() ? to_string(*obj.buy_sell_leg2) : "<null>") << "\n";
    os << "  user_def: " << opt_str(obj.user_def) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptModifyLot& obj) {
    os << "[FutOptModifyLot]\n";
    os << "  txse: " << obj.txse << "\n";
    os << "  order_no: " << obj.order_no << "\n";
    os << "  date: " << obj.date << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  asty: " << obj.asty << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  new_quantity: " << obj.new_quantity << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptModifyPrice& obj) {
    os << "[FutOptModifyPrice]\n";
    os << "  txse: " << obj.txse << "\n";
    os << "  order_no: " << obj.order_no << "\n";
    os << "  date: " << obj.date << "\n";
    os << "  asty: " << obj.asty << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  price_type: " << to_string(obj.price_type) << "\n";
    os << "  stock_no: " << obj.stock_no << "\n";
    os << "  new_price: " << opt_str(obj.new_price) << "\n";
    os << "  new_price_type: " << (obj.new_price_type.has_value() ? to_string(*obj.new_price_type) : "<null>") << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptOrder& obj) {
    os << "[FutOptOrder]\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  buy_sell2: " << (obj.buy_sell2.has_value() ? to_string(*obj.buy_sell2) : "<null>") << "\n";
    os << "  symbol2: " << opt_str(obj.symbol2) << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  lot: " << obj.lot << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  price_type: " << to_string(obj.price_type) << "\n";
    os << "  time_in_force: " << to_string(obj.time_in_force) << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    os << "  user_def: " << opt_str(obj.user_def) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptOrderDetail& obj) {
    os << "[FutOptOrderDetail]\n";
    os << "  function_type: " << opt_str(obj.function_type) << "\n";
    os << "  modified_time: " << obj.modified_time << "\n";
    os << "  before_lot: " << opt_str(obj.before_lot) << "\n";
    os << "  after_lot: " << opt_str(obj.after_lot) << "\n";
    os << "  before_price: " << opt_str(obj.before_price) << "\n";
    os << "  after_price: " << opt_str(obj.after_price) << "\n";
    os << "  filled_money: " << opt_str(obj.filled_money) << "\n";
    os << "  error_message: " << opt_str(obj.error_message) << "\n";
    os << "  status: " << opt_str(obj.status) << "\n";
    os << "  err_msg: " << opt_str(obj.err_msg) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptOrderResponse& obj) {
    os << "[FutOptOrderResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptOrderResult& obj) {
    os << "[FutOptOrderResult]\n";
    os << "  function_type: " << opt_str(obj.function_type) << "\n";
    os << "  date: " << obj.date << "\n";
    os << "  seq_no: " << obj.seq_no << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  order_no: " << opt_str(obj.order_no) << "\n";
    os << "  asset_type: " << opt_str(obj.asset_type) << "\n";
    os << "  market: " << opt_str(obj.market) << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  symbol: " << opt_str(obj.symbol) << "\n";
    os << "  unit: " << opt_str(obj.unit) << "\n";
    os << "  currency: " << opt_str(obj.currency) << "\n";
    os << "  expiry_date: " << opt_str(obj.expiry_date) << "\n";
    os << "  strike_price: " << opt_str(obj.strike_price) << "\n";
    os << "  call_put: " << (obj.call_put.has_value() ? to_string(*obj.call_put) : "<null>") << "\n";
    os << "  buy_sell: " << (obj.buy_sell.has_value() ? to_string(*obj.buy_sell) : "<null>") << "\n";
    os << "  symbol_leg2: " << opt_str(obj.symbol_leg2) << "\n";
    os << "  expiry_date_leg2: " << opt_str(obj.expiry_date_leg2) << "\n";
    os << "  strike_price_leg2: " << opt_str(obj.strike_price_leg2) << "\n";
    os << "  call_put_leg2: " << (obj.call_put_leg2.has_value() ? to_string(*obj.call_put_leg2) : "<null>") << "\n";
    os << "  buy_sell_leg2: " << (obj.buy_sell_leg2.has_value() ? to_string(*obj.buy_sell_leg2) : "<null>") << "\n";
    os << "  price_type: " << (obj.price_type.has_value() ? to_string(*obj.price_type) : "<null>") << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  after_price: " << opt_str(obj.after_price) << "\n";
    os << "  lot: " << opt_str(obj.lot) << "\n";
    os << "  after_lot: " << opt_str(obj.after_lot) << "\n";
    os << "  time_in_force: " << (obj.time_in_force.has_value() ? to_string(*obj.time_in_force) : "<null>") << "\n";
    os << "  order_type: " << (obj.order_type.has_value() ? to_string(*obj.order_type) : "<null>") << "\n";
    os << "  status: " << opt_str(obj.status) << "\n";
    os << "  is_pre_order: " << obj.is_pre_order << "\n";
    os << "  after_price_type: " << (obj.after_price_type.has_value() ? to_string(*obj.after_price_type) : "<null>") << "\n";
    os << "  filled_lot: " << opt_str(obj.filled_lot) << "\n";
    os << "  filled_money: " << opt_str(obj.filled_money) << "\n";
    os << "  before_lot: " << opt_str(obj.before_lot) << "\n";
    os << "  before_price: " << opt_str(obj.before_price) << "\n";
    os << "  user_def: " << opt_str(obj.user_def) << "\n";
    os << "  last_time: " << obj.last_time << "\n";
    os << "  error_message: " << opt_str(obj.error_message) << "\n";
    if (obj.details.has_value()) {
        if (!obj.details->empty()) {
            os << "  Order Details:\n";
            for (size_t i = 0; i < obj.details->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.details->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Order Details: <empty>\n";
        }
    } else {
        os << "  Order Details: <null>\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptTPSLWrapper& obj) {
    os << "[FutOptTPSLWrapper]\n";
    os << "  stop_sign: " << to_string(obj.stop_sign) << "\n";
    os << "  tp: " << opt_str(obj.tp) << "\n";
    os << "  sl: " << opt_str(obj.sl) << "\n";
    os << "  end_date: " << opt_str(obj.end_date) << "\n";
    os << "  intraday: " << opt_str(obj.intraday) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const FutOptTrailOrder& obj) {
    os << "[FutOptTrailOrder]\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  price: " << obj.price << "\n";
    os << "  direction: " << to_string(obj.direction) << "\n";
    os << "  tick_num: " << obj.tick_num << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  lot: " << obj.lot << "\n";
    os << "  price_type: " << to_string(obj.price_type) << "\n";
    os << "  diff: " << obj.diff << "\n";
    os << "  time_in_force: " << to_string(obj.time_in_force) << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const HybridPosition& obj) {
    os << "[HybridPosition]\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  is_spread: " << obj.is_spread << "\n";
    os << "  position_kind: " << obj.position_kind << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  expiry_date: " << obj.expiry_date << "\n";
    os << "  strike_price: " << opt_str(obj.strike_price) << "\n";
    os << "  call_put: " << (obj.call_put.has_value() ? to_string(*obj.call_put) : "<null>") << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  orig_lots: " << obj.orig_lots << "\n";
    os << "  tradable_lot: " << obj.tradable_lot << "\n";
    os << "  order_type: " << (obj.order_type.has_value() ? to_string(*obj.order_type) : "<null>") << "\n";
    os << "  currency: " << opt_str(obj.currency) << "\n";
    os << "  market_price: " << obj.market_price << "\n";
    os << "  initial_margin: " << obj.initial_margin << "\n";
    os << "  maintenance_margin: " << obj.maintenance_margin << "\n";
    os << "  clearing_margin: " << obj.clearing_margin << "\n";
    os << "  initial_margin_all_single: " << obj.initial_margin_all_single << "\n";
    os << "  opt_value: " << obj.opt_value << "\n";
    os << "  opt_long_value: " << obj.opt_long_value << "\n";
    os << "  opt_short_value: " << obj.opt_short_value << "\n";
    os << "  profit_or_loss: " << obj.profit_or_loss << "\n";
    os << "  premium: " << obj.premium << "\n";
    if (obj.spreads.has_value()) {
        if (!obj.spreads->empty()) {
            os << "  Order Details:\n";
            for (size_t i = 0; i < obj.spreads->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.spreads->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Order Details: <empty>\n";
        }
    } else {
        os << "  Order Details: <null>\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Inventory& obj) {
    os << "[Inventory]\n";
    os << "  date: " << obj.date << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  stock_no: " << obj.stock_no << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    os << "  lastday_qty: " << obj.lastday_qty << "\n";
    os << "  buy_qty: " << obj.buy_qty << "\n";
    os << "  buy_filled_qty: " << obj.buy_filled_qty << "\n";
    os << "  buy_value: " << obj.buy_value << "\n";
    os << "  today_qty: " << obj.today_qty << "\n";
    os << "  tradable_qty: " << obj.tradable_qty << "\n";
    os << "  sell_qty: " << obj.sell_qty << "\n";
    os << "  sell_filled_qty: " << obj.sell_filled_qty << "\n";
    os << "  sell_value: " << obj.sell_value << "\n";
    os << "  odd: " << obj.odd << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const InventoryOdd& obj) {
    os << "[InventoryOdd]\n";
    os << "  lastday_qty: " << obj.lastday_qty << "\n";
    os << "  buy_qty: " << obj.buy_qty << "\n";
    os << "  buy_filled_qty: " << obj.buy_filled_qty << "\n";
    os << "  buy_value: " << obj.buy_value << "\n";
    os << "  today_qty: " << obj.today_qty << "\n";
    os << "  tradable_qty: " << obj.tradable_qty << "\n";
    os << "  sell_qty: " << obj.sell_qty << "\n";
    os << "  sell_filled_qty: " << obj.sell_filled_qty << "\n";
    os << "  sell_value: " << obj.sell_value << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const InventoryResponse& obj) {
    os << "[InventoryResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const LoginResponse& obj) {
    os << "[LoginResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MaintenanceData& obj) {
    os << "[MaintenanceData]\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  maintenance_summary: " << obj.maintenance_summary << "\n";
    if (!obj.maintenance_detail.empty()) {
        os << "  Maintenance Details:\n";
        for (size_t i = 0; i < obj.maintenance_detail.size(); ++i) {
            os << "    [" << i << "]\n";
            std::stringstream ss;
            ss << obj.maintenance_detail[i];
            std::string line;
            while (std::getline(ss, line)) {
                os << "      " << line << "\n";
            }
        }
    } else {
        os << "  Maintenance Details: <empty>\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const MaintenanceDetail& obj) {
    os << "[MaintenanceDetail]\n";
    os << "  stock_no: " << obj.stock_no << "\n";
    os << "  order_no: " << obj.order_no << "\n";
    os << "  order_type: " << (obj.order_type.has_value() ? to_string(*obj.order_type) : "<null>") << "\n";
    os << "  quantity: " << opt_str(obj.quantity) << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  cost_price: " << opt_str(obj.cost_price) << "\n";
    os << "  shortsell_margin: " << opt_str(obj.shortsell_margin) << "\n";
    os << "  collateral: " << opt_str(obj.collateral) << "\n";
    os << "  margin_loan_amt: " << opt_str(obj.margin_loan_amt) << "\n";
    os << "  maintenance_ratio: " << opt_str(obj.maintenance_ratio) << "\n";
    os << "  collateral_interest: " << opt_str(obj.collateral_interest) << "\n";
    os << "  margin_interest: " << opt_str(obj.margin_interest) << "\n";
    os << "  shortsell_interest: " << opt_str(obj.shortsell_interest) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MaintenanceResponse& obj) {
    os << "[MaintenanceResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MaintenanceSummary& obj) {
    os << "[MaintenanceSummary]\n";
    os << "  margin_value: " << obj.margin_value << "\n";
    os << "  shortsell_value: " << obj.shortsell_value << "\n";
    os << "  shortsell_margin: " << opt_str(obj.shortsell_margin) << "\n";
    os << "  collateral: " << opt_str(obj.collateral) << "\n";
    os << "  margin_loan_amt: " << obj.margin_loan_amt << "\n";
    os << "  maintenance_ratio: " << obj.maintenance_ratio << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MarginShortQuota& obj) {
    os << "[MarginShortQuota]\n";
    os << "  stock_no: " << opt_str(obj.stock_no) << "\n";
    os << "  date: " << obj.date << "\n";
    os << "  shortsell_orig_quota: " << opt_str(obj.shortsell_orig_quota) << "\n";
    os << "  shortsell_tradable_quota: " << opt_str(obj.shortsell_tradable_quota) << "\n";
    os << "  margin_orig_quota: " << opt_str(obj.margin_orig_quota) << "\n";
    os << "  margin_tradable_quota: " << opt_str(obj.margin_tradable_quota) << "\n";
    os << "  margin_ratio: " << opt_str(obj.margin_ratio) << "\n";
    os << "  short_ratio: " << opt_str(obj.short_ratio) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const MarginShortQuotaResponse& obj) {
    os << "[MarginShortQuotaResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ModifyPrice& obj) {
    os << "[ModifyPrice]\n";
    os << "  txse: " << obj.txse << "\n";
    os << "  order_no: " << obj.order_no << "\n";
    os << "  date: " << obj.date << "\n";
    os << "  asty: " << obj.asty << "\n";
    os << "  price_type: " << to_string(obj.price_type) << "\n";
    os << "  stock_no: " << obj.stock_no << "\n";
    os << "  new_price: " << opt_str(obj.new_price) << "\n";
    os << "  new_price_type: " << (obj.new_price_type.has_value() ? to_string(*obj.new_price_type) : "<null>") << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const ModifyQuantity& obj) {
    os << "[ModifyQuantity]\n";
    os << "  txse: " << obj.txse << "\n";
    os << "  order_no: " << obj.order_no << "\n";
    os << "  date: " << obj.date << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  asty: " << obj.asty << "\n";
    os << "  stock_no: " << obj.stock_no << "\n";
    os << "  new_quantity: " << obj.new_quantity << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Order& obj) {
    os << "[Order]\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  quantity: " << obj.quantity << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  price_type: " << to_string(obj.price_type) << "\n";
    os << "  time_in_force: " << to_string(obj.time_in_force) << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    os << "  user_def: " << opt_str(obj.user_def) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const OrderDetail& obj) {
    os << "[OrderDetail]\n";
    os << "  function_type: " << opt_str(obj.function_type) << "\n";
    os << "  modified_time: " << obj.modified_time << "\n";
    os << "  before_qty: " << opt_str(obj.before_qty) << "\n";
    os << "  after_qty: " << opt_str(obj.after_qty) << "\n";
    os << "  before_price: " << opt_str(obj.before_price) << "\n";
    os << "  after_price: " << opt_str(obj.after_price) << "\n";
    os << "  filled_money: " << opt_str(obj.filled_money) << "\n";
    os << "  status: " << opt_str(obj.status) << "\n";
    os << "  err_msg: " << opt_str(obj.err_msg) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const OrderResponse& obj) {
    os << "[OrderResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const OrderResult& obj) {
    os << "[OrderResult]\n";
    os << "  function_type: " << opt_str(obj.function_type) << "\n";
    os << "  date: " << obj.date << "\n";
    os << "  seq_no: " << obj.seq_no << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  order_no: " << opt_str(obj.order_no) << "\n";
    os << "  asset_type: " << opt_str(obj.asset_type) << "\n";
    os << "  market: " << opt_str(obj.market) << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  stock_no: " << opt_str(obj.stock_no) << "\n";
    os << "  buy_sell: " << (obj.buy_sell.has_value() ? to_string(*obj.buy_sell) : "<null>") << "\n";
    os << "  price_type: " << (obj.price_type.has_value() ? to_string(*obj.price_type) : "<null>") << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  quantity: " << opt_str(obj.quantity) << "\n";
    os << "  time_in_force: " << (obj.time_in_force.has_value() ? to_string(*obj.time_in_force) : "<null>") << "\n";
    os << "  order_type: " << (obj.order_type.has_value() ? to_string(*obj.order_type) : "<null>") << "\n";
    os << "  is_pre_order: " << obj.is_pre_order << "\n";
    os << "  status: " << opt_str(obj.status) << "\n";
    os << "  after_price_type: " << (obj.after_price_type.has_value() ? to_string(*obj.after_price_type) : "<null>") << "\n";
    os << "  after_price: " << opt_str(obj.after_price) << "\n";
    os << "  unit: " << opt_str(obj.unit) << "\n";
    os << "  after_qty: " << opt_str(obj.after_qty) << "\n";
    os << "  filled_qty: " << opt_str(obj.filled_qty) << "\n";
    os << "  filled_money: " << opt_str(obj.filled_money) << "\n";
    os << "  before_qty: " << opt_str(obj.before_qty) << "\n";
    os << "  before_price: " << opt_str(obj.before_price) << "\n";
    os << "  user_def: " << opt_str(obj.user_def) << "\n";
    os << "  last_time: " << obj.last_time << "\n";
    os << "  error_message: " << opt_str(obj.error_message) << "\n";
    if (obj.details.has_value()) {
        if (!obj.details->empty()) {
            os << "  Order Details:\n";
            for (size_t i = 0; i < obj.details->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.details->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Order Details: <empty>\n";
        }
    } else {
        os << "  Order Details: <null>\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const ParentChildRecord& obj) {
    os << "[ParentChildRecord]\n";
    os << "  guid: " << opt_str(obj.guid) << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  condition_content: " << obj.condition_content << "\n";
    os << "  action: " << obj.action << "\n";
    os << "  condition_buy_sell: " << obj.condition_buy_sell << "\n";
    os << "  condition_symbol: " << obj.condition_symbol << "\n";
    os << "  condition_price: " << obj.condition_price << "\n";
    os << "  condition_volume: " << obj.condition_volume << "\n";
    os << "  condition_filled_volume: " << obj.condition_filled_volume << "\n";
    os << "  start_date: " << obj.start_date << "\n";
    os << "  status: " << obj.status << "\n";
    os << "  error_message: " << obj.error_message << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Position& obj) {
    os << "[Position]\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  position_kind: " << obj.position_kind << "\n";
    os << "  order_no: " << obj.order_no << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  expiry_date: " << obj.expiry_date << "\n";
    os << "  strike_price: " << opt_str(obj.strike_price) << "\n";
    os << "  call_put: " << (obj.call_put.has_value() ? to_string(*obj.call_put) : "<null>") << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  orig_lots: " << obj.orig_lots << "\n";
    os << "  tradable_lot: " << obj.tradable_lot << "\n";
    os << "  order_type: " << (obj.order_type.has_value() ? to_string(*obj.order_type) : "<null>") << "\n";
    os << "  currency: " << opt_str(obj.currency) << "\n";
    os << "  profit_or_loss: " << obj.profit_or_loss << "\n";
    os << "  market_price: " << obj.market_price << "\n";
    os << "  initial_margin: " << obj.initial_margin << "\n";
    os << "  maintenance_margin: " << obj.maintenance_margin << "\n";
    os << "  clearing_margin: " << obj.clearing_margin << "\n";
    os << "  premium: " << obj.premium << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Realized& obj) {
    os << "[Realized]\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  stock_no: " << obj.stock_no << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  filled_qty: " << obj.filled_qty << "\n";
    os << "  filled_price: " << obj.filled_price << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    os << "  realized_profit: " << obj.realized_profit << "\n";
    os << "  realized_loss: " << obj.realized_loss << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const RealizedResponse& obj) {
    os << "[RealizedResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const RealizedSummary& obj) {
    os << "[RealizedSummary]\n";
    os << "  start_date: " << obj.start_date << "\n";
    os << "  end_date: " << obj.end_date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  stock_no: " << obj.stock_no << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    os << "  filled_qty: " << obj.filled_qty << "\n";
    os << "  filled_avg_price: " << obj.filled_avg_price << "\n";
    os << "  realized_profit_and_loss: " << obj.realized_profit_and_loss << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const RealizedSummaryResponse& obj) {
    os << "[RealizedSummaryResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Recover& obj) {
    os << "[Recover]\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  account_type: " << obj.account_type << "\n";
    os << "  recover_type: " << obj.recover_type << "\n";
    os << "  recover_count: " << obj.recover_count << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Reply& obj) {
    os << "[Reply]\n";
    os << "  reply_code: " << obj.reply_code << "\n";
    os << "  advisory: " << obj.advisory << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SdkRef& obj) {
    os << "[SdkRef]\n";
    os << "  stock: " << obj.stock << "\n";
    os << "  accounting: " << obj.accounting << "\n";
    os << "  futopt: " << obj.futopt << "\n";
    os << "  futopt_accounting: " << obj.futopt_accounting << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Settlement& obj) {
    os << "[Settlement]\n";
    os << "  date: " << obj.date << "\n";
    os << "  settlement_date: " << opt_str(obj.settlement_date) << "\n";
    os << "  buy_value: " << opt_str(obj.buy_value) << "\n";
    os << "  buy_fee: " << opt_str(obj.buy_fee) << "\n";
    os << "  buy_settlement: " << opt_str(obj.buy_settlement) << "\n";
    os << "  buy_tax: " << opt_str(obj.buy_tax) << "\n";
    os << "  sell_value: " << opt_str(obj.sell_value) << "\n";
    os << "  sell_fee: " << opt_str(obj.sell_fee) << "\n";
    os << "  sell_settlement: " << opt_str(obj.sell_settlement) << "\n";
    os << "  sell_tax: " << opt_str(obj.sell_tax) << "\n";
    os << "  total_bs_value: " << opt_str(obj.total_bs_value) << "\n";
    os << "  total_fee: " << opt_str(obj.total_fee) << "\n";
    os << "  total_tax: " << opt_str(obj.total_tax) << "\n";
    os << "  total_settlement_amount: " << opt_str(obj.total_settlement_amount) << "\n";
    os << "  currency: " << opt_str(obj.currency) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SettlementData& obj) {
    os << "[SettlementData]\n";
    os << "  account: " << obj.account << "\n";
    if (obj.details.has_value()) {
        if (!obj.details->empty()) {
            os << "  Order Details:\n";
            for (size_t i = 0; i < obj.details->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.details->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Order Details: <empty>\n";
        }
    } else {
        os << "  Order Details: <null>\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const SettlementResponse& obj) {
    os << "[SettlementResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SplitDescription& obj) {
    os << "[SplitDescription]\n";
    os << "  method: " << to_string(obj.method) << "\n";
    os << "  interval: " << obj.interval << "\n";
    os << "  single_quantity: " << obj.single_quantity << "\n";
    os << "  total_quantity: " << opt_str(obj.total_quantity) << "\n";
    os << "  start_time: " << obj.start_time << "\n";
    os << "  end_time: " << opt_str(obj.end_time) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SpreadPosition& obj) {
    os << "[SpreadPosition]\n";
    os << "  date: " << obj.date << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  position_kind: " << obj.position_kind << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  expiry_date: " << obj.expiry_date << "\n";
    os << "  strike_price: " << opt_str(obj.strike_price) << "\n";
    os << "  call_put: " << (obj.call_put.has_value() ? to_string(*obj.call_put) : "<null>") << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  price: " << opt_str(obj.price) << "\n";
    os << "  orig_lots: " << obj.orig_lots << "\n";
    os << "  tradable_lot: " << obj.tradable_lot << "\n";
    os << "  order_type: " << (obj.order_type.has_value() ? to_string(*obj.order_type) : "<null>") << "\n";
    os << "  currency: " << opt_str(obj.currency) << "\n";
    os << "  market_price: " << obj.market_price << "\n";
    os << "  initial_margin: " << obj.initial_margin << "\n";
    os << "  maintenance_margin: " << obj.maintenance_margin << "\n";
    os << "  clearing_margin: " << obj.clearing_margin << "\n";
    os << "  initial_margin_all_single: " << obj.initial_margin_all_single << "\n";
    os << "  opt_value: " << obj.opt_value << "\n";
    os << "  opt_long_value: " << obj.opt_long_value << "\n";
    os << "  opt_short_value: " << obj.opt_short_value << "\n";
    os << "  profit_or_loss: " << obj.profit_or_loss << "\n";
    os << "  premium: " << obj.premium << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const StringResponse& obj) {
    os << "[StringResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SymbolQuote& obj) {
    os << "[SymbolQuote]\n";
    os << "  market: " << obj.market << "\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  istib_or_psb: " << obj.istib_or_psb << "\n";
    os << "  market_type: " << to_string(obj.market_type) << "\n";
    os << "  status: " << opt_str(obj.status) << "\n";
    os << "  reference_price: " << opt_str(obj.reference_price) << "\n";
    os << "  unit: " << obj.unit << "\n";
    os << "  update_time: " << obj.update_time << "\n";
    os << "  limitup_price: " << opt_str(obj.limitup_price) << "\n";
    os << "  limitdown_price: " << opt_str(obj.limitdown_price) << "\n";
    os << "  open_price: " << opt_str(obj.open_price) << "\n";
    os << "  high_price: " << opt_str(obj.high_price) << "\n";
    os << "  low_price: " << opt_str(obj.low_price) << "\n";
    os << "  last_price: " << opt_str(obj.last_price) << "\n";
    os << "  total_volume: " << opt_str(obj.total_volume) << "\n";
    os << "  total_transaction: " << opt_str(obj.total_transaction) << "\n";
    os << "  total_value: " << opt_str(obj.total_value) << "\n";
    os << "  last_size: " << opt_str(obj.last_size) << "\n";
    os << "  last_transaction: " << opt_str(obj.last_transaction) << "\n";
    os << "  last_value: " << opt_str(obj.last_value) << "\n";
    os << "  bid_price: " << opt_str(obj.bid_price) << "\n";
    os << "  bid_volume: " << opt_str(obj.bid_volume) << "\n";
    os << "  ask_price: " << opt_str(obj.ask_price) << "\n";
    os << "  ask_volume: " << opt_str(obj.ask_volume) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const SymbolQuoteResponse& obj) {
    os << "[SymbolQuoteResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    os << "  data: " << opt_str(obj.data) << "\n";
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const TPSLWrapper& obj) {
    os << "[TPSLWrapper]\n";
    os << "  stop_sign: " << to_string(obj.stop_sign) << "\n";
    os << "  tp: " << opt_str(obj.tp) << "\n";
    os << "  sl: " << opt_str(obj.sl) << "\n";
    os << "  end_date: " << opt_str(obj.end_date) << "\n";
    os << "  intraday: " << opt_str(obj.intraday) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const TrailOrder& obj) {
    os << "[TrailOrder]\n";
    os << "  symbol: " << obj.symbol << "\n";
    os << "  price: " << obj.price << "\n";
    os << "  direction: " << to_string(obj.direction) << "\n";
    os << "  percentage: " << obj.percentage << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  quantity: " << obj.quantity << "\n";
    os << "  price_type: " << to_string(obj.price_type) << "\n";
    os << "  diff: " << obj.diff << "\n";
    os << "  time_in_force: " << to_string(obj.time_in_force) << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const UnRealizedResponse& obj) {
    os << "[UnRealizedResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Unrealized& obj) {
    os << "[Unrealized]\n";
    os << "  date: " << obj.date << "\n";
    os << "  account: " << obj.account << "\n";
    os << "  branch_no: " << obj.branch_no << "\n";
    os << "  stock_no: " << obj.stock_no << "\n";
    os << "  buy_sell: " << to_string(obj.buy_sell) << "\n";
    os << "  order_type: " << to_string(obj.order_type) << "\n";
    os << "  cost_price: " << obj.cost_price << "\n";
    os << "  tradable_qty: " << obj.tradable_qty << "\n";
    os << "  today_qty: " << obj.today_qty << "\n";
    os << "  unrealized_profit: " << obj.unrealized_profit << "\n";
    os << "  unrealized_loss: " << obj.unrealized_loss << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecCloseRecordResponse& obj) {
    os << "[VecCloseRecordResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecConditionDetailResponse& obj) {
    os << "[VecConditionDetailResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecEquityResponse& obj) {
    os << "[VecEquityResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecFutOptFilledResponse& obj) {
    os << "[VecFutOptFilledResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecFutOptHybridPositionResponse& obj) {
    os << "[VecFutOptHybridPositionResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecFutOptOrderResponse& obj) {
    os << "[VecFutOptOrderResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecFutOptPositionResponse& obj) {
    os << "[VecFutOptPositionResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecOrderResponse& obj) {
    os << "[VecOrderResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecRecoverResponse& obj) {
    os << "[VecRecoverResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

std::ostream& operator<<(std::ostream& os, const VecSymbolQuoteResponse& obj) {
    os << "[VecSymbolQuoteResponse]\n";
    os << "  is_success: " << obj.is_success << "\n";
    if (obj.data.has_value()) {
        if (!obj.data->empty()) {
            os << "  Data:\n";
            for (size_t i = 0; i < obj.data->size(); ++i) {
                os << "    [" << i << "]\n";
                std::stringstream ss;
                ss << obj.data->at(i);
                std::string line;
                while (std::getline(ss, line)) {
                    os << "      " << line << "\n";
                }
            }
        } else {
            os << "  Data: <empty>\n";
        }
    } else {
        os << "  Data: <null>\n";
    }
    os << "  message: " << opt_str(obj.message) << "\n";
    return os;
}

} // namespace fubon
