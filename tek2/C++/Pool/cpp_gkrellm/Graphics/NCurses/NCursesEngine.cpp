/*
** NCursesEngine.cpp for cpp_gkrellm in /home/rubysh/Work/Repositories/Epitech/SecondYear/Pool/cpp_gkrellm/Graphics/NCurses/NCursesEngine.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Jan 21 12:06:22 2017 Anas Buyumad
** Last update Sat Jan 21 12:06:23 2017 Anas Buyumad
*/

#include <iostream>
#include <unistd.h>
#include "NCursesEngine.hpp"

NCursesEngine::NCursesEngine(const std::vector<IMonitorModule *> &modules) : EngineScreen(new Screen(modules)) {
  this->modulesCache = modules;
}

NCursesEngine::~NCursesEngine() {
  if (this->EngineScreen) {
    delete this->EngineScreen;
  }
}

bool NCursesEngine::display(const std::vector<IMonitorModule *> &modules, const std::vector<IMonitorModule *> &registeredModules) {
  char	buffer[100];
  size_t	read_count;

  read_count = read(0, buffer, sizeof(buffer));
  buffer[read_count] = '\0';
  if (read_count > 0) {
    this->EngineScreen->handleSequence(buffer, modules);
  }

  registeredModules.at(this->EngineScreen->getHModuleIndex())->display(this->EngineScreen->getModuleDataScreen());

  return false;
}

bool NCursesEngine::isOpen() const {
  return true;
}
