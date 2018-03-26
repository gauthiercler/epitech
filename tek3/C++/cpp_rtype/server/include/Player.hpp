//
// Created by ventinc on 1/19/18.
//

#ifndef CPP_RTYPE_PLAYER_HPP
#define CPP_RTYPE_PLAYER_HPP

#include <ClientChannel.hpp>
#include "Game.hpp"

namespace rtypeserver {

    class Game;

    class Player : public std::enable_shared_from_this<Player>
    {
    public:
        using RouterReceiver = rnetwork::Router<void (rnetwork::packet::PacketBase const&)>;
        using RouterSender = rnetwork::Router<void (rnetwork::packet::PacketBase const&)>;

        Player(const std::shared_ptr<rnetwork::ClientChannel>& channel, uint16_t id = 0);
        Player(const Player &player) = default;
        virtual ~Player() = default;

        uint16_t getId() const;

        bool haveChannel(const std::shared_ptr<rnetwork::ClientChannel> &channel) const;
        void send(rnetwork::packet::PacketBase const& packetBase);

        std::shared_ptr<rtypeserver::Game> getGame() const;
        void joinGame(std::shared_ptr<rtypeserver::Game> game);
        void leaveGame();

        Player &operator=(const Player &player) = default;

        RouterReceiver& routerReceiver();
        RouterSender& routerSender();
    private:
        RouterSender _router;
        RouterReceiver _receiver;
        std::shared_ptr<rnetwork::ClientChannel> _channel;
        std::shared_ptr<rtypeserver::Game> _game;
        uint16_t _id;

        void initRouter();
        void sendTCP(rnetwork::packet::PacketBase const& packet);
    };

}


#endif //CPP_RTYPE_PLAYER_HPP
