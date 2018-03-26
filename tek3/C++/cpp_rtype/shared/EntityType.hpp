//
// Created by ventinc on 1/19/18.
//

#ifndef CPP_RTYPE_ENTITYTYPE_HPP
#define CPP_RTYPE_ENTITYTYPE_HPP

#include <cstdint>

namespace rtype {

	enum class EntityType : uint16_t {
		OURPLAYER = 0,
		PLAYER,
		ENEMY
	};

}

#endif //CPP_RTYPE_ENTITYTYPE_HPP
