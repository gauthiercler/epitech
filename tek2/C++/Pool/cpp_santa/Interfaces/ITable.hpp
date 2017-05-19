/*
** ITable.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Interfaces/ITable.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 11:39:45 2017 Antoine FORET
** Last update Sat Jan 14 11:39:47 2017 Antoine FORET
*/

#ifndef CPP_SANTA_ITABLE_HPP
# define CPP_SANTA_ITABLE_HPP

# include				"Abstracts/AObject.hpp"

class ITable
{
public:
  virtual ~ITable() {};

  virtual bool				put(AObject *object) = 0;
  virtual AObject			*take() = 0;
  virtual const std::string	* const *look() const = 0;

  virtual unsigned int			getItemsNumber() const = 0;
};

#endif //CPP_SANTA_ITABLE_HPP
