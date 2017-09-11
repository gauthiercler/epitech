/*
** Highscore.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/game/Highscore.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Sun Jun 18 09:17:57 2017 Vincent DUSAUTOIR
** Last update Sun Jun 18 09:17:57 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_HIGHSCORE_HPP
#define CPP_INDIE_STUDIO_HIGHSCORE_HPP

#include <string>
#include <vector>
#include <regex>

namespace indie{
  class Highscore {
    std::vector<size_t>		_scores;
    std::regex			_numberRegex;

  public:
    Highscore();
    ~Highscore();

    void		load(const std::string &pathname);
    std::vector<size_t>	getScores() const;
    void		addScore(size_t score);
    void		save(const std::string &pathname);

  private:
    void		sortScore();
  };
}

#endif //CPP_INDIE_STUDIO_HIGHSCORE_HPP
