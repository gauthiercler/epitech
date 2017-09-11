/*
** PowSkullMalus.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/entity/powerup/PowSkullMalus.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 22:56:19 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 22:56:19 2017 Vincent DUSAUTOIR
*/

#include "entity/PowSkullMalus.hpp"

void indie::PowSkullMalus::power(indie::APlayer &player) {
  player.addMalus(1);
  player.getScore().updateGlobalScore(EntityType::MALUS);
  player.getScore().removeScore(EntityType::POWER_UP);
  player.getScore().removeScore(EntityType::BOMB_UP);
}

indie::PowSkullMalus::PowSkullMalus(irr::scene::ISceneManager *smgr) :
  APowerUp(smgr, "SkullPowerUp")
{
}