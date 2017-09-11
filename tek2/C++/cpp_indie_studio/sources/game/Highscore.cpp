/*
** Highscore.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/game/Highscore.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sun Jun 18 09:19:47 2017 Vincent DUSAUTOIR
** Last update Sun Jun 18 09:19:48 2017 Vincent DUSAUTOIR
*/

#include <fstream>
#include <iostream>
#include "game/Highscore.hpp"

indie::Highscore::Highscore() : _numberRegex("^[ \\t]*[0-9]+[ \\t]*$") {

}

indie::Highscore::~Highscore() {

}

void indie::Highscore::load(const std::string &pathname) {
  std::string line;
  std::ifstream	file(pathname);

  if (file.is_open())
  {
    while (getline(file, line))
    {
      if (std::regex_match(line, this->_numberRegex))
      {
	this->_scores.push_back(static_cast<size_t>(std::stoi(line)));
      }
    }
    file.close();
    this->sortScore();
  }
}

std::vector<size_t> indie::Highscore::getScores() const {
  return this->_scores;
}

void indie::Highscore::sortScore() {
  std::sort(this->_scores.begin(), this->_scores.end(), [](size_t first, size_t second){
    return (first > second);
  });
}

void indie::Highscore::addScore(size_t score) {
  if (score > 0)
  {
    this->_scores.push_back(score);
    this->sortScore();
  }
}

void indie::Highscore::save(const std::string &pathname) {
  std::ofstream	file(pathname);

  if (file.is_open())
  {
    for (auto &score : this->_scores)
      file << score << std::endl;
    file.close();
  }
}

