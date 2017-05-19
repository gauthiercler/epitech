/*
** IFrame.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/interfaces/IFrame.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Mar 17 15:13:40 2017 Vincent DUSAUTOIR
** Last update Fri Mar 17 15:13:40 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_IFRAME_HPP
#define CPP_ARCADE_IFRAME_HPP


#include <string>
#include "Structures.hpp"
#include "IPicture.hpp"

namespace arcade
{

  class		IFrame
  {
  public:
    virtual		~IFrame() {};
    virtual bool	draw(const pos &pos, const IPicture &picture) = 0;
    virtual bool	draw(const pos &pos, const rectangle &rectangle) = 0;
    virtual bool	draw(const pos &pos, const std::string &str, const arcade::text &text) = 0;
    virtual bool	draw(const pos &pos, const arcade::circle &circle) = 0;
    virtual bool	draw(const pos &start, const pos &end, const rgb &color, uint64_t thickness = 1) = 0;
    virtual bool	draw(const rgb &color) = 0;
    virtual uint64_t	getId() const = 0;
  };
}

#endif //CPP_ARCADE_IFRAME_HPP
