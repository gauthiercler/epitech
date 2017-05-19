/*
** Event.hpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/libs/Ncurses/includes/Event.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Mar 19 19:23:30 2017 Anas Buyumad
** Last update Sun Mar 19 19:23:30 2017 Anas Buyumad
*/

#ifndef CPP_ARCADE_EVENT_HPP
#define CPP_ARCADE_EVENT_HPP

#include "IEvent.hpp"

namespace Curses
{
  class				Event : public arcade::IEvent
  {

  public:

    Event(arcade::eventType type, arcade::eventValue value);
    virtual ~Event();

    virtual void		setType(arcade::eventType);
    virtual void		setValue(arcade::eventValue);
    virtual arcade::eventType		getType() const;
    virtual arcade::eventValue		getValue() const;
    virtual arcade::CommandType		get() const;

  private:

    arcade::eventType 		type;
    arcade::eventValue		value;
  };
}

#endif //CPP_ARCADE_EVENT_HPP
