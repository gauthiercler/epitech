/*
** pingCommand.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/pingCommand.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:49 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:49 2017 Gauthier Cler
*/

#include "pingCommand.hpp"

bool Spider::Commands::pingCommand::run(const std::string &, Spider::Network::Client::instance client, DB::Manager &) {
  const long timestamp = std::time(nullptr);
  std::string json;

  json += R"({"type": "PONG", "data": ")";
  json += std::to_string(timestamp);
  json += R"("})";
  client->send(json);
  return true;
}
