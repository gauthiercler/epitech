/*
** IPlayer.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/IPlayer.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:18:29 2017 Anthony LECLERC
** Last update jeu. mai 04 15:18:29 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_IPLAYER_HPP
#define CPP_INDIE_STUDIO_IPLAYER_HPP

#include <game/Score.hpp>
#include "APlayer.hpp"
#include "IrrlichtWrapper.hpp"
#include "IBombSpawner.hpp"
#include "IMutableEntity.hpp"

namespace indie {
  /**
   * @brief Player class
   */
  enum EPlayerActions {
    EPA_MOVE_UP,
    EPA_MOVE_DOWN,
    EPA_MOVE_LEFT,
    EPA_MOVE_RIGHT,
    EPA_JUMP,
    EPA_PUT_BOMB,
  };

  class IPlayerController;

  class HumanPlayer : public APlayer {
  private:
    IPlayerController *_eventController;

  public:
    HumanPlayer(irr::scene::ISceneManager *scene,
	   std::string const& meshID,
           std::string const& textureID = "",
	   std::string const& name = "HumanPlayer",
	   bool visible = true);
    virtual ~HumanPlayer();

    void 		setEventController(IPlayerController *controller);
    IPlayerController	*getEventController() const;

    virtual void onDeath(Map &map) override;

    virtual void	update(Map &map);

    virtual void setVisible(bool state) override;

    virtual void remove();
  };
}
#endif //CPP_INDIE_STUDIO_IPLAYER_HPP
