/*
** IrrlichtWrapper.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/IrrlichtWrapper.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 14:42:22 2017 Anthony LECLERC
** Last update jeu. mai 04 14:42:22 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_IRRLICHTWRAPPER_HPP
#define CPP_INDIE_STUDIO_IRRLICHTWRAPPER_HPP

#define SCREEN_WIDTH	1600
#define SCREEN_HEIGHT	900

/**
 * @brief Irrlicht class wrapper.
 */
#include <managers/RessourceManager.hpp>
#include <managers/WindowManager.hpp>
#include <managers/SoundManager.hpp>
#include <managers/ScriptManager.hpp>
#include <managers/EventManager.hpp>

namespace indie {
  class RessourceManager;
  class WindowManager;
  class SoundManager;
  class ScriptManager;
  class EventManager;

  class IrrlichtWrapper {
  private:
    WindowManager	_windowManager;
    std::unique_ptr<irr::scene::ISceneManager> _sceneManager;
    RessourceManager	_ressourceManager;
    SoundManager	_soundManager;
    ScriptManager	_scriptManager;
    EventManager	_eventManager;


  public:
    IrrlichtWrapper();

    ~IrrlichtWrapper();

    bool		isRunning();

    irr::scene::ISceneManager *getSceneManager();
    RessourceManager 	&getRessourceManager();
    WindowManager	&getWindowManager();
    SoundManager	&getSoundManager();
    ScriptManager	&getScriptManager();
    EventManager	&getEventManager();
  };
}

#endif //CPP_INDIE_STUDIO_IRRLICHTWRAPPER_HPP
