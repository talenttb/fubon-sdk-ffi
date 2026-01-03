# 富邦 C++ SDK 完整功能清單

**版本**: v2.2.6
**文檔日期**: 2026-01-03

---

## SDK 模組架構

```
FubonSDK
├── FubonCore (核心管理)
│   ├── login()
│   ├── dma_login()
│   └── register_callback()
│
├── Accounting (證券帳務查詢)
│   ├── bank_remain()
│   ├── inventories()
│   ├── maintenance()
│   ├── query_settlement()
│   ├── realized_gains_and_loses()
│   ├── realized_gains_and_loses_summary()
│   └── unrealized_gains_and_loses()
│
├── StockFunctions (證券交易)
│   ├── 基本下單
│   ├── 批次操作
│   ├── 條件單
│   ├── 智慧單
│   └── 查詢功能
│
├── FutOptFunctions (期貨選擇權交易)
│   ├── 基本下單
│   ├── 批次操作
│   ├── 條件單
│   ├── 智慧單
│   └── 查詢功能
│
└── FutOptAccounting (期貨帳務查詢)
    ├── close_position_record()
    ├── query_hybrid_position()
    ├── query_margin_equity()
    └── query_single_position()
```

---

## 1. FubonCore（核心管理）

### 1.1 認證功能

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `login()` | personal_id, password, cert_path, cert_pass | `LoginResponse` | 一般憑證登入 |
| `dma_login()` | personal_id, password | `LoginResponse` | DMA 登入 |

### 1.2 Callback 註冊

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `register_callback()` | Callback* | void | 註冊事件回調 |

**Callback 介面包含 7 個虛函數**：
- `on_order()` - 證券委託回報
- `on_order_changed()` - 證券委託異動
- `on_filled()` - 證券成交回報
- `on_futopt_order()` - 期貨委託回報
- `on_futopt_order_changed()` - 期貨委託異動
- `on_futopt_filled()` - 期貨成交回報
- `on_event()` - 系統事件通知

---

## 2. Accounting（證券帳務查詢）- 7 個 API

### 2.1 基本帳務查詢

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `bank_remain()` | Account | `BankRemainResponse` | 查詢銀行餘額 |
| `inventories()` | Account | `InventoryResponse` | 查詢庫存 |
| `maintenance()` | Account | `MaintenanceResponse` | 查詢維持率 |
| `query_settlement()` | Account, range | `SettlementResponse` | 查詢交割資訊 |

### 2.2 損益查詢

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `realized_gains_and_loses()` | Account | `RealizedResponse` | 已實現損益明細 |
| `realized_gains_and_loses_summary()` | Account | `RealizedSummaryResponse` | 已實現損益彙總 |
| `unrealized_gains_and_loses()` | Account | `UnRealizedResponse` | 未實現損益 |

**數據結構清單**：
- `BankRemain` - 銀行餘額（5 欄位）
- `Inventory` - 庫存（15 欄位 + 嵌套 InventoryOdd）
- `MaintenanceData` - 維持率（Summary + Details 陣列）
- `Settlement` - 交割（14 個 optional 欄位）
- `Realized`, `Unrealized` - 損益資料

---

## 3. StockFunctions（證券交易）- 60+ API

### 3.1 基本下單操作

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `place_order()` | Account, Order, unblock? | `OrderResponse` | 下單 |
| `cancel_order()` | Account, OrderResult, unblock? | `OrderResponse` | 取消委託 |
| `modify_price()` | Account, ModifyPrice, unblock? | `OrderResponse` | 改價 |
| `modify_quantity()` | Account, ModifyQuantity, unblock? | `OrderResponse` | 改量 |

### 3.2 批次操作

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `batch_place_order()` | Account, Order[] | `VecOrderResponse` | 批次下單 |
| `batch_cancel_order()` | Account, OrderResult[] | `VecOrderResponse` | 批次取消 |
| `batch_modify_price()` | Account, ModifyPrice[] | `VecOrderResponse` | 批次改價 |
| `batch_modify_quantity()` | Account, ModifyQuantity[] | `VecOrderResponse` | 批次改量 |
| `batch_order_lists()` | Account | `BatchResponse` | 批次清單 |
| `batch_order_detail()` | Account, BatchResult | `VecOrderResponse` | 批次明細 |

