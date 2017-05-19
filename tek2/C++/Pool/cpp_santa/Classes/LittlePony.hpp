/*
** LittlePony.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/LittlePony.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 10:51:11 2017 Antoine FORET
** Last update Sat Jan 14 10:51:11 2017 Antoine FORET
*/

#ifndef CPP_SANTA_LITTLEPONY_HPP
# define CPP_SANTA_LITTLEPONY_HPP

# include		"Abstracts/AToy.hpp"

class			LittlePony : public AToy {

private:

public:
  LittlePony(const std::string &name = "Basic Pony");
  LittlePony(const LittlePony &pony);
  virtual ~LittlePony();

  bool			isTaken();
  bool			isPut();
  virtual LittlePony	*clone() const;

  /* OPERATORS */
  LittlePony		&operator=(const LittlePony &pony);

};


#endif //CPP_SANTA_LITTLEPONY_HPP
