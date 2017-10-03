/*
** Parser.cpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/Parser.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 19 22:28:27 2017 Gauthier Cler
** Last update Mon Jun 19 22:28:27 2017 Gauthier Cler
*/

#include 		<iostream>
#include 		"Parser.hpp"

ai::Parser::Parser()
{

  _syntaxRegexes.insert({ResponseType::SERVER_WELCOME, boost::regex( R"(^WELCOME$)" )});
  _syntaxRegexes.insert({ResponseType::SPOTS_REMAINING, boost::regex( R"(^(\d{1,}|ko)$)" )});
  _syntaxRegexes.insert({ResponseType::MAP_DIMENSIONS, boost::regex( R"(^\d{1,} \d{1,}$)" )});
  _syntaxRegexes.insert({ResponseType::MESSAGE, boost::regex( R"(^message [0-8], [a-zA-Z0-9]{1,}:(StartIncantation|EndIncantation):[2-8]$)" )});
  _syntaxRegexes.insert({ResponseType::DEATH, boost::regex( R"(^dead$)" )});
  _syntaxRegexes.insert({ResponseType::FORWARD, boost::regex( R"(^ok$)" )});
  _syntaxRegexes.insert({ResponseType::TURN_RIGHT, boost::regex( R"(^ok$)" )});
  _syntaxRegexes.insert({ResponseType::TURN_LEFT, boost::regex( R"(^ok$)" )});
  _syntaxRegexes.insert({ResponseType::LOOK, boost::regex( R"(^\[ (,{0,} )?(((player|egg|food|linemate|deraumere|sibur|mendiane|phiras|thystame)( (player|egg|food|linemate|deraumere|sibur|mendiane|phiras|thystame)){0,}),{0,} ){0,}\]$)" )});
  _syntaxRegexes.insert({ResponseType::INVENTORY, boost::regex( R"(^\[ food \d{1,}, linemate \d{1,}, deraumere \d{1,}, sibur \d{1,}, mendiane \d{1,}, phiras \d{1,}, thystame \d{1,} \]$)" )});
  _syntaxRegexes.insert({ResponseType::BROADCAST, boost::regex( R"(^ok$)" )});
  _syntaxRegexes.insert({ResponseType::CONNECT, boost::regex( R"(^\d+$)" )});
  _syntaxRegexes.insert({ResponseType::FORK, boost::regex( R"(^ok$)" )});
  _syntaxRegexes.insert({ResponseType::EJECT, boost::regex( R"(^(ok|ko)$)" )});
  _syntaxRegexes.insert({ResponseType::TAKE_OBJECT, boost::regex( R"(^(ok|ko)$)" )});
  _syntaxRegexes.insert({ResponseType::SET_OBJECT, boost::regex( R"(^(ok|ko)$)" )});
  _syntaxRegexes.insert({ResponseType::START_INCANTATION, boost::regex( R"(^(Elevation underway|ko)$)" )});
  _syntaxRegexes.insert({ResponseType::END_INCANTATION, boost::regex( R"(^(Current level: \d{1,}|ko)$)" )});

  _serverCommands.insert({ResponseType::FORWARD, "Forward"});
  _serverCommands.insert({ResponseType::TURN_RIGHT, "Right"});
  _serverCommands.insert({ResponseType::TURN_LEFT, "Left"});
  _serverCommands.insert({ResponseType::LOOK, "Look"});
  _serverCommands.insert({ResponseType::INVENTORY, "Inventory"});
  _serverCommands.insert({ResponseType::BROADCAST, "Broadcast"});
  _serverCommands.insert({ResponseType::SPOTS_REMAINING, "Connect_nbr"});
  _serverCommands.insert({ResponseType::FORK, "Fork"});
  _serverCommands.insert({ResponseType::EJECT, "Eject"});
  _serverCommands.insert({ResponseType::TAKE_OBJECT, "Take"});
  _serverCommands.insert({ResponseType::SET_OBJECT, "Set"});
  _serverCommands.insert({ResponseType::START_INCANTATION, "Incantation"});

  _dic.push_back(std::make_pair("player", [](Cell &cell, unsigned int nb) -> void {cell.player += nb;}));
  _dic.push_back(std::make_pair("egg", [](Cell &cell, unsigned int nb) -> void {cell.eggs += nb;}));
  _dic.push_back(std::make_pair("food", [](Cell &cell, unsigned int nb) -> void {cell.content.food += nb;}));
  _dic.push_back(std::make_pair("linemate", [](Cell &cell, unsigned int nb) -> void {cell.content.linemate += nb;}));
  _dic.push_back(std::make_pair("deraumere", [](Cell &cell, unsigned int nb) -> void {cell.content.deraumere += nb;}));
  _dic.push_back(std::make_pair("sibur", [](Cell &cell, unsigned int nb) -> void {cell.content.sibur += nb;}));
  _dic.push_back(std::make_pair("mendiane", [](Cell &cell, unsigned int nb) -> void {cell.content.mendiane += nb;}));
  _dic.push_back(std::make_pair("phiras", [](Cell &cell, unsigned int nb) -> void {cell.content.phiras += nb;}));
  _dic.push_back(std::make_pair("thystame", [](Cell &cell, unsigned int nb) -> void {cell.content.thystame += nb;}));
}

