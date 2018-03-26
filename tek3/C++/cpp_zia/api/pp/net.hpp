
#pragma once

#include <memory>

#include "../net.h"

namespace zia::api {
    struct ImplSocket {
        virtual void sendMessage(std::string &) = 0;

        virtual std::string receiveMessage() = 0;
    };
}
