/*
** ProcessorModule.hpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Modules/ProcessorModule.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jan 21 18:18:51 2017 Vincent DUSAUTOIR
** Last update Sat Jan 21 18:18:51 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_GKRELLM_PROCESSORMODULE_HPP
#define CPP_GKRELLM_PROCESSORMODULE_HPP


#include <list>
#include <Core/Core.hpp>
#include "IMonitorModule.hpp"

class						ProcessorModule : public IMonitorModule {
  std::string					_id;
  bool						_enabled;
  Config::GraphicMode				_graphicMode;
  std::map<std::string, std::map<std::string, float>>		_content;
  unsigned int					_cacheInterval;
  std::map<std::string, float>			_prev_work;
  std::map<std::string, float>			_prev_total;
  std::map<std::string, std::list<float>>	_cache;
  std::map<std::string, float>			_percentages;
  std::map<std::string, unsigned int>		_count;
  std::string					_modelName;

public:
  ProcessorModule();
  ProcessorModule(const ProcessorModule &other);
  virtual ~ProcessorModule();

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
  void						computePercentages(std::map<std::string, float> container, const std::string &name);
  ProcessorModule				&operator=(const ProcessorModule &other);
};

#endif //CPP_GKRELLM_PROCESSORMODULE_HPP
