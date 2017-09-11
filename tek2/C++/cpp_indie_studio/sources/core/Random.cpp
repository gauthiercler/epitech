/*
** Random.cpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/include/core/Random.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jun 13 11:09:34 2017 Gauthier Cler
** Last update Tue Jun 13 11:09:34 2017 Gauthier Cler
*/

#include <core/Random.hpp>

indie::Random indie::Random::singleton;

indie::Random::Random()  : _seed(false)
{}

std::mt19937::result_type indie::Random::generate() {
  if (!_seed) {
    _rand.seed(std::random_device()());
    _seed = true;
  }
  return _rand();
}

indie::Random &indie::Random::get() {
  return singleton;
}

std::mt19937::result_type indie::Random::operator()(int i) {
  return generate() % i;
}