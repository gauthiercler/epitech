/*
** Core.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/core/sources/Core.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Apr 04 16:06:27 2017 Gauthier Cler
** Last update Tue Apr 04 16:06:27 2017 Gauthier Cler
*/

#include <algorithm>
#include <Error.hpp>
#include <iostream>
#include "Core.hpp"
#include "Utils.hpp"

arcade::Core::Core() : _graphic(NULL), _game(NULL), _dynLoader(new DynLoader), _open(true){
  this->reloadGraphicLibs();
  this->_selected = this->_graphicLibs.begin();
}

arcade::Core::Core(const std::string &libPath) : _graphic(NULL), _game(NULL), _dynLoader(new DynLoader), _open(true){
  this->setGraphic(this->loadGraphic(libPath));
  this->reloadGraphicLibs();
  this->_selected = this->_graphicLibs.begin();
  if (this->getGraphic() != NULL)
  {
    this->getGraphic()->openWindow("Arcade", 840, 880);
    this->getGraphic()->resetStackEvents();
    this->_launcher.initGraphic(*this->getGraphic());
  }
}

arcade::Core::~Core() {
  if (this->_game)
    delete this->_game;
  this->unloadGraphic();
  if (this->getDynLoader())
    delete this->_dynLoader;
}

void		arcade::Core::changeGame(const std::string &path) {
  IGame		*newGame;

  try
  {
    newGame = this->loadGame(path);
    if (this->getGame())
      this->unloadGame();
    this->setGame(newGame);
    this->getGame()->init(*this->getGraphic());
  } catch (arcade::DynLoaderError &e) {
    std::cerr << e.what() << std::endl;
  }
}

DynLoader *arcade::Core::getDynLoader() const {
  return this->_dynLoader;
}

arcade::IGame *arcade::Core::getGame() {
  return this->_game;
}

void arcade::Core::setGame(arcade::IGame *game) {
  this->_game = game;
}

void arcade::Core::unloadGame() {
  if (this->getGame())
  {
    delete this->getGame();
    this->setGame(NULL);
  }
}

arcade::IGraphic *arcade::Core::loadGraphic(const std::string &path) {
  this->getDynLoader()->load(path);
  return (reinterpret_cast<IGraphic * (*)()>(this->getDynLoader()->getSymbol("createGraphic")))();
}

void arcade::Core::unloadGraphic() {
  if (this->getGraphic())
  {
    this->getGraphic()->closeWindow();
    delete this->getGraphic();
    this->setGraphic(NULL);
  }
}

arcade::IGraphic *arcade::Core::getGraphic() {
  return this->_graphic;
}

void arcade::Core::setGraphic(arcade::IGraphic *graphic) {
  this->_graphic = graphic;
}

void arcade::Core::run() {
  if (this->getGraphic() != NULL)
  {
    while (this->isOpen())
    {
      this->receiveEvent(this->getGraphic()->getEvent(false));
      if (this->getGame() != NULL)
	this->getGame()->Play();
      else
	this->_launcher.display();
      this->getGraphic()->display();
    }
  }
}

void arcade::Core::reloadGraphicLibs() {
  this->_graphicLibs = arcade::Utils::scanDirectory("lib");
}

void arcade::Core::changeGraphic(const arcade::eventValue eventValue) {
  IGraphic		*newGraphic = NULL;

  if (eventValue == EV_3)
  {
    this->_selected = std::next(this->_selected);
    if (this->_selected == this->_graphicLibs.end())
      this->_selected = this->_graphicLibs.begin();
  } else if (eventValue == EV_2) {
    if (this->_selected == this->_graphicLibs.begin())
      this->_selected = std::prev(this->_graphicLibs.end());
    else
      this->_selected = std::prev(this->_selected);
  }
  try {
    newGraphic = this->loadGraphic("lib/" + this->getCurrentGraphic());
    if (this->getGraphic())
      this->unloadGraphic();
    this->setGraphic(newGraphic);
    this->getGraphic()->openWindow("Arcade", 840, 880);
    this->_launcher.initGraphic(*this->getGraphic());
    if (this->getGame())
      this->getGame()->init(*this->getGraphic());
  } catch (arcade::DynLoaderError &e) {
    std::cerr << e.what() << std::endl;
  }
}

const std::string &arcade::Core::getCurrentGraphic() const {
  return (this->_selected == this->_graphicLibs.end() || this->_graphicLibs.size() == 0) ? *new std::string("") : *this->_selected;
}

