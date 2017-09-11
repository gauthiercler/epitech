/*
** MeshManager.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MeshManager.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:04:18 2017 Anthony LECLERC
** Last update jeu. mai 04 15:04:18 2017 Anthony LECLERC
*/

#include <irrlicht/irrlicht.h>
#include <iostream>
#include "managers/RessourceManager.hpp"


indie::RessourceManager::RessourceManager(irr::scene::ISceneManager *smgr,
					  irr::IrrlichtDevice &device) :
  _smgr(smgr),
  _device(device)
{
  this->load();
}

indie::RessourceManager::~RessourceManager()
{}

void indie::RessourceManager::loadStaticMesh(std::string const &path, std::string const &name)
{
  irr::scene::IAnimatedMesh		*mesh;

  mesh = this->_smgr->getMesh(path.c_str());
  if (mesh == nullptr) {
    throw IrrlichtError("Couldn't load " + path + ".");
  }
  this->_staticMeshes.insert( {name, mesh->getMesh(0)} );
}

void indie::RessourceManager::loadAnimatedMesh(std::string const &path, std::string const &name)
{
  irr::scene::IAnimatedMesh	*mesh;

  mesh = this->_smgr->getMesh(path.c_str());
  if (mesh == nullptr) {
    throw IrrlichtError("Couldn't load " + path + ".");
  }
  this->_animatedMeshes.insert( {name, mesh} );
}

void indie::RessourceManager::loadTexture(std::string const &path,
					  std::string const &name)
{
  irr::video::ITexture		*texture;

  texture = this->_device.getVideoDriver()->getTexture(path.c_str());
  if (texture == nullptr) {
    throw IrrlichtError("Couldn't load " + path + ".");
  }
  this->_textures.insert( {name, texture} );
}

void indie::RessourceManager::loadFont(std::string const &path,
				       std::string const &name) {
  irr::gui::IGUIFont		*font;

  font = this->_device.getGUIEnvironment()->getFont(path.c_str());
  if (font == nullptr) {
    throw IrrlichtError("Couldn't load " + path + ".");
  }
  this->_fonts.insert( {name, font} );
}

