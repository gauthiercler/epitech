//
// Created by ventinc on 1/10/18.
//

#ifndef CPP_RTYPE_GAME_HPP
#define CPP_RTYPE_GAME_HPP

#include <SFML/Graphics.hpp>
#include <asset/AssetsLoader.hpp>
#include <rnetwork/async/IOService.hpp>
#include <client/include/singleton/Context.hpp>
#include <ClientChannel.hpp>
#include <shared_queue/shared_storage.hpp>
#include "Manager.hpp"
#include "Position.hpp"
#include "AContext.hpp"
#include "EntityType.hpp"
#include "packet/MovePacket.hpp"

namespace rtype {
	class Game : public AContext {
		using IoService = rnetwork::async::IOService;

	public:
		explicit Game(sf::RenderWindow &window);

		~Game() override = default;

		void run(sf::Time &time) override;

	private:
		void initSystems();
		void initComponentStores();
		void initAssets();
		void initFPS();
		void init();

		ecs::Entity spawnPlayer(rtype::EntityType type, rtype::ct::Position const& pos);

		AssetsLoader &_assetsLoader;
		ecs::Manager _manager;
		rnetwork::shared_queue<rnetwork::packet::MovePacket> _movepackets;
		bool		_isInit{false};

	};
}


#endif //CPP_RTYPE_GAME_HPP
