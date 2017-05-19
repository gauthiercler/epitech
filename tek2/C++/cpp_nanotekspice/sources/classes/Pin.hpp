/*
** Pin.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/Pin.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Jan 30 13:32:38 2017 Anas Buyumad
** Last update Mon Jan 30 13:32:38 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_PIN_HPP
#define CPP_NANOTEKSPICE_PIN_HPP

#include <sources/interfaces/IComponent.hpp>

namespace nts { class AComponent; }

class Pin {

public:

  enum PinType
  {
    INPUT,
    OUTPUT,
    IGNORED
  };

  Pin(PinType Type = INPUT, nts::IComponent *motherboard = NULL, size_t number = 0, bool border = false);
  ~Pin();

  PinType 		getType() const;
  nts::Tristate 	getValue() const;
  nts::IComponent	*getMotherboard() const;
  size_t		getMBnumber() const;
  bool			isLinked() const;
  bool			isLocked() const;
  std::pair<nts::IComponent*, size_t>	*getComponentLinkAt(size_t index) const;

  void			setType(Pin::PinType Type);
  void			setValue(nts::Tristate value);
  void			setLinkState(bool state);
  void			setLockState(bool state);
  void			setComponentLink(nts::IComponent *component, size_t pin_num);

  nts::Tristate		Compute();
  void			Dump() const;

private:

  PinType						_type;
  nts::Tristate 					_value;
  size_t						_number;
  bool							_border;
  bool							_isLinked;
  bool							_isLocked;
  std::vector<std::pair<nts::IComponent *, size_t> *>	_componentLinks;
  nts::IComponent *					_motherboard;
};


#endif //CPP_NANOTEKSPICE_PIN_HPP
