/*
** OptionHandler.cpp for PSU_2016_zappy in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_zappy/ai/OptionHandler.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Jun 26 11:11:24 2017 Anas Buyumad
** Last update Mon Jun 26 11:11:25 2017 Anas Buyumad
*/

#include "OptionHandler.hpp"

OptionHandler::OptionHandler(int argumentCount, const char *argumentValues[]) :
  _descriptor("Allowed Options"),
  _conform(false),
  _programName(argumentValues[0]) {

  try {
    _descriptor.add_options()
      ("help,", "Displays the Help Message")
      ("name,n", boost::program_options::value<std::string>()->required(), "Defines the team name")
      ("port,p", boost::program_options::value<std::string>()->required(), "Defines the connection port")
      ("machine,h", boost::program_options::value<std::string>()->default_value("localhost"), "Defines the connection hostname");

    boost::program_options::store(
      boost::program_options::command_line_parser(argumentCount, argumentValues)
	.options(_descriptor)
	.style(boost::program_options::command_line_style::allow_long_disguise
	       ^ boost::program_options::command_line_style::long_allow_next
	       ^ boost::program_options::command_line_style::allow_short
	       ^ boost::program_options::command_line_style::allow_dash_for_short
	       ^ boost::program_options::command_line_style::short_allow_next).run(),
      _retriever);

    if (_retriever.count("help")) {
      this->displayHelpMessage();
      return ;
    }

    boost::program_options::notify(_retriever);

    if (_retriever.count("name")) {
      _team.assign(_retriever["name"].as<std::string>());
    }

    if (_retriever.count("port")) {
      _port.assign(_retriever["port"].as<std::string>());
    }

    if (_retriever.count("machine")) {
      _host.assign(_retriever["machine"].as<std::string>());
    }
  }
  catch (const std::exception &error) {
    std::cout << "Error : " << error.what() << std::endl;
    return ;
  }
  catch (...) {
    std::cout << "An Unknown Error Occurred" << std::endl;
    return ;
  }

  _conform = true;
}

OptionHandler::~OptionHandler() {

}

const std::string &OptionHandler::getTeamName(void) const {
  return _team;
}

const std::string &OptionHandler::getPort(void) const {
  return _port;
}

const std::string &OptionHandler::getHostName(void) const {
  return _host;
}

bool OptionHandler::isConform(void) const {
  return _conform;
}

void OptionHandler::displayHelpMessage(void) {
  std::stringstream	stream;
  std::string		message;

  stream << _descriptor;
  message.assign(stream.str());

  boost::algorithm::replace_all(message, "- [ --help ]", "-help");
  std::cout << message << std::endl;
}

void OptionHandler::dumpConfiguration(void) const {
  std::cout << "Team name was set to : " << _team << std::endl;
  std::cout << "Port name was set to : " << _port << std::endl;
  std::cout << "Machine name was set to : " << _host << std::endl;
}

void OptionHandler::setSpotsRemaining(unsigned long nb) {
  _spotsRemaining = nb;
}

void OptionHandler::setMapSize(std::pair<unsigned int, unsigned int> mapSize) {
  _mapSize = mapSize;
}

unsigned long OptionHandler::getSpotsRemaining() const {
  return _spotsRemaining;
}

const std::pair<unsigned int, unsigned int> &OptionHandler::getMapSize() const {
  return _mapSize;
}

const std::string &OptionHandler::getProgramName(void) const {
  return _programName;
}
