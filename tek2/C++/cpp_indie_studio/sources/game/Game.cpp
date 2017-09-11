/*
** Game.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Game.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:24:56 2017 Anthony LECLERC
** Last update Fri Jun 16 17:16:04 2017 Sylvain Chaugny
*/

#include <menu/MenuButton.hpp>
#include <game/Highscore.hpp>
#include "maps/Serialize.hpp"
#include "Engine.hpp"
#include "controllers/PlayerController.hpp"
#include "entity/Box.hpp"
#include "entity/Brick.hpp"
#include "entity/PowerUpFactory.hpp"
#include "entity/PowMoreBomb.hpp"
#include "entity/PowMorePower.hpp"
#include "entity/PowAquaBomb.hpp"
#include "entity/PowSkullMalus.hpp"
#include "entity/PowMoreSpeed.hpp"
#include "game/Game.hpp"
#include "core/Core.hpp"

indie::Game::Game(Core &core, MapAttributes const& map, const std::vector<struct PlayerInfo> &players) :
    smgr(Engine::get().getSceneManager()->createNewSceneManager()),
    _core(core),
    _hud(Hud(*this)),
    _map(nullptr),
    _camera(smgr->addCameraSceneNode(), *_map),
    _mapManager(smgr),
    _collMgr(smgr),
    _loading(true),
    _tempo(true),
    _over(false)

{
  PowerUpFactory::registerFactory<PowMoreBomb>(smgr, 70);
  PowerUpFactory::registerFactory<PowMorePower>(smgr, 70);
  PowerUpFactory::registerFactory<PowAquaBomb>(smgr, 30);
  PowerUpFactory::registerFactory<PowSkullMalus>(smgr, 50);
  PowerUpFactory::registerFactory<PowMoreSpeed>(smgr, 50);

  _playerControllers.push_back(
    std::make_unique<PlayerKeyboardController>(irr::EKEY_CODE::KEY_UP,
					       irr::EKEY_CODE::KEY_DOWN,
					       irr::EKEY_CODE::KEY_RIGHT,
					       irr::EKEY_CODE::KEY_LEFT,
					       irr::EKEY_CODE::KEY_SPACE));
  _playerControllers.push_back(
    std::make_unique<PlayerKeyboardController>(irr::EKEY_CODE::KEY_KEY_Z,
					       irr::EKEY_CODE::KEY_KEY_S,
					       irr::EKEY_CODE::KEY_KEY_D,
					       irr::EKEY_CODE::KEY_KEY_Q,
					       irr::EKEY_CODE::KEY_KEY_A));
  _playerControllers.push_back(
    std::make_unique<PlayerKeyboardController>(irr::EKEY_CODE::KEY_KEY_T,
					       irr::EKEY_CODE::KEY_KEY_G,
					       irr::EKEY_CODE::KEY_KEY_H,
					       irr::EKEY_CODE::KEY_KEY_F,
					       irr::EKEY_CODE::KEY_KEY_R));
  _playerControllers.push_back(
    std::make_unique<PlayerKeyboardController>(irr::EKEY_CODE::KEY_KEY_I,
					       irr::EKEY_CODE::KEY_KEY_K,
					       irr::EKEY_CODE::KEY_KEY_L,
					       irr::EKEY_CODE::KEY_KEY_J,
					       irr::EKEY_CODE::KEY_KEY_U));

  _mapManager.generate(map);
  _mapManager.create(_collMgr);
  _map = _mapManager.getMap();
  _save.attr = map;

  this->generatePlayers(players);

  for (auto &player : _players) {
    _collMgr.setEntityWorldResponse(player.get());
    _mapManager.setPlayer(player);
  }
  
  irr::scene::ILightSceneNode *light = smgr->addLightSceneNode(0, irr::core::vector3df(200, 2000, 1200),
							       irr::video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 8000.0f);
  light->getLightData().AmbientColor.set(1.0f, 1.0f, 1.0f, 1.0f);
  light->enableCastShadow(true);
  light->setLightType(irr::video::E_LIGHT_TYPE::ELT_POINT);
  smgr->setShadowColor(irr::video::SColor(100,0,0,0));
  _camera.init(*_map);
  smgr->addSkyDomeSceneNode(Engine::get().getRessourceManager().getTexture("skydome"),16,8,1,2.0f);

  this->_beginTime = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
  this->_beginTimeSet = false;
  _hud.setStartTime(_beginTime);

  _playerNames = {
    {"P1", {"HUDPlayer1", "HUDBPlayer1"}},
    {"P2", {"HUDPlayer2", "HUDBPlayer2"}},
    {"P3", {"HUDPlayer3", "HUDBPlayer3"}},
    {"P4", {"HUDPlayer4", "HUDBPlayer4"}},
    {"AI", {"HUDAI", "HUDBAI"}}
  };
}


