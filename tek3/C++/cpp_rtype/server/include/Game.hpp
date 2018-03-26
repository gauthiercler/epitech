//
// Created by ventinc on 1/19/18.
//

#ifndef CPP_RTYPE_GAME_HPP
#define CPP_RTYPE_GAME_HPP

#include <chrono>
#include <shared_queue/shared_storage.hpp>
#include <server/include/spawner/SpawnerManager.hpp>
#include <server/include/libloader/DLLoaderManager.hpp>
#include "Manager.hpp"
#include "Player.hpp"
#include "server/include/spawner/Spawner.hpp"
#include "packet/MovePacket.hpp"
#include "RtypeCommand.hpp"

namespace rtypeserver {

	class Player;

	class Game : public std::enable_shared_from_this<Game>
    {
    private:
        unsigned int _id;
        bool _running = false;
        std::vector<std::shared_ptr<Player>> _players;

    public:
		Game(unsigned int id, rtype::module::DLLoaderManager<void> &dlm);
		~Game() = default;

        unsigned long nbPlayers() const;
        unsigned int getId() const;

		void start();
		void run();
		bool addPlayer(std::shared_ptr<Player> player);
        void unregisterPlayer(std::shared_ptr<Player> player);

		void broadcast(rnetwork::packet::PacketBase& p);

	private:
		void initComponentsStore();
		void initSystems();
        void startPlayer(std::shared_ptr<Player> player);
		ecs::Entity makePlayer();
		void sendToPlayers(rnetwork::packet::PacketBase &packet);
		void callSpawners(float elapsedTime);

		ecs::Manager _manager;
		rtypeserver::SpawnerManager _spawnerManager;
		rnetwork::shared_queue<rnetwork::packet::MovePacket> _moveUpdates;
//		spawner::Spawner	spawner;
		std::chrono::time_point<std::chrono::high_resolution_clock> last;
	};

}

#endif //CPP_RTYPE_GAME_HPP
