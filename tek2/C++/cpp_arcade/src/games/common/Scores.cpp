/*
** Score.cpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/common/Score.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Apr 04 21:47:49 2017 Gauthier Cler
** Last update Tue Apr 04 21:47:49 2017 Gauthier Cler
*/

#include <fstream>
#include <iostream>
#include "Scores.hpp"

arcade::Scores::Scores() : _regex(std::regex("^.+:.+$")){

}

arcade::Scores::~Scores() {

}

bool arcade::Scores::load(const std::string &fileName) {
  std::ifstream	file(fileName);
  std::string	line;

  if (!file.is_open())
    return false;
  while (std::getline(file, line))
  {
    if (std::regex_match(line, this->getRegex()))
      this->_scores.push_back({line.substr(0, line.find(':')), line.substr(line.find(':') + 1)});
    else {
      std::cerr << "Invalid formated arcade::Scores file." << std::endl;
      this->_scores.clear();
      file.close();
      return false;
    }
  }
  file.close();
  this->decrypt();
  return true;
}

bool arcade::Scores::save(const std::string &fileName) {
  std::ofstream	file(fileName);

  this->encrypt();
  if (!file.is_open())
  {
    this->decrypt();
    return false;
  }
  for (auto current : this->_scores)
    file << current.first << ":" << current.second << std::endl;
  file.close();
  this->decrypt();
  return true;
}

void arcade::Scores::encrypt() {
  static const std::string key = std::string("81e2605f28d66815a0b16e08f1a38814e377ab12f40bb0d9aa272bd743f71b4d8694e790f128436985ab0f3736f57246098968da2d79e4467dbaeebb917cf531");
  int iterator = 0;
  for (auto &current : this->_scores) {
    for (auto &letter : current.second) {
      letter ^= key[iterator];
      iterator += 1;
    }
  }
}

void arcade::Scores::decrypt() {
  this->encrypt();
}

void arcade::Scores::add(const std::string &playerName, uint64_t score) {
  std::stringstream scoreString;

  scoreString << score;
  this->_scores.push_back({playerName, scoreString.str()});
  std::sort(this->_scores.begin(), this->_scores.end(),
	    [](std::pair<std::string, std::string> first, std::pair<std::string, std::string> second)
	    {
	      return std::stoi(first.second) > std::stoi(second.second);
	    });
}

const std::regex &arcade::Scores::getRegex() const {
  return this->_regex;
}

const std::vector<std::pair<std::string, std::string>> &arcade::Scores::getAllScores() const {
  return this->_scores;
}
