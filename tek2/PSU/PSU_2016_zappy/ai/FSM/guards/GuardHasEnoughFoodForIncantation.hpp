/*
** GuardHasEnoughFoorForIncantation.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/guards/GuardHasEnoughFoorForIncantation.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jun 29 18:37:51 2017 Gauthier Cler
** Last update Thu Jun 29 18:37:51 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_GUARDHASENOUGHFOORFORINCANTATION_HPP
# define PSU_2016_ZAPPY_GUARDHASENOUGHFOORFORINCANTATION_HPP

#include <iostream>
#include <FSM/configuration.hpp>
#include <classes/LevelRequirement.hpp>
#include "FSM/definitions.hpp"

namespace ai
{
  struct GuardHasEnoughFoodForIncantation
  {
    template <class Fsm,class Evt,class SourceState,class TargetState>
    bool operator()(Evt const& , Fsm&fsm , SourceState& ,TargetState&)
    {
      std::cout << "GuardHasEnoughFoodForIncantation::on_guard()" <<  std::endl;
      return fsm.inventory.food * FOOD_TIME >=
	fsm.vision.front().content.sum() * ai::actionTime.at(ResponseType::TAKE_OBJECT)
	+ ai::LevelRequirement::get()[fsm.level + 1].second.sum() * ai::actionTime.at(ResponseType::SET_OBJECT)
	+ FOOD_TIME * 2;
    }
  };
}

#endif /* !PSU_2016_ZAPPY_GUARDHASENOUGHFOORFORINCANTATION_HPP*/
