/*
** main.cpp for cpp_spider in /home/gogo/rendu/cpp_spider/client/src/main.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Oct 08 22:14:41 2017 Gauthier Cler
** Last update Sun Oct 08 22:14:41 2017 Gauthier Cler
*/

#include <fstream>
#include <iostream>
#include "Engine.hpp"

int main(void)
{
  try {
    Client::Engine      engine;
    engine.run();
  }
  catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return (0);
}