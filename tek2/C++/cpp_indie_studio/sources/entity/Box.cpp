/*
** Box.cpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/sources/entity/Box.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 12 16:51:40 2017 Gauthier Cler
** Last update Mon Jun 12 16:51:40 2017 Gauthier Cler
*/

#include <entity/Fire.hpp>
#include "entity/PowerUpFactory.hpp"
#include "Engine.hpp"
#include "entity/Box.hpp"
#include  "entity/APowerUp.hpp"

indie::Box::Box(irr::scene::ISceneManager *smgr) : ACube(smgr, "cube", true, false, EntityType::BOX)
{}

indie::Box::~Box() {

}

void indie::Box::onDeath(indie::Map &map) {

  std::shared_ptr<IEntity> powerUp = std::shared_ptr<IEntity>(PowerUpFactory::spawn());
  std::shared_ptr<IEntity> flame = std::make_shared<Fire>(_node->getSceneManager(), "cube", "lava", 1, powerUp);

  map.addSpawningQueue(flame, map.getMapPosition(_node->getPosition()));
}
