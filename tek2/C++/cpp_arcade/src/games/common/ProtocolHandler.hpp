#ifndef CPP_ARCADE_PROTOCOLHANDLER_HPP
#define CPP_ARCADE_PROTOCOLHANDLER_HPP

#include <cstdint>
#include <Protocol.hpp>
#include <IEvent.hpp>
#include <vector>

namespace arcade
{

  class ProtocolHandler {

  public:

    ProtocolHandler();
    ~ProtocolHandler();

    void			setCommandType(arcade::CommandType commandType);
    arcade::CommandType 	getCommandType(void);
    void			setMap(const std::vector<std::vector<TileType>>	&map);
    void			setHead(std::pair<int, int> head);
    void			setTail(std::vector<std::pair<int, int>> tail);
    void			setLength(uint16_t length);
    bool			getCommand();
    arcade::IEvent		&getEvent();
    void			dumpMap(void);
    void			dumpPosition(void);
    void			dumpToLittle(uint16_t value);

  private:

    arcade::CommandType 			_commandType;
    std::vector<std::vector<TileType>>		_map;
    std::pair<int, int>				_head;
    std::vector<std::pair<int, int>>		_tail;
    uint16_t 					_length;
  };

  class ProtocolEvent : public IEvent {

  public:

    ProtocolEvent();
    virtual	~ProtocolEvent();

    virtual void		setType(eventType);
    virtual void		setValue(eventValue);
    virtual eventType		getType() const;
    virtual eventValue		getValue() const;
    virtual CommandType		get() const;

  private:

    arcade::eventType 		_type;
    arcade::eventValue 		_value;
  };

}



#endif //CPP_ARCADE_PROTOCOLHANDLER_HPP
