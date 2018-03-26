//
// Created by ventinc on 1/11/18.
//

#include <SFML/Window/Event.hpp>
#include "components/Speed.hpp"
#include "components/RtypeCommand.hpp"
#include "singleton/Window.hpp"
#include "system/HandleMoveInput.hpp"
#include "Manager.hpp"

rtype::HandleMoveInput::HandleMoveInput(sf::RenderWindow &window) : window(window){
	this->setRequiredComponents({ ecs::componentType<ct::RtypeCommand>(),
								  ecs::componentType<ct::Speed>() });
}

void rtype::HandleMoveInput::process(ecs::Manager& mgr, float elapsedTime)
{
	
	for (auto&& entity : entities) {
		auto command = mgr.getEntityComponent<ct::RtypeCommand>(entity);
		using InputType = decltype(command);
		auto input = command.input;

		// Can do for input CHARGE
		mgr.getEntityComponent<ct::Speed>(entity).y = 0;
		mgr.getEntityComponent<ct::Speed>(entity).x = 0;
		if (this->hasCommand(input, InputType::Down))
			mgr.getEntityComponent<ct::Speed>(entity).y += 200;
		if (this->hasCommand(input, InputType::Up))
			mgr.getEntityComponent<ct::Speed>(entity).y += -200;
		if (this->hasCommand(input, InputType::Left))
			mgr.getEntityComponent<ct::Speed>(entity).x += -200;
		if (this->hasCommand(input, InputType::Right))
			mgr.getEntityComponent<ct::Speed>(entity).x += 200;
	}
}

bool rtype::HandleMoveInput::hasCommand(long command, long what)
{
	return (command & what) != 0;
}
