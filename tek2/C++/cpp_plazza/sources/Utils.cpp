/*
** Utils.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/libs/common/Utils.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Mon Apr 03 16:33:09 2017 Vincent DUSAUTOIR
** Last update Mon Apr 03 16:33:10 2017 Vincent DUSAUTOIR
*/

#include <algorithm>
#include <sstream>
#include <iostream>
#include <functional>
#include "Utils.hpp"

std::string Utils::trim(const std::string &sentence) {
  size_t first = sentence.find_first_not_of(" \t\n\r");
  size_t last = sentence.find_last_not_of(" \t\n\r");

  if (first == sentence.npos)
    return sentence;
  return sentence.substr(first, (last - first + 1));
}

std::string Utils::removeSpaces(const std::string &sentence) {
  std::string result(sentence);
  result.erase(std::remove_if(result.begin(), result.end(), [](char x){return std::isspace(x);}), result.end());
  return result;
}

std::vector<std::string> Utils::explode(const std::string &sentence, const char delim)
{
  std::vector<std::string> result;
  std::string token;

  std::istringstream stream(sentence);
  while (std::getline(stream, token, delim))
    result.push_back(std::move(token));
  return (result);
}

std::string Utils::epur(const std::string &sentence) {
  bool space = false;
  std::stringstream epur("");
  std::string trim;
  trim = Utils::trim(sentence);
  for (auto ch : trim)
  {
    if (std::isspace(ch) && !space)
    {
      epur << " ";
      space = true;
    } else if (!std::isspace(ch)) {
      epur << ch;
      space = false;
    }
  }
  return epur.str();
}

std::string Utils::getLine() {
  std::string line;
  std::getline(std::cin, line);
  return line;
}
