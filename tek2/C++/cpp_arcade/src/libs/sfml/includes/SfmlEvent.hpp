/*
** SfmlEvent.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/includes/SfmlEvent.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Mar 20 09:17:59 2017 Vincent DUSAUTOIR
** Last update Mon Mar 20 09:17:59 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_SFMLEVENT_HPP
#define CPP_ARCADE_SFMLEVENT_HPP

#include <map>
#include <SFML/Window/Event.hpp>
#include "IEvent.hpp"

namespace arcade
{
  class SfmlEvent : public arcade::IEvent
  {
    eventType			_eventType;
    eventValue			_eventValue;
    std::map<sf::Keyboard::Key, arcade::eventValue >	_eventsMap;

  public:
    SfmlEvent();
    virtual ~SfmlEvent();
    virtual void			setType(eventType);
    virtual void			setValue(eventValue);
    virtual eventType			getType() const;
    virtual eventValue			getValue() const;
    virtual CommandType			get() const;
    void				setSfmlEvent(sf::Event &event);
    void				initMap();
  };
}

#endif //CPP_ARCADE_SFMLEVENT_HPP
