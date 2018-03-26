//
// Square.cpp for cpp_rtype in /home/anthony/repository/cpp_rtype/Square.cpp
//
// Made by Anthony LECLERC
// Login   <anthony.leclerc@epitech.eu>
//
// Started on  mer. janv. 10 17:49:54 2018 Anthony LECLERC
// Last update mer. janv. 10 17:49:54 2018 Anthony LECLERC
//

#include "components/RtypeInput.hpp"
#include "components/RtypeCommand.hpp"
#include "components/Drawable.hpp"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <Weapon.hpp>
#include <BoundingBox.hpp>
#include <Collide.hpp>
#include <singleton/Singleton.hpp>
#include <singleton/Settings.hpp>
#include <client/include/spawner/SimpleBullet.hpp>
#include "Square.hpp"

bool rtype::Square::make(ecs::Manager& mgr, ct::PlayerID::Id id, float posx, float posy, unsigned int sprite)
{
  	auto e = mgr.createEntity();

  	rtype::ct::Position p;
  	p.x = posx;
  	p.y = posy;

  	bool ret = mgr.addComponent(e, p);
  	ret &= mgr.addComponent(e, ct::Speed(0, 0));
	ret &= mgr.addComponent(e, ct::RtypeInput(Singleton<Settings>::get().getKeyboard()));
	ret &= mgr.addComponent(e, ct::RtypeCommand());
	ret &= mgr.addComponent(e, ct::BoundingBox(80, 40));
	ret &= mgr.addComponent(e, sf::Color(255, 255, 255));
	ret &= mgr.addComponent(e, ct::Weapon(std::make_unique<spawner::SimpleBullet>()));
	ret &= mgr.addComponent(e, ct::Collide(ct::Collide::CollideType::PLAYER));

	ct::PlayerID _id;
	_id.id = id;
	ret &= mgr.addComponent(e, _id);

  	ret &= mgr.registerEntity(e);
  	return ret;
}

bool rtype::Square::make_net(ecs::Manager& mgr, ct::PlayerID::Id id, float posx, float posy)
{
	auto e = mgr.createEntity();

	ct::Position p;
	p.x = posx;
	p.y = posy;

	bool ret = mgr.addComponent(e, p);
	ret &= mgr.addComponent(e, ct::Speed(0, 0));
	ret &= mgr.addComponent(e, ct::BoundingBox(30, 30));
	ret &= mgr.addComponent(e, sf::Color(255, 0, 0));
	ret &= mgr.addComponent(e, ct::Collide(ct::Collide::CollideType::ENEMY));
	ct::PlayerID _id;
	_id.id = id;
	ret &= mgr.addComponent(e, _id);

	ret &= mgr.registerEntity(e);
	return ret;
}