indie::Game::Game(Core &core, const std::vector<PlayerInfo> &players) :
  smgr(Engine::get().getSceneManager()->createNewSceneManager()),
  _core(core),
  _hud(Hud(*this)),
  _map(nullptr),
  _camera(smgr->addCameraSceneNode(), *_map),
  _mapManager(smgr),
  _collMgr(smgr),
  _loading(true),
  _tempo(true),
  _over(false)

{
  _playerControllers.push_back(
    std::make_unique<PlayerKeyboardController>(irr::EKEY_CODE::KEY_UP,
					       irr::EKEY_CODE::KEY_DOWN,
					       irr::EKEY_CODE::KEY_RIGHT,
					       irr::EKEY_CODE::KEY_LEFT,
					       irr::EKEY_CODE::KEY_SPACE));
  _playerControllers.push_back(
    std::make_unique<PlayerKeyboardController>(irr::EKEY_CODE::KEY_KEY_Z,
					       irr::EKEY_CODE::KEY_KEY_S,
					       irr::EKEY_CODE::KEY_KEY_D,
					       irr::EKEY_CODE::KEY_KEY_Q,
					       irr::EKEY_CODE::KEY_KEY_A));
  _playerControllers.push_back(
    std::make_unique<PlayerKeyboardController>(irr::EKEY_CODE::KEY_KEY_T,
					       irr::EKEY_CODE::KEY_KEY_G,
					       irr::EKEY_CODE::KEY_KEY_H,
					       irr::EKEY_CODE::KEY_KEY_F,
					       irr::EKEY_CODE::KEY_KEY_R));
  _playerControllers.push_back(
    std::make_unique<PlayerKeyboardController>(irr::EKEY_CODE::KEY_KEY_I,
					       irr::EKEY_CODE::KEY_KEY_K,
					       irr::EKEY_CODE::KEY_KEY_L,
					       irr::EKEY_CODE::KEY_KEY_J,
					       irr::EKEY_CODE::KEY_KEY_U));


  PowerUpFactory::registerFactory<PowMoreBomb>(smgr, 70);
  PowerUpFactory::registerFactory<PowMorePower>(smgr, 70);
  PowerUpFactory::registerFactory<PowAquaBomb>(smgr, 30);
  PowerUpFactory::registerFactory<PowSkullMalus>(smgr, 50);
  PowerUpFactory::registerFactory<PowMoreSpeed>(smgr, 50);

  _mapManager.generate(13, 11, 0.6);

  _mapManager.create(_collMgr);
  _map = _mapManager.getMap();

  this->generatePlayers(players);

  for (auto &player : _players) {
    _collMgr.setEntityWorldResponse(player.get());
    _mapManager.setPlayer(player);
  }

  irr::scene::ILightSceneNode *light = smgr->addLightSceneNode(0, irr::core::vector3df(200, 2000, 1200),
							       irr::video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 8000.0f);
  light->getLightData().AmbientColor.set(1.0f, 1.0f, 1.0f, 1.0f);
  light->enableCastShadow(true);
  light->setLightType(irr::video::E_LIGHT_TYPE::ELT_POINT);
  smgr->setShadowColor(irr::video::SColor(100,0,0,0));
  _camera.init(*_map);
  smgr->addSkyDomeSceneNode(Engine::get().getRessourceManager().getTexture("skydome"),16,8,1,2.0f);

  this->_beginTime = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
  this->_beginTimeSet = false;
  _hud.setStartTime(_beginTime);

  _playerNames = {
    {"P1", {"HUDPlayer1", "HUDBPlayer1"}},
    {"P2", {"HUDPlayer2", "HUDBPlayer2"}},
    {"P3", {"HUDPlayer3", "HUDBPlayer3"}},
    {"P4", {"HUDPlayer4", "HUDBPlayer4"}},
    {"AI", {"HUDAI", "HUDBAI"}}
  };
}



indie::Game::~Game() {
  PowerUpFactory::clear();
  smgr->drop();
}

