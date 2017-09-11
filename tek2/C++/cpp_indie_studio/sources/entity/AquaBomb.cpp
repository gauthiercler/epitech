/*
** BlueBomb.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/entity/BlueBomb.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Jun 14 15:45:29 2017 Vincent DUSAUTOIR
** Last update Wed Jun 14 15:45:29 2017 Vincent DUSAUTOIR
*/

#include <entity/Fire.hpp>
#include "entity/AquaBomb.hpp"
#include "entity/APlayer.hpp"

indie::AquaBomb::AquaBomb(irr::scene::ISceneManager *smgr, APlayer &player,
			    irr::u64 power, irr::f32 timer, irr::u64 attackTime) :
  ABomb(smgr, "AquaBomb",
	"TAquaBomb", player,
	power, timer, attackTime)
{}

indie::AquaBomb::~AquaBomb()
{}

indie::ABomb *indie::AquaBomb::clone()
{
  return new AquaBomb(*this);
}

bool indie::AquaBomb::killAtPos(indie::Map &map, irr::core::vector2di pos) {
  auto cell = map.getCell({pos.X, pos.Y});
  if (cell != nullptr) {
    if (cell->getType() == EntityType::FIRE)
      return false;
    cell->setDeath(true);
    if (cell->isKillable())
      this->_player.getScore().addScore(cell->getType());
    if (!cell->isCrossable() && !cell->isKillable())
      return true;
  } else {
    map.addEntity(std::make_shared<Fire>(Engine::get().getSceneManager(),
						"cube", "lava", 1, nullptr), pos);
  }
  return false;
}
