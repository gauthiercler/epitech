/*
** EventManager.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/managers/EventManager.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 11:05:52 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 11:05:52 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_EVENTMANAGER_HPP
#define PSU_2016_ZAPPY_EVENTMANAGER_HPP

#include "utils/Position.hpp"
#include "WindowManager.hpp"

namespace zappy{

  class			EventManager{
    sf::Event		_event;

  public:
    EventManager();
    ~EventManager();

    bool		update();
    bool		isClosed();
    bool		isKeyPressed();
    bool		isKeyReleased();
    bool		isTextEntered();
    bool		isButtonPressed();
    bool		isButtonPressed(const Position &pos, const Size &size = Size(0, 0));
    bool		isButtonReleased();
    bool		isButtonReleased(const Position &pos, const Size &size = Size(0, 0));
    bool		isMouseMoving();
    bool		isMouseMoving(const Position &pos, const Size &size = Size(0, 0));
    bool		isMouseEvent();
    bool		isMouseEvent(sf::Event::EventType type);
    bool		isKeyboardEvent();
    bool		isKeyboardEvent(sf::Event::EventType type, sf::Keyboard::Key keyboard);
    Position		getMousePositionPressed();
    Position		getMousePosition();
    char		getTextEntered();
    sf::Event::KeyEvent	 &getKey();
    sf::Event::EventType getType();
  };

}

#endif //PSU_2016_ZAPPY_EVENTMANAGER_HPP
