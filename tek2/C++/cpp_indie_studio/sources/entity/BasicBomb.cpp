/*
** BasicBomb.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/BasicBomb.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juin 10 14:46:47 2017 Anthony LECLERC
** Last update sam. juin 10 14:46:47 2017 Anthony LECLERC
*/

#include	"entity/BasicBomb.hpp"

indie::BasicBomb::BasicBomb(irr::scene::ISceneManager *smgr, APlayer &player,
    irr::u64 power, irr::f32 timer, irr::u64 attackTime) :
    ABomb(smgr, "FireBomb",
    "TFireBomb", player,
    power, timer, attackTime)
{}

indie::BasicBomb::~BasicBomb()
{}

indie::ABomb *indie::BasicBomb::clone()
{
  return new BasicBomb(*this);
}
