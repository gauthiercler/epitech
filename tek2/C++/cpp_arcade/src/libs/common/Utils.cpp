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
#include <dirent.h>
#include <iostream>
#include "Utils.hpp"

std::string arcade::Utils::trim(const std::string &sentence) {
  size_t first = sentence.find_first_not_of(" \t\n\r");
  size_t last = sentence.find_last_not_of(" \t\n\r");

  if (first == sentence.npos)
    return sentence;
  return sentence.substr(first, (last - first + 1));
}

std::string arcade::Utils::removeSpaces(const std::string &sentence) {
  std::string result(sentence);
  result.erase(std::remove_if(result.begin(), result.end(), [](char x){return std::isspace(x);}), result.end());
  return result;
}

std::vector<std::string> arcade::Utils::explode(const std::string &sentence, char delim)
{
  std::vector<std::string> result;
  std::string token;

  std::istringstream stream(sentence);
  while (std::getline(stream, token, delim))
    result.push_back(std::move(token));
  return (result);
}

std::vector<std::string> arcade::Utils::scanDirectory(const std::string &path) {
  DIR *dir;
  struct dirent *ent;
  std::vector<std::string> files;

  if ((dir = opendir(path.c_str())) != NULL) {
    while ((ent = readdir (dir)) != NULL) {
      if (ent->d_type != DT_DIR)
	files.push_back(std::string(ent->d_name));
    }
    closedir (dir);
  }else {
    std::cout << "Can't Open dir " << path << std::endl;
  }
  return (files);
}