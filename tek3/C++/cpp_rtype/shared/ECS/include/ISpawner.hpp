//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_ASPAWNER_HPP
#define CPP_RTYPE_ASPAWNER_HPP

#include <Position.hpp>
#include "Entity.hpp"
#include "Manager.hpp"

namespace ecs {
	class ISpawner {
	public:
		virtual ~ISpawner() = default;

		virtual Entity spawn(Manager &manager, const rtype::ct::Position &pos) const = 0;
	};
}

#endif //CPP_RTYPE_ASPAWNER_HPP
