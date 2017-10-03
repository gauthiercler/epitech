/*
** Random.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/utils/Random.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Jun 23 09:04:41 2017 Vincent DUSAUTOIR
** Last update Fri Jun 23 09:04:41 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_RANDOM_HPP
#define PSU_2016_ZAPPY_RANDOM_HPP

#include <random>

namespace zappy {
  class Random {
    static Random	singleton;
    std::mt19937	_rand;
    bool		_seed;
    Random();
  public:
    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;
    std::mt19937::result_type generate();
    static Random &get();
    std::mt19937::result_type operator()(int);
  };
}

#endif //PSU_2016_ZAPPY_RANDOM_HPP