### 3.3 查詢功能

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `get_order_results()` | Account | `VecOrderResponse` | 當日委託 |
| `get_order_results_detail()` | Account | `VecOrderResponse` | 當日委託明細 |
| `order_history()` | Account, start_date, end_date? | `VecOrderResponse` | 歷史委託 |
| `filled_history()` | Account, start_date?, end_date? | `FilledResponse` | 成交記錄 |

### 3.4 即時資訊

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `query_symbol_quote()` | Account, symbol, market_type? | `SymbolQuoteResponse` | 個股報價 |
| `query_symbol_snapshot()` | Account, market_type?, stock_types? | `VecSymbolQuoteResponse` | 市場快照 |
| `margin_quota()` | Account, stock_no | `MarginShortQuotaResponse` | 融資融券額度 |
| `daytrade_and_stock_info()` | Account, stock_no | `DayTradeStockInfoResponse` | 當沖資訊 |

### 3.5 條件單（Single Condition）

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `single_condition()` | Account, dates, stop_sign, Condition, Order, TPSL? | `ConditionOrderResultResponse` | 單一條件單 |
| `single_condition_day_trade()` | Account, stop_sign, end_time, Condition, Order, DayTrade, TPSL?, fix? | `ConditionOrderResultResponse` | 當沖條件單 |
| `single_condition_stop()` | Account, dates, stop_sign, Condition, Order, stop_conditions, TPSL? | `ConditionOrderResultResponse` | 停損條件單 |

### 3.6 條件單（Multi Condition）

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `multi_condition()` | Account, dates, stop_sign, Conditions[], Order, TPSL? | `ConditionOrderResultResponse` | 多條件單 |
| `multi_condition_day_trade()` | Account, stop_sign, end_time, Conditions[], Order, DayTrade, TPSL?, fix? | `ConditionOrderResultResponse` | 當沖多條件單 |
| `multi_condition_stop()` | Account, dates, stop_sign, Conditions[], Order, stop_conditions, 2nd_stop?, TPSL? | `ConditionOrderResultResponse` | 停損多條件單 |

### 3.7 智慧單

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `trail_profit()` | Account, dates, stop_sign, TrailOrder | `ConditionOrderResultResponse` | 移動停利單 |
| `time_slice_order()` | Account, dates, stop_sign, SplitDescription, Order | `ConditionOrderResultResponse` | 分批委託單 |

### 3.8 條件單查詢

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `get_condition_order()` | Account, status? | `VecConditionDetailResponse` | 條件單查詢 |
| `get_condition_order_by_id()` | Account, guid | `VecConditionDetailResponse` | ID 查詢條件單 |
| `get_condition_daytrade_by_id()` | Account, guid | `VecConditionDetailResponse` | ID 查詢當沖條件單 |
| `get_condition_history()` | Account, dates, history_type? | `VecConditionDetailResponse` | 條件單歷史 |
| `get_trail_order()` | Account | `VecConditionDetailResponse` | 移動停利單查詢 |
| `get_trail_history()` | Account, dates | `VecConditionDetailResponse` | 移動停利歷史 |
| `get_time_slice_order()` | Account, batch_no | `VecConditionDetailResponse` | 分批委託查詢 |
| `cancel_condition_orders()` | Account, guid | `StringResponse` | 取消條件單 |

---

## 4. FutOptFunctions（期貨選擇權交易）- 30+ API

### 4.1 基本下單操作

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `place_order()` | Account, FutOptOrder, unblock? | `FutOptOrderResponse` | 下單 |
| `cancel_order()` | Account, FutOptOrderResult, unblock? | `FutOptOrderResponse` | 取消委託 |
| `modify_price()` | Account, FutOptModifyPrice, unblock? | `FutOptOrderResponse` | 改價 |
| `modify_lot()` | Account, FutOptModifyLot, unblock? | `FutOptOrderResponse` | 改口數 |