ai::Parser::~Parser()
{}

void 			ai::Parser::epurStr(std::string &string) {
  while (isUseless(string[0]))
    string.erase(0, 1);
  while (isUseless(string.back()))
    string.erase(string.size() - 1, 1);
}

bool 			ai::Parser::isUseless(const char character) {
  for (auto &c : _uselessChar)
    if (c == character)
      return (true);
  return (false);
}

bool ai::Parser::splitInventoryInfo(std::string str, ai::Cell &cell) {
  size_t				spacePos;

  epurStr(str);
  spacePos = str.find_first_of(' ');
  try {
    return (strToCell(str.substr(0, spacePos), cell,
		      std::stoul(str.substr(spacePos + 1))));
  }
  catch (std::invalid_argument) {
    std::cerr << "Couldn't get the number of objects in an inventory" << std::endl;
    return (false);
  }
}

bool 			ai::Parser::addCell(std::vector<ai::Cell> &view, std::string &in, size_t comaPos) {
  view.push_back(Cell());
  if (!fillCell(in.substr(0, comaPos), view.back(), ' '))
  {
    in = in.substr(comaPos + 1);
    return (false);
  }
  in = in.substr(comaPos + 1);
  return (true);
}

bool 			ai::Parser::fillCell(std::string str, ai::Cell &cell, char delim) {
  size_t 		delimPos;

  epurStr(str);
  while ((delimPos = str.find(delim)) != std::string::npos) {
    strToCell(str.substr(0, delimPos), cell, 1);
    str = str.substr(delimPos + 1);
  }
  return (strToCell(str, cell, 1));
}

bool			ai::Parser::strToCell(std::string str, ai::Cell &cell, unsigned int nb) {
  epurStr(str);

  for (auto &d : _dic)
    if (d.first == str) {
      d.second(cell, nb);
      return (true);
    }
  return (false);
}

bool ai::Parser::responseSyntaxMatches(const std::string &response,
				       ai::ResponseType type) {

  return boost::regex_match(response, _syntaxRegexes.at(type));
}

std::unique_ptr<ai::Response<unsigned int>>
ai::Parser::processConnectResponse(const std::string &input) {
  std::unique_ptr<ai::Response<unsigned int>>	response = std::make_unique<ai::Response<unsigned int>>(input, ResponseType::CONNECT);
  std::string					in = response->getInput();

  try {
    response->setValue(std::stoul(in));
  }
  catch (std::invalid_argument)
  {
    std::cerr << "Error: Expected a valid number for CONNECT command." << std::endl;
    response->setStatus(false);
  }
  return response;
}

