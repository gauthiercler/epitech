/*
** MenuButton.cpp for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/sources/menu/MenuButton.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 11 16:51:49 2017 Anas Buyumad
** Last update Sun Jun 11 16:51:49 2017 Anas Buyumad
*/

#include	"menu/MenuButton.hpp"

indie::MenuButton::MenuButton(irr::gui::IGUIEnvironment *gui, irr::video::ITexture *texture, irr::s32 xPos, irr::s32 yPos, const std::string &name) :
    _button(nullptr)
    , _name(name)
    , _size(texture->getSize())
    , _xPos(xPos)
    , _yPos(yPos)
{

  _button = gui->addButton(irr::core::rect<irr::s32>(0, 0, 0, 0), 0, -1, L"", L"");
  if (_button == nullptr) {
    throw IrrlichtError("Couldn't create button.");
  }
  this->setImage(texture);
}

void indie::MenuButton::setImage(irr::video::ITexture *texture) {
  irr::core::dimension2d<irr::u32> size = texture->getSize();
  _button->setUseAlphaChannel(true);
  _button->setImage(texture);
  _button->setRelativePosition(irr::core::rect<irr::s32>(_xPos - (size.Width / 2), _yPos - (size.Height / 2), _xPos + (size.Width / 2), _yPos + (size.Height / 2)));
}

const std::string &indie::MenuButton::getName(void) {
  return _name;
}

void indie::MenuButton::setVisible(bool state) {
  _button->setVisible(state);
}

void indie::MenuButton::draw(void) {
  _button->draw();
}
