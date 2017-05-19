/*
** Box.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/Box.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 11:06:57 2017 Antoine FORET
** Last update Sat Jan 14 11:06:57 2017 Antoine FORET
*/

#ifndef CPP_SANTA_BOX_HPP
# define CPP_SANTA_BOX_HPP

# include		"Abstracts/AWrap.hpp"

class			Box : public AWrap {

private:
  bool			_open;

public:
  Box();
  Box(const Box &box);
  virtual ~Box();

  AObject		*clone() const;

  /* GETTERS */
  bool			isOpen() const;

  /* SETTERS */
  void			closeMe();
  void			setOpen(bool open);
  virtual bool		wrapMeThat(AObject *object);

  /* OPERATORS */
  Box			&operator=(const Box &box);

};


#endif //CPP_SANTA_BOX_HPP
