/*
** IResponse.hpp for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/ai/classes/IResponse.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Tue Jun 20 13:05:42 2017 Montagne Valentin
** Last update Tue Jun 20 13:05:42 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_IRESPONSE_HPP
#define PSU_2016_ZAPPY_IRESPONSE_HPP

#include				<string>

namespace 				ai {

  enum class				ResponseType
  {
    NONE,
    SERVER_WELCOME,
    SPOTS_REMAINING,
    MAP_DIMENSIONS,
    MESSAGE,
    DEATH,
    FORWARD,
    TURN_RIGHT,
    TURN_LEFT,
    LOOK,
    INVENTORY,
    BROADCAST,
    CONNECT,
    FORK,
    EJECT,
    TAKE_OBJECT,
    SET_OBJECT,
    START_INCANTATION,
    END_INCANTATION
  };

  class 				AResponse {

  protected:

    std::string				_input;
    ResponseType 			_type;
    bool				_status;

  public:

    AResponse(const std::string &input, ResponseType type);
    virtual ~AResponse() {};

    //GETTERS

    const std::string			&getInput(void) const;

    ResponseType 			getType(void) const;

    virtual bool			getStatus(void) const = 0;

    //SETTERS

    void				setStatus(bool stat);

  };

}

std::ostream				&operator<<(std::ostream &os, const ai::AResponse &resp);

#endif //PSU_2016_ZAPPY_IRESPONSE_HPP
