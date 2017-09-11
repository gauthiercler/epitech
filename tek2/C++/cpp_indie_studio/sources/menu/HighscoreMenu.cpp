/*
** HighscoreMenu.cpp for cpp_indie_studio in /home/rubysh/Work/Repositories/Epitech/SecondYear/CPE/cpp_indie_studio/sources/menu/HighscoreMenu.cpp
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Jun 16 01:00:44 2017 Anas Buyumad
** Last update Fri Jun 16 01:00:44 2017 Anas Buyumad
*/

#include	"Engine.hpp"
#include	"menu/HighscoreMenu.hpp"

indie::HighscoreMenu::HighscoreMenu(indie::Menu &menu) : _menu(menu) {
  this->_events.push_back({{irr::KEY_ESCAPE, PRESSED}, std::bind(&indie::HighscoreMenu::changeToMainMenu, this)});
}

indie::HighscoreMenu::~HighscoreMenu() {

}

void
indie::HighscoreMenu::receiveEvent(const indie::EventManager &eventManager) {
  for (auto event : this->_events) {
    switch (event.first.second)
    {
      case PRESSED:
	if (eventManager.isKeyPressed(event.first.first))
	  event.second();
	break;
      case DOWN:
	if (eventManager.isKeyDown(event.first.first))
	  event.second();
	break;
      case UP:
	if (eventManager.isKeyUp(event.first.first))
	  event.second();
	break;
      case RELEASED:
	if (eventManager.isKeyReleased(event.first.first))
	  event.second();
	break;
    }
  }
}

void indie::HighscoreMenu::buildElements(void) {
  irr::s32		iterator;

  iterator = 1;
  _highscores.load(".highscore");

  Engine::get().getWindowManager().setGUITransparency(255);
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->getSkin()->setFont(Engine::get().getRessourceManager().getFont("Score"));

  auto scores = _highscores.getScores();
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("MainMenuWallpaper"), {0,0});

  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("MainMenuHighscoresButton"), {MenuButton::Position::XCenter - 640 / 2 , 50});

  for (auto score : scores) {
    if (iterator < 6) {
      auto text = Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addStaticText(std::to_wstring(score).c_str(), {MenuButton::Position::XCenter - 50, (iterator + 1) * 100, MenuButton::Position::XCenter + 50, (iterator + 1) * 100 + 100});
      text->setOverrideColor({255, 0, 0, 0});
      iterator += 1;
    }
  }
}

void indie::HighscoreMenu::render(void) {
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->drawAll();
}

void indie::HighscoreMenu::changeToMainMenu(void) {
  Engine::get().getSoundManager().playSound("Reset");
  _menu.changeCurrentMenu(Menu::MAIN);
}

const std::vector<indie::Game::PlayerInfo> &
indie::HighscoreMenu::getPlayerConfig() {
  return playerConfig;
}