void arcade::Core::receiveEvent(const arcade::IEvent &event) {
  bool use = false;

  if (event.getType() == ET_KEYBOARD_CLICK &&
      (event.getValue() == EV_2 || event.getValue() == EV_3))
    this->changeGraphic(event.getValue());
  else
  {
    if (event.getType() == ET_KEYBOARD_CLICK && event.getValue() == EV_9)
      this->unloadGame();
    if (this->getGame())
    {
      if (event.getType() == ET_KEYBOARD_CLICK && (event.getValue() == EV_4 || event.getValue() == EV_5)) {
	this->_launcher.receiveEvent(event);
	this->changeGame("games/" + this->_launcher.getSelectedGame());
      } else if (event.getType() == ET_KEYBOARD_CLICK && event.getValue() == EV_8)
	this->changeGame("games/" + this->_launcher.getSelectedGame());
      else
	this->getGame()->receiveEvent(event);
    }
    else
    {
      if (event.getType() == ET_KEYBOARD_CLICK && event.getValue() == EV_ENTER)
	this->changeGame("games/" + this->_launcher.getSelectedGame());
      else
	this->_launcher.receiveEvent(event);
    }
    if (!use)
    {
      if (event.getType() == arcade::ET_WINDOW_CLOSED || (event.getType() == ET_KEYBOARD_CLICK && event.getValue() == EV_ESCAPE))
	this->setOpen(false);
    }
  }
}

bool arcade::Core::isOpen() const {
  return this->_open;
}

void arcade::Core::setOpen(bool open) {
  this->_open = open;
}

arcade::IGame *arcade::Core::loadGame(const std::string &path) {
  this->getDynLoader()->load(path);
  return (reinterpret_cast<IGame * (*)()>(this->getDynLoader()->getSymbol("createGame")))();
}

arcade::Core::Launcher::Launcher() : _clock(100){
  this->reloadGameLibs();
  this->_selected = this->_gameLibs.begin();
}

arcade::Core::Launcher::~Launcher() {
  if (this->menu_background.find("lib_arcade_snake.so") != this->menu_background.end()) {
    delete this->menu_background["lib_arcade_snake.so"];
  }
  if (this->menu_background.find("lib_arcade_pacman.so") != this->menu_background.end()) {
    delete this->menu_background["lib_arcade_pacman.so"];
  }
}

void arcade::Core::Launcher::reloadGameLibs() {
  this->_gameLibs = arcade::Utils::scanDirectory("games");
}

void arcade::Core::Launcher::initGraphic(arcade::IGraphic &glib) {
  this->_glib = &glib;
  this->_frame = &this->_glib->addFrame(pos(0, 0), 840, 880, 0);
  this->menu_background.insert({"lib_arcade_snake.so", this->_glib->loadPicture("ressources/menu/lib_snake_menu.png")});
  this->menu_background.insert({"lib_arcade_pacman.so", this->_glib->loadPicture("ressources/menu/lib_pacman_menu.png")});
  this->menu_background["lib_arcade_snake.so"]->setColor(arcade::rgb(255, 46, 204, 113));
  this->menu_background["lib_arcade_pacman.so"]->setColor(arcade::rgb(255, 0, 0, 0));
  for (auto it : this->menu_background) {
    it.second->setInnerPos(arcade::pos(0, 0), 840, 880);
  }
}

const std::string &arcade::Core::Launcher::getSelectedGame() {
  return (this->_selected == this->_gameLibs.end() || this->_gameLibs.size() == 0) ? *new std::string("") : *this->_selected;
}

void arcade::Core::Launcher::receiveEvent(const arcade::IEvent &event) {
  if (this->_clock.tick())
  {
    if (event.getType() == ET_KEYBOARD_CLICK) {
      switch(event.getValue())
      {
	case EV_5:
	case EV_RIGHT:
	  if (this->_selected == this->_gameLibs.end())
	    this->_selected = this->_gameLibs.begin();
	  else
	    this->_selected = std::next(this->_selected);
	  break;
	case EV_4:
	case EV_LEFT:
	  if (this->_selected == this->_gameLibs.begin())
	    this->_selected = std::prev(this->_gameLibs.end());
	  else
	    this->_selected = std::prev(this->_selected);
	  break;
	default:
	  break;
      }
      if (this->_selected == this->_gameLibs.end())
	this->_selected = this->_gameLibs.begin();
    }
  }
}

void arcade::Core::Launcher::display() {
  if (this->_frame)
  {
    if (this->menu_background.find(this->getSelectedGame()) != this->menu_background.end()) {
      this->_frame->draw(this->menu_background[this->getSelectedGame()]->getColor());
      this->_frame->draw(arcade::pos(0, 0), *this->menu_background[this->getSelectedGame()]);
    }
    else {
      this->_frame->draw(rgb(255, 52, 73, 94));
    }
    this->_frame->draw(pos((800 / 2) - ((this->getSelectedGame().length() / 2) * 10), 750), this->getSelectedGame(), text(rgb(255, 236, 240, 241), 25));
  }
}
