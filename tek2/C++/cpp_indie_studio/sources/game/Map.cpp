/*
** Map.cpp for indie in /home/sylvain/Documents/projets/tek2/c++/cpp_indie_studio/entityManager
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Thu May 25 17:47:16 2017 Sylvain Chaugny
** Last update Thu May 25 17:48:30 2017 Sylvain Chaugny
*/

#include                <algorithm>
#include <cmath>
#include <core/Random.hpp>
#include <Engine.hpp>
#include		"game/Map.hpp"
#include		"entity/IEntity.hpp"
#include		"entity/ABomb.hpp"
#include                "entity/HumanPlayer.hpp"

const irr::f32 indie::Map::Tilesize(150);

indie::Map::Map(irr::scene::IMeshSceneNode *node, int width, int length) :
  _terrain(node), _width(width), _length(length), _map(), _addingQueue()
{
  _terrain->setPosition({0, 0, 0});
  _terrain->setMaterialFlag(irr::video::EMF_LIGHTING, true);
  irr::scene::ITriangleSelector *selector = node->getSceneManager()->createTriangleSelector(node->getMesh(), node);
  node->setTriangleSelector(selector);
  selector->drop();
}

indie::Map::~Map() {

}

void indie::Map::setTexture(irr::video::ITexture *texture) {
  _terrain->setMaterialTexture(0, texture);
  _terrain->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void indie::Map::setVisible(bool state) {
  _terrain->setVisible(state);
}

irr::scene::ISceneNode *indie::Map::getSceneNode() const {
  return _terrain;
}

void indie::Map::setWidth(int width) {
  _width = width;
}

void indie::Map::setLength(int length) {
  _length = length;
}

void indie::Map::addEntity(std::shared_ptr<IEntity> entity,
			   irr::core::vector2di const &pos) {
  this->addChild(entity.get(), pos);
  try {
    _map[pos] = entity;
  } catch (...) {
    std::cerr << "Cannot place Entity in map" << std::endl;
  }
}

indie::IEntity *indie::Map::getCell(irr::core::vector2di const &pos) {
  auto entity = this->_map.find(pos);

  if (entity == this->_map.end())
    return nullptr;
  else
    return entity->second.get();
}

void indie::Map::clear() {
  _map.clear();
}

irr::scene::ITriangleSelector *indie::Map::getCollisionTriangle() const {
  return _terrain->getTriangleSelector();
}

void indie::Map::update(CollisionManager& collMgr) {
  std::queue<std::shared_ptr<IEntity> > deleteQueue;
  for (auto itMap = this->_map.begin(); itMap != this->_map.end(); ++itMap) {
    if (itMap->second->isDead()) {
      collMgr.removeEntity(itMap->second.get());
      deleteQueue.push(itMap->second);
      IEntity *entity = itMap->second.get();
      itMap = _map.erase(itMap);
      entity->onDeath(*this);
    }
    if (itMap != _map.end())
      itMap->second->update(*this);
  }
  for (auto itPlayer = this->_players.begin(); itPlayer != this->_players.end(); ) {
    if ((*itPlayer)->isDead()) {
      collMgr.removeEntity(itPlayer->get());
      (*itPlayer)->onDeath(*this);
      (*itPlayer)->remove();
      itPlayer = this->_players.erase(itPlayer);
    }
    if (itPlayer != this->_players.end()) {
      (*itPlayer)->update(*this);
      ++itPlayer;
    }
  }
  while (!deleteQueue.empty())
  {
    deleteQueue.front()->remove();
    deleteQueue.pop();
  }
  while (!_addingQueue.empty())
  {
    addEntity(_addingQueue.front().second, _addingQueue.front().first);
    _addingQueue.pop();
  }
}

irr::core::vector2di indie::Map::getMapPosition(const irr::core::vector3df &pos) const {
  irr::core::vector2di mapPosition;

  mapPosition.X = static_cast<int>(std::round(static_cast<double>(pos.X) / Tilesize +
						static_cast<double>(_width / 2) -
						((_width % 2 == 0) ? 0.5 : 0)));
  mapPosition.Y = static_cast<int>(std::round(static_cast<double>(_length / 2) -
						((_length % 2 == 0) ? 0.5 : 0) -
						static_cast<double >(pos.Z) / Tilesize));

  return mapPosition;
}

irr::core::vector3df
indie::Map::getRealPosition(const irr::core::vector2di &pos) const{
  irr::core::vector3df realPos;

  realPos.X = (pos.X * Tilesize) - (_width * Tilesize) / 2 + Tilesize / 2;
  realPos.Z =  (_length * Tilesize) / 2 - (pos.Y * Tilesize) - Tilesize / 2;
  realPos.Y = 1;

  return realPos;
}

void
indie::Map::addChild(IEntity *entity,
		     irr::core::vector2di const &pos) {
  _terrain->addChild(entity->getSceneNode());
  entity->getSceneNode()->setPosition(this->getRealPosition(pos));
}

void indie::Map::explodeBomb(const indie::ABomb *bomb) {
  this->removeEntity(this->getMapPosition(bomb->getSceneNode()->getPosition()));
  bomb->getSceneNode()->remove();
}

void indie::Map::removeEntity(irr::core::vector2di const &pos) {
  auto entity = this->_map.find(pos);

  if (entity != this->_map.end())
    this->_map.erase(entity);
}

void indie::Map::addSpawningQueue(std::shared_ptr<indie::IEntity> entity,
                                  irr::core::vector2di const &pos) {
  _addingQueue.emplace(pos, entity);
}

void indie::Map::addPlayer(std::shared_ptr<indie::APlayer> player,
                           irr::core::vector2di const &pos)
{
  addChild(player.get(), pos);
  _players.push_back(player);
}

indie::APlayer *indie::Map::getPlayer(irr::core::vector2di const &pos) {
  for (auto &&player : _players)
  {
    if (getMapPosition(player->getSceneNode()->getPosition()) == pos)
      return (player.get());
  }
  return nullptr;
}

const indie::Map::t_map &indie::Map::get() const {
  return _map;
}

int indie::Map::getWidth() const {
  return _width;
}

int indie::Map::getLength() const {
  return _length;
}

const std::vector<std::shared_ptr<indie::APlayer>> &indie::Map::getPlayers() const {
  return _players;
}

size_t indie::Map::playerNbr() const {
  return this->_players.size();
}