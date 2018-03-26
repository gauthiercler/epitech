#ifndef CPP_RTYPE_ROUTER_HPP
#define CPP_RTYPE_ROUTER_HPP

#include <functional>
#include <cstdint>
#include <unordered_map>
#include <rnetwork/packet/PacketBase.hpp>
#include "shared/rnetwork/config/Export.hpp"
#include "rnetwork/IClient.hpp"

namespace rnetwork
{
    template<typename F>
    class Router;

    template<typename Ret, typename T, typename ...Args>
    class Router<Ret (T, Args...)>
    {
    public:
        using Callback = Ret (T, Args ...);

        Router() = default;
        Router(const Router<Callback> &router) = default;
        virtual ~Router() = default;

        void registerRoute(uint16_t op, const std::function<Callback> &callback) {
            _routes[op] = callback;
        }

        void unregisterRoute(uint16_t op) {
            _routes.erase(op);
        }

        void clear() {
            _routes.clear();
        }

        bool isRegistered(uint16_t op) const {
            return _routes.find(op) != _routes.end();
        }

        template<typename TPacket, typename ...TArgs>
        Ret operator()(TPacket&& packet, TArgs&& ...args) {
            return _routes[packet.getOp()](std::forward<TPacket>(packet), std::forward<TArgs>(args)...);
        }

        Router &operator=(const Router<Callback> &router) = default;
    private:

        std::unordered_map<uint16_t, std::function<Callback> > _routes;


    };
}


#endif //CPP_RTYPE_ROUTER_HPP
