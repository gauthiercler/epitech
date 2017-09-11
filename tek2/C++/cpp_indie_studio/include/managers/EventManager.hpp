/*
** EventManager.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/EventManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:08:04 2017 Anthony LECLERC
** Last update jeu. mai 04 15:08:04 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_EVENTMANAGER_HPP
#define CPP_INDIE_STUDIO_EVENTMANAGER_HPP

#include <irrlicht/IEventReceiver.h>
#include <memory>
#include <set>
#include <irrlicht/ISceneManager.h>

namespace indie {

  enum keyStates {UP, DOWN, PRESSED, RELEASED};
  enum processState {STARTED, ENDED};


  class IEventController;
  /**
   * @brief Event Manager
   */
  class EventManager : public irr::IEventReceiver {
    keyStates _keyState[irr::KEY_KEY_CODES_COUNT];
    processState _processState;
    std::set<IEventController *> _controllers;
    irr::scene::ISceneManager *_smgr;
    irr::gui::IGUIElement *_lastGUI;
  public:

    /**
     * @brief Class constructor
     */
    EventManager();

    /**
     * @brief Register a controller in the event manager
     * @param controller Interface to manage events for specific implementations
     * @return controller
     */
    IEventController *registerController(IEventController *controller)
    {
      _controllers.insert(controller);
      return controller;
    }

/**
     * @brief Remove the controller from the event set
     * @param c
     */
    void remove(IEventController *c)
    {
      _controllers.erase(c);
    }

    /**
     * @brief Callback on event
     * @param event
     * @return bool
     */
    virtual bool OnEvent(irr::SEvent const&event);

    /** @name Key status
     * Get status of given key or Keycode
     */
    ///@{
    /** Check if key is in down state. */
    virtual bool isKeyDown(irr::EKEY_CODE keyCode) const;
    /** Check if key is beeing pressed (Up -> Down). */
    virtual bool isKeyPressed(irr::EKEY_CODE keyCode) const;
    /** Check if key is in up state */
    virtual bool isKeyUp(irr::EKEY_CODE keyCode) const;
    /** Check if key is beeing released (Down -> Up). */
    virtual bool isKeyReleased(irr::EKEY_CODE keyCode) const;
    //@}
    irr::gui::IGUIElement const* lastGUIEvent() const;

    void endProcess();
    void startProcess();

    /**
     * @brief Execute all actives controllers in the manager.
     */
    void execute();

    /**
     * @brief Class Destructor
     */
    ~EventManager();

    void setNewSceneManager(irr::scene::ISceneManager *);
  };

}


#endif //CPP_INDIE_STUDIO_EVENTMANAGER_HPP
