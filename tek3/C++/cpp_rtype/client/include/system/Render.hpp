//
// Created by ventinc on 1/10/18.
//

#ifndef CPP_RTYPE_RENDER_HPP
#define CPP_RTYPE_RENDER_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Manager.hpp"

namespace rtype {

	class Render : public ecs::System {
	public:
		Render(sf::RenderWindow& window);
		void process(ecs::Manager& mgr, float elapsedTime) override;

	private:
		sf::RenderWindow &_window;
	};
}

#endif //CPP_RTYPE_RENDER_HPP
