//
// Created by ventinc on 1/17/18.
//

#ifndef CPP_RTYPE_COLLIDE_HPP
#define CPP_RTYPE_COLLIDE_HPP

namespace rtype {
	namespace ct {
		/// @brief Collide.
		struct Collide {
			enum class CollideType {
				DEFAULT = 0,
				PLAYER,
				ENEMY,
				BULLET,
				POWERUP
			};

			CollideType type = CollideType::DEFAULT;
			CollideType by = CollideType::DEFAULT;

			explicit Collide(CollideType type) : type(type) {};
		};
	}
}

#endif //CPP_RTYPE_COLLIDE_HPP
