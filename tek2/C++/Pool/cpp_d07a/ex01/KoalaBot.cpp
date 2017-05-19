/*
** KoalaBot.cpp for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07a/ex01/KoalaBot.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 18:50:58 2017 Gauthier CLER
** Last update Tue Jan 10 18:50:59 2017 Gauthier CLER
*/


#include <iostream>
#include "KoalaBot.h"

KoalaBot::KoalaBot(const std::string & serial) {
  this->_serial = serial;
}

KoalaBot::~KoalaBot() {

}

void KoalaBot::informations() const{
  std::cout << "[KoalaBot] " << this->_serial << std::endl;
  this->_arms.informations();
  this->_legs.informations();
  this->_head.informations();
}

bool KoalaBot::status() const{
  return this->_legs.isFunctionnal() && this->_head.isFunctionnal() && this->_arms.isFunctionnal();
}

void KoalaBot::setParts(Head const &head) {
  this->_head = head;
}

void KoalaBot::setParts(Legs const &legs) {
  this->_legs = legs;
}

void KoalaBot::setParts(Arms const &arms) {
  this->_arms = arms;
}

void KoalaBot::swapParts(Head &head) {
  Head tmp = this->_head;
  this->_head = head;
  head = tmp;
}

void KoalaBot::swapParts(Legs &legs) {
  Legs tmp = this->_legs;
  this->_legs = legs;
  legs = tmp;
}

void KoalaBot::swapParts(Arms &arms) {
  Arms tmp = this->_arms;
  this->_arms = arms;
  arms = tmp;
}
