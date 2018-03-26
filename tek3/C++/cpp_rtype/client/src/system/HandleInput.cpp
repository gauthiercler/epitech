//
// HandleInput.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/HandleInput.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  jeu. janv. 11 14:30:37 2018 Anthony LECLERC
// Last update jeu. janv. 11 14:30:37 2018 Anthony LECLERC
//

#include <SFML/Window/Event.hpp>
#include <rnetwork/udp/Client.hpp>
#include "system/HandleInput.hpp"

#include "components/RtypeInput.hpp"
#include "components/RtypeCommand.hpp"
#include "Manager.hpp"

void rtype::HandleInput::process(ecs::Manager& mgr, float elapsedTime)
{
	sf::Event ev {};

	while (_window.pollEvent(ev))
	{
		if (ev.type == sf::Event::KeyPressed || ev.type == sf::Event::KeyReleased)
			_keyPressed[ev.key.code] = sf::Keyboard::isKeyPressed(ev.key.code);
	}

	if (_keyPressed[sf::Keyboard::Escape]) {
		_keyPressed[sf::Keyboard::Escape] = false;
		mgr.setEnded(true);
	}
	else {
		for (auto&& entity : entities)
		{
			auto& input = mgr.getEntityComponent<Input>(entity);
			auto& command = mgr.getEntityComponent<ct::RtypeCommand>(entity);
			long newInput { 0 };

			if (_keyPressed[input.Charge])
				newInput |= command.Charge;
			if (_keyPressed[input.Up])
				newInput |= command.Up;
			if (_keyPressed[input.Down])
				newInput |= command.Down;
			if (_keyPressed[input.Left])
				newInput |= command.Left;
			if (_keyPressed[input.Right])
				newInput |= command.Right;
			if (_keyPressed[input.Fire])
				newInput |= command.Fire;
			command.triggered = command.input != newInput;
			command.input = newInput;
		}
	}
}

rtype::HandleInput::HandleInput(sf::RenderWindow& window)
 : _window(window), _keyPressed { false }
{
	setRequiredComponents({
							  ecs::componentType<Input>(),
							  ecs::componentType<ct::RtypeCommand>()
						  });
}