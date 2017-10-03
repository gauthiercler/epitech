/*
** Chat.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/game/Chat.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri Jun 30 13:12:55 2017 Vincent DUSAUTOIR
** Last update Fri Jun 30 13:12:55 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_CHAT_HPP
#define PSU_2016_ZAPPY_CHAT_HPP

#include <list>
#include <string>

namespace zappy {
  enum class		MessageType{
    SERVER,
    DEFAULT
  };

  class			Message {
    std::string		_name;
    std::string		_message;
    MessageType		_type;

  public:
    Message(const std::string &name, const std::string &message, MessageType type = MessageType::DEFAULT);
    ~Message();

    void		render(size_t nbr);
  };

  class			Chat {
    bool			_active;
    std::list<Message>		_messages;

  public:
    Chat();
    ~Chat();

    void		update();
    void		render();
    void		addMessage(const Message &message);
    void		setActive(bool active);
    void		reset();
    bool		isActive() const;

  protected:
    void		renderMessages();
  };
}

#endif //PSU_2016_ZAPPY_CHAT_HPP
