#include <string>
#include <iostream>
#include "./fubon.hpp"

namespace fubon
{
    class FubonSDK
    {
    private:
        std::shared_ptr<fubon::FubonCore> _core;

    public:
        std::shared_ptr<fubon::StockFunctions> stock;
        std::shared_ptr<fubon::Accounting> accounting;
        std::shared_ptr<FutOptFunctions> futopt;
        std::shared_ptr<FutOptAccounting> futopt_accounting;

        FubonSDK(std::optional<uint64_t> pong_inteval, std::optional<int64_t> missed_count, const std::string& url)
        {
            _core = fubon::FubonCore::init(pong_inteval, missed_count, url);
            fubon::SdkRef innderRef = _core->get_ref();
            stock = innderRef.stock;
            accounting = innderRef.accounting;
            futopt = innderRef.futopt;
            futopt_accounting = innderRef.futopt_accounting;
        }

        FubonSDK()
        {
            _core = fubon::FubonCore::init(30, 3, "wss://neoapi.fbs.com.tw/TASP/XCPXWS");
            fubon::SdkRef innderRef = _core->get_ref();
            stock = innderRef.stock;
            accounting = innderRef.accounting;
            futopt = innderRef.futopt;
            futopt_accounting = innderRef.futopt_accounting;
        }

   

        fubon::LoginResponse login(const std::string &personal_id, const std::string &password, const std::string &cert_path, const std::string &cert_pass){
            return _core->login(personal_id, password, cert_path, cert_pass);
        }
    
        fubon::LoginResponse dma_login(const std::string &personal_id, const std::string &password) {
            return _core->dma_login(personal_id, password);
        }

        void register_callback(const std::shared_ptr<Callback> &callback){
            return _core->inner_register_callback(callback);
        }



    };
} // namespace FubonNeo