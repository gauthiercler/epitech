/*
** CommandResponseCommand.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/CommandResponseCommand.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:17 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:17 2017 Gauthier Cler
*/

#include "CommandResponseCommand.hpp"

bool Spider::Commands::CommandResponseCommand::run(const std::string &data, Spider::Network::Client::instance client, DB::Manager &manager)
{
  DB::Model key("response");

  key.load(data);
  key.add("mac", client->getMac());
  manager["responses"]->insert(key);
  return true;
}
