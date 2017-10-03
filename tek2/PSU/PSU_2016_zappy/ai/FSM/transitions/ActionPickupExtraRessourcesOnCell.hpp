/*
** ActionPickupExtraRessourcesOnCell.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/FSM/transitions/ActionPickupExtraRessourcesOnCell.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jun 29 19:18:03 2017 Gauthier Cler
** Last update Thu Jun 29 19:18:03 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ACTIONPICKUPEXTRARESSOURCESONCELL_HPP
# define PSU_2016_ZAPPY_ACTIONPICKUPEXTRARESSOURCESONCELL_HPP

#include <classes/IOStreamHandler.hpp>
#include <classes/LevelRequirement.hpp>

namespace ai {
  struct ActionPickupExtraRessourcesOnCell {

    ItemType	getExtraRessourceType(Inventory &cell, unsigned int &level) const {
      auto needed = ai::LevelRequirement::get()[level + 1].second;

      if (cell == needed)
	return ItemType::NONE;

      if (cell.deraumere > needed.deraumere) return ItemType::DERAUMERE;
      if (cell.linemate > needed.linemate) return ItemType::LINEMATE;
      if (cell.mendiane > needed.mendiane) return ItemType::MENDIANE;
      if (cell.food > needed.food) return ItemType::FOOD;
      if (cell.phiras > needed.phiras) return ItemType::PHIRAS;
      if (cell.sibur > needed.sibur) return ItemType::SIBUR;
      if (cell.thystame > needed.thystame) return ItemType::THYSTAME;

      return ItemType::NONE;
    }

    void	removeItemFromCell(Inventory &cell, ItemType type) const {
      switch (type) {
	case ItemType::DERAUMERE: cell.deraumere -= 1; break;
	case ItemType::LINEMATE: cell.linemate -= 1; break;
	case ItemType::MENDIANE: cell.mendiane -= 1; break;
	case ItemType::FOOD: cell.food -= 1; break;
	case ItemType::PHIRAS: cell.phiras -= 1; break;
	case ItemType::SIBUR: cell.sibur -= 1; break;
	case ItemType::THYSTAME: cell.thystame -= 1; break;
	default:
	  break;
      }
    }

    template <class Event, class Fsm, class SourceState, class TargetState>
    void operator()(Event const&, Fsm&fsm, SourceState&, TargetState&) const
    {
      std::cout << "ActionPickupExtraRessourcesOnCell()" << std::endl;
      ItemType type = this->getExtraRessourceType(fsm.vision.front().content, fsm.level);
      if (type != ItemType::NONE) {
	auto response = IOStreamHandler::get().getResponseHandler().requestObjectAction(ResponseType::TAKE_OBJECT, type);

	if (!response->getStatus()) {
	  IOStreamHandler::get().abortConnection(
	    "ActionPickupExtraRessourcesOnCell :: Invalid Take Extra Ressources Response");
	}
	this->removeItemFromCell(fsm.vision.front().content, type);
      }
    }
  };
}

#endif /* !PSU_2016_ZAPPY_ACTIONPICKUPEXTRARESSOURCESONCELL_HPP*/