bool indie::Game::render() {
  if (_loading) {
    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();
    _loadingScreen = Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("LoadingScreen"), {0, 0});
    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->drawAll();
    _loading = !_loading;
    _hud.build();
  }
  else if (!this->isEnded()) {
    if (_tempo) {
      std::this_thread::sleep_for(std::chrono::seconds(2));
      if (!this->_beginTimeSet)
      {
	this->_beginTime = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
	this->_beginTimeSet = true;
      }
      Engine::get().getSoundManager().playSound("GameStart");
      Engine::get().getSoundManager().enableSoundLoop("Battle");
      Engine::get().getSoundManager().playSound("Battle");
      _tempo = !_tempo;
    }
    smgr->drawAll();
    if (_hud.isActive())
      _hud.render();
  }
  else {
    smgr->drawAll();
    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->drawAll();
  }
  return true;
}

bool indie::Game::clear() {
  return false;
}

bool indie::Game::update() {
  this->_map->update(_collMgr);
  if (this->isEnded()) {
    if (!_over) {
      auto winner = this->getBetterPlayer();

      this->setActive(false);
      this->saveScores();
      Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();
      if (winner == nullptr) {
	displayDraw();
      }
      else {
	displayWinner(winner);
      }
      _over = !_over;
    }
  }
  return false;
}

void indie::Game::receiveEvent(const indie::EventManager &) {
  for (auto &player : _players) {
    if (player->isDropping())
      player->updateDropAnimation();
  }
}

void indie::Game::setActive(bool state)
{
  if (state)
    Engine::get().getEventManager().setNewSceneManager(smgr);
  for (auto &player : _players)
    player->setVisible(state);
  Engine::get().getWindowManager().getDevice().getCursorControl()->setVisible(!state);
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();
  Engine::get().getWindowManager().setGUITransparency(255);
  if (!_loading && !_over)
    _hud.build();
  _hud.setActive(state);
  _camera.setVisible(state);
}

const std::vector<std::shared_ptr<indie::APlayer>> &indie::Game::getPlayers() const {
  return _players;
}

bool indie::Game::isEnded() {
  const irr::u32 now = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
  const irr::f32 deltaTime = static_cast<irr::f32>(now - _beginTime) / 1000.0f;

  if (!(this->_map->playerNbr() <= 1 || deltaTime >= 120)) {
    if (roundf(deltaTime) == 60.0) {
      Engine::get().getSoundManager().playSound("HurryUp");
    }

    if (roundf(deltaTime) == 62.0) {
      Engine::get().getSoundManager().stopSound("Battle");
      Engine::get().getSoundManager().enableSoundLoop("SpeedBattle");
      Engine::get().getSoundManager().playSound("SpeedBattle");
    }

    if (roundf(deltaTime) == 120.0) {
      Engine::get().getSoundManager().playSound("TimeOver");
    }
  }
  return (this->_map->playerNbr() <= 1 || deltaTime >= 120);
}

std::shared_ptr<indie::APlayer> indie::Game::getBetterPlayer() {
  if (this->_players.size() == 0)
  {
    return nullptr;
  }
  std::sort(this->_players.begin(), this->_players.end(), [](std::shared_ptr<APlayer> &first, std::shared_ptr<APlayer> &second){
    if (!first->isDead() && second->isDead())
      return (!first->isDead() && second->isDead());
    return (first->getScore().getAllScore() < first->getScore().getAllScore());
  });

  std::shared_ptr<APlayer> &winner = this->_players.front();
  for (auto &player : this->_players) {
    if (player->isDead() == winner->isDead() && player->getScore().getAllScore() == winner->getScore().getAllScore() && player != winner)
      return nullptr;
  }
  return winner;
}

const std::map<std::string, std::pair<std::string, std::string>> &indie::Game::getPlayerNames() const {
  return _playerNames;
}

void indie::Game::displayWinner(std::shared_ptr<APlayer> &winner) {
  Engine::get().getSoundManager().stopSound("Battle");
  Engine::get().getSoundManager().stopSound("SpeedBattle");
  Engine::get().getSoundManager().stopSound("HurryUp");
  Engine::get().getSoundManager().playSound("Winner");
  Engine::get().getSoundManager().playSound("WinnerMusic");
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture(_playerNames.at(winner->getName()).second), {MenuButton::Position::XCenter - 150 / 2, MenuButton::Position::YCenter - MenuButton::YEighthScreen - 90 / 2});
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("HUDWins"), {MenuButton::Position::XCenter - 280 / 2, MenuButton::Position::YCenter - 85 / 2});
}

