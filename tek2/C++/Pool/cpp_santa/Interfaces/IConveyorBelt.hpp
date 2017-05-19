/*
** IConveyorBelt.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Interfaces/IConveyorBelt.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 12:00:05 2017 Antoine FORET
** Last update Sat Jan 14 12:00:05 2017 Antoine FORET
*/

#ifndef CPP_SANTA_ICONVEYORBELT_HPP
# define CPP_SANTA_ICONVEYORBELT_HPP

# include		"Abstracts/AToy.hpp"
# include		"Abstracts/AWrap.hpp"

class IConveyorBelt
{

public:
  virtual ~IConveyorBelt() {};

  virtual bool			in() = 0;
  virtual bool			out() = 0;
  virtual bool			put(AObject *object) = 0;
  virtual AObject		*take() = 0;
  virtual const std::string	*look() const = 0;
};

#endif //CPP_SANTA_ICONVEYORBELT_HPP