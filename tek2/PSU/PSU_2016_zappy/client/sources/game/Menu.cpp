/*
** Menu.cpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/game/Menu.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 13:25:35 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 13:25:35 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include <utils/Utils.hpp>
#include "utils/Color.hpp"
#include "managers/Engine.hpp"
#include "game/Menu.hpp"
#include "Core.hpp"

zappy::Menu::Menu(zappy::Core &core) : _core(core) {
  this->_buttonBackground1 = Rect(Size(600, 48), Position(0, 500), Color(41, 128, 185), true);
  this->_buttonBackground2 = Rect(Size(600, 48), Position(0, 596), Color(41, 128, 185), true);

  this->_buttonText1 = Text("Connect", "roboto", 32);
  this->_buttonText1.setCentered(true);
  this->_buttonText1.setColor(Color(236, 240, 241));
  this->_buttonText1.setPosition(Position(Engine::get().getWindowSize().width / 2, 534));

  this->_buttonText2 = Text("Quit", "roboto", 32);
  this->_buttonText2.setCentered(true);
  this->_buttonText2.setColor(Color(236, 240, 241));
  this->_buttonText2.setPosition(Position(Engine::get().getWindowSize().width / 2, 632));

  this->_ipText = Text(this->_ip, "roboto", 32);
  this->_ipText.setCentered(true);
  this->_ipText.setPosition(Position(Engine::get().getWindowSize().width / 2, 350));
  this->_ipBackground = Rect(Size(600, 48), Position(0, 318), Color(255, 255, 255), true);

  this->_zappyText = Text("ZAPPY", "pixeled", 50);
  this->_zappyText.setCentered(true);
  this->_zappyText.setPosition(Position(Engine::get().getWindowSize().width / 2, 280));
  this->_zappyText.setColor(Color(22, 160, 133));

  this->_winner = Text("", "pixeled", 30);
  this->_winner.setCentered(true);
  this->_winner.setPosition(Position(Engine::get().getWindowSize().width / 2, 130));
  this->_winner.setColor(Color(241, 196, 15));
}

zappy::Menu::~Menu() {

}

void zappy::Menu::update(zappy::EventManager &event) {
  if (event.isKeyboardEvent()) {
    this->keyboardEvent(event);
  } else if (event.isMouseEvent()) {
    this->mouseEvent(event);
  }
  this->_ipText.setString(this->_ip);
}

void zappy::Menu::render() {
  Engine::get().getWindowManager().clear(sf::Color(52, 73, 94));

  Engine::get().getWindowManager().draw(this->_ipBackground);
  Engine::get().getWindowManager().draw(this->_buttonBackground1);
  Engine::get().getWindowManager().draw(this->_buttonBackground2);
  Engine::get().getWindowManager().draw(this->_buttonText1);
  Engine::get().getWindowManager().draw(this->_buttonText2);
  Engine::get().getWindowManager().draw(this->_ipText);
  Engine::get().getWindowManager().draw(this->_zappyText);
  Engine::get().getWindowManager().draw(this->_winner);
}

void zappy::Menu::addIp(char c) {
  if ((isalnum(c) || ispunct(c)) && this->_ip.length() < 30)
    this->_ip += c;
  else if (c == '\b')
    this->_ip = this->_ip.substr(0, this->_ip.size()-1);
}

void zappy::Menu::connect() {
  this->_winner.setString("");
  auto host = Utils::explode(this->_ip, ':');
  if (host.size() > 0) {
    std::string hostname = host[0];
    size_t port = (host.size() > 1) ? std::stoi(host[1]) : 8081;
    if (Engine::get().getSocket().connectTo(hostname, port))
      this->_core.setCoreState(CoreState::GAME);
  }
}

void zappy::Menu::keyboardEvent(zappy::EventManager &event) {
  if (event.isKeyboardEvent(sf::Event::KeyPressed, sf::Keyboard::Return))
    this->connect();
  else if (event.isTextEntered())
    this->addIp(event.getTextEntered());
}

void zappy::Menu::mouseEvent(zappy::EventManager &event) {
  if (event.isMouseMoving())
  {
    if (event.isMouseMoving(this->_buttonBackground1.getPosition(), this->_buttonBackground1.getSize()))
      this->_buttonBackground1.setColor(Color(52, 152, 219));
    else
      this->_buttonBackground1.setColor(Color(41, 128, 185));
    if (event.isMouseMoving(this->_buttonBackground2.getPosition(), this->_buttonBackground2.getSize()))
      this->_buttonBackground2.setColor(Color(52, 152, 219));
    else
      this->_buttonBackground2.setColor(Color(41, 128, 185));
  } else if (event.isButtonPressed()) {
    if (event.isButtonPressed(this->_buttonBackground1.getPosition(), this->_buttonBackground1.getSize()))
      this->connect();
    if (event.isButtonPressed(this->_buttonBackground2.getPosition(), this->_buttonBackground2.getSize()))
      this->_core.close();
  }
}

void zappy::Menu::setWinner(const std::string &winner) {
  this->_winner.setString(winner);
}
