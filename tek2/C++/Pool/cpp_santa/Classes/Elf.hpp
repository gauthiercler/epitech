/*
** Elf.hpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Classes/Elf.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 13:51:47 2017 Antoine FORET
** Last update Sat Jan 14 13:51:47 2017 Antoine FORET
*/

#ifndef CPP_SANTA_ELF_HPP
# define CPP_SANTA_ELF_HPP

# include		"Interfaces/IElf.hpp"

class			Elf : public IElf {

private:
  std::string		_name;
  AObject		*_leftHand;
  AObject		*_rightHand;

public:
  Elf(const std::string &name = "Ditto");
  Elf(const Elf &elf);
  virtual ~Elf();

  virtual bool		take(ITable &table);
  virtual bool		take(IConveyorBelt &conveyorBelt);
  virtual bool		put(ITable &table);
  virtual bool		put(IConveyorBelt &conveyorBelt);
  virtual bool		craftGift(AWrap &wrap, AObject &object);
  virtual bool		createGift(IConveyorBelt &conveyorBelt, ITable &table);

  /* GETTERS */
  AObject		*getLeftHand() const;
  AObject		*getRightHand() const;
  const std::string	&getName() const;

  /* SETTERS */
  void			setLeftHand(AObject *object);
  void			setRightHand(AObject *object);
  void			setName(const std::string &name);

  /* OPERATORS */
  Elf			&operator=(const Elf &elf);

};


#endif //CPP_SANTA_ELF_HPP
