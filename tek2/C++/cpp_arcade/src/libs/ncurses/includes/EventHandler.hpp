/*
** EventHandler.hpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/libs/Ncurses/includes/EventHandler.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Mar 19 19:23:33 2017 Anas Buyumad
** Last update Sun Mar 19 19:23:33 2017 Anas Buyumad
*/

#ifndef CPP_ARCADE_EVENTS_HPP
#define CPP_ARCADE_EVENTS_HPP

#include <vector>
#include <unordered_map>
#include "Event.hpp"

namespace Curses
{
  class				EventHandler
  {
  public:

    EventHandler();
    ~EventHandler();

    const arcade::IEvent &	getEvent(bool blocking) const;

    void			setUpKeypad(void) const ;
    void			loadSequences(void);

  private:

    std::vector<const Curses::Event *>			events;
    std::unordered_map<std::string, arcade::eventValue>	keymap;
  };
}
#endif //CPP_ARCADE_EVENTS_HPP
