/*
** IA.hpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/include/game/IA.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jun 14 16:18:08 2017 Gauthier Cler
** Last update Wed Jun 14 16:18:08 2017 Gauthier Cler
*/

#ifndef CPP_INDIE_STUDIO_IA_HPP
# define CPP_INDIE_STUDIO_IA_HPP

#include <pybind11/embed.h>
#include <future>
#include "entity/APlayer.hpp"
#include <game/Position.hpp>
#include "Map.hpp"

namespace indie {

  enum class Action {
    NOTHING,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    BOMB
  };

  enum class IADiff {
    EASY,
    HARD
  };

  class IA : public APlayer {
  public:
    IA(irr::scene::ISceneManager *scene,
       std::string const& meshID,
       std::string const& textureID = "",
       std::string const& name = "IA",
       IADiff difficulty = IADiff::EASY,
       bool visible = true);
    virtual ~IA();
    virtual void update(indie::Map &map);
    virtual void setVisible(bool state);

    const Position &getLastTarget() const;
    void setLastTarget(const Position &pos);
    void convertMap(const Map &map);
    Action		computeScript(const Position &pos);
    void		assessAction(const Action &action);
    void		dropBombUpdate(Map &map);
    void		generateBombRange(const Map &map);
    void		assessBombPower(Position pos, Action dir, uint64_t iteration, uint64_t maxIterations);

  private:
    Position							_lastTarget;
    std::future<Action>						_async;
    bool							_started;
    std::map<int, std::map<int, indie::EntityType>>		_convertedMap;
    Action							_lastAction;
    IADiff							_difficulty;
  };
}
#endif /* !CPP_INDIE_STUDIO_IA_HPP*/
