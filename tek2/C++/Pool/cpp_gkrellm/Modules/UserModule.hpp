/*
** UserModule.hpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Modules/UserModule.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jan 21 11:42:04 2017 Vincent DUSAUTOIR
** Last update Sat Jan 21 11:42:04 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_GKRELLM_USERMODULE_HPP
#define CPP_GKRELLM_USERMODULE_HPP

#include <Core/Core.hpp>
#include <SFML/Graphics.hpp>
#include "IMonitorModule.hpp"

class						UserModule : public IMonitorModule {
  std::string					_id;
  bool						_enabled;
  Config::GraphicMode				_graphicMode;
  std::map<std::string, std::string>		_content;

public:
  UserModule();
  UserModule(const UserModule &other);
  virtual ~UserModule();

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
  UserModule					&operator=(const UserModule &other);
};


#endif //CPP_GKRELLM_USERMODULE_HPP
