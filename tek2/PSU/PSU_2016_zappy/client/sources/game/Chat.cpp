
#include <game/Chat.hpp>
#include <iostream>
#include <drawable/Rect.hpp>
#include <managers/Engine.hpp>
#include <drawable/Text.hpp>

zappy::Message::Message(const std::string &name, const std::string &message,
			MessageType type) : _name(name), _message(message), _type(type) {

}

zappy::Message::~Message() {
}

void zappy::Message::render(size_t nbr) {
  Text text(this->_name + ": " + this->_message, "pixeled", 12);

  text.setPosition(Position(330, 700 + 20 * nbr));
  if (this->_type == MessageType::SERVER)
    text.setColor(Color(192, 57, 43));
  else
    text.setColor(Color(236, 240, 241));
  Engine::get().getWindowManager().draw(text);
}

zappy::Chat::Chat() : _active(false) {

}

zappy::Chat::~Chat() {

}

void zappy::Chat::update() {
  while (this->_messages.size() > 10) {
    this->_messages.pop_front();
  }
}

void zappy::Chat::render() {
  if (this->_active) {
    Rect rect(Size(800, 230), Position(320, 670), Color(22, 160, 133, 200));
    Text text("Press E to close chat", "pixeled", 14);

    text.setPosition(Position(330, 680));
    text.setColor(Color(44, 62, 80));
    Engine::get().getWindowManager().draw(rect);
    Engine::get().getWindowManager().draw(text);
    this->renderMessages();
  } else {
    Rect rect(Size(300, 30), Position(570, 870), Color(22, 160, 133, 200));
    Text text("Press E to open chat", "pixeled", 14, true);

    text.setPosition(Position(720, 895));
    text.setColor(Color(236, 240, 241));
    Engine::get().getWindowManager().draw(rect);
    Engine::get().getWindowManager().draw(text);
  }
}

void zappy::Chat::setActive(bool active) {
  this->_active = active;
}

bool zappy::Chat::isActive() const {
  return this->_active;
}

void zappy::Chat::addMessage(const zappy::Message &message) {
  this->_messages.push_back(message);
}

void zappy::Chat::renderMessages() {
  size_t nbr;

  nbr = 0;
  for (auto &message : this->_messages) {
    message.render(nbr);
    nbr++;
  }
}

void zappy::Chat::reset() {
  this->_messages.clear();
  this->setActive(false);
}
