/*
** AStar.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/pacman/sources/AStar.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Apr 07 22:26:05 2017 Gauthier Cler
** Last update Fri Apr 07 22:26:05 2017 Gauthier Cler
*/

#include <algorithm>
#include <iostream>
#include <Pacman.hpp>
#include <functional>
#include "AStar.hpp"

arcade::AStar::AStar(const std::vector<std::vector<cellType>> &map,
		     const std::pair<int, int> &start,
		     const std::pair<int, int> &target,
		     int mapSize,
		     std::vector<Ghost> enemies) {
  this->_map = map;
  this->_start = start;
  this->_target = target;
  this->_mapSize = mapSize;
  for (auto &current : enemies) {
    if (current.getPos().first != start.first && current.getPos().second != start.second)
      this->_map[current.getPos().second][current.getPos().first] = WALL;
  }
}

arcade::AStar::~AStar() {

}

std::vector<std::pair<int, int>> arcade::AStar::compute() {
  node	start;

  start.pos = this->_start;
  start.father = {-1, -1};
  start.g = 0;
  start.h = this->getHeuristic(start.pos);
  start.f = start.g + start.h;
  this->_open.push_front(start);
  this->_map[this->_target.second][this->_target.first] = EXIT;
  while (this->_open.size())
  {
    node	selected = this->getLowerNode();
    if (selected.pos.first == this->_target.first && selected.pos.second == this->_target.second) {
      this->fill_result(selected);
      std::reverse(this->_result.begin(), this->_result.end());
      this->_result.erase(this->_result.begin());
      return this->_result;
    }
    if (selected.pos.first >= 0 &&
      selected.pos.first < this->_mapSize &&
      selected.pos.second >= 0 &&
      selected.pos.second < this->_mapSize)
      this->_map[selected.pos.second][selected.pos.first] = VISITED;
    this->_closed.push_front(selected);

    node save = selected;
    this->_open.remove_if([selected](node node){ return node.pos.first == selected.pos.first && node.pos.second == selected.pos.second; });;
    this->addSon(SOUTH, save);
    this->addSon(EAST, save);
    this->addSon(NORTH, save);
    this->addSon(WEST, save);
  }
  return this->_result;
}

int arcade::AStar::getHeuristic(const std::pair<int, int> &pos) {
  return (abs(pos.first - this->_target.first) + abs(pos.second - this->_target.second));
}

static bool min(const arcade::node &first, const arcade::node &second) {
  return first.f < second.f;
}

arcade::node arcade::AStar::getLowerNode() {
  return *std::min_element(this->_open.begin(), this->_open.end(), &min);
}

void arcade::AStar::addSon(arcade::dir direction, node father) {
  node	newNode;
  std::pair<int, int>	possiblePos;

  newNode.father.first = this->_closed.front().pos.first;
  newNode.father.second = this->_closed.front().pos.second;
  possiblePos = {this->getPosX(father.pos.first, direction), this->getPosY(father.pos.second, direction)};
  newNode.g = this->_closed.front().g + 1;
  if (possiblePos.first < 0 || possiblePos.first >= this->_mapSize || possiblePos.second < 0 || possiblePos.second >= this->_mapSize) {
    return ;
  }
  if (this->_map[possiblePos.second][possiblePos.first] != POSSIBLE &&
      this->_map[possiblePos.second][possiblePos.first] != COIN &&
      this->_map[possiblePos.second][possiblePos.first] != BOOST &&
      this->_map[possiblePos.second][possiblePos.first] != EMPTY &&
      this->_map[possiblePos.second][possiblePos.first] != WAITING &&
      this->_map[possiblePos.second][possiblePos.first] != EXIT
    ) {
    return ;
  }
  newNode.pos = possiblePos;
  newNode.f = this->_closed.front().g + this->getHeuristic(newNode.pos);
  if (this->_map[newNode.pos.second][newNode.pos.first] != WAITING) {
    this->_map[newNode.pos.second][newNode.pos.first] = WAITING;
    this->_open.push_front(newNode);
  } else {
    node old = this->getNode(newNode.pos);
    if (newNode.g < old.g) {
      old.g = newNode.g;
      old.f = newNode.f;
      old.father.first = newNode.father.first;
      old.father.second = newNode.father.second;
    }
  }
}

int arcade::AStar::getPosX(int y, arcade::dir direction) {
  switch(direction)
  {
    case NORTH:
      return y - 1;
    case EAST:
      return y;
    case SOUTH:
      return y + 1;
    default:
      return y;
  }
}

int arcade::AStar::getPosY(int x, arcade::dir direction) {
  switch(direction)
  {
    case NORTH:
      return x;
    case EAST:
      return x + 1;
    case SOUTH:
      return x;
    default:
      return x - 1;
  }
}

arcade::node arcade::AStar::getNode(const std::pair<int, int> &pos) {
  for (auto &currentNode : this->_open)
    if (currentNode.pos.first == pos.first && currentNode.pos.second == pos.second)
      return currentNode;
  return this->_open.front();
}

void arcade::AStar::fill_result(arcade::node selected) {
  node	father;

  father.pos = {selected.father.first, selected.father.second};
  this->_result.push_back({selected.pos.first, selected.pos.second});
  while (father.pos.first != -1 && father.pos.second != -1) {
    this->_result.push_back({father.pos.first, father.pos.second});
    for (auto &currentNode : this->_closed) {
      if (currentNode.pos.first == father.pos.first && currentNode.pos.second == father.pos.second) {
	father.pos.first = currentNode.father.first;
	father.pos.second = currentNode.father.second;
	break;
      }
    }
  }
}
