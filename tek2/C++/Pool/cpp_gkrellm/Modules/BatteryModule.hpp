/*
** BatteryModule.hpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Modules/BatteryModule.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sun Jan 22 06:13:07 2017 Vincent DUSAUTOIR
** Last update Sun Jan 22 06:13:07 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_GKRELLM_BATTERYMODULE_HPP
#define CPP_GKRELLM_BATTERYMODULE_HPP


#include <SFML/Graphics.hpp>
#include "Core/Core.hpp"
#include "IMonitorModule.hpp"

class						BatteryModule : public IMonitorModule {
  std::string					_id;
  bool						_enabled;
  Config::GraphicMode				_graphicMode;
  std::map<std::string, std::string>		_content;

public:
  BatteryModule();
  BatteryModule(const BatteryModule &other);
  virtual ~BatteryModule();

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
  BatteryModule					&operator=(const BatteryModule &other);
};


#endif //CPP_GKRELLM_BATTERYMODULE_HPP
