/*
** sickkoalalist.cpp for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex05/sickkoalalist.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 20:45:24 2017 Gauthier CLER
** Last update Mon Jan 09 20:45:24 2017 Gauthier CLER
*/

#include "sickkoalalist.h"

SickKoalaList::SickKoalaList(SickKoala *Koala) {
  this->koala = Koala;
  this->next = NULL;
  this->prev = NULL;
}

SickKoalaList::~SickKoalaList() {

}

bool SickKoalaList::isEnd() {
  return this->next == NULL;
}

void SickKoalaList::append(SickKoalaList *node) {
  if (this->next != NULL)
    this->next->append(node);
  else{
    this->next = node;
    node->prev = this;
  }
}

SickKoala *SickKoalaList::getFromName(std::string name) {
  if (this->koala && this->koala->getName().compare(name) == 0)
    return this->koala;
  else if (this->next)
    return this->next->getFromName(name);
  return NULL;
}

SickKoalaList	*SickKoalaList::remove(SickKoalaList *node) {
  if (this->next == node){
    if (this->next->next != NULL)
    {
      this->next = this->next->next;
      this->next->prev = this;
    }
  }
  else if (this->next != NULL)
    this->next->remove(node);
  return this;
}

SickKoalaList *SickKoalaList::removeFromName(std::string name) {
  if (this->next && this->next->koala && this->next->koala->getName().compare(name) == 0){
    if (this->next->next != NULL)
    {
      this->next = this->next->next;
      this->next->prev = this;
    }
  }
  else if (this->next != NULL)
    this->next->removeFromName(name);
  return this;
}

void SickKoalaList::dump() {
  SickKoalaList *tmp = this;

  std::cout << "Liste des patients: ";
  while (tmp)
  {
    if (tmp->koala == NULL)
      std::cout << "[NULL]";
    else
      std::cout << tmp->koala->getName();
    if (tmp->next != NULL)
      std::cout << ", ";
    tmp = tmp->next;
  }
  std::cout << "." << std::endl;
}

SickKoalaList *SickKoalaList::getNext() {
  return this->next;
}

SickKoala *SickKoalaList::getContent() {
  return this->koala;
}

