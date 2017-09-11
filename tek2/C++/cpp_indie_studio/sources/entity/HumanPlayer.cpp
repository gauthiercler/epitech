/*
** Player.cpp for indie in /home/sylvain/Documents/projets/tek2/c++/cpp_indie_studio/entityManager
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu May 25 09:38:42 2017 Sylvain Chaugny
** Last update Fri May 26 16:16:53 2017 Sylvain Chaugny
*/

#include        <iostream>
#include        <entity/AquaBomb.hpp>
#include 	"entity/BasicBomb.hpp"
#include        "entity/HumanPlayer.hpp"
#include        "controllers/PlayerController.hpp"

indie::HumanPlayer::HumanPlayer(irr::scene::ISceneManager *smgr,
		      std::string const& meshID,
                      std::string const& textureID,
		      std::string const& name,
                      bool visible) :
    APlayer(smgr, meshID, textureID, name, visible),
    _eventController(nullptr)
{}

indie::HumanPlayer::~HumanPlayer()
{
  if (_eventController)
    Engine::get().getEventManager().remove(_eventController);
}

void indie::HumanPlayer::setEventController(indie::IPlayerController *controller)
{
  controller->setTarget(this);
  _eventController = controller;
  Engine::get().getEventManager().registerController(this->getEventController());
}

indie::IPlayerController *indie::HumanPlayer::getEventController() const
{
  return _eventController;
}

void indie::HumanPlayer::update(indie::Map &map) {
  auto cell = map.getCell(map.getMapPosition(_node->getPosition()));
  if (cell && cell->getType() == EntityType::FIRE) {
    this->setDeath(true);
    return ;
  }
  if (this->_goDrop) {
    const irr::core::vector2di bombPos = map.getMapPosition(this->_node->getPosition());
    if (map.getCell(bombPos) == nullptr)
    {
      _bombSpawn.update();
      if (_bombSpawn.leftBombs() > 0) {
        map.addSpawningQueue(_bombSpawn.spawn(), bombPos);
      }
    }
    this->_goDrop = false;
  }
}

void indie::HumanPlayer::onDeath(indie::Map &map) {
  APlayer::onDeath(map);
  if (_eventController)
    _eventController->setActive(false);
}

void indie::HumanPlayer::setVisible(bool state) {
  _eventController->setActive(state);
}

void indie::HumanPlayer::remove() {
  APlayer::remove();
  Engine::get().getEventManager().remove(getEventController());
}