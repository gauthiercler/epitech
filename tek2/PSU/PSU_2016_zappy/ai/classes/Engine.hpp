/*
** Engine.hpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/Engine.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 23 11:33:36 2017 Gauthier Cler
** Last update Fri Jun 23 11:33:36 2017 Gauthier Cler
*/

#ifndef PSU_2016_ZAPPY_ENGINE_HPP
#define PSU_2016_ZAPPY_ENGINE_HPP

#include "FSM/FSM.hpp"
#include "IOStreamHandler.hpp"
#include "OptionHandler.hpp"
#include "SelectType.hpp"
#include "Socket.hpp"

namespace ai {

  class Engine {
  public:
    Engine(int argumentCount, const char *argumentValues[]);
    ~Engine();

    ai::machine 	&getFSM(void);
    const OptionHandler	&getOptionHandler(void);

    void		connect();
    void		assessServerResponse(ResponseType type);
    void		run();

  private:

    ai::machine		_machine;
    OptionHandler	_configuration;
  };

}


#endif //PSU_2016_ZAPPY_ENGINE_HPP
