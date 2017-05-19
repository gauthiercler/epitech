/*
** IMonitorModule.hpp for cpp_gkrellm in /home/foret_a/Lab/cpp_gkrellm/Modules/IMonitorModule.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jan 20 22:42:04 2017 Antoine FORET
** Last update Sat Jan 21 19:28:12 2017 Antoine FORET
*/

#ifndef CPP_GKRELLM_IMONITORMODULE_HPP
# define CPP_GKRELLM_IMONITORMODULE_HPP

# include				<map>
# include				<SFML/Graphics.hpp>
# include				<ncurses.h>
# include				"Config/Config.hpp"

class					IMonitorModule
{
public:
  virtual ~IMonitorModule(){};

  /**
   * Gather data to store
   * @return bool
   */
  virtual bool					refresh() = 0;

  /**
   * clear current cache
   */
  virtual void					clearCache() = 0;

  /**
   * Set cache max interval cache is always between now and now - interval
   * @param unsigned int interval
   */
  virtual void					setCacheInterval(unsigned int interval) = 0;

  /**
   * Module identifier
   * @return const std::string
   */
  virtual const std::string			&getIdentifier() const = 0;

  /**
   * Check if Module is enabled
   * @return bool
   */
  virtual bool					isEnabled() const = 0;
  virtual void					enable() = 0;
  virtual void					disable() = 0;

  virtual void					display(sf::RenderTexture &texture, sf::Text &writter) = 0;
  virtual void					display(WINDOW *ModuleRender) = 0;

  /**
   * Change Graphic mode
   * @param Config::GraphicMode graphics
   */
  virtual void					setGraphics(Config::GraphicMode graphics) = 0;

  /**
   * Clone current Module
   * @return IMonitorModule
   */
  virtual IMonitorModule			*clone() const = 0;
};

#endif //CPP_GKRELLM_IMONITORMODULE_HPP
