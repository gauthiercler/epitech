/*
** IComponent.hpp for cpp_nanotekspice in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_nanotekspice/sources/interfaces/IComponent.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jan 27 20:15:48 2017 Anas Buyumad
** Last update Fri Jan 27 20:15:49 2017 Anas Buyumad
*/

#ifndef CPP_NANOTEKSPICE_ICOMPONENT_HPP
# define CPP_NANOTEKSPICE_ICOMPONENT_HPP


#include <cstddef>
#include <vector>

namespace nts
{
  enum Tristate
  {
    UNDEFINED = (-true),
    TRUE = true,
    FALSE = false
  };

  class IComponent
  {

  public:
    /// Compute value of the precised pin
    virtual nts::Tristate Compute(size_t pin_num_this = 1) = 0;

    /// Useful to link IComponent together
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target) = 0;

    ///// Print on terminal the name of the component and
    //// the state of every pin of the current component
    /// The output won’t be tested, but it may help you
    // as a trace.
    virtual void Dump(void) const = 0;

    virtual ~IComponent(void) { }
  };
}

#endif //CPP_NANOTEKSPICE_ICOMPONENT_HPP
