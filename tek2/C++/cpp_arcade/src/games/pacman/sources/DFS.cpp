/*
** DFS.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/pacman/includes/DFS.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Apr 08 10:21:42 2017 Gauthier Cler
** Last update Sat Apr 08 10:21:42 2017 Gauthier Cler
*/

#include <iostream>
#include "DFS.hpp"

arcade::DFS::DFS(const std::vector<std::vector<arcade::cellType>> &map,
		 const std::pair<int, int> &start,
		 const std::pair<int, int> &target, int mapSize) {
  this->_map = map;
  this->_start = start;
  this->_target = target;
  this->_mapSize = mapSize;
}

arcade::DFS::~DFS() {

}

bool arcade::DFS::recursiveFinding(std::pair<int, int> pos,
				   std::pair<int, int> target) {
  if (pos.first < 0 || pos.first >= this->_mapSize || pos.second < 0 || pos.second >= this->_mapSize)
    return false;
  if (this->_map[pos.second][pos.first] != EMPTY &&
      this->_map[pos.second][pos.first] != COIN &&
      this->_map[pos.second][pos.first] != BOOST)
    return false;
  if (pos.first == target.first && pos.second == target.second)
    return true;
  this->_map[pos.second][pos.first] = VISITED;
  if (recursiveFinding({pos.first - 1, pos.second}, target))
    return true;
  if (recursiveFinding({pos.first + 1, pos.second}, target))
    return true;
  if (recursiveFinding({pos.first, pos.second - 1}, target))
    return true;
  if (recursiveFinding({pos.first, pos.second + 1}, target))
    return true;
  this->_map[pos.second][pos.first] = EMPTY;
  return false;
}

std::vector<std::pair<int, int>> arcade::DFS::compute() {
  if (!this->recursiveFinding(this->_start, this->_target))
    this->_result.push_back(this->_start);
  this->addPath(this->_start);
  return this->_result;
}

void arcade::DFS::addPath(std::pair<int, int> pos) {
  if (pos.first >= 0 && pos.first < this->_mapSize && pos.second >= 0 && pos.second < this->_mapSize && this->_map[pos.second][pos.first] == VISITED) {
    this->_map[pos.second][pos.first] = EMPTY;
    this->_result.push_back(pos);
    this->addPath({pos.first + 1, pos.second});
    this->addPath({pos.first - 1, pos.second});
    this->addPath({pos.first, pos.second + 1});
    this->addPath({pos.first, pos.second - 1});
  }
}

bool arcade::DFS::isNeighbor(std::pair<int, int> pos) {
  return pos.first >= 0 && pos.first < this->_mapSize && pos.second >= 0 && pos.second < this->_mapSize && this->_map[pos.second][pos.first] == VISITED;
}
