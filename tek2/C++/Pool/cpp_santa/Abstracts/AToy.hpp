/*
** AToy.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Abstracts/AToy.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 10:22:55 2017 Antoine FORET
** Last update Sat Jan 14 10:22:55 2017 Antoine FORET
*/

#ifndef CPP_SANTA_ATOY_HPP
#define CPP_SANTA_ATOY_HPP


# include		"AObject.hpp"

class			AToy : public AObject {

protected:

public:
  AToy(const std::string &name = "Basic Toy");
  AToy(const AToy &toy);
  virtual ~AToy();

  /* OPERATORS */
  AToy			&operator=(const AToy &toy);
};


#endif //CPP_SANTA_ATOY_HPP