### 4.2 批次操作

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `batch_place_order()` | Account, FutOptOrder[] | `VecFutOptOrderResponse` | 批次下單 |
| `batch_cancel_order()` | Account, FutOptOrderResult[] | `VecFutOptOrderResponse` | 批次取消 |
| `batch_modify_price()` | Account, FutOptModifyPrice[] | `VecFutOptOrderResponse` | 批次改價 |
| `batch_modify_lot()` | Account, FutOptModifyLot[] | `VecFutOptOrderResponse` | 批次改口數 |
| `batch_order_lists()` | Account | `BatchResponse` | 批次清單 |
| `batch_order_detail()` | Account, BatchResult | `VecFutOptOrderResponse` | 批次明細 |

### 4.3 查詢功能

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `get_order_results()` | Account, market_type? | `VecFutOptOrderResponse` | 當日委託 |
| `get_order_results_detail()` | Account, market_type? | `VecFutOptOrderResponse` | 當日委託明細 |
| `order_history()` | Account, dates, market_type? | `VecFutOptOrderResponse` | 歷史委託 |
| `filled_history()` | Account, market_type, dates | `VecFutOptFilledResponse` | 成交記錄 |
| `query_estimate_margin()` | Account, FutOptOrder | `EstimateMarginResponse` | 估算保證金 |

### 4.4 條件單

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `single_condition()` | Account, dates, stop_sign, Condition, FutOptOrder, TPSL? | `ConditionOrderResultResponse` | 單一條件單 |
| `multi_condition()` | Account, dates, stop_sign, Conditions[], FutOptOrder, TPSL? | `ConditionOrderResultResponse` | 多條件單 |
| `trail_profit()` | Account, dates, stop_sign, FutOptTrailOrder | `ConditionOrderResultResponse` | 移動停利單 |
| `time_slice_order()` | Account, dates, stop_sign, SplitDescription, FutOptOrder | `ConditionOrderResultResponse` | 分批委託單 |

### 4.5 條件單查詢

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `get_condition_order()` | Account, market_type?, status? | `VecConditionDetailResponse` | 條件單查詢 |
| `get_condition_order_by_id()` | Account, guid, market_type? | `VecConditionDetailResponse` | ID 查詢條件單 |
| `get_condition_history()` | Account, dates, market_type?, history_type? | `VecConditionDetailResponse` | 條件單歷史 |
| `get_trail_order()` | Account, market_type? | `VecConditionDetailResponse` | 移動停利單查詢 |
| `get_trail_history()` | Account, dates, market_type? | `VecConditionDetailResponse` | 移動停利歷史 |
| `get_time_slice_order()` | Account, batch_no, market_type? | `VecConditionDetailResponse` | 分批委託查詢 |
| `cancel_condition_orders()` | Account, guid, market_type? | `StringResponse` | 取消條件單 |

---

## 5. FutOptAccounting（期貨帳務查詢）- 4 個 API

| API | 參數 | 返回 | 說明 |
|-----|------|------|------|
| `query_single_position()` | Account | `VecFutOptPositionResponse` | 單式部位查詢 |
| `query_hybrid_position()` | Account | `VecFutOptHybridPositionResponse` | 混合部位查詢（含價差） |
| `query_margin_equity()` | Account | `VecEquityResponse` | 保證金權益查詢 |
| `close_position_record()` | Account, dates | `VecCloseRecordResponse` | 平倉記錄查詢 |

**數據結構清單**：
- `Position` - 期貨部位
- `HybridPosition` - 混合部位（含價差單式）
- `Equity` - 保證金權益
- `CloseRecord` - 平倉記錄

---

## 6. 數據結構統計

### 6.1 主要結構體（60+）

**基礎類型**：
- Account, AccountRes, BankRemain, Inventory, MaintenanceData, Settlement

