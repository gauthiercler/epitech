/*
** FlyModule.hpp for cpp_gkrellm in /home/gogo/rendu/tek2/cpp_gkrellm/Modules/FlyModule.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jan 22 05:28:55 2017 Gauthier CLER
** Last update Sun Jan 22 05:28:55 2017 Gauthier CLER
*/

#ifndef CPP_GKRELLM_FLYMODULE_HPP
#define CPP_GKRELLM_FLYMODULE_HPP


#include "IMonitorModule.hpp"

class FlyModule : public IMonitorModule {
  std::string					_id;
  bool						_enabled;
  Config::GraphicMode				_graphicMode;
  bool						_state;

public:
  FlyModule();
  FlyModule(const FlyModule &other);
  virtual ~FlyModule();

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
  FlyModule					&operator=(const FlyModule &other);
};


#endif //CPP_GKRELLM_FLYMODULE_HPP
