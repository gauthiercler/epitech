/*
** LittleHand.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex01/LittleHand.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 12:09:54 2017 Gauthier CLER
** Last update Tue Jan 17 12:09:54 2017 Gauthier CLER
*/

#include "LittleHand.h"

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons,
			      FruitBox &bananas, FruitBox &limes) {
  int		counter = 0;
  int		size = unsorted.nbFruits();
  while (counter < size)
  {
    bool ret = false;
    Fruit *currentFruit = unsorted.pickFruit();
    if (currentFruit->getName() == "lemon")
      ret = lemons.putFruit(currentFruit);
    else if (currentFruit->getName() == "banana")
      ret = bananas.putFruit(currentFruit);
    else if (currentFruit->getName() == "lime")
      ret = limes.putFruit(currentFruit);
    if (!ret)
      unsorted.putFruit(currentFruit);
    counter += 1;
  }
}
