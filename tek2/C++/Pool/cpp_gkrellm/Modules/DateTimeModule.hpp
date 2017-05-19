/*
** DateTimeModule.hpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Modules/DateTimeModule.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jan 21 11:42:04 2017 Vincent DUSAUTOIR
** Last update Sat Jan 21 11:42:04 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_GKRELLM_DATETIMEMODULE_HPP
#define CPP_GKRELLM_DATETIMEMODULE_HPP

#include <Core/Core.hpp>
#include "IMonitorModule.hpp"

class						DateTimeModule : public IMonitorModule {
  std::string					_id;
  bool						_enabled;
  Config::GraphicMode				_graphicMode;
  std::map<std::string, std::string>		_content;

public:
  DateTimeModule();
  DateTimeModule(const DateTimeModule &other);
  virtual ~DateTimeModule();

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
  DateTimeModule				&operator=(const DateTimeModule &other);
};

#endif //CPP_GKRELLM_USERMODULE_HPP
