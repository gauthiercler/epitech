/*
** IMonitorDisplay.hpp for cpp_gkrellm in /home/foret_a/Lab/cpp_gkrellm/Graphics/IMonitorDisplay.hpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jan 20 22:54:12 2017 Antoine FORET
** Last update Fri Jan 20 22:54:12 2017 Antoine FORET
*/

#ifndef CPP_GKRELLM_IMONITORDISPLAY_HPP
#define CPP_GKRELLM_IMONITORDISPLAY_HPP

#include <vector>
#include "Modules/IMonitorModule.hpp"

class IMonitorDisplay
{
public:
  virtual ~IMonitorDisplay() {};
  virtual bool				display(const std::vector<IMonitorModule *> &modules,
						      const std::vector<IMonitorModule *> &registeredModules) = 0; // Render datas and return true if Core have to refresh it's datas
  virtual bool				isOpen() const = 0;
};

#endif //CPP_GKRELLM_IMONITORDISPLAY_HPP
