/*
** SFMLEngine.hpp for cpp_gkrellm in /home/foret_a/Lab/cpp_gkrellm/Graphics/SFMLEngine/SFMLEngine.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 21 12:01:54 2017 Antoine FORET
** Last update Sat Jan 21 12:01:54 2017 Antoine FORET
*/

#ifndef CPP_GKRELLM_SFMLENGINE_HPP
#define CPP_GKRELLM_SFMLENGINE_HPP

# include			<SFML/Graphics.hpp>
# include			"Graphics/IMonitorDisplay.hpp"

class SFMLEngine : public IMonitorDisplay
{

private:
  sf::RenderWindow		*_window;
  sf::RenderTexture		*_moduleBuffer;
  sf::Sprite			_moduleSprite;
  sf::Font			_font;
  sf::Text			_writter;
  sf::Texture			_settingTexture;
  sf::Sprite			_settingSprite;
  IMonitorModule		*_titleModules[3]; // Modules visible from title bar
  sf::FloatRect			_titlePos[3];
  unsigned int			_selectedIndex;
  bool				_inOption;
  bool				_haveToReload;
  sf::Texture			_settingsAsserts[2]; // Checked, cross
  sf::Sprite			_settingsSprites[2]; // Checked, cross

public:
  SFMLEngine(const std::vector<IMonitorModule *> &modules);
  virtual ~SFMLEngine();

  virtual bool			display(const std::vector<IMonitorModule *> &modules,
					      const std::vector<IMonitorModule *> &reguisteredModules);
  virtual bool			isOpen() const;

private:
  SFMLEngine(const SFMLEngine &sfmlEngine); // Not canonical
  SFMLEngine			&operator=(const SFMLEngine &sfmlEngine);

  void				eventManager(const std::vector<IMonitorModule *> &modules,
						   const std::vector<IMonitorModule *> &registeredModules);
  void				displayModules(const std::vector<IMonitorModule *> &modules);
  void				displayModuleTitle();
  void				configWrite(const std::string &label,
						  unsigned int x,
						  unsigned int y,
						  sf::Color color,
						  sf::Color hovered,
						  sf::Text::Style style,
						  float scale);
  void				manageClick(const std::vector<IMonitorModule *> &modules, const std::vector<IMonitorModule *> &registeredModules);
  IMonitorModule		*nextModule(IMonitorModule *base, const std::vector<IMonitorModule *> &modules);
  IMonitorModule		*prevModule(IMonitorModule *base, const std::vector<IMonitorModule *> &modules);

  void				displayOptions(const std::vector<IMonitorModule *> &modules);
  void				reloadBar(const std::vector<IMonitorModule *> &modules);
};


#endif //CPP_GKRELLM_SFMLENGINE_HPP
