/*
** Score.hpp for cpp_arcade in /home/gogo/rendu/tek2/cpp_arcade/src/games/common/Score.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Apr 04 21:45:51 2017 Gauthier Cler
** Last update Tue Apr 04 21:45:51 2017 Gauthier Cler
*/

#ifndef CPP_ARCADE_SCORES_HPP
#define CPP_ARCADE_SCORES_HPP

#include <string>
#include <vector>
#include <regex>

namespace arcade {

  class Scores {
  public:
    Scores();
    ~Scores();
    bool							load(const std::string &fileName);
    bool							save(const std::string &fileName);
    void							encrypt();
    const std::vector<std::pair<std::string, std::string>>	&getAllScores() const;
    void							decrypt();
    void							add(const std::string &playerName, uint64_t score);
    const std::regex						&getRegex() const;

  private:
    std::vector<std::pair<std::string, std::string>>	_scores;
    std::regex						_regex;
  };

}

#endif //CPP_ARCADE_SCORES_HPP
