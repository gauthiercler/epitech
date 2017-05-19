/*
** Core.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/core/includes/Core.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Apr 04 15:46:30 2017 Gauthier Cler
** Last update Tue Apr 04 15:46:30 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_CORE_HPP
#define CPP_ARCADE_CORE_HPP

#include <vector>
#include "IGame.hpp"
#include "DynLoader.hpp"
#include "Clock.hpp"

namespace arcade {
  class Core {

    class Launcher {

      Clock			_clock;
      std::vector<std::string>	_gameLibs;
      std::vector<std::string>::iterator _selected;
      IGraphic			*_glib;
      IFrame			*_frame;
      std::map<std::string, arcade::IPicture *>	menu_background;

    public:
      Launcher();
      ~Launcher();
      void		initGraphic(IGraphic &glib);
      void		receiveEvent(const IEvent &event);
      void		display();
      void		reloadGameLibs();
      const std::string	&getSelectedGame();
    };

  public:
    Core();
    Core(const std::string &libPath);
    ~Core();
    IGame	*loadGame(const std::string &path);
    void	changeGame(const std::string &path);
    void	unloadGame();
    IGraphic	*loadGraphic(const std::string &path);
    void	unloadGraphic();
    void	changeGraphic(const arcade::eventValue eventValue);
    void	run();
    void	reloadGraphicLibs();
    IGame	*getGame();
    void	setGame(IGame *game);
    IGraphic	*getGraphic();
    const std::string &getCurrentGraphic() const;
    void	setGraphic(IGraphic *graphic);
    DynLoader	*getDynLoader() const;
    void	receiveEvent(const IEvent &event);
    bool	isOpen() const;
    void	setOpen(bool open);

  private:
    IGraphic			*_graphic;
    IGame			*_game;
    DynLoader			*_dynLoader;
    bool			_open;
    Launcher			_launcher;
    std::vector<std::string>	_graphicLibs;
    std::vector<std::string>::iterator _selected;
    std::string			_currentGraphic;
  };
}

#endif //CPP_ARCADE_CORE_HPP
