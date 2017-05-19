/*
** IElf.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Interfaces/IElf.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 13:20:02 2017 Antoine FORET
** Last update Sat Jan 14 13:20:02 2017 Antoine FORET
*/

#ifndef CPP_SANTA_IELF_HPP
# define CPP_SANTA_IELF_HPP

# include		"IConveyorBelt.hpp"
# include		"ITable.hpp"
# include		"Abstracts/AWrap.hpp"
# include		"Abstracts/AToy.hpp"

class IElf
{
public:
  virtual ~IElf() {};

  virtual bool		take(ITable &table) = 0;
  virtual bool		take(IConveyorBelt &conveyorBelt) = 0;
  virtual bool		put(ITable &table) = 0;
  virtual bool		put(IConveyorBelt &conveyorBelt) = 0;
  virtual bool		craftGift(AWrap &wrap, AObject &object) = 0;
  virtual bool		createGift(IConveyorBelt &conveyorBelt, ITable &table) = 0;
};

#endif //CPP_SANTA_IELF_HPP
