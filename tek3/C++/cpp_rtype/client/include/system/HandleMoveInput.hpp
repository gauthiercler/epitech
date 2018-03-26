//
// Created by ventinc on 1/11/18.
//

#ifndef CPP_RTYPE_KEYBOARDINPUT_HPP
#define CPP_RTYPE_KEYBOARDINPUT_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "system/System.hpp"

namespace rtype {
	class HandleMoveInput : public ecs::System {
	public:
		explicit HandleMoveInput(sf::RenderWindow &window);

		void process(ecs::Manager& mgr, float elapsedTime) override;

	private:
		bool hasCommand(long command, long what);
		sf::RenderWindow &window;
	};
}

#endif //CPP_RTYPE_KEYBOARDINPUT_HPP
