/*
** Snake.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/snake/sources/Snake.cpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Apr 05 08:57:34 2017 Vincent DUSAUTOIR
** Last update Wed Apr 05 08:57:34 2017 Vincent DUSAUTOIR
*/

#include <iostream>
#include <random>
#include <ctime>
#include <sstream>
#include "Snake.hpp"

arcade::Snake::Snake() : _glib(NULL), _frame(NULL), _banner(NULL), _direction(RIGHT), _total(3), _clock(100), _scoreEntered(false) {
  std::vector<arcade::TileType>		tmp;
  std::srand(std::time(0));

  for (int x = 0; x < Snake::mapSize ; x++)
    tmp.push_back(TileType::EMPTY);
  for (int y = 0 ; y < Snake::mapSize ; y++)
    this->_map.push_back(tmp);
  this->_fruits.first = std::rand() % Snake::mapSize;
  this->_fruits.second = std::rand() % Snake::mapSize;
  this->_head.first = Snake::mapSize / 2;
  this->_head.second = Snake::mapSize / 2;
  this->_tail.push_back({this->_head.first - 3, this->_head.second});
  this->_tail.push_back({this->_head.first - 2, this->_head.second});
  this->_tail.push_back({this->_head.first - 1, this->_head.second});
  this->_score.load(".snake.score");
}

arcade::Snake::~Snake() {
  if (this->_glib != NULL)
  {
    if (this->_frame != NULL)
      this->_glib->deleteFrame(this->_frame->getId());
    if (this->_banner != NULL)
      this->_glib->deleteFrame(this->_banner->getId());
  }
}

void arcade::Snake::Play() {
  if (this->getGraphic() != NULL) {
    if (this->isDead())
      this->displayDead();
    else if (this->_clock.tick()) {
      this->eat();
      this->update();
      this->display();
    }
  }
}

void arcade::Snake::init(arcade::IGraphic &glib) {
  this->setGraphic(&glib);
  this->_banner = &(this->getGraphic()->addFrame(pos(0, 0), 840, 40));
  this->_frame = &(this->getGraphic()->addFrame(pos(0, 40), 840, 840));
  this->_banner->draw(rgb(255, 236, 240, 241));
  this->_banner->draw(pos(325, 5), "Playing Snake", text(rgb(255, 0, 0, 0), 25));
}

void arcade::Snake::close() {

}

void arcade::Snake::reload(arcade::IGraphic &glib) {
  static_cast<void>(glib);
}

void arcade::Snake::receiveEvent(const arcade::IEvent &event) {
  if (event.getType() == ET_KEYBOARD_CLICK)
  {
    if (!this->isDead())
    {
      if (event.getValue() == EV_UP && this->getDirection() != DOWN)
	this->setDirection(UP);
      else if (event.getValue() == EV_DOWN && this->getDirection() != UP)
	this->setDirection(DOWN);
      else if (event.getValue() == EV_LEFT && this->getDirection() != RIGHT)
	this->setDirection(LEFT);
      else if (event.getValue() == EV_RIGHT && this->getDirection() != LEFT)
	this->setDirection(RIGHT);
    } else {
      if (!this->_scoreEntered && event.getType() == ET_KEYBOARD_CLICK && event.getValue() == EV_ENTER)
	this->registerScore();
      else if (!this->_scoreEntered)
	this->_input.receiveEvent(event);
    }
  }
}

void arcade::Snake::dumpMap() const {

}

arcade::IGraphic *arcade::Snake::getGraphic() const{
  return this->_glib;
}

void arcade::Snake::setGraphic(arcade::IGraphic *glib) {
  this->_glib = glib;
}

void arcade::Snake::movePlayer() {
  int x;
  int y;

  x = 0;
  y = 0;
  switch (this->getDirection())
  {
    case UP:
      y = -1; break;
    case DOWN:
      y = 1; break;
    case LEFT:
      x = -1; break;
    case RIGHT:
      x = 1; break;
  }
  this->_head.first += x;
  this->_head.second += y;
}

void arcade::Snake::setDirection(direction dir) {
  this->_direction = dir;
}

arcade::Snake::direction arcade::Snake::getDirection() {
  return this->_direction;
}

const std::vector<std::vector<arcade::TileType>> &arcade::Snake::getMap() const {
  return this->_map;
}

const std::pair<int, int> &arcade::Snake::getHead() const {
  return this->_head;
}

const std::vector<std::pair<int, int>> &arcade::Snake::getTail() const {
  return this->_tail;
}

void arcade::Snake::update() {
  for (int i = 0; i < static_cast<int>(this->_tail.size()) - 1 ; ++i) {
    this->_tail[i] = this->_tail[i + 1];
  }
  if (this->_total >= 1)
    this->_tail[this->_total - 1] = this->_head;
  this->movePlayer();
  if (!this->isDead())
  {
    this->cleanMap();
    this->_map[this->_head.second][this->_head.first] = arcade::TileType::BLOCK;
    for (auto node : this->_tail)
      this->_map[node.second][node.first] = arcade::TileType::BLOCK;
    this->_map[this->_fruits.second][this->_fruits.first] = arcade::TileType::POWERUP;
  }
}

