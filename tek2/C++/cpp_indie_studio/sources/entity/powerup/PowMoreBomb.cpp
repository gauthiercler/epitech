/*
** PowMoreBomb.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/PowMoreBomb.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 14 21:02:18 2017 Anthony LECLERC
** Last update mer. juin 14 21:02:18 2017 Anthony LECLERC
*/

#include "entity/PowMoreBomb.hpp"

void indie::PowMoreBomb::power(indie::APlayer &player) {
  player.addBomb();
  player.getScore().updateGlobalScore(EntityType::BONUS);
  player.getScore().addScore(EntityType::BOMB_UP);
}

indie::PowMoreBomb::PowMoreBomb(irr::scene::ISceneManager *smgr) :
  APowerUp(smgr, "BombPowerUp")
{
}
