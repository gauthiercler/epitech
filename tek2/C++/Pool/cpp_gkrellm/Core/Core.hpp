/*
** Core.hpp for cpp_gkrellm in /home/foret_a/Lab/cpp_gkrellm/Core/Core.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 21 08:56:06 2017 Antoine FORET
** Last update Sat Jan 21 08:56:06 2017 Antoine FORET
*/

#ifndef CPP_GKRELLM_CORE_HPP
#define CPP_GKRELLM_CORE_HPP

# include			"Modules/IMonitorModule.hpp"
# include			"Graphics/IMonitorDisplay.hpp"

class Core {

private:
  std::vector<IMonitorModule *>	_registeredModules;
  std::vector<IMonitorModule *>	_enabledModules; // Reference on some _registeredModules
  IMonitorDisplay		*_graphicsEngine;
  unsigned int			_cachedError;
  Config::GraphicMode		_mode;

public:
  Core(Config::GraphicMode mode = Config::GraphicMode::GRAPHICS);
  ~Core();

  bool				run();

  void				registerModule(const IMonitorModule &module);
  void				unregisterModule(const std::string &identifier);

protected:
  IMonitorModule		&getModule(const std::string &identifier);
  void				display();
  void				reloadModules();
  void				gatherDatas();

private:
  Core(const Core &core); // We don't want our core to be copied, it has to be unique in our session
  Core				&operator=(const Core &core);

  void				loadGraphicsEngine();
  void				registerBaseModules();

};

typedef void (*preloader)(Core &);

#endif //CPP_GKRELLM_CORE_HPP
