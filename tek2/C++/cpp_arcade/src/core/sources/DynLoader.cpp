/*
** DynLoader.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/core/sources/DynLoader.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Apr 04 16:13:34 2017 Gauthier Cler
** Last update Tue Apr 04 16:13:34 2017 Gauthier Cler
*/

#include <dlfcn.h>
#include <iostream>
#include "DynLoader.hpp"
#include "Error.hpp"

DynLoader::DynLoader(){
}

DynLoader::~DynLoader() {
  for (auto handler : this->_handlers)
    dlclose(handler.second);
}

void DynLoader::load(const std::string &path) {
  void *handler;

  auto already_load = this->_handlers.find(path);
  this->setLib(path);
  if (already_load == this->_handlers.end())
  {
    handler = dlopen(path.c_str(), RTLD_NOW);
    if (!handler)
      throw arcade::DynLoaderError("Can't open shared library " + path);
    this->_handlers.insert({this->getLib(), handler});
  }
}

void *DynLoader::getSymbol(const std::string &symbolName) {
  void *symbol = dlsym(this->getHandler(), symbolName.c_str());

  if (!symbol)
    throw arcade::DynLoaderError("Can't find symbol " + symbolName);

  return symbol;
}

void DynLoader::setLib(const std::string &lib) {
  this->_lib = lib;
}

const std::string &DynLoader::getLib() const {
  return this->_lib;
}

void *DynLoader::getHandler() {
  auto handler = this->_handlers.find(this->getLib());

  return handler->second;
}
