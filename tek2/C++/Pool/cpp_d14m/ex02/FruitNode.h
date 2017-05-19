/*
** FruitNode.h for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex00/FruitNode.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 10:46:31 2017 Gauthier CLER
** Last update Tue Jan 17 10:46:31 2017 Gauthier CLER
*/

#ifndef CPP_D14M_FRUITNODE_H
#define CPP_D14M_FRUITNODE_H

#include "Fruit.h"

typedef struct s_fruitNode FruitNode;

struct s_fruitNode {
  Fruit		*fruit;
  FruitNode	*next;
};

#endif //CPP_D14M_FRUITNODE_H
