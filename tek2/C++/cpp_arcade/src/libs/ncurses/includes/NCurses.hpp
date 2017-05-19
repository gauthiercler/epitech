/*
** Ncurses.hpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/libs/Ncurses/includes/Ncurses.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar 18 18:32:17 2017 Anas Buyumad
** Last update Sat Mar 18 18:32:17 2017 Anas Buyumad
*/

#ifndef CPP_ARCADE_NCURSES_HPP
#define CPP_ARCADE_NCURSES_HPP

#include <ncurses.h>
#include "IGraphic.hpp"
#include "Terminal.hpp"
#include "EventHandler.hpp"
#include "Error.hpp"

namespace arcade
{
  class				NCurses : public arcade::IGraphic
  {

  public:

    NCurses();
    virtual ~NCurses();

    virtual bool			openWindow(const std::string &name, uint64_t width, uint64_t height);
    virtual void			closeWindow();
    virtual arcade::IFrame		&addFrame(const arcade::pos &positions, uint64_t width, uint64_t height, uint64_t depth = 0);
    virtual arcade::IPicture		*loadPicture(const std::string &path) const;
    virtual arcade::ISprite		*loadSprite(const std::string &path) const;
    virtual arcade::ISound		*loadSound(const std::string &path) const;
    virtual bool			display();
    virtual const arcade::IEvent	&getEvent(bool blocking = true);
    virtual void			resetStackEvents();
    virtual void			deleteFrame(uint64_t id);

  private:

    Curses::Terminal			*terminal;
    Curses::EventHandler		*eventHandler;

  };
}


#endif //CPP_ARCADE_NCURSES_HPP