void indie::Game::displayDraw(void) {
  Engine::get().getSoundManager().stopSound("Battle");
  Engine::get().getSoundManager().stopSound("SpeedBattle");
  Engine::get().getSoundManager().stopSound("HurryUp");
  Engine::get().getSoundManager().playSound("Draw");
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("HUDDraw"), {MenuButton::Position::XCenter - 310 / 2, MenuButton::Position::YCenter - 85 / 2});
}

void indie::Game::saveScores() {
  Highscore hs;

  hs.load(".highscore");

  for (auto &player : this->_players)
    hs.addScore(player->getScore().getAllScore());
  hs.save(".highscore");
}

indie::MapSaveInfos& indie::Game::save() {
  SerializePlayer getPlayer;
  for (auto& pl : _players) {
    _save.players.push_back(getPlayer.serialize(pl));
  }
  std::vector<TileInfo>::iterator bricks = std::find_if(_save.attr.data.walls.begin(), _save.attr.data.walls.end(),
				  [](TileInfo &w) { return w.name == "Bricks"; });
  std::vector<TileInfo>::iterator boxes = std::find_if(_save.attr.data.walls.begin(), _save.attr.data.walls.end(),
				   [](TileInfo &w) { return w.name == "Box"; });

  if (bricks == _save.attr.data.walls.end())
  {
    TileInfo vtbrick;
    vtbrick.name = "Bricks";
    vtbrick.texturePath = "minecraftBrick";
    _save.attr.data.walls.push_back(vtbrick);
    bricks = _save.attr.data.walls.end() - 1;
  } else
    bricks->pos.clear();
  if (boxes == _save.attr.data.walls.end())
  {
    TileInfo vtbox;
    vtbox.name = "Box";
    vtbox.texturePath = "minecraftBox";
    _save.attr.data.walls.push_back(vtbox);
    boxes = _save.attr.data.walls.end() - 1;
  } else
    boxes->pos.clear();
  Map::t_map wmap;
  wmap = _map->get();
  for (auto&& it = wmap.begin(); it != wmap.end() ; ++it ) {
    if (it->second->getType() == EntityType::BRICK)
    {
      bricks->pos.push_back(_map->getMapPosition(it->second->getSceneNode()->getPosition()));
    }
    else if (it->second->getType() == EntityType::BOX)
    {
      boxes->pos.push_back(_map->getMapPosition(it->second->getSceneNode()->getPosition()));
    }
  }
  return _save;
}

void indie::Game::generatePlayers(const std::vector<PlayerInfo> &players) {
  size_t	humanCount = 1;

  for (auto &player : players) {
    if (player.type == PlayerMode::HUMAN) {
      auto human = std::make_shared<HumanPlayer>(smgr, "bomberman_stand", player.textureName, "P" + std::to_string(humanCount));
      human.get()->setEventController(_playerControllers.at(humanCount - 1).get());
      _players.push_back(human);
      humanCount += 1;
    } else
      _players.push_back(std::make_shared<IA>(smgr, "bomberman_stand", player.textureName, "AI"));
  }
}

indie::Game::Hud::Hud(const indie::Game &game) :
  _game(game),
  _positions({{0, 0}, {SCREEN_WIDTH - 275, 0}, {0, SCREEN_HEIGHT - 275}, {SCREEN_WIDTH - 275, SCREEN_HEIGHT - 275}}),
  _active(true),
  _startTime(0)
{
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->getSkin()->setFont(Engine::get().getRessourceManager().getFont("Bomberman"));
}

indie::Game::Hud::~Hud() {

}

