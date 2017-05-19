/*
** SystemModule.hpp for cpp_gkrellm in /home/gogo/rendu/tek2/cpp_gkrellm/Modules/SystemModule.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat Jan 21 11:43:43 2017 Gauthier CLER
** Last update Sat Jan 21 11:43:43 2017 Gauthier CLER
*/

#ifndef CPP_GKRELLM_SYSTEMMODULE_HPP
#define CPP_GKRELLM_SYSTEMMODULE_HPP

# include "IMonitorModule.hpp"
# include <SFML/Graphics.hpp>

class 						SystemModule  : virtual public IMonitorModule {
private:
  std::string					_id;
  bool						_enabled;
  Config::GraphicMode 				_graphicMode;
  std::map<std::string, std::string>		_content;
public:
  SystemModule();
  SystemModule(const SystemModule &other);
  SystemModule					&operator=(const SystemModule &other);
  virtual ~SystemModule();
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


#endif //CPP_GKRELLM_SYSTEMMODULE_HPP
