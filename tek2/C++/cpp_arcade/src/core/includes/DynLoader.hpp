/*
** DynLoader.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/core/includes/DynLoader.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Apr 04 16:13:18 2017 Gauthier Cler
** Last update Tue Apr 04 16:13:18 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_DYNLOADER_HPP
#define CPP_ARCADE_DYNLOADER_HPP

#include <string>
#include <map>

class DynLoader {
public:
  DynLoader();
  ~DynLoader();
  void	load(const std::string &path);
  void	unload();
  void	*getSymbol(const std::string &symbolName);
  void	setLib(const std::string &lib);
  const std::string &getLib() const;
  void	*getHandler();

private:
  std::map<std::string, void *>		_handlers;
  std::string				_lib;
};


#endif //CPP_ARCADE_DYNLOADER_HPP
