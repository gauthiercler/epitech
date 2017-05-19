/*
** TablePePeNoel.cpp for cpp_santa in /home/gogo/rendu/tek2/cpp_santa/Classes/TablePePeNoel.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Jan 14 14:02:52 2017 Gauthier CLER
** Last update Sat Jan 14 14:02:52 2017 Gauthier CLER
*/

#include <iostream>
#include "TablePePeNoel.hpp"


TablePePeNoel::TablePePeNoel() : ITable() {
  for (unsigned int idx = 0; idx < MAX_TABLE_CAPACITY; idx += 1){
    this->setItem(idx, NULL);
  }
}

TablePePeNoel::TablePePeNoel(const TablePePeNoel &tablePePeNoel) {
  for (unsigned int idx = 0; idx < MAX_TABLE_CAPACITY; idx += 1)
    this->setItem(idx, tablePePeNoel.getItem(idx));
}

TablePePeNoel::~TablePePeNoel() {
  for (unsigned int i = 0; i < MAX_TABLE_CAPACITY ; i++) {
    if (this->getItem(i) != NULL)
      delete this->getItem(i);
  }
}

const std::string * const *TablePePeNoel::look() const {
  return this->_itemsName;
}

AObject *TablePePeNoel::getItem(unsigned int idx) const{
  return this->_items[idx];
}

bool TablePePeNoel::put(AObject *object) {
  if (this->getItemsNumber() == MAX_TABLE_CAPACITY){
    std::cerr << "Impossible to add another object, table is full" << std::endl;
    return false;
  }
  for (unsigned int idx = 0; idx < this->getItemsNumber(); idx += 1)
  {
    if (this->getItem(idx) == NULL){
      this->setItem(idx, object);
      break;
    }
  }
  return true;
}

AObject *TablePePeNoel::take() {
  AObject	*selectedObject;

  if (!this->getItemsNumber())
    return NULL;
  selectedObject = this->getItem(0);
  this->setItem(0, NULL);
  this->refreshNames();
  return selectedObject;
}

void TablePePeNoel::refreshNames() {
  AObject	*tmp;
  for (unsigned int idx = 0; idx < MAX_TABLE_CAPACITY - 1; idx += 1)
  {
    if (!this->getItem(idx)){
      tmp = this->getItem(idx);
      this->setItem(idx, this->getItem(idx + 1));
      this->setItem(idx + 1, tmp);
    }
  }
}

TablePePeNoel &TablePePeNoel::operator=(const TablePePeNoel &tablePePeNoel) {
  for (unsigned int idx = 0; idx < MAX_TABLE_CAPACITY; idx += 1)
    this->setItem(idx, tablePePeNoel.getItem(idx));
  this->refreshNames();
  return *this;
}

unsigned int TablePePeNoel::getItemsNumber() const {
  unsigned int	counter = 0;

  for (unsigned int idx = 0; this->getItem(idx); idx += 1)
    counter += 1;
  return counter;
}

void TablePePeNoel::setItem(unsigned int idx, AObject *item) {
  this->_items[idx] = item;
  if (this->getItem(idx) != NULL)
    this->_itemsName[idx] = &this->getItem(idx)->getName();
  else
    this->_itemsName[idx] = NULL;
}
