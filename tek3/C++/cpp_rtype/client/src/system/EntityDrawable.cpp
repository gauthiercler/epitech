//
// Created by ventinc on 1/12/18.
//

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <BoundingBox.hpp>
#include "components/Position.hpp"
#include "components/Drawable.hpp"
#include "system/EntityDrawable.hpp"
#include "Manager.hpp"

rtype::EntityDrawable::EntityDrawable() {
	this->setRequiredComponents({ ecs::componentType<ct::Position>(),
								  ecs::componentType<sf::Color>(),
								  ecs::componentType<ct::BoundingBox>(),
								  ecs::componentType<ct::Drawable>()});
}

void rtype::EntityDrawable::process(ecs::Manager &mgr, float elapsedTime) {
	for (auto &&entity : this->entities) {

		auto &drawable = mgr.getEntityComponent<ct::Drawable>(entity);
		auto &pos = mgr.getEntityComponent<ct::Position>(entity);
		auto &color = mgr.getEntityComponent<sf::Color>(entity);
		auto &size = mgr.getEntityComponent<ct::BoundingBox>(entity);

		auto rect = std::make_shared<sf::RectangleShape>(sf::Vector2f(size.width, size.height));
		rect->setSize({static_cast<float>(size.width), static_cast<float>(size.height)});
		rect->setPosition(pos.x, pos.y);
		rect->setFillColor(color);
		drawable.content = rect;
	}
}
