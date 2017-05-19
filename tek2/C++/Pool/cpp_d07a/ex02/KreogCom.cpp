/*
** KreogCom.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07a/ex02/KreogCom.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 22:07:07 2017 Gauthier CLER
** Last update Tue Jan 10 22:07:09 2017 Gauthier CLER
*/


#include <clocale>
#include <iostream>
#include "KreogCom.h"

KreogCom::KreogCom(int x, int y, int serial) : _x(x), _y(y), _serial(serial){
  this->next = NULL;
  this->prev = NULL;
  std::cout << "KreogCom " << this->_serial << " initialised" << std::endl;
}

KreogCom::~KreogCom() {
  if (this->next)
    this->next->prev = this->prev;
  if (this->prev)
    this->prev->next = this->next;
  std::cout << "KreogCom " << this->_serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial) {
  KreogCom	*toAdd;

  toAdd = new KreogCom(x, y, serial);
  if (this->next == NULL){
    this->next = toAdd;
    toAdd->prev = this;
    toAdd->next = NULL;
  }
  else{
    toAdd->next = this->next;
    toAdd->prev = this;
    this->next->prev = toAdd;
    this->next = toAdd;
  }
}

KreogCom *KreogCom::getCom() {
  if (this->next != NULL)
    return this->next;
  return 0;
}

void KreogCom::removeCom() {
  KreogCom	*tmp;
  if (this->next != NULL)
  {
    tmp = this->next;
    if (tmp->next != NULL){
      this->next = tmp->next;
      this->next->prev = this;
    }else{
      this->next->prev = NULL;
      this->next = NULL;
    }
    delete tmp;
  }
}

void KreogCom::ping() const {
  std::cout << "KreogCom " << this->_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad() const{
  KreogCom *tmp = this->next;

  while (tmp)
  {
    tmp->ping();
    tmp = tmp->next;
  }
  this->ping();
}
