/*
** ResponseHandler.hpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/classes/ResponseHandler.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 25 00:22:48 2017 Anas Buyumad
** Last update Sun Jun 25 00:22:48 2017 Anas Buyumad
*/

#ifndef PSU_2016_ZAPPY_RESPONSEHANDLER_HPP
#define PSU_2016_ZAPPY_RESPONSEHANDLER_HPP

#include <queue>
#include <thread>
#include <unordered_map>
#include <stack>
#include "AResponse.hpp"
#include "Parser.hpp"
#include "FSM/configuration.hpp"

namespace ai {

  class FSM;

  class ResponseHandler {

  public:

    ResponseHandler();
    ~ResponseHandler();

    const std::queue<ResponseType>				&getExpectedResponses(void) const;
    const std::queue<std::pair<std::string, ResponseType>>	&getReceivedResponses(void) const;
    const std::stack<std::string>				&getReceivedMessages(void) const;
    const Parser						&getParser(void) const;

    void			assessReceivedResponse(const std::string &response);
    void			pushReceivedMessage(const std::string &message);
    void			pushExpectedResponse(ResponseType type);

    const std::string				popReceivedMessage(void);
    std::pair<std::string, ResponseType>	popReceivedResponse(void);

    void					clearMessagesStack(void);

    void			waitForResponse(void);
    void			sendCommand(ResponseType type);


    std::unique_ptr<Response<bool>>			broadcastMessage(const std::string &teamName, BroadcastMessageType type, unsigned int level);
    std::unique_ptr<Response<bool>>			requestIncantation(ResponseType type);
    std::unique_ptr<Response<bool>>			requestObjectAction(ResponseType action, ItemType item);
    std::unique_ptr<Response<bool>>			requestAction(ResponseType type);
    std::unique_ptr<Response<unsigned int>>		requestConnectedPlayers(void);
    std::unique_ptr<Response<std::vector<ai::Cell>>>	requestVision(void);
    std::unique_ptr<Response<Inventory>>		requestInventory(void);

    std::unique_ptr<Response<Broadcast>>		getBroadcastMessage(void);

  private:

    Parser						_parser;

    std::queue<ResponseType>				_expectedResponses;
    std::queue<std::pair<std::string, ResponseType>>	_receivedResponses;
    std::stack<std::string>				_receivedMessages;

  };

}

#endif //PSU_2016_ZAPPY_RESPONSEHANDLER_HPP