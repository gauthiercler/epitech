/*
** Score.cpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/sources/game/Score.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 14:51:30 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 14:51:30 2017 Vincent DUSAUTOIR
*/

#include	"game/Score.hpp"

indie::Score::Score() : _globalScoreModif(0) {
  this->_scoreValues = {
    {EntityType::EMPTY, 0},
    {EntityType::BOX, 10},
    {EntityType::BRICK, 2000000},
    {EntityType::BOMB, 0},
    {EntityType::FIRE, 0},
    {EntityType::POWER_UP, 0},
    {EntityType::BOMB_UP, 0},
    {EntityType::SPEED_UP, 0},
    {EntityType::PLAYER, 100},
  };
}

indie::Score::~Score() {

}

void indie::Score::addScore(indie::EntityType type) {
  auto score = this->_scores.find(type);

  if (score != this->_scores.end())
    score->second += 1;
  else
    this->_scores.insert({type, 1});
}

void indie::Score::removeScore(indie::EntityType type) {
  auto score = this->_scores.find(type);

  if (score != this->_scores.end()) {
    if (score->second > 0) {
      score->second -= 1;
    }
  }
}

size_t indie::Score::getScoreFor(indie::EntityType type) {
  return this->_scoreValues[type] * this->getNumberOf(type);
}

size_t indie::Score::getAllScore() {
  size_t	allScore;

  allScore = 0;
  for (auto &score : this->_scores) {
      allScore += this->_scoreValues[score.first] * score.second;
  }
  allScore += _globalScoreModif;
  return allScore;
}

size_t indie::Score::getNumberOf(indie::EntityType type) {
  auto score = this->_scores.find(type);

  if (score == this->_scores.end())
    return 0;
  return score->second;
}

void indie::Score::updateGlobalScore(indie::EntityType type) {
  if (type == EntityType::BONUS) {
    _globalScoreModif += 5;
  }
  else if (type == EntityType::MALUS) {
    if (_globalScoreModif >= 5)
      _globalScoreModif -= 5;
  }
}