void indie::RessourceManager::load(void) {

  this->loadTexture("assets/Terrain/grass.jpg", "Grass");
  this->loadAnimatedMesh("assets/FireBomb/Bomb.obj", "FireBomb");
  this->loadAnimatedMesh("assets/AquaBomb/AquaBomb.obj", "AquaBomb");
  this->loadTexture("assets/FireBomb/texture.png", "TFireBomb");
  this->loadTexture("assets/AquaBomb/texture.png", "TAquaBomb");
  this->loadFont("assets/font/font.xml", "iceland");

  this->loadAnimatedMesh("assets/models/bomberman_run.b3d", "bomberman_run");
  this->loadAnimatedMesh("assets/models/bomberman_stand.b3d", "bomberman_stand");
  this->loadAnimatedMesh("assets/models/bomberman_drop.b3d", "bomberman_drop");

  this->loadTexture("assets/textures/bomberman_red.png", "bomberman_red");
  this->loadTexture("assets/textures/bomberman_black.png", "bomberman_black");
  this->loadTexture("assets/textures/bomberman_blue.png", "bomberman_blue");
  this->loadTexture("assets/textures/bomberman_green.png", "bomberman_green");
  this->loadTexture("assets/textures/bomberman_lblue.png", "bomberman_lblue");
  this->loadTexture("assets/textures/bomberman_orange.png", "bomberman_orange");
  this->loadTexture("assets/textures/bomberman_pink.png", "bomberman_pink");
  this->loadTexture("assets/textures/bomberman_purple.png", "bomberman_purple");

  this->loadTexture("assets/textures/fireParticule.png", "fire");

  this->loadStaticMesh("assets/models/minecraftBox.obj", "cube");
  this->loadStaticMesh("assets/models/minecraftBrick.obj", "brick");

  this->loadTexture("assets/Splash/TeamName.png", "TeamName");

  this->loadStaticMesh("assets/Splash/AnasIcon.obj", "SplashIcon");
  this->loadTexture("assets/textures/minecraftBox.png", "cube");
  this->loadTexture("assets/textures/minecraftBrick.png", "brick");

  this->loadAnimatedMesh("assets/models/minecraftBox.obj", "cube");
  this->loadTexture("assets/textures/lava.png", "lava");

  this->loadAnimatedMesh("assets/models/firePowerUp.obj", "FirePowerUp");
  this->loadAnimatedMesh("assets/models/BombPowerUp.obj", "BombPowerUp");
  this->loadAnimatedMesh("assets/models/PierceBombPowerUp.obj", "AquaPowerUp");
  this->loadAnimatedMesh("assets/models/SkullPowerUp.obj", "SkullPowerUp");
  this->loadAnimatedMesh("assets/models/SkatePowerUp.obj", "SkatePowerUp");

  this->loadTexture("assets/HUD/Power.png", "PowerIcon");
  this->loadTexture("assets/HUD/Bombs.png", "BombsIcon");
  this->loadTexture("assets/HUD/Speed.png", "SpeedIcon");
  this->loadTexture("assets/HUD/Score.png", "ScoreIcon");
  this->loadTexture("assets/HUD/Clock.png", "ClockIcon");
  this->loadTexture("assets/HUD/Frame.png", "HUDFrame");
  this->loadTexture("assets/HUD/Player1.png", "HUDPlayer1");
  this->loadTexture("assets/HUD/Player2.png", "HUDPlayer2");
  this->loadTexture("assets/HUD/Player3.png", "HUDPlayer3");
  this->loadTexture("assets/HUD/Player4.png", "HUDPlayer4");
  this->loadTexture("assets/HUD/AI.png", "HUDAI");

  this->loadTexture("assets/HUD/BPlayer1.png", "HUDBPlayer1");
  this->loadTexture("assets/HUD/BPlayer2.png", "HUDBPlayer2");
  this->loadTexture("assets/HUD/BPlayer3.png", "HUDBPlayer3");
  this->loadTexture("assets/HUD/BPlayer4.png", "HUDBPlayer4");
  this->loadTexture("assets/HUD/BAI.png", "HUDBAI");
  this->loadTexture("assets/HUD/Wins.png", "HUDWins");
  this->loadTexture("assets/HUD/Draw.png", "HUDDraw");

  this->loadTexture("assets/Terrain/skydome.jpg", "skydome");

  this->loadTexture("assets/LoadingScreen.png", "LoadingScreen");

  this->loadMenuRessources();

}

