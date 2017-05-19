/*
** ColorHandler.hpp for cpp_arcade in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_arcade/src/libs/ncurses/includes/ColorHandler.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Mar 21 16:41:49 2017 Anas Buyumad
** Last update Tue Mar 21 16:41:49 2017 Anas Buyumad
*/

#ifndef CPP_ARCADE_COLORHANDLER_HPP
#define CPP_ARCADE_COLORHANDLER_HPP

#include <ncurses.h>
#include <Structures.hpp>
#include <unordered_map>

namespace Curses
{
  class				ColorHandler
  {

  public:

    ColorHandler();
    ~ColorHandler();

    bool		getColorHandle(void) const;
    bool		getColor256Handle(void) const;

    void		fillStandardPalette(void);
    void		fillComplexPalette(void);
    short int		getClosestShade(const arcade::rgb &color, const std::unordered_map<short int, arcade::rgb> &palette) const;

  private:

    bool		handles_color;
    bool		handles_color256;

  public :

    std::unordered_map<short int, arcade::rgb>	color_palette;
    std::unordered_map<short int, arcade::rgb>	pair_palette;
    std::unordered_map<short int, arcade::rgb>	text_palette;
  };
}
#endif //CPP_ARCADE_COLORHANDLER_HPP
