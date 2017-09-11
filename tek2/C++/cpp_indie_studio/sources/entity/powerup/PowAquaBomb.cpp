/*
** PowAquaBomb.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/entity/powerup/PowAquaBomb.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 22:19:06 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 22:19:06 2017 Vincent DUSAUTOIR
*/

#include "entity/AquaBomb.hpp"
#include "entity/PowAquaBomb.hpp"

void indie::PowAquaBomb::power(indie::APlayer &player) {
  player.setBombType(std::make_unique<AquaBomb>(player.getSceneNode()->getSceneManager(),
                                      player));
  player.getScore().updateGlobalScore(EntityType::BONUS);
}

indie::PowAquaBomb::PowAquaBomb(irr::scene::ISceneManager *smgr) :
  APowerUp(smgr, "AquaPowerUp")
{
}
