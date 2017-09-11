/*
** BombSpawner.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/BombSpawner.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 09 19:15:12 2017 Anthony LECLERC
** Last update ven. juin 09 19:15:12 2017 Anthony LECLERC
*/

#include <assert.h>
#include <algorithm>
#include "entity/IBombSpawner.hpp"

indie::BombSpawner::BombSpawner(APlayer *owner, std::unique_ptr<indie::ABomb> bomb,
size_t max) :
    _max(max)
  , _proto(std::move(bomb))
  , _created()
  , _owner(owner)
{
  _proto->setVisible(false);
}

indie::BombSpawner::~BombSpawner()
{}

std::shared_ptr<indie::ABomb> indie::BombSpawner::spawn()
{
  update();
  assert(_created.size() <= _max);
  std::shared_ptr<ABomb> bomb = std::shared_ptr<ABomb>(_proto->clone());
  _created.push_back(bomb);
  return bomb;
}

void indie::BombSpawner::setPrototype(std::unique_ptr<indie::ABomb> proto)
{
  _proto = std::move(proto);
}

indie::ABomb &indie::BombSpawner::getProtoype()
{
  return *_proto;
}

size_t    indie::BombSpawner::maxBombs() const
{
  return _max;
}

size_t    indie::BombSpawner::leftBombs()
{
  update();
  return _max - _created.size();
}

indie::BombSpawner &indie::BombSpawner::operator++() {
  ++_max;
  update();
  return *this;
}

indie::BombSpawner &indie::BombSpawner::operator--() {
  if (_max > 1)
    --_max;
  update();
  return (*this);
}

void indie::BombSpawner::update() {
  _created.erase(std::remove_if(_created.begin(), _created.end(), [](std::shared_ptr<ABomb>& it)
  { return it.use_count() == 1; }), _created.end());
  if (_created.size() > _max)
    _created.resize(_max);
}

const std::vector<std::shared_ptr<indie::ABomb>> &
indie::BombSpawner::getBombs() const {
  return _created;
}
