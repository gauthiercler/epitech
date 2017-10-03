/*
** Engine.cpp for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/ai/classes/Engine.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jun 23 11:37:48 2017 Gauthier Cler
** Last update Fri Jun 23 11:37:50 2017 Gauthier Cler
*/

#include <boost/algorithm/string.hpp>
#include "Engine.hpp"

ai::Engine::Engine(int argumentCount, const char *argumentValues[]) :
  _configuration(argumentCount, argumentValues) {
}

ai::Engine::~Engine() {

}

ai::machine &ai::Engine::getFSM()  {
  return _machine;
}

const OptionHandler &ai::Engine::getOptionHandler(void) {
  return _configuration;
}

void ai::Engine::connect() {

  ai::IOStreamHandler::get().connect(_configuration.getHostName(), _configuration.getPort());
  IOStreamHandler::get().startIOReadProcesser();

  this->assessServerResponse(ResponseType::SERVER_WELCOME);

  IOStreamHandler::get().getResponseHandler().pushExpectedResponse(ResponseType::SPOTS_REMAINING);
  IOStreamHandler::get().getResponseHandler().pushExpectedResponse(ResponseType::MAP_DIMENSIONS);
  IOStreamHandler::get().writeData(_configuration.getTeamName());

  this->assessServerResponse(ResponseType::SPOTS_REMAINING);
  this->assessServerResponse(ResponseType::MAP_DIMENSIONS);
}

void ai::Engine::assessServerResponse(ResponseType type) {
  std::pair<std::string, ResponseType>	response;

  IOStreamHandler::get().getResponseHandler().waitForResponse();
  response = IOStreamHandler::get().getResponseHandler().popReceivedResponse();

  if (response.second != type) {
    IOStreamHandler::get().abortConnection("Invalid server welcome sequence");
  }

  switch (type) {
    case ResponseType::SPOTS_REMAINING:
    {
      if (!boost::regex_match(response.first, boost::regex( R"(^\d{1,}$)")))
	throw Error("Invalid number of spots remaining");
      _configuration.setSpotsRemaining(std::stoul(response.first));
      break;
    }
    case ResponseType::MAP_DIMENSIONS:
    {
      if (!boost::regex_match(response.first, boost::regex( R"(^\d{1,} \d{1,}$)")))
	throw Error("Invalid map size");
      std::vector<std::string> tokens;
      boost::algorithm::split(tokens, response.first, boost::is_any_of(" "));
      _configuration.setMapSize({std::stoul(tokens.front()), std::stoul(tokens.back())});
      break;
    }
    default:
      break;
  }
}

void ai::Engine::run() {

  _machine.teamName = _configuration.getTeamName();
  _machine.mapSize = _configuration.getMapSize();
  _machine.remainingSpots = _configuration.getSpotsRemaining();
  _machine.programName = _configuration.getProgramName();
  _machine.port = _configuration.getPort();
  _machine.host = _configuration.getHostName();

  _machine.start();

  while (ai::running) {

    if (_machine.level == 8)
      break ;
    _machine.process_event(EventStartComputation());
    IOStreamHandler::get().pollIOService();
  }

  _machine.stop();
}