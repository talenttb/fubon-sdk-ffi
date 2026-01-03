#include <iostream>
#include <string>
#include "fubon.hpp"
#include "sdk.hpp"
#include "pretty_print.hpp"

using namespace fubon;


struct CustomCallback : public fubon::Callback {
    void on_event(std::string code, std::string data) override {
        std::cout<<code<<" "<<data<<std::endl; 
    }

    void on_order(std::optional<std::string> err, OrderResult data) override {
        if (err.has_value()) { 
            std::cerr << "Error in on_order: " << err.value() << std::endl;
            return; 
        }

        if (data.order_no.has_value()) { // 或者更簡潔的 if (data.order_no)
            std::cout << "on order: " << data.order_no.value() << std::endl;
        }
        else {
            std::cout << "on order: order_no is not available." << std::endl;
        }
    };
    
    void on_order_changed(std::optional<std::string> err, OrderResult data) override {
        std::cout<<data.order_no.value() <<" "<<std::endl; 
    };
    
    void on_filled(std::optional<std::string> err, FilledData data) override {
         std::cout<<data.order_no<<" "<<std::endl; 
    };

    void on_futopt_order(std::optional<std::string> err, FutOptOrderResult data) override {
        if (err.has_value()) {
            std::cerr << "Error in on_order: " << err.value() << std::endl;
            return;
        }

        if (data.order_no.has_value()) { // 或者更簡潔的 if (data.order_no)
            std::cout << "on order: " << data.order_no.value() << std::endl;
        }
        else {
            std::cout << "on order: order_no is not available." << std::endl;
        }
    };

    void on_futopt_order_changed(std::optional<std::string> err, FutOptOrderResult data) override {
        std::cout<<data.order_no.value()<<" "<<std::endl; 
    };

    void on_futopt_filled(std::optional<std::string> err, FutOptFilledData data) override {
        std::cout<<data.order_no<<" "<<std::endl; 
    };
};

