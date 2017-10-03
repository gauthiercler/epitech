/*
** Random.cpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/classes/Random.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Jun 28 22:44:01 2017 Anas Buyumad
** Last update Wed Jun 28 22:44:02 2017 Anas Buyumad
*/

#include "Random.hpp"

ai::Random ai::Random::singleton;

ai::Random::Random() {
  _generator.seed(std::time(0));
}

ai::Random &ai::Random::get() {
  return singleton;
}

int ai::Random::operator()(int lowerBound, int higherBound) {
  boost::random::uniform_int_distribution<>	distributor(lowerBound, higherBound);
  return distributor(_generator);
}
