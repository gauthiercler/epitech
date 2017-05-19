/*
** Terminal.hpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/libs/Ncurses/includes/Terminal.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar 18 18:50:00 2017 Anas Buyumad
** Last update Sat Mar 18 18:50:00 2017 Anas Buyumad
*/

#ifndef CPP_ARCADE_TERMINAL_HPP
#define CPP_ARCADE_TERMINAL_HPP

#include <ncurses.h>
#include <termios.h>
#include <IFrame.hpp>
#include <vector>
#include "ColorHandler.hpp"

namespace Curses
{
  class				Terminal
  {

    class				Window : public arcade::IFrame
    {

    public:

      Window(Terminal *terminal, const arcade::pos &positions, uint64_t width, uint64_t height, uint64_t ratio, uint64_t depth, uint64_t id = 0);
      virtual ~Window();

      WINDOW		*getFrame() const;
      arcade::pos	getPos() const;
      uint64_t 		getWidth() const;
      uint64_t 		getHeight() const;
      uint64_t 		getRatio() const;
      uint64_t 		getDepth() const;
      virtual uint64_t	getId() const;
      bool		refresh();

      uint64_t 		getBaseX(uint64_t posx) const;
      uint64_t 		getBaseY(uint64_t posy) const;
      void		rotatePos(arcade::pos &pos, const arcade::pos &orig, float rotation_angle) const;
      bool		drawCell(const arcade::pos &pos, const arcade::rgb &color);

      virtual bool	draw(const arcade::pos &pos, const arcade::IPicture &picture);
      virtual bool	draw(const arcade::pos &pos, const arcade::rectangle &rectangle);
      virtual bool	draw(const arcade::pos &pos, const std::string &str, const arcade::text &text);
      virtual bool	draw(const arcade::pos &pos, const arcade::circle &circle);
      virtual bool	draw(const arcade::pos &start, const arcade::pos &end, const arcade::rgb &color, uint64_t thickness = 1);
      virtual bool	draw(const arcade::rgb &color);

    private:

      WINDOW		*frame;
      Terminal		*terminal;
      arcade::pos	positions;
      uint64_t 		width;
      uint64_t		height;
      uint64_t 		ratio;
      uint64_t 		depth;
      uint64_t		id;

    };

  public:

    Terminal(const std::string &name, uint64_t width, uint64_t height, uint64_t ratio = 1);
    ~Terminal();

    uint64_t 			getWidth(void) const;
    uint64_t 			getHeight(void) const;
    uint64_t 			getRatio(void) const;
    void 			setWidth(uint64_t width);
    void 			setHeght(uint64_t height);

    bool			handlesColor(void) const;
    bool			handlesColor256(void) const;
    short int			getColorPair(const arcade::rgb &color) const;
    short int			getTextPair(const arcade::rgb &color) const;
    bool			checkTerminalSize();
    bool			setupTerminal(void);
    bool			setNonBlockingIO(void);
    bool			backupTerminal() const;
    void			convertPos(const arcade::pos &pixelPos, arcade::pos &cursesPos) const;
    void			convertPixels(uint64_t &width, uint64_t &height) const;
    arcade::IFrame &		addWindow(const arcade::pos &positions, uint64_t width, uint64_t height, uint64_t depth);
    void			removeWindow(uint64_t id);
    bool			refreshTerminal() const;

  private:

    std::string				name;
    uint64_t				width;
    uint64_t 				height;
    uint64_t				ratio;
    ColorHandler			*colorHandler;
    struct termios			config;
    struct termios			backupConfig;
    std::vector<std::pair<uint64_t , Window *>>	windows;
  };

}

#endif //CPP_ARCADE_TERMINAL_HPP
