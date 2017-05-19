/*
** KoalaBot.h for cpp_d07m in /home/gogo/rendu/tek2/cpp_d07a/ex01/KoalaBot.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 10 18:51:03 2017 Gauthier CLER
** Last update Tue Jan 10 18:51:04 2017 Gauthier CLER
*/


#ifndef CPP_D07M_KOALABOT_H
#define CPP_D07M_KOALABOT_H


#include "Parts.h"

class KoalaBot {
private:
  Head	_head;
  Legs	_legs;
  Arms	_arms;
  std::string	_serial;

public:
  KoalaBot(const std::string & serial = "Bob-01");
  ~KoalaBot();
  void setParts(Head const & head);
  void setParts(Legs const & legs);
  void setParts(Arms const & arms);
  void swapParts(Head & head);
  void swapParts(Legs & legs);
  void swapParts(Arms & arms);
  void informations() const;
  bool status() const;
};


#endif //CPP_D07M_KOALABOT_H
