/*
** Score.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/game/Score.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 14:48:47 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 14:48:47 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_SCORE_HPP
# define CPP_INDIE_STUDIO_SCORE_HPP

# include <map>
# include "entity/IEntity.hpp"

namespace indie{
  class		Score {
    std::map<EntityType, size_t>	_scores;
    std::map<EntityType, size_t>	_scoreValues;
    size_t				_globalScoreModif;

  public:
    Score();
    ~Score();

    void	addScore(EntityType type);
    void	removeScore(EntityType type);
    void	updateGlobalScore(EntityType type);
    size_t	getScoreFor(EntityType type);
    size_t	getAllScore();
    size_t	getNumberOf(EntityType type);
  };
}

#endif //CPP_INDIE_STUDIO_SCORE_HPP
