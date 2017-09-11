/*
** PlayerSelectMenu.hpp for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/include/menu/PlayerSelectMenu.hpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Jun 13 19:16:55 2017 Anas Buyumad
** Last update Fri Jun 16 17:20:18 2017 Sylvain Chaugny
*/

#ifndef CPP_INDIE_STUDIO_PLAYERSELECTMENU_HPP
#define CPP_INDIE_STUDIO_PLAYERSELECTMENU_HPP

#include <functional>
#include <game/Game.hpp>
#include "IMenu.hpp"
#include "Menu.hpp"
#include "MenuButton.hpp"

namespace indie
{
  class PlayerSelectMenu : public IMenu
  {

  public :

    enum playerType
    {
      NONE = 0,
      PLAYER_ONE,
      PLAYER_TWO,
      PLAYER_THREE,
      PLAYER_FOUR,
      AI
    };

    class PlayerConfig
    {
      irr::scene::IAnimatedMeshSceneNode					*_node;
      std::string								_skin;
      playerType 								_type;
      std::pair<std::unique_ptr<MenuButton>, std::unique_ptr<MenuButton>>	_arrowsButton;
      std::unique_ptr<MenuButton>						_typeButton;
      irr::core::vector2df							_centerPos;
      irr::core::vector3df							_rotationBase;
      irr::core::vector3df							_rotation;

    public:

      PlayerConfig(irr::scene::IAnimatedMeshSceneNode *node, const std::string &skinID, playerType type, const irr::core::vector3df &pos, const irr::core::vector2df &centerPos, const irr::core::vector3df &rotation);
      ~PlayerConfig();

      irr::core::vector2df	getCenterPos(void) const;
      playerType 		getType(void) const;
      void			changeType(playerType type, irr::video::ITexture *typeTexture);
      void			rotate(irr::f32 Yangle);
      void			setRotation(irr::core::vector3df angle);
      void			resetRotation(void);
      void			buildArrows();
      void			buildType(irr::video::ITexture *typeTexture);
      void			showArrows(bool state);
      const std::string		&getTexture(void) const;
    };


  public:



    PlayerSelectMenu(indie::Menu &menu);
    ~PlayerSelectMenu();

    virtual void		receiveEvent(const indie::EventManager &eventManager);
    virtual void		buildElements(void);
    virtual void		render(void);

    void			changeToMainMenu(void) const;
    void			changeToMapSelect(void);
    void			jumpPrev(void);
    void			jumpNext(void);
    void			changeType(irr::EKEY_CODE key);


    const std::vector<std::unique_ptr<PlayerConfig>>		&getPlayersConfig(void) const;

    irr::video::ITexture	*getTypeTexture(playerType type);
    void			setTypeState(playerType type, bool state);
    std::vector<std::pair<std::pair<playerType, std::string>, bool>>::iterator	getTypeIterator(playerType type);
    virtual const std::vector<indie::Game::PlayerInfo> &getPlayerConfig();
  private:

    indie::Menu				&_menu;
    irr::scene::ISceneManager		*_smgr;
    irr::scene::ICameraSceneNode 	*_camera;

    std::vector<std::pair<std::pair<irr::EKEY_CODE, indie::keyStates>, std::function<void (void)>>>	_events;

    std::vector<std::unique_ptr<PlayerConfig>>					_players;
    std::vector<std::unique_ptr<PlayerConfig>>::iterator			_currentPlayer;

    std::vector<std::pair<std::pair<playerType, std::string>, bool>>		_playerTypes;
    std::vector<indie::Game::PlayerInfo>		playersInfo;
  };
}

#endif //CPP_INDIE_STUDIO_PLAYERSELECTMENU_HPP
