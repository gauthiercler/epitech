/*
** NCursesEngine.hpp for cpp_gkrellm in /home/rubysh/Work/Repositories/Epitech/SecondYear/Pool/cpp_gkrellm/Graphics/NCurses/NCursesEngine.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jan 21 11:36:01 2017 Anas Buyumad
** Last update Sat Jan 21 11:36:01 2017 Anas Buyumad
*/

#ifndef CPP_GKRELLM_NCURSESENGINE_HPP
#define CPP_GKRELLM_NCURSESENGINE_HPP

#include <Graphics/IMonitorDisplay.hpp>
#include <Graphics/NCurses/Classes/Screen.hpp>

class NCursesEngine : public IMonitorDisplay {

public:

  NCursesEngine(const std::vector<IMonitorModule *> &modules);
  virtual ~NCursesEngine();

  virtual bool				display(const std::vector<IMonitorModule *> &modules,
						      const std::vector<IMonitorModule *> &registeredModules); // Render datas and return true if Core have to refresh it's datas
  virtual bool				isOpen() const;

private:

  Screen		*EngineScreen;
  std::vector<IMonitorModule *> modulesCache;

};


#endif //CPP_GKRELLM_NCURSESENGINE_HPP
