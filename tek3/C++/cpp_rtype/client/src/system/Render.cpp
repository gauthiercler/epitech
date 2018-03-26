//
// Created by ventinc on 1/10/18.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "components/Drawable.hpp"
#include "components/Position.hpp"
#include "Manager.hpp"
#include "system/Render.hpp"

void rtype::Render::process(ecs::Manager &mgr, float elapsedTime) {

	this->_window.clear(sf::Color::Black);
	for (auto&& entity : entities) {
		auto drawable = mgr.getEntityComponent<ct::Drawable>(entity);
		if (drawable.content)
			this->_window.draw(*drawable.content);
	}
	this->_window.display();
}

rtype::Render::Render(sf::RenderWindow& window)
	: _window(window)
{
	this->setRequiredComponents({ ecs::componentType<rtype::ct::Drawable>()});
}
