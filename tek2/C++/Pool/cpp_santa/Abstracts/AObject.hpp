/*
** AObject.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Abstracts/AObject.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 10:28:24 2017 Antoine FORET
** Last update Sat Jan 14 10:28:24 2017 Antoine FORET
*/

#ifndef CPP_SANTA_AOBJECT_HPP
# define CPP_SANTA_AOBJECT_HPP

# include			<string>

class				AObject {

protected:
  std::string			_name;
  bool				_wrappable;
  bool				_canWrap;
  bool				_taken;

public:
  AObject(const std::string &name = "Basic Object", bool wrappable = false, bool canWrap = false);
  AObject(const AObject &object);
  virtual ~AObject();


  virtual bool			isTaken() = 0;
  virtual bool			isPut() = 0;

  /* GETTERS */
  virtual const std::string	&getName() const;
  virtual bool			isWrappable() const;
  virtual bool			canWrap() const;
  bool				getTaken() const;
  virtual AObject		*clone() const = 0;

  /* SETTERS */
  void				setName(const std::string &name);
  void				setTaken(bool taken);
  void				setWrappable(bool wrappable);

  void				setCanWrap(bool canWrap);
  /* OPERATORS */
  AObject			&operator=(const AObject &object);
};

#endif //CPP_SANTA_AOBJECT_HPP
