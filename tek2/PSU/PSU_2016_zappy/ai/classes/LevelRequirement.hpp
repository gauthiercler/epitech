/*
** LevelRequirement.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/LevelRequirement.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jun 28 16:51:18 2017 Gauthier Cler
** Last update Wed Jun 28 16:51:18 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_LEVELREQUIREMENT_HPP
# define PSU_2016_ZAPPY_LEVELREQUIREMENT_HPP

#include <vector>
#include <memory>
#include "Inventory.hpp"

namespace ai {
  class LevelRequirement {
  private:
    static LevelRequirement	singleton;
    const std::vector<std::pair<unsigned int, ai::Inventory>> _list = {
      {1, Inventory(1, 0, 0, 0, 0, 0)},
      {2, Inventory(1, 1, 1, 0, 0, 0)},
      {2, Inventory(2, 0, 1, 0, 2, 0)},
      {4, Inventory(1, 1, 2, 0, 1, 0)},
      {4, Inventory(1, 2, 1, 3, 0, 0)},
      {6, Inventory(1, 2, 3, 0, 1, 0)},
      {6, Inventory(2, 2, 2, 2, 2, 1)}
    };
    LevelRequirement()
    {};
  public:
    static const LevelRequirement &get();
    const std::pair<unsigned int, ai::Inventory>        operator[](unsigned int index) const;
  };

}

#endif /* !PSU_2016_ZAPPY_LEVELREQUIREMENT_HPP*/
