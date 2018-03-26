//
// Created by ventinc on 1/19/18.
//

#ifndef CPP_RTYPE_PLAYERSPAWNER_HPP
#define CPP_RTYPE_PLAYERSPAWNER_HPP

#include "ISpawner.hpp"

namespace rtypeserver {

	class PlayerSpawner : public ecs::ISpawner {
	public:
		PlayerSpawner() = default;
		~PlayerSpawner() override = default;

		virtual ecs::Entity
		spawn(
			ecs::Manager& manager,
			const rtype::ct::Position& pos) const override;
	};
}


#endif //CPP_RTYPE_PLAYERSPAWNER_HPP
