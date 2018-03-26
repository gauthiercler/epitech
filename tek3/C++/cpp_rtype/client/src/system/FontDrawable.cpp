//
// Created by ventinc on 1/12/18.
//

#include <SFML/Graphics/Text.hpp>
#include <asset/Font.hpp>
#include "system/FontDrawable.hpp"
#include "components/Text.hpp"
#include "components/Drawable.hpp"
#include "components/Position.hpp"
#include "Manager.hpp"

rtype::FontDrawable::FontDrawable(AssetsLoader &loader) : loader(loader) {
	this->setRequiredComponents({ecs::componentType<ct::Position>(),
								 ecs::componentType<ct::Text>()});
}

void rtype::FontDrawable::process(ecs::Manager &mgr, float elapsedTime) {
	for (auto &&entity : this->entities) {
		if (!mgr.hasEntityComponent<ct::Drawable>(entity)) {
			mgr.addComponent(entity, ct::Drawable());
			mgr.registerEntity(entity);
		}
		auto &text = mgr.getEntityComponent<ct::Text>(entity);
		auto sfText = std::make_shared<sf::Text>();
		try {
			auto &font = this->loader.get<asset::Font>(text.font);
			sfText->setFont(font.get());
		}
		catch (std::exception const& e) {
			std::cout << "[TEXT] :: " << text.content << std::endl;
			return ;
		}

		auto &drawable = mgr.getEntityComponent<ct::Drawable>(entity);
		auto &pos = mgr.getEntityComponent<ct::Position>(entity);
		sfText->setString(text.content);
		sfText->setPosition(pos.x, pos.y);
//		sfText->setFillColor(text.color);
		sfText->setCharacterSize(text.size);
		drawable.content = sfText;
	}
}
