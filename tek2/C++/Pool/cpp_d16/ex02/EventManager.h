/*
** EventManager.hpp for cpp_d16 in /home/gogo/rendu/tek2/cpp_d16/ex02/EventManager.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 19 10:53:19 2017 Gauthier CLER
** Last update Thu Jan 19 10:53:20 2017 Gauthier CLER
*/

#ifndef CPP_D16_EVENTMANAGER_HPP
#define CPP_D16_EVENTMANAGER_HPP


#include <list>
#include "Event.h"

class EventManager {
public:
  EventManager();
  ~EventManager();
  EventManager(EventManager const &);
  EventManager& operator=(EventManager const &);
  void addEvent(const Event&);
  void removeEventsAt(unsigned int);
  void dumpEvents(void) const;
  void dumpEventAt(unsigned int) const;
  unsigned int	getTime() const;
  void addTime(unsigned int);
  void addEventList(std::list<Event>&);
private:
  std::list<Event>	_list;
  unsigned int		_time;
};


#endif //CPP_D16_EVENTMANAGER_HPP
