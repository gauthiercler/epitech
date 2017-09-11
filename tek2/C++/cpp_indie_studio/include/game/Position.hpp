/*
** Position.hpp for indie in /home/sylvain/Documents/projets/tek2/c++/cpp_indie_studio
**
** Made by Sylvain Chaugny
** Login   <sylvain.chaugny@epitech.eu>
**
** Started on  Tue May 23 16:15:02 2017 Sylvain Chaugny
** Last update Tue May 23 16:27:41 2017 Sylvain Chaugny
*/

#ifndef		CPP_INDIE_POSITION_HPP_
# define	CPP_INDIE_POSITION_HPP_

namespace	indie
{
  class		Position
  {
  public:
    int		x;
    int		y;

    Position(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    Position(Position const &ref) : x(ref.x), y(ref.y) {}
    Position &operator=(const Position &rhs) {
      x = rhs.x;
      y = rhs.y;
      return *this;
    }

    ~Position() {}
  };
};

#endif		/* !CPP_INDIE_POSITION_HPP_ */
