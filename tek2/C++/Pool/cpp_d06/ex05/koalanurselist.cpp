/*
** koalanurselist.cpp for cpp_d06 in /home/gogo/rendu/tek2/cpp_d06/ex05/koalanurselist.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jan 09 21:32:58 2017 Gauthier CLER
** Last update Mon Jan 09 21:32:58 2017 Gauthier CLER
*/


#include "koalanurselist.h"

KoalaNurseList::KoalaNurseList(KoalaNurse *Koala) {
  this->koala = Koala;
  this->next = NULL;
  this->prev = NULL;
}

KoalaNurseList::~KoalaNurseList() {

}

bool KoalaNurseList::isEnd() {
  return this->next == NULL;
}

void KoalaNurseList::append(KoalaNurseList *node) {
  if (this->next != NULL)
    this->next->append(node);
  else{
    this->next = node;
    node->prev = this;
  }
}

KoalaNurse *KoalaNurseList::getFromID(int id){
  if (this->koala && this->koala->getId() == id)
    return this->koala;
  else if (this->next)
    return this->next->getFromID(id);
  return NULL;
}

KoalaNurseList	*KoalaNurseList::remove(KoalaNurseList *node) {
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

KoalaNurseList *KoalaNurseList::removeFromID(int id) {
  if (this->next && this->next->koala && this->next->koala->getId() == id){
    if (this->next->next != NULL)
    {
      this->next = this->next->next;
      this->next->prev = this;
    }
  }
  else if (this->next != NULL)
    this->next->removeFromID(id);
  return this;
}

void KoalaNurseList::dump() {
  KoalaNurseList *tmp = this;

  std::cout << "Liste des infirmieres: ";
  while (tmp)
  {
    if (tmp->koala == NULL)
      std::cout << "[NULL]";
    else
      std::cout << tmp->koala->getId();
    if (tmp->next != NULL)
      std::cout << ", ";
    tmp = tmp->next;
  }
  std::cout << "." << std::endl;
}

KoalaNurseList *KoalaNurseList::getNext() {
  return this->next;
}

KoalaNurse *KoalaNurseList::getContent() {
  return this->koala;
}

