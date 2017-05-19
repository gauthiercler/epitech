/*
** main_cypher.cpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/sources/main_cypher.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Apr 27 09:02:59 2017 Vincent DUSAUTOIR
** Last update Thu Apr 27 09:02:59 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "XorCypher.hpp"
#include "CaesarCypher.hpp"
#include "File.hpp"

void		xorf(std::string filename, std::string key) {
  plazza::File	file;
  std::string	buffer;
  plazza::XorCypher cypher;

  cypher.setKey(key);
  file.load(filename);
  if (file.isOpen()) {
    buffer = file.getBuffer();
    cypher >> buffer;
    std::cout << buffer;
  }
}

void		caesarf(std::string filename, std::string key) {
  plazza::File	file;
  plazza::CaesarCypher cypher;
  std::string buffer;
  int capacity;

  capacity = std::stoi(key);
  file.load(filename);
  if (file.isOpen()) {
    buffer = file.getBuffer();
    cypher.setMoved(capacity);
    cypher >> buffer;
    std::cout << buffer;
  }
}

int		main(int ac, char **av) {
  if (ac > 3) {
    if (std::string("xor") == av[1])
      xorf(av[2], av[3]);
    else if (std::string("caesar") == av[1])
      caesarf(av[2], av[3]);
  }
  return 0;
}