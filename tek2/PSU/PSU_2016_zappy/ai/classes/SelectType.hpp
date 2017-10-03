/*
** SelectType.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/SelectType.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Jun 24 19:08:52 2017 Gauthier Cler
** Last update Sat Jun 24 19:08:52 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_SELECTTYPE_HPP
# define PSU_2016_ZAPPY_SELECTTYPE_HPP

#include "AResponse.hpp"
#include "Parser.hpp"

namespace ai {
  template <ResponseType>
  struct SelectType;

  template<> struct SelectType<ResponseType::FORWARD> { typedef bool type; };
  template<> struct SelectType<ResponseType::TURN_RIGHT> { typedef bool type; };
  template<> struct SelectType<ResponseType::TURN_LEFT> { typedef bool type; };
  template<> struct SelectType<ResponseType::LOOK> { typedef std::vector<ai::Cell> type; };
  template<> struct SelectType<ResponseType::INVENTORY> { typedef Inventory type; };
  template<> struct SelectType<ResponseType::BROADCAST> { typedef bool type; };
  template<> struct SelectType<ResponseType::CONNECT> { typedef unsigned int type; };
  template<> struct SelectType<ResponseType::FORK> { typedef bool type; };
  template<> struct SelectType<ResponseType::EJECT> { typedef bool type; };
  template<> struct SelectType<ResponseType::TAKE_OBJECT> { typedef bool type; };
  template<> struct SelectType<ResponseType::SET_OBJECT> { typedef bool type; };
  template<> struct SelectType<ResponseType::START_INCANTATION> { typedef int type; };
}

#endif /* !PSU_2016_ZAPPY_SELECTTYPE_HPP*/
