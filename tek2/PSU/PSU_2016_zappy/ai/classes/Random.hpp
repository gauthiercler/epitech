/*
** Random.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/classes/Random.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Jun 28 22:43:15 2017 Anas Buyumad
** Last update Wed Jun 28 22:43:15 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_RANDOM_HPP
#define PSU_2016_ZAPPY_RANDOM_HPP

#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <ctime>

namespace ai {

  class Random {

    static Random				singleton;
    boost::random::mt19937			_generator;
    Random();

  public:

    Random(const Random&) = delete;
    Random& operator=(const Random&) = delete;
    static Random &get();
    int		operator()(int lowerBound, int higherBound);

  };

}


#endif //PSU_2016_ZAPPY_RANDOM_HPP
