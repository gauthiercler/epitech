/*
** MenuButton.h for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/include/menu/MenuButton.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 11 16:31:39 2017 Anas Buyumad
** Last update Sun Jun 11 16:31:39 2017 Anas Buyumad
*/

#ifndef CPP_INDIE_STUDIO_MENUBUTTON_H
#define CPP_INDIE_STUDIO_MENUBUTTON_H

#include <IrrlichtWrapper.hpp>

namespace indie
{
  class MenuButton
  {
  public:

    enum Size
    {
      XHalfScreen = (SCREEN_WIDTH / 2),
      XFourthScreen = (SCREEN_WIDTH / 4),
      XEighthScreen = (SCREEN_WIDTH / 8),
      XSixteenthScreen = (SCREEN_WIDTH / 16),
      YHalfScreen = (SCREEN_HEIGHT / 2),
      YFourthScreen = (SCREEN_HEIGHT / 4),
      YEighthScreen = (SCREEN_HEIGHT / 8),
      YSixteenthScreen = (SCREEN_HEIGHT / 16)
    };

    enum Position
    {
      XCenter = (SCREEN_WIDTH / 2),
      XLeftCenter = (SCREEN_WIDTH / 2) - (SCREEN_WIDTH / 4),
      XRightCenter = (SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 4),
      YCenter = (SCREEN_HEIGHT / 2),
      YUpperCenter = (SCREEN_HEIGHT / 2) - (SCREEN_HEIGHT / 4),
      YLowerCenter = (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 4)
    };

    MenuButton(irr::gui::IGUIEnvironment *gui, irr::video::ITexture *texture, irr::s32 Xpos, irr::s32 Ypos, const std::string &name);

    void		setImage(irr::video::ITexture *texture);
    const std::string	&getName(void);
    void		setVisible(bool state);
    void		draw(void);

  private:

    irr::gui::IGUIButton		*_button;
    std::string				_name;
    irr::core::dimension2d<irr::u32>	_size;
    irr::s32				_xPos;
    irr::s32				_yPos;
  };
}

#endif //CPP_INDIE_STUDIO_MENUBUTTON_H
