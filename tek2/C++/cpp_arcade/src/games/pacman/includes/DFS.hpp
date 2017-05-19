/*
** DFS.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/pacman/includes/DFS.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Apr 08 10:21:31 2017 Gauthier Cler
** Last update Sat Apr 08 10:21:31 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_DFS_HPP
#define CPP_ARCADE_DFS_HPP


#include <vector>
#include "PacmanCell.hpp"

namespace arcade {

  class DFS {
  public:
    DFS(const std::vector<std::vector<cellType>> &map, const std::pair<int, int> &start, const std::pair<int, int> &target, int mapSize);
    ~DFS();
    bool		recursiveFinding(std::pair<int, int> pos, std::pair<int, int> target);
    std::vector<std::pair<int, int>>	compute();
    void		addPath(std::pair<int, int> pos);
    bool		isNeighbor(std::pair<int, int> pos);
  private:
    std::vector<std::vector<cellType>>		_map;
    std::pair<int, int>				_start;
    std::pair<int, int>				_target;
    std::vector<std::pair<int, int>>		_result;
    int 					_mapSize;
  };
}


#endif //CPP_ARCADE_DFS_HPP
