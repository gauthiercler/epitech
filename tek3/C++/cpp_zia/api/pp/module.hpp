
#pragma once

#include "../module.h"

#include "conf.hpp"
#include "http.hpp"
#include "net.hpp"
#include "nobyte/NoByte.hpp"

namespace zia::apipp {

    class Module : public zia::api::Module {
    protected:
        Conf conf{};
        ResponsePtr response{};
        RequestPtr request{};
        zia::api::NetInfo net{};

    public:
        ~Module() override = default;

        bool config(const zia::api::Conf &conf) override {
            this->conf = Conf::fromBasicConfig(conf);
            return true;
        }

        void reset() {
            // We must be sure that we correctly releasing pointers
            this->request.reset();
            this->response.reset();
        }

        bool smartExec(RequestPtr &request, ResponsePtr &response, zia::api::NetInfo &net) {
            this->request = request;
            this->response = response;
            this->net = net;

            auto ret = this->perform();

            this->reset(); // Reset pointers.
            return ret;
        }

        bool exec(zia::api::HttpDuplex &http) override {
            this->response = Response::fromBasicHttpDuplex(http);
            this->request = Request::fromBasicHttpDuplex(http);

            auto ret = this->perform();

            http.resp = this->response->toBasicHttpResponse();
            http.req = this->request->toBasicHttpRequest();

            this->reset(); // Reset pointers.
            return ret;
        }

        virtual bool perform() = 0;
    };

}
