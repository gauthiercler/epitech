/*
** AComponent.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/classes/AComponent.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Feb 03 15:52:07 2017 Anas Buyumad
** Last update Fri Feb 03 15:52:07 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_ACOMPONENT_HPP
#define CPP_NANOTEKSPICE_ACOMPONENT_HPP

#include <sources/interfaces/IComponent.hpp>
#include <string>
#include <iostream>
#include "Pin.hpp"

namespace nts
{
  class AComponent : public nts::IComponent {

  public:

    virtual ~AComponent();


    enum ComponentType
    {
      CHIPSET,
      CLOCK,
      OUTPUT,
      INPUT
    };

  protected:

    std::string				_name;
    ComponentType			_type;
    size_t				_nbPins;
    std::vector<Pin *>			_pins;
    std::vector<nts::IComponent *>	_innerCircuit;

  public:

    void				setName(std::string name);
    void				setType(ComponentType type);
    void				setNbPins(size_t amount);

    std::string				getName(void) const;
    ComponentType			getType(void) const;
    size_t				getNbPins() const;
    Pin *				getPinAt(size_t index) const;

    static bool				CheckPinInRange(size_t PinsAmount, size_t PinNumber);
    static bool				CheckDupeLink(std::vector<std::pair<nts::IComponent*, size_t>*> LinkList, nts::IComponent *component, size_t pin_num);

    static nts::Tristate 		ComputeListValue(std::vector<nts::Tristate> computeList);

    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
    virtual void Dump(void) const;
  };
}


#endif //CPP_NANOTEKSPICE_ACOMPONENT_HPP
