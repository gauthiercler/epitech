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

FruitBox *const *LittleHand::organizeCoconut(Coconut const *const *coconuts_packet) {
  int 		counter = 0;
  int		nbBox = 0;

  while (coconuts_packet[counter])
    counter += 1;
  nbBox = counter / 6;
  if (nbBox * 6 < counter)
    nbBox += 1;
  FruitBox	**array = new FruitBox *[nbBox + 1];

  int	arrayIndex = 0;
  int	i = 0;
  int	cocoPerBox = 0;
  int	k = 0;
  while (i < nbBox)
  {
    cocoPerBox = 6;
    if (k + 6 >= counter)
      cocoPerBox = counter - k;
    array[i] = new FruitBox(cocoPerBox);
    for (int j = 0; j < array[arrayIndex]->_fruitBoxSize; j++)
    {
      array[arrayIndex]->putFruit(const_cast<Coconut*>(coconuts_packet[k]));
      k++;
    }
    arrayIndex += 1;
    i++;
  }
  array[i] = NULL;
  return array;
}
