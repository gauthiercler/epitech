/*
** ClientCommand.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/Spider/Commands/commands/ClientCommand.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:44:09 2017 Gauthier Cler
** Last update Sun Oct 08 19:44:09 2017 Gauthier Cler
*/

#include "ClientCommand.hpp"
#include <iostream>

bool Spider::Commands::ClientCommand::run(const std::string &data, Spider::Network::Client::instance networkClient, DB::Manager &manager) {
  DB::Model client("client");

  client.load(data);
  networkClient->setMac(client.get("mac"));

  if (client.get("antivirus").empty())
    client.add("antivirus", "none");

  if (!manager["clients"]->exist(client))
  {
    manager["clients"]->insert(client);
    std::clog << "[INFO][SPIDER] New client registered (mac: " << networkClient->getMac() << ")." << std::endl;
  }
  return true;
}
