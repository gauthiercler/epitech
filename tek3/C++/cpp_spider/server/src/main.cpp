/*
** main.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/server/src/main.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 19:45:44 2017 Gauthier Cler
** Last update Sun Oct 08 19:45:44 2017 Gauthier Cler
*/

#include <boost/thread/future.hpp>
#include <iostream>
#include <Spider/Network/NetworkManager/NetworkManager.hpp>
#include <Spider/Spider/Spider.hpp>
#include <parser/Error.hpp>


int main() {
  try {
    Spider::Spider spider;

    spider.run();
  } catch (const Spider::ParserError &e) {
    std::cerr << "[ERROR][PARSER] " << e.what() << std::endl;
  }

  /*Spider::Network::Client::instance client = Spider::Network::Client::connect("127.0.0.1", 7075);

  client->send(R"({"type": "test", "data": "'}test"})");
  client->listen();*/
}