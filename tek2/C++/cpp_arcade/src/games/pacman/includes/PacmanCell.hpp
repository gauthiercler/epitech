/*
** PacmanCell.h for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/pacman/includes/PacmanCell.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Apr 08 15:33:58 2017 Gauthier Cler
** Last update Sat Apr 08 15:33:58 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_PACMANCELL_H
#define CPP_ARCADE_PACMANCELL_H

namespace arcade {
  enum cellType
  {
    EMPTY,
    WALL,
    COIN,
    BOOST,
    FRUIT,
    PACMAN,
    GHOST,
    VISITED,
    EXIT,
    POSSIBLE,
    WAITING,
w
  };
}

#endif //CPP_ARCADE_PACMANCELL_H
