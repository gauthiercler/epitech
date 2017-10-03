/*
** ActionDropAllStonesOnCell.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/transitions/ActionDropAllStonesOnCell.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 23 10:39:20 2017 Gauthier Cler
** Last update Fri Jun 23 10:39:20 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ACTIONDROPALLSTONESONCELL_HPP
# define PSU_2016_ZAPPY_ACTIONDROPALLSTONESONCELL_HPP

#include <iostream>
#include <classes/LevelRequirement.hpp>

namespace ai {
  struct ActionDropAllStonesOnCell {

    ItemType	getItemToDrop(Inventory &cell, unsigned int &level) const {
      auto needed = ai::LevelRequirement::get()[level + 1].second;

      if (cell == needed)
	return ItemType::NONE;

      if (cell.deraumere < needed.deraumere) return ItemType::DERAUMERE;
      if (cell.linemate < needed.linemate) return ItemType::LINEMATE;
      if (cell.mendiane < needed.mendiane) return ItemType::MENDIANE;
      if (cell.food < needed.food) return ItemType::FOOD;
      if (cell.phiras < needed.phiras) return ItemType::PHIRAS;
      if (cell.sibur < needed.sibur) return ItemType::SIBUR;
      if (cell.thystame < needed.thystame) return ItemType::THYSTAME;

      return ItemType::NONE;
    }

    void	addItemToCell(Inventory &cell, ItemType type) const {
      switch (type) {
	case ItemType::DERAUMERE: cell.deraumere += 1; break;
	case ItemType::LINEMATE: cell.linemate += 1; break;
	case ItemType::MENDIANE: cell.mendiane += 1; break;
	case ItemType::FOOD: cell.food += 1; break;
	case ItemType::PHIRAS: cell.phiras += 1; break;
	case ItemType::SIBUR: cell.sibur += 1; break;
	case ItemType::THYSTAME: cell.thystame += 1; break;
	default:
	  break;
      }
    }

    template <class Event, class Fsm, class SourceState, class TargetState>
    void operator()(Event const&, Fsm&fsm, SourceState&, TargetState&) const
    {
      std::cout << "ActionDropAllStonesOnCell()" << std::endl;
      Inventory &content = fsm.vision.front().content;
      while (!(content >= ai::LevelRequirement::get()[fsm.level + 1].second)) {
	std::cout << content << std::endl;
	ItemType type = this->getItemToDrop(content, fsm.level);
	if (type != ItemType::NONE) {
	  std::cout << "Setting object of type " << static_cast<int>(type) << std::endl;
	  auto response = IOStreamHandler::get().getResponseHandler().requestObjectAction(ResponseType::SET_OBJECT, type);
	  if (!response->getStatus()) {
	    IOStreamHandler::get().abortConnection(
	      "ActionDropAllStonesOnCell :: Invalid Drop Ressource Response");
	  }
	  this->addItemToCell(content, type);
	}
      }
    }
  };
}

#endif /* !PSU_2016_ZAPPY_ACTIONDROPALLSTONESONCELL_HPP*/
