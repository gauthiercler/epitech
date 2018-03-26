//
// RemoveWhenOutBounds.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/RemoveWhenOutBounds.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  dim. janv. 21 08:54:13 2018 Anthony LECLERC
// Last update dim. janv. 21 08:54:13 2018 Anthony LECLERC
//

#include "Manager.hpp"
#include <Position.hpp>
#include <component/types/ComponentIdGenerator.hpp>
#include <Dead.hpp>
#include "client/include/system/RemoveWhenOutBounds.hpp"

void rtype::RemoveWhenOutBounds::process(ecs::Manager& mgr, float)
{
	for (auto&& entity : entities)
	{
		auto const& pos = mgr.getEntityComponent<ct::Position>(entity);
		auto const& box = mgr.getEntityComponent<ct::BoundingBox>(entity);
		if (pos.x > _world.width + box.width || pos.x < -static_cast<float>(box.width) ||
			pos.y > _world.height + box.height || pos.y < -static_cast<float>(box.height))
		{
			mgr.addComponent(entity, ct::Dead() );
			mgr.registerEntity(entity);
		}
	}
}

rtype::RemoveWhenOutBounds::RemoveWhenOutBounds(rtype::ct::BoundingBox const& worldBox) :
	_world(worldBox)
{
	setRequiredComponents({ecs::componentType<ct::Position>(),
						  ecs::componentType<ct::BoundingBox>() });
}

void
rtype::RemoveWhenOutBounds::setBounds(rtype::ct::BoundingBox const& worldBox)
{
	_world = worldBox;
}
