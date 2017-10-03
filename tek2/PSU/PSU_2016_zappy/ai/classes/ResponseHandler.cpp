/*
** ResponseHandler.cpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/classes/ResponseHandler.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 25 00:30:52 2017 Anas Buyumad
** Last update Sun Jun 25 00:30:52 2017 Anas Buyumad
*/

#include <FSM/FSM.hpp>
#include "IOStreamHandler.hpp"
#include "ResponseHandler.hpp"
#include "SelectType.hpp"

ai::ResponseHandler::ResponseHandler() {
  this->pushExpectedResponse(ResponseType::SERVER_WELCOME);
}

ai::ResponseHandler::~ResponseHandler() {

}

const std::queue<ai::ResponseType> &ai::ResponseHandler::getExpectedResponses(void) const {
  return _expectedResponses;
}

const std::queue<std::pair<std::string, ai::ResponseType>> &
ai::ResponseHandler::getReceivedResponses(void) const {
  return _receivedResponses;
}

const std::stack<std::string> &ai::ResponseHandler::getReceivedMessages(void) const {
  return _receivedMessages;
}

const ai::Parser &ai::ResponseHandler::getParser(void) const {
  return _parser;
}

void ai::ResponseHandler::assessReceivedResponse(const std::string &response) {
  ResponseType		expectedType;

  std::cout << std::endl << "Assessing Response -> " << response << std::endl;


  if (_parser.responseSyntaxMatches(response, ResponseType::DEATH)) {
    std::cerr << "->   Machine Died   <-" << std::endl;
    IOStreamHandler::get().disconnect();
    ai::running = false;
    return ;
  }
  if (_expectedResponses.size()) {
    expectedType = _expectedResponses.front();
    std::cout << "->   Expected type :: " << static_cast<int>(expectedType) << "   <-" << std::endl;
    if (_parser.responseSyntaxMatches(response, expectedType)) {
      std::cout << "->   Regex Match   <-" << std::endl;
      std::cout << "->   Adding received response   <-" << std::endl;
      this->_receivedResponses.push({response, expectedType});
      _expectedResponses.pop();
    }
    else {
      std::cout << "->   Regex Mismatch   <-" << std::endl;
      this->pushReceivedMessage(response);
    }
  }
  else {
    this->pushReceivedMessage(response);
  }
}

void ai::ResponseHandler::pushReceivedMessage(const std::string &message) {

  if (_parser.responseSyntaxMatches(message, ResponseType::MESSAGE)) {
    std::cout << "->   Pushing Received Message From Broadcast   <-" << std::endl;
    _receivedMessages.push(message);
  }
  else {
    std::cout << "->   Invalid Broadcast Message   <-" << std::endl;
  }
}

void ai::ResponseHandler::pushExpectedResponse(ai::ResponseType type) {
  std::cout << "->   Pushing Expected Response :: " << static_cast<int>(type) << "   <-" << std::endl;
  _expectedResponses.push(type);
}

const std::string ai::ResponseHandler::popReceivedMessage(void) {
  std::string		receivedMessage;

  if (_receivedMessages.size()) {
    receivedMessage.assign(_receivedMessages.top().c_str());
    _receivedMessages.pop();
  }
  return receivedMessage;
}

std::pair<std::string, ai::ResponseType>
ai::ResponseHandler::popReceivedResponse(void) {
  std::pair<std::string, ResponseType>	receivedResponse = {std::string(""), ResponseType::NONE};

  if (_receivedResponses.size()) {
    receivedResponse.first.assign(_receivedResponses.front().first);
    receivedResponse.second = _receivedResponses.front().second;
    _receivedResponses.pop();
  }
  return receivedResponse;
}

void ai::ResponseHandler::waitForResponse(void) {
  while (!_receivedResponses.size()) {
//    std::cout << "Waiting for Response, Size :: " << _receivedResponses.size() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    IOStreamHandler::get().pollIOService();
  }
}

void ai::ResponseHandler::sendCommand(ai::ResponseType type) {
  IOStreamHandler::get().getResponseHandler().pushExpectedResponse(type);
  IOStreamHandler::get().writeData(_parser.getServerCommands().at(type));
}

std::unique_ptr<ai::Response<bool>>
ai::ResponseHandler::requestAction(ai::ResponseType type) {
  std::pair<std::string, ResponseType>	response;

  this->sendCommand(type);

  IOStreamHandler::get().getResponseHandler().waitForResponse();
  response = IOStreamHandler::get().getResponseHandler().popReceivedResponse();

  if (response.second != type) {
    IOStreamHandler::get().abortConnection("Invalid response type for requestAction");
  }
  return _parser.processBooleanResponse(response.first, response.second);
}

