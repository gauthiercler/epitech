/*
** OpenGLEvent.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/libs/opengl/OpenGLEvent.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Mar 19 18:58:15 2017 Gauthier Cler
** Last update Sun Mar 19 18:58:15 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_OPENGLEVENT_HPP
#define CPP_ARCADE_OPENGLEVENT_HPP


#include <IEvent.hpp>
#include <SFML/Window/Event.hpp>
#include <map>

namespace arcade {
  class OpenGLEvent : public IEvent{

  public:
    OpenGLEvent();
    virtual			~OpenGLEvent();
    virtual void		setType(eventType type);
    virtual void		setValue(eventValue value);
    virtual eventType		getType() const;
    virtual eventValue		getValue() const;
    virtual CommandType		get() const;
    void			setSfmlEvent(sf::Event &event);
    void			initMap();

  private:
    std::map<sf::Keyboard::Key, arcade::eventValue >	_eventsMap;
    eventType 	_type;
    eventValue 	_value;
  };
}



#endif //CPP_ARCADE_OPENGLEVENT_HPP
