/*
** koaladoctorlist.cpp for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex05/koaladoctorlist.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 21:26:36 2017 Gauthier CLER
** Last update Mon Jan 09 21:26:36 2017 Gauthier CLER
*/


#include "koaladoctorlist.h"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *Koala) {
  this->koala = Koala;
  this->next = NULL;
  this->prev = NULL;
}

KoalaDoctorList::~KoalaDoctorList() {

}

bool KoalaDoctorList::isEnd() {
  return this->next == NULL;
}

void KoalaDoctorList::append(KoalaDoctorList *node) {
  if (this->next != NULL)
    this->next->append(node);
  else{
    this->next = node;
    node->prev = this;
  }
}

KoalaDoctor *KoalaDoctorList::getFromName(std::string name) {
  if (this->koala && this->koala->getName().compare(name) == 0)
    return this->koala;
  else if (this->next)
    return this->next->getFromName(name);
  return NULL;
}

KoalaDoctorList	*KoalaDoctorList::remove(KoalaDoctorList *node) {
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

KoalaDoctorList *KoalaDoctorList::removeFromName(std::string name) {
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

void KoalaDoctorList::dump() {
  KoalaDoctorList *tmp = this;

  std::cout << "Liste des medecins: ";
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

KoalaDoctorList *KoalaDoctorList::getNext() {
  return this->next;
}

KoalaDoctor *KoalaDoctorList::getContent() {
  return this->koala;
}

