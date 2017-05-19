/*
** arcade::Ghost.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/pacman/includes/arcade::Ghost.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Apr 05 23:00:54 2017 Gauthier Cler
** Last update Wed Apr 05 23:00:55 2017 Gauthier Cler
*/

#include <Structures.hpp>
#include "Ghost.hpp"

arcade::Ghost::Ghost(const std::pair<int ,int> &pos, uint64_t id, uint64_t deadId, GhostState state) : _id(id), _deadId(deadId), _state(state){
  this->setPos(pos);
}

arcade::Ghost::~Ghost() {

}

void arcade::Ghost::setPos(const std::pair<int, int> &pos) {
  this->_position = pos;
}

std::pair<int, int> arcade::Ghost::getPos() const {
  return this->_position;
}

void arcade::Ghost::setPath(const std::vector<std::pair<int, int>> &path) {
  this->_path = path;
}

const std::pair<int, int> arcade::Ghost::getFirstElement() const{
  return this->_path.front();
}

void arcade::Ghost::eraseFirstElement() {
  this->_path.erase(this->_path.begin());
}

unsigned long arcade::Ghost::getPathSize() const {
  return this->_path.size();
}

uint64_t arcade::Ghost::getId() const {
  return this->_id;
}

arcade::GhostState arcade::Ghost::getState() const {
  return this->_state;
}

void arcade::Ghost::setState(const arcade::GhostState &state) {
  this->_state = state;
}

uint64_t arcade::Ghost::getDeadId() const {
  return this->_deadId;
}
