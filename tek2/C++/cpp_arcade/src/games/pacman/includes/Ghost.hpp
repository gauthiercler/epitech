/*
** Ghost.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/pacman/includes/Ghost.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Apr 05 23:00:46 2017 Gauthier Cler
** Last update Wed Apr 05 23:00:46 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_GHOST_HPP
#define CPP_ARCADE_GHOST_HPP


#include <utility>
#include <vector>

namespace arcade {

  enum GhostState {
    HUNTING,
    DEAD,
    RUN
  };

  class Ghost {
    std::pair<int, int>			_position;
    std::vector<std::pair<int, int>>	_path;
    uint64_t				_id;
    uint64_t				_deadId;
    GhostState 				_state;

  public:
    Ghost(const std::pair<int, int> &pos, uint64_t id, uint64_t deadId, GhostState state);
    ~Ghost();
    void				setPos(const std::pair<int, int> &pos);
    std::pair<int, int>			getPos() const;
    void				setPath(const std::vector<std::pair<int , int>> &path);
    const std::pair<int, int>		getFirstElement() const;
    void				eraseFirstElement();
    unsigned long			getPathSize() const;
    uint64_t				getId() const;
    uint64_t				getDeadId() const;
    GhostState				getState() const;
    void				setState(const GhostState &state);
  };
}


#endif //CPP_ARCADE_GHOST_HPP
