/*
** Response.hpp for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/ai/classes/Response.hpp
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Tue Jun 20 10:44:09 2017 Montagne Valentin
** Last update Tue Jun 20 10:44:09 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_RESPONSE_HPP
#define PSU_2016_ZAPPY_RESPONSE_HPP

#include                        "AResponse.hpp"

namespace 			ai {

  template 			<typename T>
  class 			Response : public AResponse {

  private:

    T				_response;

  public:

    Response(const std::string &input, ResponseType type)

      : AResponse(input, type)
    {}

    virtual ~Response() override {};

    void 			setValue(const T &value)
    {
      _response = value;
    }

    const T 			&getValue(void) const
    {
      return (_response);
    }

    virtual bool		getStatus(void) const override
    {
      return (_status);
    }

  };

}

#endif //PSU_2016_ZAPPY_RESPONSE_HPP
