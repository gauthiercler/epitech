/*
** FruitBox.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex00/FruitBox.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 10:44:18 2017 Gauthier CLER
** Last update Tue Jan 17 10:44:18 2017 Gauthier CLER
*/

#include "FruitBox.h"

FruitBox::FruitBox(int size) {
  this->_fruitBoxSize = size;
  this->_box = NULL;
}

FruitBox::~FruitBox() {
  FruitNode *tmp;
  while (this->_box)
  {
    tmp = this->_box;
    this->_box = this->_box->next;
    delete tmp;
  }
}

int FruitBox::nbFruits() const {
  int	counter = 0;
  FruitNode *tmp = this->_box;
  while (tmp)
  {
    tmp = tmp->next;
    counter += 1;
  }
  return counter;
}

bool FruitBox::putFruit(Fruit *f) {
  if (this->nbFruits() == this->_fruitBoxSize)
    return false;
  if (this->isFruit(f))
    return false;
  FruitNode	*tmp = this->_box;
  FruitNode	*newNode = new FruitNode;
  newNode->next = NULL;
  newNode->fruit = f;
  if (this->_box == NULL)
    this->_box = newNode;
  else{
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = newNode;
  }
  return true;
}

Fruit *FruitBox::pickFruit() {
  Fruit		*fruit;
  FruitNode	*tmp;
  if (this->_box == NULL)
    return NULL;

  tmp = this->_box;
  this->_box = this->_box->next;

  fruit = tmp->fruit;
  delete tmp;
  return fruit;
}

FruitNode *FruitBox::head() const{
  return this->_box;
}

bool FruitBox::isFruit(Fruit *f) {
  FruitNode *tmp;

  tmp = this->_box;
  while (tmp)
  {
    if (tmp->fruit == f)
      return true;
    tmp = tmp->next;
  }
  return false;
}
