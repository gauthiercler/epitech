/*
** Inventory.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/Inventory.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 19 21:26:47 2017 Gauthier Cler
** Last update Mon Jun 19 21:26:47 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_INVENTORY_HPP
#define PSU_2016_ZAPPY_INVENTORY_HPP

#include			<iostream>

namespace ai {

  struct Inventory {

  public:

    unsigned int food;
    unsigned int linemate;
    unsigned int deraumere;
    unsigned int sibur;
    unsigned int mendiane;
    unsigned int phiras;
    unsigned int thystame;

    Inventory(unsigned int linemate = 0,
	      unsigned int deraumere = 0,
	      unsigned int sibur = 0,
	      unsigned int mendiane = 0,
	      unsigned int phiras = 0,
	      unsigned int thystame = 0,
	      unsigned int food = 0) :
      food(food),
      linemate(linemate),
      deraumere(deraumere),
      sibur(sibur),
      mendiane(mendiane),
      phiras(phiras),
      thystame(thystame)
    {};

    Inventory(const Inventory &other) :
      food(other.food),
      linemate(other.linemate),
      deraumere(other.deraumere),
      sibur(other.sibur),
      mendiane(other.mendiane),
      phiras(other.phiras),
      thystame(other.thystame) {
    }

    ~Inventory() {};

    Inventory	&operator=(const Inventory &other) {
      food = other.food;
      linemate = other.linemate;
      deraumere = other.deraumere;
      sibur = other.sibur;
      mendiane = other.mendiane;
      phiras = other.phiras;
      thystame = other.thystame;
      return *this;
    }

    Inventory	operator-(const Inventory &other) const {
      return {
	      other.linemate >= linemate ? 0 : linemate - other.linemate,
	      other.deraumere >= deraumere ? 0 : deraumere - other.deraumere,
	      other.sibur >= sibur ? 0 : sibur - other.sibur,
	      other.mendiane >= mendiane ? 0 : mendiane - other.mendiane,
	      other.phiras >= phiras ? 0 : phiras - other.phiras,
	      other.thystame >= thystame ? 0 : thystame - other.thystame};
    }

    bool	operator>=(const Inventory &rhs) {
      return
	deraumere >= rhs.deraumere &&
	linemate >= rhs.linemate &&
	mendiane >= rhs.mendiane &&
	phiras >= rhs.phiras &&
	sibur >= rhs.sibur &&
	thystame >= rhs.thystame &&
	food >= rhs.food;
    }

    bool	operator==(const Inventory &rhs) {
      return
	deraumere == rhs.deraumere &&
	linemate == rhs.linemate &&
	mendiane == rhs.mendiane &&
	phiras == rhs.phiras &&
	sibur == rhs.sibur &&
	thystame == rhs.thystame &&
	food == rhs.food;
    }
    unsigned int	sum() const {
      return deraumere + linemate + mendiane + phiras + thystame + food;
    }
    size_t		weight() const {
      return
	linemate * 1 +
	deraumere * 1 +
	sibur * 1 +
	mendiane * 1 +
	phiras * 1 +
	thystame * 1000;
    }
    double		getMatchWeight(const Inventory &target) const {
      return
	(target.linemate ? (linemate < target.linemate ? linemate * 1 : target.linemate * 1) : 0) +
	(target.deraumere ? (deraumere < target.deraumere ? deraumere * 1 : target.deraumere * 1) : 0) +
	(target.sibur ? (sibur < target.sibur ? sibur * 1 : target.sibur * 1) : 0) +
	(target.mendiane ? (mendiane < target.mendiane ? mendiane * 1 : target.mendiane * 1) : 0) +
	(target.phiras ? (phiras < target.phiras ? phiras * 1 : target.phiras * 1) : 0) +
	(target.thystame ? (thystame < target.thystame ? thystame * 1 : target.thystame * 1000) : 0);
    }

  };
}

inline std::ostream		&operator<<(std::ostream &os, const ai::Inventory &inventory) {
  os << "[Inventory]" << std::endl
     << "Food : " << inventory.food << std::endl
     << "Linemate : " << inventory.linemate << std::endl
     << "Deraumere : " << inventory.deraumere << std::endl
     << "Sibur : " << inventory.sibur << std::endl
     << "Mendiane : " << inventory.mendiane << std::endl
     << "Phiras : " << inventory.phiras << std::endl
     << "Thystame : " << inventory.thystame;
  return (os);
}

#endif //PSU_2016_ZAPPY_INVENTORY_HPP