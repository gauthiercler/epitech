/*
** SFML.hpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/sfml/includes/SFML.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sun Mar 19 20:29:08 2017 Vincent DUSAUTOIR
** Last update Sun Mar 19 20:29:09 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_ARCADE_SFML_HPP
#define CPP_ARCADE_SFML_HPP

#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include "IGraphic.hpp"
#include "SfmlFrame.hpp"
#include "SfmlPicture.hpp"
#include "SfmlSprite.hpp"
#include "SfmlEvent.hpp"
#include "SfmlSound.hpp"

namespace arcade
{

class				Sfml : public IGraphic
{
  sf::RenderWindow		*_window;
  SfmlEvent			_event;
  std::vector<std::pair<uint64_t, SfmlFrame *>> _frames;

public:
  Sfml();
  virtual ~Sfml();

  virtual bool			openWindow(const std::string &name, uint64_t width, uint64_t height);
  virtual void			closeWindow();
  virtual IFrame		&addFrame(const pos &positions, uint64_t width, uint64_t height, uint64_t depth = 0);
  virtual IPicture		*loadPicture(const std::string &path) const;
  virtual ISprite		*loadSprite(const std::string &path) const;
  virtual ISound		*loadSound(const std::string &path) const;
  virtual bool			display();
  virtual const IEvent		&getEvent(bool blocking = true);
  virtual void			resetStackEvents();
  virtual void			deleteFrame(uint64_t id);

};

}

#endif //CPP_ARCADE_SFML_HPP
