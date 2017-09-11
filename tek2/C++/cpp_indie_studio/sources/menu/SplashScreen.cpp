/*
** SplashScreen.cpp for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/sources/menu/SplashScreen.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Jun 18 02:58:28 2017 Anas Buyumad
** Last update Sun Jun 18 02:58:28 2017 Anas Buyumad
*/

#include <unistd.h>
#include <menu/MenuButton.hpp>
#include <iostream>
#include	"menu/SplashScreen.hpp"

indie::SplashScreen::SplashScreen() : _smgr(Engine::get().getSceneManager()->createNewSceneManager()), _camera(_smgr->addCameraSceneNode()), _icon(nullptr), _team(nullptr) {
  _camera->setTarget({0, 100, 0});
  _camera->setPosition({0, 100, -350});

  _icon = _smgr->addMeshSceneNode(Engine::get().getRessourceManager().getStaticMesh("SplashIcon"));
  _icon->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  _icon->setPosition({0, 400, 0});
  _icon->setScale({75, 75, 75});
  _icon->setRotation({0.0f, 0.0f, 0.0f});

  _bomberman = _smgr->addAnimatedMeshSceneNode(Engine::get().getRessourceManager().getAnimatedMesh("bomberman_run"));
  _bomberman->setMaterialTexture(0, Engine::get().getRessourceManager().getTexture("bomberman_orange"));
  _bomberman->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  _bomberman->setRotation({0,  200, 0});
  _bomberman->setScale({75, 75, 75});
  _bomberman->setPosition({-350, -250, -85});
}

indie::SplashScreen::~SplashScreen() {

}

void indie::SplashScreen::render() {
  bool		rendering;

  rendering = true;
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();

  Engine::get().getSoundManager().enableSoundLoop("SplashSong");
  Engine::get().getSoundManager().playSound("SplashSong");

  while (rendering && Engine::get().isRunning())
  {
    Engine::get().getWindowManager().beginScene();
    Engine::get().getEventManager().startProcess();

    if (!renderIcon()) {
      if (!renderTeam()) {
	renderBomberman();
      }
    }

    if (Engine::get().getEventManager().isKeyPressed(irr::KEY_RETURN)) {
      rendering = false;
    }

    _smgr->drawAll();
    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->drawAll();
    Engine::get().getEventManager().endProcess();
    Engine::get().getWindowManager().endScene();
  }
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();
  _smgr->clear();
  Engine::get().getSoundManager().playSound("Bomberman");
}

bool indie::SplashScreen::renderIcon() {
  if (_icon->getPosition().Y > 100.0f || _icon->getRotation().Y > 0.0f) {
    auto rotationYaxis = _icon->getRotation().Y + 4.0f;

    if (rotationYaxis > 360.0f) {
      rotationYaxis = 0.0f;
    }
    _icon->setPosition({_icon->getPosition().X, _icon->getPosition().Y - 1, _icon->getPosition().Z});
    _icon->setRotation({_icon->getRotation().X, rotationYaxis, _icon->getRotation().Z});
    return true;
  }
  return false;
}

bool indie::SplashScreen::renderTeam() {
  irr::video::SColor	teamColor;

  if (_team == nullptr) {
    _team = Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("TeamName"), {MenuButton::XCenter - static_cast<int>(Engine::get().getRessourceManager().getTexture("TeamName")->getSize().Width) / 2, MenuButton::YLowerCenter - static_cast<int>(Engine::get().getRessourceManager().getTexture("TeamName")->getSize().Height) / 2});

    Engine::get().getSoundManager().playSound("ThisIsBad");

    teamColor = _team->getColor();
    teamColor.setAlpha(0);
    _team->setColor(teamColor);
  }


  if (_team->getColor().getAlpha() < 255) {
    teamColor = _team->getColor();
    teamColor.setAlpha(teamColor.getAlpha() + 1);
    if (teamColor.getAlpha() == 210) {
      Engine::get().getSoundManager().playSound("Go");
    }
    _team->setColor(teamColor);
    return true;
  }
  return false;
}

bool indie::SplashScreen::renderBomberman() {
  auto Position = _bomberman->getPosition();
  auto Scale = _bomberman->getScale();

  if (Position.X < 0) {
    Position.X += 0.5;
  }
  if (Position.Y < 75) {
    Position.Y += 0.5;
  }
  Position.Z += 1;

  Scale.X > 0 ? Scale.X -= 0.1 : 0;
  Scale.Y > 0 ? Scale.Y -= 0.1 : 0;
  Scale.Z > 0 ? Scale.Z -= 0.1 : 0;

  if (Position.Z >= 1500) {
    _bomberman->setScale({75, 75, 75});
    _bomberman->setPosition({-350, -250, -85});
  }
  else {
    _bomberman->setPosition(Position);
    _bomberman->setScale(Scale);
  }
  return false;
}
