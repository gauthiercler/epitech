/*
** Errors.cpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/Errors.cpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 16:19:06 2017 Gauthier CLER
** Last update Tue Jan 17 16:19:06 2017 Gauthier CLER
*/

#include "Errors.hpp"

NasaError::NasaError(std::string const &message, const std::string &component) : _message(message), _component(component){
}

std::string const &NasaError::getComponent() const {
  return this->_component;
}

MissionCriticalError::MissionCriticalError(std::string const &message,
					   const std::string &component)
  : NasaError(message, component) {

}

LifeCriticalError::LifeCriticalError(std::string const &message,
				     const std::string &component) : NasaError(
  message, component) {

}

UserError::UserError(std::string const &message, const std::string &component)
  : NasaError(message, component) {

}

CommunicationError::CommunicationError(std::string const &message)
  : NasaError(message, "CommunicationDevice") {

}
