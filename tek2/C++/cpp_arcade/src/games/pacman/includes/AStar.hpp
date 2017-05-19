/*
** AStar.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/common/AStar.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Apr 05 15:14:30 2017 Gauthier Cler
** Last update Wed Apr 05 15:14:30 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_ASTAR_HPP
#define CPP_ARCADE_ASTAR_HPP

#include <utility>
#include <list>
#include <Structures.hpp>
#include "PacmanCell.hpp"
#include "Ghost.hpp"
#include <vector>

namespace arcade {

  enum dir
  {
    NORTH,
    SOUTH,
    EAST,
    WEST
  };

  struct s_node {
    int				f;
    int				g;
    int				h;
    std::pair<int, int>				pos;
    std::pair<int, int>				father;
  };

  typedef s_node node;
  class AStar {
  public:
    AStar(const std::vector<std::vector<cellType>> &map, const std::pair<int, int> &start, const std::pair<int, int> &target, int mapSize, std::vector<Ghost> enemies);
    ~AStar();
    std::vector<std::pair<int, int>>	compute();
    int					getHeuristic(const std::pair<int, int> &pos);
    node				getLowerNode();
    void				addSon(dir direction, node father);
    int					getPosX(int y, dir direction);
    int					getPosY(int x, dir direction);
    node				getNode(const std::pair<int, int> &pos);
    void				fill_result(node selected);

  private:
    std::list<node>				_open;
    std::list<node>				_closed;
    std::vector<std::vector<cellType>>		_map;
    std::vector<std::pair<int, int>>		_result;
    std::pair<int, int>				_start;
    std::pair<int, int>				_target;
    int 					_mapSize;
  };
}

#endif //CPP_ARCADE_ASTAR_HPP
