/*
** Errors.hpp for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14a/Errors.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 16:19:37 2017 Gauthier CLER
** Last update Tue Jan 17 16:19:37 2017 Gauthier CLER
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>

class NasaError : public std::exception
{
public:
  NasaError(std::string const &message,
	    std::string const &component = "Unknown");
  std::string const &getComponent() const;
  virtual ~NasaError() throw() {};
  const char* what() const throw(){  return this->_message.c_str(); };
private:
  std::string _message;
  std::string	_component;
};

class MissionCriticalError : public NasaError
{
public:
  MissionCriticalError(std::string const &message,
		       std::string const &component = "Unknown");
  virtual ~MissionCriticalError() throw() {};

};

class LifeCriticalError : public NasaError
{
public:
  LifeCriticalError(std::string const &message,
		    std::string const &component = "Unknown");
  virtual ~LifeCriticalError() throw() {};
};

class UserError : public NasaError
{
public:
  UserError(std::string const &message,
	    std::string const &component = "Unknown");
  virtual ~UserError() throw() {};
};

class CommunicationError : public NasaError
{
public:
  CommunicationError(std::string const &message);
  virtual ~CommunicationError() throw() {};
};

#endif