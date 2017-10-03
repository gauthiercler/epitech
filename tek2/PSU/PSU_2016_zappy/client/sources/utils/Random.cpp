/*
** Random.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/utils/Random.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Jun 23 09:05:01 2017 Vincent DUSAUTOIR
** Last update Fri Jun 23 09:05:01 2017 Vincent DUSAUTOIR
*/

#include "utils/Random.hpp"

zappy::Random zappy::Random::singleton;

zappy::Random::Random()  : _seed(false)
{}

std::mt19937::result_type zappy::Random::generate() {
  if (!_seed) {
    _rand.seed(std::random_device()());
    _seed = true;
  }
  return _rand();
}

zappy::Random &zappy::Random::get() {
  return singleton;
}

std::mt19937::result_type zappy::Random::operator()(int i) {
  return generate() % i;
}