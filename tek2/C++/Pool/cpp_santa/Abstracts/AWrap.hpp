/*
** AWrap.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Abstracts/AWrap.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 10:56:33 2017 Antoine FORET
** Last update Sat Jan 14 10:56:33 2017 Antoine FORET
*/

#ifndef CPP_SANTA_AWRAP_HPP
# define CPP_SANTA_AWRAP_HPP

# include		"AObject.hpp"

class			AWrap : public AObject {

private:
  AObject		*_content;

public:
  AWrap(const std::string name = "Basic Wrap Container", bool wrappable = false, bool canWrap = false);
  AWrap(const AWrap &wrap);
  virtual ~AWrap();

  virtual bool		isTaken();
  virtual bool		isPut();

  /* GETTERS */
  AObject		*openMe(); // No const cause will set _content to NULL

  /* SETTERS */
  virtual bool		wrapMeThat(AObject *object);

  /* OPERATORS */
  AWrap			&operator=(const AWrap &wrap);

};


#endif //CPP_SANTA_AWRAP_HPP
