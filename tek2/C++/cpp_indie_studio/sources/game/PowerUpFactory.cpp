/*
** PowerUpFactory.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/PowerUpFactory.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 14 16:13:56 2017 Anthony LECLERC
** Last update mer. juin 14 16:13:56 2017 Anthony LECLERC
*/

#include <core/Random.hpp>
#include <iostream>
#include <algorithm>
#include "entity/PowerUpFactory.hpp"

std::vector<std::unique_ptr<indie::IPowerUpSpawner > > indie::PowerUpFactory::Factories;

indie::APowerUp *indie::PowerUpFactory::spawn() {
  irr::u64 weight = Random::get().generate() % 100;

  APowerUp *powerUp = nullptr;
  auto range = std::partition(Factories.begin(), Factories.end(), [=](auto& f) { return f->frequency() < weight; });
  if (range != Factories.end()) {
    std::random_shuffle(range, Factories.end(), Random::get());
    powerUp = (*range)->spawn();
  }
  return (powerUp);
}

void indie::PowerUpFactory::clear() {
  Factories.clear();
}
