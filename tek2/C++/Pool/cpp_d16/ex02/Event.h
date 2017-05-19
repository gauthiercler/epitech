/*
** Event.h for cpp_d16 in /home/gogo/rendu/tek2/cpp_d16/ex02/Event.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jan 19 10:53:33 2017 Gauthier CLER
** Last update Thu Jan 19 10:53:33 2017 Gauthier CLER
*/

#ifndef CPP_D16_EVENT_H
#define CPP_D16_EVENT_H


#include <string>

class Event {
public:
  Event(void);
  Event(unsigned int, const std::string&);
  ~Event(void);
  Event(const Event&other);
  Event& operator=(const Event&other);
  unsigned int getTime(void) const;
  const std::string& getEvent(void) const;
  void setTime(unsigned int time);
  void setEvent(const std::string &event);

private:
  unsigned int	_time;
  std::string	_event;
};


#endif //CPP_D16_EVENT_H