std::unique_ptr<ai::Response<unsigned int>>
ai::ResponseHandler::requestConnectedPlayers(void) {
  std::pair<std::string, ResponseType>	response;

  this->sendCommand(ResponseType::CONNECT);

  IOStreamHandler::get().getResponseHandler().waitForResponse();
  response = IOStreamHandler::get().getResponseHandler().popReceivedResponse();

  if (response.second != ResponseType::CONNECT) {
    IOStreamHandler::get().abortConnection("Invalid response type for requestConnect");
  }
  return _parser.processConnectResponse(response.first);
}

std::unique_ptr<ai::Response<std::vector<ai::Cell>>> ai::ResponseHandler::requestVision(void) {
  std::pair<std::string, ResponseType>	response;

  this->sendCommand(ResponseType::LOOK);

  IOStreamHandler::get().getResponseHandler().waitForResponse();
  response = IOStreamHandler::get().getResponseHandler().popReceivedResponse();

  if (response.second != ResponseType::LOOK) {
    IOStreamHandler::get().abortConnection("Invalid response type for requestLook");
  }
  return _parser.processLookResponse(response.first);
}

std::unique_ptr<ai::Response<ai::Inventory>>
ai::ResponseHandler::requestInventory(void) {
  std::pair<std::string, ResponseType>	response;

  this->sendCommand(ResponseType::INVENTORY);

  IOStreamHandler::get().getResponseHandler().waitForResponse();
  response = IOStreamHandler::get().getResponseHandler().popReceivedResponse();

  if (response.second != ResponseType::INVENTORY) {
    IOStreamHandler::get().abortConnection("Invalid response type for requestInventory");
  }
  return _parser.processInventoryResponse(response.first);
}

std::unique_ptr<ai::Response<bool>>
ai::ResponseHandler::requestObjectAction(ai::ResponseType action,
				      ai::ItemType item) {
  std::pair<std::string, ResponseType>	response;

  if (action != ResponseType::SET_OBJECT && action != ResponseType::TAKE_OBJECT) {
    IOStreamHandler::get().abortConnection("RequestObjectAction :: Invalid action");
  }

  IOStreamHandler::get().getResponseHandler().pushExpectedResponse(action);
  IOStreamHandler::get().writeData(_parser.getServerCommands().at(action) + " " + ai::itemList.at(item));

  IOStreamHandler::get().getResponseHandler().waitForResponse();
  response = IOStreamHandler::get().getResponseHandler().popReceivedResponse();

  if (response.second != action) {
    IOStreamHandler::get().abortConnection("Invalid response type for manipulateObject");
  }
  return _parser.processBooleanResponse(response.first, response.second);
}

std::unique_ptr<ai::Response<bool>>
ai::ResponseHandler::requestIncantation(ResponseType state) {
  std::pair<std::string, ResponseType>		response;

  if (state == ResponseType::START_INCANTATION) {
    IOStreamHandler::get().getResponseHandler().pushExpectedResponse(ResponseType::START_INCANTATION);
    IOStreamHandler::get().getResponseHandler().pushExpectedResponse(ResponseType::END_INCANTATION);
    IOStreamHandler::get().writeData(_parser.getServerCommands().at(state));
  }
  IOStreamHandler::get().getResponseHandler().waitForResponse();
  response = IOStreamHandler::get().getResponseHandler().popReceivedResponse();
  if (response.second != state) {
    IOStreamHandler::get().abortConnection("Invalid response type for manipulateObject");
  }
    return _parser.processIncantationResponse(response.first, state);
}

std::unique_ptr<ai::Response<bool>>
ai::ResponseHandler::broadcastMessage(const std::string &teamName,
				      ai::BroadcastMessageType type,
				      unsigned int level) {
  std::pair<std::string, ResponseType>	response;

  IOStreamHandler::get().getResponseHandler().pushExpectedResponse(ResponseType::BROADCAST);
  IOStreamHandler::get().writeData(_parser.getServerCommands().at(ResponseType::BROADCAST) + " " + teamName + ":"
				   + messagesList.at(type) + ":" + std::to_string(level + 1));

  IOStreamHandler::get().getResponseHandler().waitForResponse();
  response = IOStreamHandler::get().getResponseHandler().popReceivedResponse();

  if (response.second != ResponseType::BROADCAST) {
    IOStreamHandler::get().abortConnection("Invalid response type for requestConnect");
  }
  return _parser.processBooleanResponse(response.first, response.second);
}

std::unique_ptr<ai::Response<ai::Broadcast>>
ai::ResponseHandler::getBroadcastMessage(void) {
  std::string		response;

  if (_receivedMessages.size()) {
    response.assign(this->popReceivedMessage());
  }

  if (!response.size()) {
    IOStreamHandler::get().abortConnection("No Broadcasted message in queue");
  }

  return _parser.processBroadcastResponse(response);
}

void ai::ResponseHandler::clearMessagesStack(void) {
  _receivedMessages  = std::stack<std::string>();
}