std::unique_ptr<ai::Response<std::vector<ai::Cell>>>
ai::Parser::processLookResponse(const std::string &input) {
  std::unique_ptr<ai::Response<std::vector<ai::Cell>>>	response = std::make_unique<ai::Response<std::vector<ai::Cell>>>(input, ResponseType::LOOK);
  std::string				in = response->getInput();
  std::vector<ai::Cell>					view;
  size_t 				comaPos;

  epurStr(in);
  if (in.front() != '[' || in.back() != ']') {
    response->setStatus(false);
    return response;
  }
  in.erase(0, 1);
  in.erase(in.size() - 1, 1);
  while ((comaPos = in.find_first_of(",")) != std::string::npos) {
    addCell(view, in, comaPos);
  }
  view.push_back(Cell());
  fillCell(in, view.back(), ' ');
  response->setValue(view);
  return response;
}

std::unique_ptr<ai::Response<ai::Inventory>>
ai::Parser::processInventoryResponse(const std::string &input) {
  std::unique_ptr<ai::Response<Inventory>>	response = std::make_unique<ai::Response<Inventory>>(input, ResponseType::INVENTORY);
  std::string						in = response->getInput();
  Cell							cell;
  size_t						comaPos;

  epurStr(in);
  if (in[0] != '[' || in.back() != ']') {
    response->setStatus(false);
    return response;
  }
  in.erase(0, 1);
  in.erase(in.size() - 1, 1);
  while ((comaPos = in.find_first_of(',')) != std::string::npos)
  {
    if (!splitInventoryInfo(in.substr(0, comaPos), cell))
    {
      response->setStatus(false);
      return response;
    }
    in = in.substr(comaPos + 1);
  }
  if (!splitInventoryInfo(in, cell))
  {
    response->setStatus(false);
    return response;
  }
  response->setValue(cell.content);
  return response;
}

std::unique_ptr<ai::Response<bool>>
ai::Parser::processBooleanResponse(const std::string &input,
				   ai::ResponseType type) {
  std::unique_ptr<ai::Response<bool>>	response = std::make_unique<ai::Response<bool>>(input, type);
  std::string				in = response->getInput();

  epurStr(in);
  if (in.compare("ok") == 0)
    response->setValue(true);
  else if (in.compare("ko") == 0)
    response->setValue(false);
  else
  {
    response->setValue(false);
    response->setStatus(false);
  }
  return response;
}

std::map<ai::ResponseType, std::string> &ai::Parser::getServerCommands(void) {
  return _serverCommands;
}

std::unique_ptr<ai::Response<bool>>
ai::Parser::processIncantationResponse(const std::string &input, ResponseType type) {
  std::unique_ptr<ai::Response<bool>>	response = std::make_unique<ai::Response<bool>>(input, type);
  std::string				in = response->getInput();

  epurStr(in);
  response->setValue(in.compare("ko") != 0);
  return response;
}

std::unique_ptr<ai::Response<ai::Broadcast>>
ai::Parser::processBroadcastResponse(const std::string &input) {
  std::unique_ptr<ai::Response<ai::Broadcast>>	response = std::make_unique<ai::Response<ai::Broadcast>>(input, ResponseType::MESSAGE);
  std::vector<std::string>	tokens;
  std::vector<std::string>	infoTokens;
  ai::Broadcast			broadcast;

  boost::algorithm::split(tokens, input, boost::algorithm::is_any_of(" "));
  if (tokens.size() != 3) {
    response->setStatus(false);
    return response;
  }
  broadcast.origin = std::stoul(tokens.at(1));
  boost::algorithm::split(infoTokens, tokens.at(2), boost::algorithm::is_any_of(":"));
  if (infoTokens.size() != 3) {
    response->setStatus(false);
    return response;
  }
  broadcast.teamName = infoTokens.at(0);
  if (infoTokens.at(1) != "StartIncantation" && infoTokens.at(1) != "EndIncantation") {
    response->setStatus(false);
    return response;
  }
  broadcast.type = (infoTokens.at(1) == "StartIncantation" ? Broadcast::START : Broadcast::END);
  broadcast.level = std::stoul(infoTokens.at(2));
  response->setValue(broadcast);
  response->setStatus(true);
  return response;
}