**訂單類型**：
- Order, OrderResult, OrderDetail
- FutOptOrder, FutOptOrderResult, FutOptOrderDetail

**修改類型**：
- ModifyPrice, ModifyQuantity
- FutOptModifyPrice, FutOptModifyLot

**條件單**：
- Condition, ConditionOrder, ConditionOrderResult
- FutOptConditionOrder
- TrailOrder, FutOptTrailOrder
- TPSLOrder, FutOptTPSLOrder
- ConditionDayTrade

**成交回報**：
- FilledData, FutOptFilledData

**部位與損益**：
- Position, HybridPosition, SpreadPosition
- Realized, Unrealized, CloseRecord

**其他**：
- BatchResult, Reply, Recover, Equity, SymbolQuote

### 6.2 列舉類型（15 個）

| 列舉 | 值數量 | 說明 |
|------|--------|------|
| `BSAction` | 4 | 買賣別 (Buy, Sell) |
| `MarketType` | 10+ | 市場類型 (Common, Fixing, Odd...) |
| `PriceType` | 8 | 價格類型 (Limit, Market...) |
| `TimeInForce` | 5 | 有效期限 (ROD, FOK, IOC...) |
| `OrderType` | 7 | 委託類型 (Stock, Margin, Short...) |
| `CallPut` | 4 | Call/Put |
| `Direction` | 2 | 方向 (Up, Down) |
| `FutOptMarketType` | 6+ | 期貨市場類型 |
| `FutOptPriceType` | 類似 PriceType | 期貨價格類型 |
| `FutOptOrderType` | 多種 | 期貨委託類型 |
| `ConditionPriceType` | 多種 | 條件價格類型 |
| `ConditionStatus` | 多種 | 條件單狀態 |
| `StopSign` | 3 | 停止標記 (Full, Partial, UntilEnd) |
| `TriggerContent` | 6 | 觸發內容 (價/量/時間...) |
| `HistoryStatus` | 6 | 歷史狀態 (Type1-6) |

### 6.3 回應類型（30+）

**格式統一**：
```cpp
struct XxxResponse {
    bool is_success;
    std::optional<T> data;
    std::optional<std::string> message;
};
```

**單一結果**：LoginResponse, BankRemainResponse, OrderResponse, FutOptOrderResponse...

**陣列結果**：VecOrderResponse, VecFutOptOrderResponse, InventoryResponse, FilledResponse...

**特殊**：BatchResponse, StringResponse

---

## 7. API 統計摘要

| 模組 | API 數量 | 主要功能 |
|------|---------|----------|
| **FubonCore** | 3 | 登入、Callback 註冊 |
| **Accounting** | 7 | 證券帳務查詢、損益 |
| **StockFunctions** | 60+ | 證券交易完整功能 |
| **FutOptFunctions** | 30+ | 期貨選擇權交易 |
| **FutOptAccounting** | 4 | 期貨帳務查詢 |
| **總計** | 104+ | - |

**數據結構**：60+ struct, 15 enum
**回應類型**：30+ Response wrappers

---

## 8. 優先級建議

### P0（必須）- 核心功能
- FubonCore: login, register_callback
- Accounting: 全部 7 個 API
- StockFunctions: 基本下單 4 個 + 查詢 4 個
- FutOptFunctions: 基本下單 4 個 + 查詢 4 個

### P1（重要）- 進階交易
- StockFunctions: 批次操作 6 個
- FutOptFunctions: 批次操作 6 個
- FutOptAccounting: 全部 4 個

### P2（次要）- 條件單與智慧單
- StockFunctions: 條件單 20+ 個
- FutOptFunctions: 條件單 10+ 個

---

## 附註

- **WebSocket**: 由 Rust core 內部管理，在 login() 時自動建立
- **Callback**: 異步事件通知，需要註冊 Callback 實例
- **Unblock**: 某些下單 API 支援 unblock 參數（異步模式）
- **Optional 參數**: C++ SDK 廣泛使用 `std::optional<T>`
