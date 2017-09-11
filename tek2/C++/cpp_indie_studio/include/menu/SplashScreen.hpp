#ifndef CPP_INDIE_STUDIO_SPLASHSCREEN_HPP
#define CPP_INDIE_STUDIO_SPLASHSCREEN_HPP

#include	"Engine.hpp"

namespace indie
{
  class SplashScreen
  {

  public:

    SplashScreen();
    ~SplashScreen();

    void	render();
    bool	renderIcon();
    bool	renderTeam();
    bool	renderBomberman();

  private:

    irr::scene::ISceneManager		*_smgr;
    irr::scene::ICameraSceneNode 	*_camera;
    irr::scene::IMeshSceneNode		*_icon;
    irr::scene::IAnimatedMeshSceneNode	*_bomberman;
    irr::gui::IGUIImage			*_team;
  };
}

#endif //CPP_INDIE_STUDIO_SPLASHSCREEN_HPP