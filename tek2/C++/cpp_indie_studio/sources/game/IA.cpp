/*
** IA.cpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/sources/game/IA.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jun 14 16:20:04 2017 Gauthier Cler
** Last update Wed Jun 14 16:20:04 2017 Gauthier Cler
*/

#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <game/Position.hpp>
#include <core/Random.hpp>
#include <core/IABinding.hpp>
#include <future>
#include "game/IA.hpp"

indie::IA::IA(irr::scene::ISceneManager *smgr,
	      std::string const &meshID,
	      const std::string &textureID,
	      const std::string &name,
	      IADiff difficulty,
	      bool visible) : APlayer(smgr, meshID, textureID, name, visible),
			      _lastTarget(-1, -1),
			      _started(false),
			      _lastAction(Action::NOTHING),
			      _difficulty(difficulty)
{

}

indie::IA::~IA() {

}



void indie::IA::update(indie::Map &map) {
  if (!_node)
    return ;
  auto cell = map.getCell(map.getMapPosition(_node->getPosition()));
  if (cell && cell->getType() == EntityType::FIRE) {
    this->setDeath(true);
    return ;
  }

  this->dropBombUpdate(map);
  if (!_started) {
    this->convertMap(map);
    auto position = map.getMapPosition(_node->getPosition());
    _async = std::async(std::launch::async, &IA::computeScript, this, Position(position.X, position.Y));
    _started = true;
  }else if (_async.wait_for(std::chrono::seconds(0)) == std::future_status::ready) {
    auto action = _async.get();
    _lastAction = action;
    this->assessAction(action);
    _started = false;
  } else
    this->assessAction(_lastAction);
}

void indie::IA::setVisible(bool) {
}

const indie::Position &indie::IA::getLastTarget() const {
  return _lastTarget;
}

void indie::IA::setLastTarget(const indie::Position &pos) {
  _lastTarget = pos;
}

void indie::IA::convertMap(const Map &map) {
  std::map<int, EntityType>			line;

  _convertedMap.clear();

  for (int i = 0; i < map.getWidth(); i++)
    line[i] = EntityType::EMPTY;
  for (int i = 0; i < map.getLength() ; i++)
    _convertedMap[i] = line;
  for (auto &cell : map.get())
    _convertedMap[cell.first.Y][cell.first.X] = cell.second.get()->getType();
  this->generateBombRange(map);

}

indie::Action indie::IA::computeScript(const Position &playerPos) {


  Action action = Action::NOTHING;
  std::lock_guard<std::mutex> lock(IABinding::get().getMutex());

  try {
    IABinding::get().getModule(_difficulty).attr("last_target") = this->getLastTarget();
    action = IABinding::get().getModule(_difficulty).attr("compute")(_convertedMap, playerPos).cast<Action>();
    this->setLastTarget(IABinding::get().getModule(_difficulty).attr("last_target").cast<Position>());
  } catch (pybind11::error_already_set &e) {
    std::cout << e.what() << std::endl;
  }
  return action;
}

void indie::IA::assessAction(const indie::Action &action) {
  switch(action) {
    case Action::LEFT:
      this->run();
      this->move( {-20, 0, 0} );
      this->getSceneNode()->setRotation({0, 90, 0});
      break;
    case Action::RIGHT:
      this->run();
      this->move( {20, 0, 0} );
      this->getSceneNode()->setRotation({0, 270, 0});
      break;
    case Action::UP:
      this->run();
      this->move( {0, 0, 20} );
      this->getSceneNode()->setRotation({0, 180, 0});
      break;
    case Action::DOWN:
      this->run();
      this->move( {0, 0, -20} );
      this->getSceneNode()->setRotation({0, 0, 0});
      break;
    case Action::NOTHING:
      this->stand();
      break;
    case Action::BOMB:
      this->stand();
      this->putBomb();
      break;
  }
}

void indie::IA::dropBombUpdate(Map &map) {
  if (this->_goDrop) {
    const irr::core::vector2di bombPos = map.getMapPosition(this->_node->getPosition());
    if (map.getCell(bombPos) == nullptr)
    {
      if (_bombSpawn.leftBombs() > 0)
	map.addEntity(_bombSpawn.spawn(), bombPos);
    }
    this->_goDrop = false;
  }
}

void indie::IA::assessBombPower(Position pos, indie::Action dir, uint64_t iteration, uint64_t maxIterations)
{
  if (iteration == maxIterations)
    return ;

  try {
    auto cell = _convertedMap[pos.y][pos.x];
    if (cell == EntityType::BRICK || cell == EntityType::BOX)
      return ;
    _convertedMap[pos.y][pos.x] = EntityType::FUTURE_FIRE;
  } catch (...) {
    return ;
  }
  iteration++;
  switch(dir) {
    case Action::UP:
      pos.y -= 1; break;
    case Action::DOWN:
      pos.y += 1; break;
    case Action::LEFT:
      pos.x -= 1; break;
    case Action::RIGHT:
      pos.x += 1; break;
    default:
      break;
  }
  this->assessBombPower(pos, dir, iteration, maxIterations);
}

void indie::IA::generateBombRange(const Map &map) {

  for (auto &player : map.getPlayers()){
    auto currentPlayer = player.get();
    if (currentPlayer != nullptr) {
      currentPlayer->getSpawner().update();
      auto bombs = currentPlayer->getSpawner().getBombs();
      for (auto &bomb : bombs) {
	auto currentBomb = bomb.get();
	if (currentBomb != nullptr) {
	  auto node = currentBomb->getSceneNode();
	  if (node != nullptr) {
	    auto nodePos = node->getPosition();
	    auto pos = map.getMapPosition(nodePos);
	    _convertedMap[pos.Y][pos.X] = EntityType::FUTURE_FIRE;
	    this->assessBombPower({pos.X, pos.Y - 1}, Action::UP, 0, currentBomb->getPower());
	    this->assessBombPower({pos.X, pos.Y + 1}, Action::DOWN, 0, currentBomb->getPower());
	    this->assessBombPower({pos.X - 1, pos.Y}, Action::LEFT, 0, currentBomb->getPower());
	    this->assessBombPower({pos.X + 1, pos.Y}, Action::RIGHT, 0, currentBomb->getPower());
	  }
	}
      }
    }
  }
}