int main()
{
    std::locale::global(std::locale("en_US.UTF-8"));
    auto callback      = std::make_shared<CustomCallback>();
    auto sdk = new FubonSDK();
    sdk->register_callback(callback);




    fubon::LoginResponse res = sdk->login("ID", "pass", "cert path", "cert pass");
    if (!res.is_success) {
        std::cout << "Login failed reason: ";
        if (res.message.has_value()) {
            std::cout << res.message.value() << std::endl;
        }
        else {
            std::cout << "No error message provided." << std::endl;
        }
    }
    else {
        std::cout << "Login succeeded." << std::endl;

        if (res.data.has_value()) {
            std::cout << "Accounts:\n";
            for (const auto& acc : res.data.value()) {
                std::cout << acc << std::endl;
            }
        }
        else {
            std::cout << "No account data available." << std::endl;
        }

        if (res.message.has_value()) {
            std::cout << "Login message: " << res.message.value() << std::endl;
        }
    }

    auto target_account = res.data.value()[0];
    auto fut_target_account = res.data.value()[1];
    std::cout << fut_target_account << std::endl;
    
    FutOptOrder order = FutOptOrder{
        BsAction::BUY,
        "TXFG5",
        std::nullopt,
        std::nullopt,
        "21000",
        2,
        FutOptMarketType::FUTURE,
        FutOptPriceType::LIMIT,
        TimeInForce::ROD,
        FutOptOrderType::AUTO,
        "c++"
    };

    FutOptOrder order2 = FutOptOrder{
        BsAction::BUY,
        "TXFG5",
        std::nullopt,
        std::nullopt,
        "21000",
        2,
        FutOptMarketType::FUTURE,
        FutOptPriceType::LIMIT,
        TimeInForce::ROD,
        FutOptOrderType::AUTO,
        "c++"
    };


    std::vector<FutOptOrder> orders;
    orders.push_back(order);
    orders.push_back(order2);


    // placeOrder
    
    /*
    auto vec_order_result = sdk->futopt->batch_place_order(fut_target_account, orders);
    if (!vec_order_result.is_success) {
        std::cout << "get order result failed reason: "
            << (vec_order_result.message.has_value() ? vec_order_result.message.value() : "No message")
            << std::endl;
    }
    else {
        if (vec_order_result.data.has_value()) {
            std::cout << vec_order_result << std::endl;
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    */
    


    // batch list
    auto batch_list = sdk->futopt->batch_order_lists(fut_target_account);
    if (!batch_list.is_success) {
        std::cout << "Get batch list result failed reason: "
            << (batch_list.message.has_value() ? batch_list.message.value() : "No message")
            << std::endl;
    }
    else {
        if (batch_list.data.has_value()) {
            std::cout << batch_list << std::endl;
        }
        else {
            std::cout << "Get batch list success but no data returned." << std::endl;
        }
    }

    
    auto batch_res = batch_list.data.value()[0];

    // batch list result
    auto batch_list_res = sdk->futopt->batch_order_detail(fut_target_account, batch_res);
    if (!batch_list_res.is_success) {
        std::cout << "get order result failed reason: "
            << (batch_list_res.message.has_value() ? batch_list_res.message.value() : "No message")
            << std::endl;
    }
    else {
        if (batch_list_res.data.has_value()) {
            std::cout << batch_list_res << std::endl;
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    

    // FutOptModifyLot
    // batch modify price

    /*
    std::vector<ModifyPrice> modify_orders = {
        sdk->stock->make_modify_price_obj(batch_list_res.data.value()[0], "30.5", std::nullopt),
        sdk->stock->make_modify_price_obj(batch_list_res.data.value()[1], "30.5", std::nullopt)
    };

    auto batch_price = sdk->stock->batch_modify_price(target_account, modify_orders);
    if (!batch_price.is_success) {
        std::cout << "batch_price failed reason: "
            << (batch_price.message.has_value() ? batch_price.message.value() : "No message")
            << std::endl;
    }
    else {
        if (batch_price.data.has_value()) {
            std::cout << batch_price << std::endl;
        }
        else {
            std::cout << "batch_price success but no data returned." << std::endl;
        }
    }
    */

    // batch modify qty
    /*
    std::vector<ModifyQuantity> modify_qty = {
        sdk->stock->make_modify_quantity_obj(batch_list_res.data.value()[0], 0),
        sdk->stock->make_modify_quantity_obj(batch_list_res.data.value()[1], 0)
    };

    auto batch_qty = sdk->stock->batch_modify_quantity(target_account, modify_qty);
    if (!batch_qty.is_success) {
        std::cout << "batch_qty failed reason: "
            << (batch_qty.message.has_value() ? batch_qty.message.value() : "No message")
            << std::endl;
    }
    else {
        if (batch_qty.data.has_value()) {
            std::cout << batch_qty << std::endl;
        }
        else {
            std::cout << "batch_qty success but no data returned." << std::endl;
        }
    }
    */

    // batch cancel 
    
    /*
    std::vector<OrderResult> cancel;
    cancel.push_back(batch_list_res.data.value()[0]);
    cancel.push_back(batch_list_res.data.value()[1]);

    auto batch_cancel = sdk->stock->batch_cancel_order(target_account, cancel);
    if (!batch_cancel.is_success) {
        std::cout << "batch_cancel failed reason: "
            << (batch_cancel.message.has_value() ? batch_cancel.message.value() : "No message")
            << std::endl;
    }
    else {
        if (batch_cancel.data.has_value()) {
            std::cout << batch_cancel << std::endl;
        }
        else {
            std::cout << "batch_cancel success but no data returned." << std::endl;
        }
    }
    */
    




    




    
    /*
    Condition condition = Condition{
        TradingType::REFERENCE,
        "TXFF5",
        TriggerContent::MATCHED_PRICE,
        "22000",
        Operator::LESS_THAN,
     };

    Condition condition2 = Condition{
        TradingType::REFERENCE,
        "TXFF5",
        TriggerContent::TOTAL_QUANTITY,
        "1000",
        Operator::GREATER_THAN,
    };

    std::vector<Condition> conditions;
    conditions.push_back(condition);
    conditions.push_back(condition2);


    FutOptConditionOrder order = FutOptConditionOrder{
        BsAction::BUY,
        "TXFF5",
        "21050",
        1,
        FutOptConditionMarketType::FUTURE,
        FutOptConditionPriceType::LIMIT,
        TimeInForce::ROD,
        FutOptConditionOrderType::NEW
    };


    FutOptTpslOrder tp = FutOptTpslOrder{
        TimeInForce::ROD,
        FutOptConditionPriceType::LIMIT,
        FutOptConditionOrderType::NEW,
        "22000",
        "22000",
    };

    FutOptTpslOrder sl = FutOptTpslOrder{
        TimeInForce::ROD,
        FutOptConditionPriceType::LIMIT,
        FutOptConditionOrderType::NEW,
        "20000",
        "20000",
    };

    FutOptTPSLWrapper tpsl = FutOptTPSLWrapper{
        StopSign::FULL,
        tp,
        sl,
        "20250615",
        false
    };
    

    //single_condition
    
    auto send_condition_order = sdk->futopt->single_condition(fut_target_account, "20250612", "20250615", StopSign::FULL, condition, order, tpsl);
    if (!send_condition_order.is_success) {
        std::cout << "get order result failed reason: "
            << (send_condition_order.message.has_value() ? send_condition_order.message.value() : "No message")
            << std::endl;
    }
    else {
        if (send_condition_order.data.has_value()) {
            const auto& send = send_condition_order.data.value();
            std::cout << send << std::endl;
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    */
    
    

    //  multi_condition
    
    /*
    auto send_condition_order = sdk->futopt->multi_condition(fut_target_account, "20250610", "20250615", StopSign::FULL, conditions, order, tpsl);
    if (!send_condition_order.is_success) {
        std::cout << "get order result failed reason: "
            << (send_condition_order.message.has_value() ? send_condition_order.message.value() : "No message")
            << std::endl;
    }
    else {
        if (send_condition_order.data.has_value()) {
            const auto& send = send_condition_order.data.value();
            std::cout << send << std::endl;
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    */

    /*
    auto get_conditionid = sdk->futopt->get_condition_order_by_id(fut_target_account, "564b7ad6-a332-470c-93ea-cf3fea00d7fa",std::nullopt);
    if (!get_conditionid.is_success) {
        std::cout << "get order result failed reason: "
            << (get_conditionid.message.has_value() ? get_conditionid.message.value() : "No message")
            << std::endl;
    }
    else {
        if (get_conditionid.data.has_value()) {
            for (const auto& result : get_conditionid.data.value()) {
                std::cout << result << std::endl;
            }
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    */


    /*
    // get condition order
    auto get_conditionid = sdk->stock->get_condition_order(target_account, std::nullopt);
    if (!get_conditionid.is_success) {
        std::cout << "get order result failed reason: "
            << (get_conditionid.message.has_value() ? get_conditionid.message.value() : "No message")
            << std::endl;
    }
    else {
        if (get_conditionid.data.has_value()) {
            for (const auto& result : get_conditionid.data.value()) {
                std::cout << result << std::endl;
            }
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    */


    /*
    // get condition history
    auto get_conditionid = sdk->stock->get_condition_history(target_account, "20250604","20250605", std::nullopt);
    if (!get_conditionid.is_success) {
        std::cout << "get order result failed reason: "
            << (get_conditionid.message.has_value() ? get_conditionid.message.value() : "No message")
            << std::endl;
    }
    else {
        if (get_conditionid.data.has_value()) {
            for (const auto& result : get_conditionid.data.value()) {
                std::cout << result << std::endl;
            }
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    */


    /*
    // cancel_condition_orders
    auto cancel_condition = sdk->stock->cancel_condition_orders(target_account, "564b7ad6-a332-470c-93ea-cf3fea00d7fa");
    if (!cancel_condition.is_success) {
        std::cout << "cancel condition result failed reason: "
            << (cancel_condition.message.has_value() ? cancel_condition.message.value() : "No message")
            << std::endl;
    }
    else {
        if (cancel_condition.data.has_value()) {
            for (const auto& result : cancel_condition.data.value()) {
                std::cout << result << std::endl;
            }
        }
        else {
            std::cout << "cancel condition success but no data returned." << std::endl;
        }
    }
    */


    

    // SplitDescription split = SplitDescription{
    //     TimeSliceOrderType::TYPE1,
    //     30,
    //     1000,
    //     10000,
    //     "083000",
    //     std::nullopt
    // };

    /*
    FutOptConditionOrder order = FutOptConditionOrder{
        BsAction::BUY,
        "TXFF5",
        "21050",
        1,
        FutOptConditionMarketType::FUTURE,
        FutOptConditionPriceType::LIMIT,
        TimeInForce::ROD,
        FutOptConditionOrderType::NEW
    };
    */

    /*
    auto timeslice = sdk->stock->time_slice_order(target_account, "20250606","20250606", StopSign::FULL, split, sliceorder);
    if (!timeslice.is_success) {
        std::cout << "send timeslice result failed reason: "
            << (timeslice.message.has_value() ? timeslice.message.value() : "No message")
            << std::endl;
    }
    else {
        if (timeslice.data.has_value()) {
            const auto& send = timeslice.data.value();
            std::cout << send << std::endl;
        }
        else {
            std::cout << "send timeslice success but no data returned." << std::endl;
        }
    }
    */

    /*
    auto get_timeslice = sdk->stock->get_time_slice_order(target_account, "25060500000002");
    if (!get_timeslice.is_success) {
        std::cout << "get order result failed reason: "
            << (get_timeslice.message.has_value() ? get_timeslice.message.value() : "No message")
            << std::endl;
    }
    else {
        if (get_timeslice.data.has_value()) {
            for (const auto& result : get_timeslice.data.value()) {
                std::cout << result << std::endl;
            }
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    

    FutOptTrailOrder trail = FutOptTrailOrder{
        "TXFF5",
        "20000",
        Direction::DOWN,
        5,
        BsAction::BUY,
        2000,
        FutOptConditionPriceType::MATCHED_PRICE,
        5,
        TimeInForce::ROD,
        FutOptConditionOrderType::NEW
    };
    */

    /*
    auto trail_order = sdk->futopt->trail_profit(fut_target_account, "20250610","20250610", StopSign::FULL, trail);
    if (!trail_order.is_success) {
        std::cout << "send trail_order result failed reason: "
            << (trail_order.message.has_value() ? trail_order.message.value() : "No message")
            << std::endl;
    }
    else {
        if (trail_order.data.has_value()) {
            const auto& send = trail_order.data.value();
            std::cout << send << std::endl;
        }
        else {
            std::cout << "send trail_order success but no data returned." << std::endl;
        }
    }
    
    */
    /*
    auto get_trail = sdk->stock->get_trail_order(target_account);
    if (!get_trail.is_success) {
        std::cout << "get order result failed reason: "
            << (get_trail.message.has_value() ? get_trail.message.value() : "No message")
            << std::endl;
    }
    else {
        if (get_trail.data.has_value()) {
            for (const auto& result : get_trail.data.value()) {
                std::cout << result << std::endl;
            }
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    */

    /*
    auto get_trail_his = sdk->stock->get_trail_history(target_account, "20250601", "20250606");
    if (!get_trail_his.is_success) {
        std::cout << "get order result failed reason: "
            << (get_trail_his.message.has_value() ? get_trail_his.message.value() : "No message")
            << std::endl;
    }
    else {
        if (get_trail_his.data.has_value()) {
            for (const auto& result : get_trail_his.data.value()) {
                std::cout << result << std::endl;
            }
        }
        else {
            std::cout << "Order result success but no data returned." << std::endl;
        }
    }
    */



        


    
    std::cout << "Waiting for 50 seconds..." << std::endl;
    // // std::this_thread::sleep_for(std::chrono::seconds(50));
    std::cout << "Program closing." << std::endl;
    return 0;

}
