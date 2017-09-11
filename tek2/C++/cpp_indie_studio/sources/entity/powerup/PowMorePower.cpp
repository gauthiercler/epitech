/*
** PowMorePower.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/entity/powerup/PowMorePower.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 09:31:27 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 09:31:27 2017 Vincent DUSAUTOIR
*/

#include "entity/PowMorePower.hpp"

void indie::PowMorePower::power(indie::APlayer &player) {
  player.addPower(1);
  player.getScore().updateGlobalScore(EntityType::BONUS);
  player.getScore().addScore(EntityType::POWER_UP);
}

indie::PowMorePower::PowMorePower(irr::scene::ISceneManager *smgr) :
  APowerUp(smgr, "FirePowerUp")
{
}