/*
** WindowManager.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/managers/WindowManager.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 10:54:52 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 10:54:52 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_WINDOWMANAGER_HPP
#define PSU_2016_ZAPPY_WINDOWMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <utils/Size.hpp>
#include <drawable/IDrawable.hpp>

namespace zappy {
  class	WindowManager{
    sf::RenderWindow	_window;
    Size		_size;

  public:
    WindowManager(const Size &size = Size(1440, 900), const std::string &name = "Zappy");
    ~WindowManager();

    bool		isOpen();
    sf::RenderWindow	&getWindow();
    void		close();
    void		display();
    void		draw(const sf::Drawable& drawable, const sf::RenderStates& states = sf::RenderStates::Default);
    void		draw(IDrawable &drawable);
    void		clear(const sf::Color& color = sf::Color(0, 0, 0, 255));
    const Size		&getSize() const;
  };
}

#endif //PSU_2016_ZAPPY_WINDOWMANAGER_HPP