void arcade::Snake::display() {
  std::stringstream score;
  score << this->_total - 3;
  this->_frame->draw(rgb(255, 52, 73, 94));
  this->_frame->draw(pos(this->_head.first * Snake::cellSize, this->_head.second * Snake::cellSize),
		     rectangle(pos(Snake::cellSize, Snake::cellSize),
			       rgb(255, 192, 57, 43)));
  for (auto node : this->_tail)
    this->_frame->draw(pos(node.first * Snake::cellSize, node.second * Snake::cellSize),
		       rectangle(pos(Snake::cellSize, Snake::cellSize),
		       rgb(255, 231, 76, 60)));
  this->_frame->draw(pos(this->_fruits.first * Snake::cellSize, this->_fruits.second * Snake::cellSize),
		     rectangle(pos(Snake::cellSize, Snake::cellSize),
			       rgb(255, 46, 204, 113)));
  this->_frame->draw(pos(380, 400), score.str(), text(rgb(255, 255, 255, 255), 25));
}

bool arcade::Snake::isDead() {
  if (this->_head.first >= Snake::mapSize
      || this->_head.first < 0
      || this->_head.second >= Snake::mapSize
      || this->_head.second < 0)
    return true;
  for (auto node : this->_tail)
  {
    if (node.first == this->_head.first && node.second == this->_head.second)
      return true;
  }
  return false;
}

void arcade::Snake::cleanMap() {
  for (auto &y : this->_map)
    for (auto &x : y)
      x = TileType::EMPTY;
}

void arcade::Snake::eat() {
  if (this->_head.first - this->_fruits.first == 0 &&
      this->_head.second - this->_fruits.second == 0)
  {
    this->_total += 1;
    while (this->_map[this->_fruits.second][this->_fruits.first] != TileType::EMPTY)
    {
      this->_fruits.first = std::rand() % Snake::mapSize;
      this->_fruits.second = std::rand() % Snake::mapSize;
    }
    this->_tail.push_back(this->_head);
  }
}

void arcade::Snake::displayDead() {
  std::stringstream	name;
  std::stringstream	score_value;
  std::vector<std::pair<std::string, std::string>> scores;
  std::vector<std::pair<std::string, std::string>>::iterator it;
  unsigned int		idx;

  idx = 0;
  name << this->_input.getValue() << "|";
  score_value << this->_total - 3;
  this->_frame->draw(rgb(255, 52, 73, 94));
  this->_frame->draw(pos(420 - (std::string("Game Over ").length() * 10 / 2), 30), std::string("Game Over "), text(rgb(255, 255, 255, 255), 20));
  this->_frame->draw(pos(420 - (std::string("Enter your pseudo").length() * 10 / 2), 100), std::string("Enter your pseudo"), text(rgb(255, 255, 255, 255), 20));
  this->_frame->draw(pos(420 - (name.str().length() * 10 / 2), 150), name.str(), text(rgb(255, 255, 255, 255), 20));
  this->_frame->draw(pos(110 , 200), std::string("Scores"), text(rgb(255, 255, 255, 255), 40));
  scores = this->_score.getAllScores();
  it = scores.begin();
  while (idx != 10 && it != scores.end())
  {
    this->_frame->draw(pos(150, 300 + idx * 50), it->first + " : " + it->second, text(rgb(255, 255, 255, 255), 20));
    idx++;
    ++it;
  }
  this->_frame->draw(pos(560 - (score_value.str().length() / 2 * 40), 360), score_value.str(), text(rgb(255, 255, 255, 255), 80));
  this->_frame->draw(pos(420 - (std::string("Press 8 to restart").length() / 2 * 10), 680), std::string("Press 8 to restart"), text(rgb(255, 255, 255, 255), 20));
  this->_frame->draw(pos(420 - (std::string("Press 9 to go back to menu").length() / 2 * 10), 720), std::string("Press 9 to go back to menu"), text(rgb(255, 255, 255, 255), 20));
}

void arcade::Snake::registerScore() {
  this->_score.add(this->_input.getValue(), this->_total - 3);
  this->_score.save(".snake.score");
  this->_scoreEntered = true;
}

extern "C" arcade::IGame *createGame()
{
  return new arcade::Snake();
}

extern "C" void Play()
{
  arcade::Snake      *Snake = new arcade::Snake();
  arcade::ProtocolHandler  *ProtocolHandler = new arcade::ProtocolHandler();
  arcade::IEvent const    *event;

  while (ProtocolHandler->getCommand()) {
    if (ProtocolHandler->getCommandType() == arcade::CommandType::WHERE_AM_I) {

      ProtocolHandler->setHead(Snake->getHead());
      ProtocolHandler->setTail(Snake->getTail());
      ProtocolHandler->setLength(Snake->getTail().size() + 1);
      ProtocolHandler->dumpPosition();
    }
    else if (ProtocolHandler->getCommandType() == arcade::CommandType::GET_MAP) {

      ProtocolHandler->setMap(Snake->getMap());
      ProtocolHandler->dumpMap();

    }
    else {
      event = &ProtocolHandler->getEvent();
      Snake->receiveEvent(*event);
      if (ProtocolHandler->getCommandType() == arcade::CommandType::GO_FORWARD
	|| ProtocolHandler->getCommandType() == arcade::CommandType::PLAY) {
	Snake->eat();
	Snake->update();
      }
    }

  }

  delete Snake;
  delete ProtocolHandler;
}