//
// Created by ventinc on 1/12/18.
//

#ifndef CPP_RTYPE_SPRITETEXTURE_HPP
#define CPP_RTYPE_SPRITETEXTURE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "system/System.hpp"

namespace rtype {

	class EntityDrawable : public ecs::System {
	public:
		explicit EntityDrawable();
		void process(ecs::Manager& mgr, float elapsedTime) override;
	};

}

#endif //CPP_RTYPE_SPRITETEXTURE_HPP
