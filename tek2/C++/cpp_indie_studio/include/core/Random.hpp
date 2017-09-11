/*
** Random.hpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/include/core/Random.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 12 19:31:14 2017 Gauthier Cler
** Last update Mon Jun 12 19:31:14 2017 Gauthier Cler
*/

#ifndef CPP_INDIE_STUDIO_RANDOM_HPP
# define CPP_INDIE_STUDIO_RANDOM_HPP

#include <random>

namespace indie {
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

#endif /* !CPP_INDIE_STUDIO_RANDOM_HPP*/