void indie::RessourceManager::loadMenuRessources(void) {

  this->loadFont("assets/Font/Bomberman/Bomberman.xml", "Bomberman");
  this->loadFont("assets/Font/Score/Score.xml", "Score");

  this->loadTexture("assets/Menu/MainMenuWallpaper.png", "MainMenuWallpaper");
  this->loadTexture("assets/Menu/Main/ResumeButton.png", "MainMenuResumeButton");
  this->loadTexture("assets/Menu/Main/NewGameButton.png", "MainMenuNewGameButton");
  this->loadTexture("assets/Menu/Main/OptionsButton.png", "MainMenuOptionsButton");
  this->loadTexture("assets/Menu/Main/HighscoresButton.png", "MainMenuHighscoresButton");
  this->loadTexture("assets/Menu/Main/SelectedResumeButton.png", "SelectedMainMenuResumeButton");
  this->loadTexture("assets/Menu/Main/DisabledResumeButton.png", "DisabledMainMenuResumeButton");
  this->loadTexture("assets/Menu/Main/SelectedNewGameButton.png", "SelectedMainMenuNewGameButton");
  this->loadTexture("assets/Menu/Main/SelectedOptionsButton.png", "SelectedMainMenuOptionsButton");
  this->loadTexture("assets/Menu/Main/SelectedHighscoresButton.png", "SelectedMainMenuHighscoresButton");
  this->loadTexture("assets/Menu/Options/PlayersButton.png", "OptionsPlayersButton");
  this->loadTexture("assets/Menu/Options/SelectedPlayersButton.png", "SelectedOptionsPlayersButton");
  this->loadTexture("assets/Menu/Options/SoundButton.png", "OptionsSoundButton");
  this->loadTexture("assets/Menu/Options/SelectedSoundButton.png", "SelectedOptionsSoundButton");
  this->loadTexture("assets/Menu/Options/AIButton.png", "OptionsAIButton");
  this->loadTexture("assets/Menu/Options/SelectedAIButton.png", "SelectedOptionsAIButton");
  this->loadTexture("assets/Menu/Options/ONButton.png", "OptionsONButton");
  this->loadTexture("assets/Menu/Options/OFFButton.png", "OptionsOFFButton");
  this->loadTexture("assets/Menu/Options/EasyButton.png", "OptionsEasyButton");
  this->loadTexture("assets/Menu/Options/MediumButton.png", "OptionsMediumButton");
  this->loadTexture("assets/Menu/Options/HardButton.png", "OptionsHardButton");
  this->loadTexture("assets/Menu/Options/LeftArrowButton.png", "OptionsLeftArrowButton");
  this->loadTexture("assets/Menu/Options/RightArrowButton.png", "OptionsRightArrowButton");
  this->loadTexture("assets/Menu/PlayerSelect/NoneButton.png", "PlayerSelectNoneButton");
  this->loadTexture("assets/Menu/PlayerSelect/PlayerOneButton.png", "PlayerSelectPlayerOneButton");
  this->loadTexture("assets/Menu/PlayerSelect/PlayerTwoButton.png", "PlayerSelectPlayerTwoButton");
  this->loadTexture("assets/Menu/PlayerSelect/PlayerThreeButton.png", "PlayerSelectPlayerThreeButton");
  this->loadTexture("assets/Menu/PlayerSelect/PlayerFourButton.png", "PlayerSelectPlayerFourButton");
  this->loadTexture("assets/Menu/PlayerSelect/AIButton.png", "PlayerSelectAIButton");
  this->loadTexture("assets/Menu/MapSelect/RandomInfo.png", "MapSelectRandomInfo");
  this->loadTexture("assets/Menu/MapSelect/RandomDisplay.png", "MapSelectRandomDisplay");

  this->loadTexture("assets/Menu/Pause/SaveGameButton.png", "PauseSaveGameButton");
  this->loadTexture("assets/Menu/Pause/SelectedSaveGameButton.png", "SelectedPauseSaveGameButton");
  this->loadTexture("assets/Menu/Pause/ResumeButton.png", "PauseResumeButton");
  this->loadTexture("assets/Menu/Pause/SelectedResumeButton.png", "SelectedPauseResumeButton");
  this->loadTexture("assets/Menu/Pause/QuitButton.png", "PauseQuitButton");
  this->loadTexture("assets/Menu/Pause/SelectedQuitButton.png", "SelectedPauseQuitButton");
}

irr::scene::IMesh *indie::RessourceManager::getStaticMesh(std::string const &name)
{
  try
  {
    return this->_staticMeshes.at(name);
  }
  catch (...)
  {
    std::cerr << "Cannot load Staticmesh " << name << std::endl;
    throw IrrlichtError("Get Static Mesh " + name);
  }

}

irr::scene::IAnimatedMesh *
indie::RessourceManager::getAnimatedMesh(std::string const &name)
{
  try
  {
    return this->_animatedMeshes.at(name);
  }
  catch (...)
  {
    std::cerr << "cannot load Animated Mesh " << name << std::endl;
    throw IrrlichtError("Get Animated mesh " + name);
  }
}

irr::video::ITexture *indie::RessourceManager::getTexture(std::string const &name)
{
  try
  {
    return this->_textures.at(name);
  }
  catch (...)
  {
    std::cerr << "Cannot load Texture " << name <<  std::endl;
    throw IrrlichtError("Get Texture " + name);
  }
}

irr::gui::IGUIFont *indie::RessourceManager::getFont(std::string const &name) {
  return this->_fonts.at(name.c_str());
}

