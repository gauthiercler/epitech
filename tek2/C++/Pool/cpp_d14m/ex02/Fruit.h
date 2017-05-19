/*
** Fruit.h for cpp_d14m in /home/gogo/rendu/tek2/cpp_d14m/ex00/Fruit.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jan 17 10:20:09 2017 Gauthier CLER
** Last update Tue Jan 17 10:20:09 2017 Gauthier CLER
*/

#ifndef CPP_D14M_FRUIT_H
#define CPP_D14M_FRUIT_H


#include <string>

class Fruit {
protected:
  std::string		_name;

public:
  int			_vitamins;
  Fruit(int vitamin = 0);
  virtual	~Fruit();
  virtual std::string	getName() const = 0;
  void			setName(std::string);
  int			getVitamins() const;
  void			setVitamins(int vitamins);
};


#endif //CPP_D14M_FRUIT_H
