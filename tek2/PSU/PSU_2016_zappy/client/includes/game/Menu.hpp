/*
** Menu.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/Menu.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 13:23:27 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 13:23:27 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_MENU_HPP
#define PSU_2016_ZAPPY_MENU_HPP

#include "managers/EventManager.hpp"
#include "drawable/Text.hpp"
#include "drawable/Rect.hpp"

namespace zappy{
  class			Core;
  class			Menu{
    Core		&_core;
    std::string		_ip;
    Text		_ipText;
    Text		_zappyText;
    Text		_winner;
    Rect		_buttonBackground1;
    Rect		_buttonBackground2;
    Rect		_ipBackground;
    Text		_buttonText1;
    Text		_buttonText2;

  public:
    Menu(Core &core);
    ~Menu();

    void		update(EventManager &event);
    void		render();
    void		addIp(char c);
    void		connect();
    void		keyboardEvent(zappy::EventManager &event);
    void		mouseEvent(zappy::EventManager &event);
    void		setWinner(const std::string &winner);
  };
}

#endif //PSU_2016_ZAPPY_MENU_HPP
