/*
** Teddy.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/Teddy.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 10:41:17 2017 Antoine FORET
** Last update Sat Jan 14 10:41:17 2017 Antoine FORET
*/

#ifndef CPP_SANTA_TEDDY_HPP
# define CPP_SANTA_TEDDY_HPP

# include		"Abstracts/AToy.hpp"

class			Teddy : public AToy {

private:

public:
  Teddy(const std::string & name = "Basic Teddy");
  Teddy(const Teddy &teddy);
  virtual ~Teddy();

  bool			isTaken();
  bool			isPut();
  virtual Teddy		*clone() const;

  /* OPERATORS */
  Teddy			&operator=(const Teddy &teddy);

};


#endif //CPP_SANTA_TEDDY_HPP
