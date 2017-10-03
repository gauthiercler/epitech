/*
** AResponse.cpp for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/ai/classes/AResponse.cpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Tue Jun 20 13:31:25 2017 Montagne Valentin
** Last update Tue Jun 20 13:31:25 2017 Montagne Valentin
*/

#include 				<iostream>
#include				"AResponse.hpp"

ai::AResponse::AResponse(const std::string &input, ai::ResponseType type)
  : _input(input), _type(type), _status(true)
{}

const std::string 			&ai::AResponse::getInput(void) const {
  return (_input);
}

ai::ResponseType 			ai::AResponse::getType(void) const {
  return (_type);
}

void 					ai::AResponse::setStatus(bool stat) {
  _status = stat;
}

std::ostream				&operator<<(std::ostream &os, const ai::AResponse &resp)
{
  os << "[Response]" << std::endl
    << " Status : " << resp.getStatus() << std::endl
    << " Input : " << resp.getInput();
  return (os);
}