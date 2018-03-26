//
// HandleInput.hpp for cpp_rtype in /home/anthony/repository/cpp_rtype/HandleInput.hpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  jeu. janv. 11 14:30:37 2018 Anthony LECLERC
// Last update jeu. janv. 11 14:30:37 2018 Anthony LECLERC
//

#ifndef CPP_RTYPE_HANDLEINPUT_HPP
#define CPP_RTYPE_HANDLEINPUT_HPP

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "system/System.hpp"
#include "components/RtypeInput.hpp"

namespace rtype {
	class HandleInput : public ecs::System {
	public:
		explicit HandleInput(sf::RenderWindow& window);

		void process(ecs::Manager& mgr, float elapsedTime) override;

	private:

		using Input = ct::RtypeInput;

		sf::RenderWindow& _window;
		bool _keyPressed[sf::Keyboard::KeyCount];
	};
}


#endif //CPP_RTYPE_HANDLEINPUT_HPP
