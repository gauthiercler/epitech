/*
** NetworkModule.hpp for cpp_gkrellm in /home/gogo/rendu/tek2/cpp_gkrellm/Modules/NetworkModule.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Jan 21 18:19:53 2017 Gauthier CLER
** Last update Sat Jan 21 18:19:53 2017 Gauthier CLER
*/

#ifndef CPP_GKRELLM_NETWORKMODULE_HPP
#define CPP_GKRELLM_NETWORKMODULE_HPP

#include "IMonitorModule.hpp"

class 						NetworkModule  : virtual public IMonitorModule {
private:
  std::string						_id;
  bool							_enabled;
  Config::GraphicMode 					_graphicMode;
  std::map<std::string, std::map<std::string, unsigned int>>	_content;
  std::map<std::string, std::map<std::string, unsigned int>>	_cache;
  unsigned int						_cacheInterval;
  unsigned int						_cacheIterator;
public:
  NetworkModule();
  NetworkModule(const NetworkModule &other);
  NetworkModule					&operator=(const NetworkModule &other);
  virtual ~NetworkModule();
  virtual bool					refresh();

  virtual void					clearCache();
  virtual void					setCacheInterval(unsigned int interval);

  virtual const std::string			&getIdentifier() const;

  virtual bool					isEnabled() const;
  virtual void					enable();
  virtual void					disable();

  virtual void					display(sf::RenderTexture &texture, sf::Text &writter);
  virtual void					display(WINDOW *ModuleRender);
  virtual void					setGraphics(Config::GraphicMode graphics);

  virtual IMonitorModule			*clone() const;
};


#endif //CPP_GKRELLM_NETWORKMODULE_HPP
