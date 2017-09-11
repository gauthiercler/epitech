/*
** PowMoreSpeed.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/entity/powerup/PowMoreSpeed.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 23:09:06 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 23:09:06 2017 Vincent DUSAUTOIR
*/

#include	"entity/PowMoreSpeed.hpp"

void indie::PowMoreSpeed::power(indie::APlayer &player) {
  player.addSpeed(20);
  player.getScore().updateGlobalScore(EntityType::BONUS);
  player.getScore().addScore(EntityType::SPEED_UP);
}

indie::PowMoreSpeed::PowMoreSpeed(irr::scene::ISceneManager *smgr) :
  APowerUp(smgr, "SkatePowerUp")
{
}