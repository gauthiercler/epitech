/*
** IGraphic.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/interfaces/IGraphic.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Mar 17 15:32:12 2017 Vincent DUSAUTOIR
** Last update Fri Mar 17 15:32:12 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_IGRAPHIC_HPP
#define CPP_ARCADE_IGRAPHIC_HPP

#include <string>
#include "IFrame.hpp"
#include "IEvent.hpp"
#include "IPicture.hpp"
#include "ISprite.hpp"
#include "ISound.hpp"

namespace arcade
{
  class				IGraphic
  {
  public:
    virtual			~IGraphic() {};
    virtual bool		openWindow(const std::string &name, uint64_t width, uint64_t height) = 0;
    virtual void		closeWindow() = 0;
    virtual IFrame		&addFrame(const pos &positions, uint64_t width, uint64_t height, uint64_t depth = 0) = 0;
    virtual IPicture		*loadPicture(const std::string &path) const = 0;
    virtual ISprite		*loadSprite(const std::string &path) const = 0;
    virtual ISound		*loadSound(const std::string &path) const = 0;
    virtual void		deleteFrame(uint64_t id) = 0;
    virtual bool		display() = 0;
    virtual const IEvent	&getEvent(bool blocking = true) = 0;
    virtual void		resetStackEvents() = 0;
  };
}

#endif //CPP_ARCADE_IGRAPHIC_HPP
