/*
** FruitBox.h for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex00/FruitBox.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 10:44:13 2017 Gauthier CLER
** Last update Tue Jan 17 10:44:13 2017 Gauthier CLER
*/

#ifndef CPP_D14M_FRUITBOX_H
#define CPP_D14M_FRUITBOX_H


#include "Fruit.h"
#include "FruitNode.h"

class FruitBox {
public:
  FruitBox(int size);
  ~FruitBox();
  int	nbFruits() const;
  bool	putFruit(Fruit *f);
  Fruit *pickFruit();
  bool	isFruit(Fruit *f);
  FruitNode	*head() const;
  int		_fruitBoxSize;

private:
  FruitNode	*_box;
};


#endif //CPP_D14M_FRUITBOX_H
