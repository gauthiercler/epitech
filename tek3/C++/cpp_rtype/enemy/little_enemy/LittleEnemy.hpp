//
// Created by montag-v on 1/17/18.
//

#ifndef CPP_RTYPE_LITTLEENEMY_HPP
#define CPP_RTYPE_LITTLEENEMY_HPP

#include "Config.hpp"
#include "ISpawner.hpp"

namespace rtype {

  namespace spawner {

	  class ENEMY_API LittleEnemy : public ecs::ISpawner {

	  public:
		  ~LittleEnemy() override = default;

		  ecs::Entity spawn(ecs::Manager &manager, const rtype::ct::Position &pos) const override;
	  };

	  // All enemy will have a getSpawner function to create a new spawner
	  extern "C" ENEMY_API const ecs::ISpawner *getSpawner();
	  extern "C" ENEMY_API void ctor();
	  extern "C" ENEMY_API void dtor();

  }

}



#endif //CPP_RTYPE_LITTLEENEMY_HPP