void indie::Game::Hud::build(void) {
  irr::gui::IGUIImage	*frame;

  _scoreBoxes.clear();

  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->clear();

  _timeCounter = Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addStaticText(L"", {SCREEN_WIDTH / 2, 50, SCREEN_WIDTH / 2 + 50, 100});
  _timeCounter->setOverrideColor({255, 255, 255, 255});

  _fpsCounter = Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addStaticText(L"", {SCREEN_WIDTH / 2 - 25, 100, SCREEN_WIDTH / 2 + 25, 150});
  _fpsCounter->setOverrideColor({255, 255, 255, 255});

  for (unsigned int index = 0 ; index < _game.getPlayers().size() ; ++index) {
    auto player = _game.getPlayers().at(index);
    auto position = _positions.at(index);

    frame = Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("HUDFrame"), {position.X, position.Y});

    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture(_game.getPlayerNames().at(player->getName()).first), {position.X + static_cast<int>(frame->getImage()->getSize().Width) / 2 - 100 / 2, position.Y + 50});

    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("ClockIcon"), {SCREEN_WIDTH / 2 - 75, 25});

    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("PowerIcon"), {position.X + static_cast<int>(frame->getImage()->getSize().Width) / 4, position.Y + InfoDelta::PowerDelta});
    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("BombsIcon"), {position.X + static_cast<int>(frame->getImage()->getSize().Width) / 4, position.Y + InfoDelta::BombsDelta});
    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("SpeedIcon"), {position.X + static_cast<int>(frame->getImage()->getSize().Width) / 4, position.Y + InfoDelta::SpeedDelta});
    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addImage(Engine::get().getRessourceManager().getTexture("ScoreIcon"), {position.X + static_cast<int>(frame->getImage()->getSize().Width) / 4, position.Y + InfoDelta::ScoreDelta});

    _scoreBoxes.push_back({
			    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addStaticText(L"X", {position.X + static_cast<int>(frame->getImage()->getSize().Width) / 2, position.Y + InfoDelta::PowerDelta + 5, position.X + static_cast<int>(frame->getImage()->getSize().Width) + 75, position.Y + InfoDelta::PowerDelta + 75}),
			    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addStaticText(L"X", {position.X + static_cast<int>(frame->getImage()->getSize().Width) / 2, position.Y + InfoDelta::BombsDelta + 5, position.X + static_cast<int>(frame->getImage()->getSize().Width) + 75, position.Y + InfoDelta::BombsDelta + 75}),
			    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addStaticText(L"X", {position.X + static_cast<int>(frame->getImage()->getSize().Width) / 2, position.Y + InfoDelta::SpeedDelta + 5, position.X + static_cast<int>(frame->getImage()->getSize().Width) + 75, position.Y + InfoDelta::SpeedDelta + 75}),
			    Engine::get().getWindowManager().getDevice().getGUIEnvironment()->addStaticText(L"X", {position.X + static_cast<int>(frame->getImage()->getSize().Width) / 2, position.Y + InfoDelta::ScoreDelta + 5, position.X + static_cast<int>(frame->getImage()->getSize().Width) + 75, position.Y + InfoDelta::ScoreDelta + 75})
			  });

    _scoreBoxes.at(index).power->setOverrideColor({255, 255, 255, 255});
    _scoreBoxes.at(index).bombs->setOverrideColor({255, 255, 255, 255});
    _scoreBoxes.at(index).speed->setOverrideColor({255, 255, 255, 255});
    _scoreBoxes.at(index).score->setOverrideColor({255, 255, 255, 255});
  }

}

void indie::Game::Hud::render(void) {
  const irr::u32 now = Engine::get().getWindowManager().getDevice().getTimer()->getTime();
  irr::f32 deltaTime = static_cast<irr::f32>(now - _startTime) / 1000.0f;
  irr::f32	clock;

  deltaTime = roundf(deltaTime);
  clock = 120 - deltaTime;
  if (clock < 0) {
    clock = 0;
  }

  _timeCounter->setText(std::to_wstring(static_cast<int>(clock)).c_str());
  _fpsCounter->setText(std::to_wstring(Engine::get().getWindowManager().getDevice().getVideoDriver()->getFPS()).c_str());
  for (unsigned int index = 0 ; index < _game.getPlayers().size() ; ++index) {

    auto stat = _scoreBoxes.at(index);

    stat.power->setText(std::to_wstring(_game.getPlayers().at(index)->getScore().getNumberOf(EntityType::POWER_UP) + 1).c_str());
    stat.bombs->setText(std::to_wstring(_game.getPlayers().at(index)->getScore().getNumberOf(EntityType::BOMB_UP) + 1).c_str());
    stat.speed->setText(std::to_wstring(_game.getPlayers().at(index)->getScore().getNumberOf(EntityType::SPEED_UP)).c_str());
    stat.score->setText(std::to_wstring(_game.getPlayers().at(index)->getScore().getAllScore()).c_str());
  }
  Engine::get().getWindowManager().getDevice().getGUIEnvironment()->drawAll();
}

bool indie::Game::Hud::isActive() const {
  return _active;
}

void indie::Game::Hud::setActive(bool state) {
  _active = state;
}

void indie::Game::Hud::setStartTime(irr::u32 startTime){
  _startTime = startTime;
}
