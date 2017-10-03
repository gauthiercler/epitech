/*
** Game.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/Game.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 13:58:49 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 13:58:49 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include "utils/Random.hpp"
#include "managers/Engine.hpp"
#include "game/Game.hpp"
#include "Core.hpp"

zappy::Game::Game(zappy::Core &core) : _core(core), _tile(nullptr), _serverTick(0), _tick(0), _help(false) {
  // KEYBOARD'S EVENTS
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::Escape}, std::bind(&zappy::Game::disconnect, this)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::Left}, std::bind(&zappy::Map::moveLeft, &this->_map)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::Right}, std::bind(&zappy::Map::moveRight, &this->_map)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::Up}, std::bind(&zappy::Map::moveUp, &this->_map)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::Down}, std::bind(&zappy::Map::moveDown, &this->_map)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::P}, std::bind(&zappy::Map::addScale, &this->_map)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::M}, std::bind(&zappy::Map::removeScale, &this->_map)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::Space}, std::bind(&zappy::Game::removeTile, this)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::O}, std::bind(&zappy::Game::addPlayer, this)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::L}, std::bind(&zappy::Game::removePlayer, this)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::N}, std::bind(&zappy::Map::resetOffset, &this->_map)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::I}, std::bind(&zappy::Game::addTick, this)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::K}, std::bind(&zappy::Game::removeTick, this)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::Return}, std::bind(&zappy::Game::sendTick, this)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::E}, std::bind(&zappy::Map::openChat, &this->_map)});
  this->_keyboardEvents.push_back({{sf::Event::KeyPressed, sf::Keyboard::H}, std::bind(&zappy::Game::goHelp, this)});
  this->_keyboardEvents.push_back({{sf::Event::KeyReleased, sf::Keyboard::H}, std::bind(&zappy::Game::stopHelp, this)});

  // MOUSE'S EVENTS
  this->_mouseEvents.push_back({sf::Event::MouseButtonPressed, std::bind(&zappy::Game::buttonPressed, this, std::placeholders::_1)});
  this->_mouseEvents.push_back({sf::Event::MouseButtonReleased, std::bind(&zappy::Game::buttonReleased, this, std::placeholders::_1)});
  this->_mouseEvents.push_back({sf::Event::MouseMoved, std::bind(&zappy::Game::mouseMoving, this, std::placeholders::_1)});

  // SERVER'S RESPONSES
  this->_serverResponses.push_back({ParseType::MAP_SIZE, std::bind(&zappy::Game::initMap, this, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::CELL_CONTENT, std::bind(&zappy::Map::setTileContent, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::PLAYER_SPAWN, std::bind(&zappy::Map::spawnPlayer, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::PLAYER_POSITION, std::bind(&zappy::Map::changePlayerPosition, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::PLAYER_LEVEL, std::bind(&zappy::Map::changePlayerLevel, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::PLAYER_INVENTORY, std::bind(&zappy::Map::changePlayerInventory, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::PLAYER_END, std::bind(&zappy::Map::excludePlayer, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::PLAYER_BROADCAST, std::bind(&zappy::Map::broadcastPlayer, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::SPAWN_INCANTATION, std::bind(&zappy::Map::spawnIncantation, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::INCANTATION_END, std::bind(&zappy::Map::endIncantation, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::EGG_SPAWN, std::bind(&zappy::Map::spawnEgg, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::EGG_END, std::bind(&zappy::Map::excludeEgg, &this->_map, std::placeholders::_1)});
  this->_serverResponses.push_back({ParseType::RECEIVE_TIME, std::bind(&zappy::Game::responseTick, this, std::placeholders::_1)});
  //TODO END_OF_THEGAME
  this->_serverResponses.push_back({ParseType::SERVER_MSG, std::bind(&zappy::Map::serverMessage, &this->_map, std::placeholders::_1)});
  //TODO UNKNOWN_COMMAND

  this->_last = std::chrono::system_clock::now();
}

zappy::Game::~Game() {
  this->disconnect();
}

void zappy::Game::update(zappy::EventManager &event) {
  for (auto &keyboardEvent : this->_keyboardEvents) {
    if (event.isKeyboardEvent(keyboardEvent.first.first, keyboardEvent.first.second))
      keyboardEvent.second();
  }
  if (event.isMouseEvent())
    {
      for (auto &mouseEvent : this->_mouseEvents) {
	if (event.isMouseEvent(mouseEvent.first))
	  mouseEvent.second(event);
      }
    }
}

void zappy::Game::render() {
  Engine::get().getWindowManager().getWindow().clear(Color(124, 172, 255).inSfml());
  if (this->_map.isGenerated())
  {
    this->_map.render();
    if (this->_tile != nullptr)
      this->_tile->renderSelected();
    if (this->_players.size() > 0)
      this->_players[this->_currentPlayer]->renderSelected(this->_currentPlayer, this->_players.size());
    this->renderTick();
  } else {
    Text text("Waiting server map information...", "pixeled", 30, true);
    text.setPosition(Position(720, 450));
    Engine::get().getWindowManager().draw(text);
  }
  this->renderH();
  if (this->_help)
    this->renderHelp();
}


void zappy::Game::buttonPressed(zappy::EventManager &event) {
  this->_mousePress = true;
  this->_mousePos = event.getMousePositionPressed();
  this->removeTile();
  this->removePlayers();
}

void zappy::Game::buttonReleased(zappy::EventManager &event) {
  this->_mousePress = false;
  this->_mousePos = event.getMousePositionPressed();
  Engine::get().getSoundManager().playSound("select");
  this->handleTile();
  this->handlePlayers();
}

void zappy::Game::mouseMoving(zappy::EventManager &event) {
  this->_mousePos = event.getMousePosition();
}

void zappy::Game::handleTile() {
  this->_tile = this->_map.getTileAtPos(this->_mousePos);
  if (this->_tile != nullptr)
    this->_tile->setDisplay(true);
}

void zappy::Game::removeTile() {
  if (this->_tile != nullptr)
    this->_tile->setDisplay(false);
  this->_tile = nullptr;
  this->_currentPlayer = 0;
  this->_players.clear();
}

void zappy::Game::handlePlayers() {
  this->_players = this->_map.getPlayersAtPos(this->_mousePos);
  this->_currentPlayer = 0;
}

void zappy::Game::removePlayers() {
  this->_players = std::vector<std::shared_ptr<Player>>();
  this->_currentPlayer = 0;
}

void zappy::Game::addPlayer() {
  this->_currentPlayer += 1;
  if (this->_players.size() == 0)
    this->_currentPlayer = 0;
  else
    this->_currentPlayer %= this->_players.size();
}

void zappy::Game::removePlayer() {
  if (this->_currentPlayer == 0)
  {
    this->_currentPlayer = this->_players.size();
    if (this->_currentPlayer != 0)
      this->_currentPlayer -= 1;
  } else
    this->_currentPlayer -= 1;
}

void zappy::Game::disconnect() {
  this->_core.setCoreState(CoreState::MENU);
  this->_map.reset();
  this->_tile = nullptr;
  this->_players.clear();
  this->_currentPlayer = 0;
  Engine::get().getSocket().disconnect();
  Engine::get().getSoundManager().stopSound("menu");
}

void zappy::Game::update(const zappy::Parser &parser) {
  for (auto &response : this->_serverResponses) {
    if (response.first == parser.getType())
      response.second(parser);
  }
}

void zappy::Game::initMap(const zappy::Parser &parser) {
  Size mapSize(std::stoi(parser[1]), std::stoi(parser[2]));

  this->_map.setSize(mapSize);
  this->_map.generate();
  Engine::get().getSoundManager().enableSoundLoop("menu");
  Engine::get().getSoundManager().playSound("menu");
}

void zappy::Game::update() {
  std::chrono::time_point<std::chrono::system_clock>	now = std::chrono::system_clock::now();
  if (!Engine::get().getSocket().isConnected())
    this->disconnect();
  this->_map.update(this->_mousePos, this->_mousePress);

  if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_last).count() > 350)
  {
    this->_map.update();
    this->_last = std::chrono::system_clock::now();
  }
}

void zappy::Game::addTick() {
  this->_tick += 1;
}

void zappy::Game::removeTick() {
  if (this->_tick > 0)
    this->_tick -= 1;
}

void zappy::Game::sendTick() {
  if (this->_tick != this->_serverTick)
    Engine::get().getSocket().send("sgt " + std::to_string(this->_tick) + "\n");
}

void zappy::Game::renderTick() {
  Rect rect(Size(200, 50), Position(620, 0), Color(22, 160, 133, 200));
  Text text("Tick: " + std::to_string(this->_serverTick), "pixeled", 14);
  Text tick(std::to_string(this->_tick), "pixeled", 14);

  text.setCentered(true);
  text.setColor(Color(236, 240, 241));
  text.setPosition(Position(720, 20));
  tick.setCentered(true);
  tick.setPosition(Position(720, 40));
  if (this->_tick == this->_serverTick)
    tick.setColor(Color(236, 240, 241));
  else
    tick.setColor(Color(231, 76, 60));
  Engine::get().getWindowManager().draw(rect);
  Engine::get().getWindowManager().draw(text);
  Engine::get().getWindowManager().draw(tick);
}

void zappy::Game::responseTick(const zappy::Parser &parser) {
  size_t tick = std::stoul(parser[1]);

  if (this->_serverTick == this->_tick)
    this->_tick = tick;
  this->_serverTick = tick;
}

void zappy::Game::goHelp() {
  this->_help = true;
}

void zappy::Game::stopHelp() {
  this->_help = false;
}

void zappy::Game::renderHelp() {
  Sprite help("help", Size(1340, 800));

  help.setPosition(Position(50, 50));
  Engine::get().getWindowManager().draw(help);
}

void zappy::Game::renderH() {
  Rect rect(Size(240, 30), Position(1200, 870), Color(22, 160, 133, 200));
  Text text("Press H for Help", "pixeled", 14);

  text.setCentered(true);
  text.setColor(Color(236, 240, 241));
  text.setPosition(Position(1320, 895));
  Engine::get().getWindowManager().draw(rect);
  Engine::get().getWindowManager().draw(text);
}
