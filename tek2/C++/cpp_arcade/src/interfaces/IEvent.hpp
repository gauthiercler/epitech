/*
** IEvent.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/interfaces/IEvent.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Mar 17 14:59:32 2017 Vincent DUSAUTOIR
** Last update Fri Mar 17 14:59:32 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_IEVENT_HPP
#define CPP_ARCADE_IEVENT_HPP

#include "Protocol.hpp"
#include "Structures.hpp"

namespace arcade{

  class		IEvent
  {
  public:
    virtual			~IEvent() {};
    virtual void		setType(eventType) = 0;
    virtual void		setValue(eventValue) = 0;
    virtual eventType		getType() const = 0;
    virtual eventValue		getValue() const = 0;
    // Invalid if not define
    virtual CommandType		get() const = 0;
  };
}

#endif //CPP_ARCADE_IEVENT_HPP
