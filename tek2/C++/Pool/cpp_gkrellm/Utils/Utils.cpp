/*
** Utils.cpp for cpp_gkrellm in /home/ventinc/epitech/piscine/cpp_gkrellm/Utils/Utils.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sat Jan 21 19:07:57 2017 Vincent DUSAUTOIR
** Last update Sat Jan 21 19:07:57 2017 Vincent DUSAUTOIR
*/

#include "Utils.hpp"

std::string		Utils::trim(const std::string &sentence) {
  size_t		first = sentence.find_first_not_of(" \n\t\r");
  size_t		last = sentence.find_last_not_of(" \n\t\r");

  if (first == sentence.npos)
    return sentence;
  return sentence.substr(first, (last - first + 1));
}