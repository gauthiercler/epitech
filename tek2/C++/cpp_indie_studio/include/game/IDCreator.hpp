/*
** IDCreator.hpp for indie in /home/sylvain/Documents/projets/tek2/c++/cpp_indie_studio
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue May 23 16:17:12 2017 Sylvain Chaugny
** Last update Tue May 23 16:27:47 2017 Sylvain Chaugny
*/

#ifndef			CPP_INDIE_IDCREATOR_HPP_
# define		CPP_INDIE_IDCREATOR_HPP_

# include		<string>
# include		"game/Position.hpp"

namespace		indie
{
  class			IDCreator
  {
  public:
    static std::string	getID(std::string const &name = "ENT", Position const &pos = Position(0, 0))
    {
      return std::string(name + std::to_string(pos.x) + std::to_string(pos.y));
    }
  };
};

#endif		/* !CPP_INDIE_IDCREATOR_HPP_ */
