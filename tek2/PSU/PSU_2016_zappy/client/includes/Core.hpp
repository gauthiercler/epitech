/*
** Core.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/Core.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:02:10 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:02:10 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_CORE_HPP
#define PSU_2016_ZAPPY_CORE_HPP

#include <server/Buffer.hpp>
#include "game/Game.hpp"
#include "game/Menu.hpp"
#include "managers/Wrapper.hpp"

namespace zappy{
  enum class		CoreState
  {
    MENU,
    GAME
  };

  class			Core{
    Wrapper		&_wrapper;
    Menu		_menu;
    Game		_game;
    Buffer		_buffer;
    Parser		_parser;
    CoreState		_coreState;

  public:
    Core();
    ~Core();

    void	run();
    void	update();
    void	render();
    void	close();
    void	handleSocket(Socket &socket);
    void	setCoreState(CoreState state);
  };
}

#endif //PSU_2016_ZAPPY_CORE_HPP
