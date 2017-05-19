/*
** Pacman.cpp for cpp_arcade in /home/ventinc/epitech/cpp/cpp_arcade/src/games/snake/sources/Pacman.cpp
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
#include <AStar.hpp>
#include <algorithm>
#include "Pacman.hpp"

arcade::Pacman::Pacman() : _glib(NULL), _direction(DOWN), _total(0), _clock(150), _startedGameTime(std::chrono::system_clock::now()), _scoreEntered(false), _canEatEnemies(false){
  std::srand(std::time(0));
  this->_map.resize(mapSize);
  for (auto mapLine : this->_map)
    mapLine.resize(mapSize);
  this->_map = {
    {EMPTY, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, EMPTY},
    {EMPTY, WALL, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, WALL, COIN, COIN, COIN, COIN, COIN, BOOST, COIN, COIN, WALL, EMPTY},
    {EMPTY, WALL, COIN, WALL, WALL, COIN, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, COIN, WALL, WALL, COIN, WALL, EMPTY},
    {EMPTY, WALL, COIN, COIN, BOOST, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, WALL, EMPTY},
    {EMPTY, WALL, COIN, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, COIN, WALL, EMPTY},
    {EMPTY, WALL, COIN, COIN, COIN, COIN, WALL, COIN, COIN, COIN, WALL, COIN, COIN, COIN, WALL, COIN, COIN, COIN, COIN, WALL, EMPTY},
    {EMPTY, WALL, WALL, WALL, WALL, COIN, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, COIN, WALL, WALL, WALL, WALL, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, WALL, COIN, WALL, COIN, COIN, COIN, COIN, COIN, COIN, COIN, WALL, COIN, WALL, EMPTY, EMPTY, EMPTY, EMPTY},
    {WALL, WALL, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, EMPTY, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, WALL, WALL},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, COIN, COIN, COIN, WALL, EMPTY, EMPTY, EMPTY, WALL, COIN, COIN, COIN, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {WALL, WALL, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, WALL, WALL},
    {EMPTY, EMPTY, EMPTY, EMPTY, WALL, COIN, WALL, COIN, COIN, COIN, EMPTY, COIN, COIN, COIN, WALL, COIN, WALL, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, WALL, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, WALL, EMPTY},
    {EMPTY, WALL, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, WALL, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, WALL, EMPTY},
    {EMPTY, WALL, COIN, WALL, WALL, COIN, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, COIN, WALL, WALL, COIN, WALL, EMPTY},
    {EMPTY, WALL, COIN, COIN, WALL, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, WALL, COIN, COIN, WALL, EMPTY},
    {EMPTY, WALL, WALL, COIN, WALL, COIN, WALL, COIN, WALL, WALL, WALL, WALL, WALL, COIN, WALL, COIN, WALL, COIN, WALL, WALL, EMPTY},
    {EMPTY, WALL, COIN, COIN, BOOST, COIN, WALL, COIN, COIN, COIN, WALL, COIN, COIN, COIN, WALL, COIN, COIN, BOOST, COIN, WALL, EMPTY},
    {EMPTY, WALL, COIN, WALL, WALL, WALL, WALL, WALL, WALL, COIN, WALL, COIN, WALL, WALL, WALL, WALL, WALL, WALL, COIN, WALL, EMPTY},
    {EMPTY, WALL, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, COIN, WALL, EMPTY},
    {EMPTY, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, EMPTY}
  };
  this->_playerPosition = {10, 11};

  std::vector<bool>	line;

  for (int i = 0; i < Pacman::mapSize ; i++)
    line.push_back(true);
  for (int i = 0; i < Pacman::mapSize ; i++)
    this->_cachedMap.push_back(line);
  for (auto &currentEnemy : this->_ennemies)
  {
    AStar	path(this->_map, currentEnemy.getPos(), this->_playerPosition, Pacman::mapSize, this->_ennemies);
    currentEnemy.setPath(path.compute());
  }
  this->_score.load(".pacman.score");
  this->_move = 0;
}

arcade::Pacman::~Pacman() {
  if (this->_glib != NULL)
  {
    if (this->_frame != NULL)
      this->_glib->deleteFrame(this->_frame->getId());
    if (this->_banner != NULL)
      this->_glib->deleteFrame(this->_banner->getId());
  }
}

void arcade::Pacman::Play() {
  if (this->getGraphic() != NULL) {
    if (this->isDead())
      this->displayDead();
    else if (this->_clock.tick()) {
      if (this->_ennemies.size() < 4)
	this->addNewGhost();
      this->eat();      this->update();
      this->display();
      this->_cachedMap = std::vector<std::vector<bool>>(Pacman::mapSize, std::vector<bool>(Pacman::mapSize));
    }
  }
}

void arcade::Pacman::init(arcade::IGraphic &glib) {
  std::vector<bool>	line;

  this->setGraphic(&glib);
  this->_banner = &this->getGraphic()->addFrame(pos(0, 0), 840, 40);
  this->_frame = &this->getGraphic()->addFrame(pos(0, 40), 840, 840);
  this->_sprite = this->getGraphic()->loadSprite("ressources/sprites/pacman.sprite");
  this->_wall = this->getGraphic()->loadPicture("ressources/pictures/pacman_wall.png");
  this->_wall->setColor(rgb(255, 41, 128, 185));
  this->_wall->setInnerPos(pos(0, 0), 40, 40);
  this->_frame->draw(rgb(255, 0, 0, 0));
  for (auto &y : this->_cachedMap)
    for (auto x : y)
      x = true;
  this->display();
}

void arcade::Pacman::close() {

}

void arcade::Pacman::reload(arcade::IGraphic &glib) {
  static_cast<void>(glib);
}

void arcade::Pacman::receiveEvent(const arcade::IEvent &event) {
  if (event.getType() == ET_KEYBOARD_CLICK)
  {
    if (!this->isDead()) {
      switch (event.getValue())
      {
	case EV_UP:
	  if (this->_map[this->_playerPosition.second - 1][this->_playerPosition.first] != WALL)
	    this->setDirection(UP); break;
	case EV_DOWN:
	  if (this->_map[this->_playerPosition.second + 1][this->_playerPosition.first] != WALL)
	    this->setDirection(DOWN); break;
	case EV_LEFT:
	  if (this->_map[this->_playerPosition.second][this->_playerPosition.first - 1] != WALL)
	    this->setDirection(LEFT); break;
	case EV_RIGHT:
	  if (this->_map[this->_playerPosition.second][this->_playerPosition.first + 1] != WALL)
	    this->setDirection(RIGHT); break;
	default:
	  break;
      }
    } else {
      if (!this->_scoreEntered && event.getType() == ET_KEYBOARD_CLICK && event.getValue() == EV_ENTER)
	this->registerScore();
      else if (!this->_scoreEntered)
	this->_input.receiveEvent(event);
    }
  }
}

void arcade::Pacman::dumpMap() const {

}

arcade::IGraphic *arcade::Pacman::getGraphic() const{
  return this->_glib;
}

void arcade::Pacman::setGraphic(arcade::IGraphic *glib) {
  this->_glib = glib;
}

void arcade::Pacman::movePlayer() {
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

  //TP from left to right
  if (this->_playerPosition.first + x == -1) {
    this->_playerPosition.first = 20;
    this->_cachedMap[this->_playerPosition.second][0] = true;
    this->_cachedMap[this->_playerPosition.second][this->_playerPosition.first] = true;
  }
    //TP from right to left
  else if (this->_playerPosition.first + x == 21) {
    this->_playerPosition.first = 0;
    this->_cachedMap[this->_playerPosition.second][20] = true;
    this->_cachedMap[this->_playerPosition.second][this->_playerPosition.first] = true;
  }
    //Normal moving
  else if (_map[this->_playerPosition.second + y][this->_playerPosition.first + x] != WALL) {
    this->_cachedMap[this->_playerPosition.second][this->_playerPosition.first] = true;
    this->_playerPosition.first += x;
    this->_playerPosition.second += y;
    this->_cachedMap[this->_playerPosition.second][this->_playerPosition.first] = true;
  }

  for (auto &currentEnemy : this->_ennemies)
  {
    if (currentEnemy.getState() == DEAD && currentEnemy.getPos().first == 10 && currentEnemy.getPos().second == 9)
      currentEnemy.setState(HUNTING);
    std::vector<std::pair<int, int>> alreadySet;
      AStar	path(this->_map, currentEnemy.getPos(), (currentEnemy.getState() == HUNTING) ? this->_playerPosition : std::pair<int, int>(10, 9), Pacman::mapSize, this->_ennemies);
      std::vector<std::pair<int, int>>	compute = path.compute();
      currentEnemy.setPath(compute);
    bool isInVec = false;
    if (currentEnemy.getPathSize() > 0) {
      for (auto &vecValue : alreadySet){
	if (vecValue.first == currentEnemy.getPos().first && vecValue.second == currentEnemy.getPos().second)
	  isInVec = true;
      }
      if (!isInVec) {
	this->_cachedMap[currentEnemy.getPos().second][currentEnemy.getPos().first] = true;
	currentEnemy.setPos(currentEnemy.getFirstElement());
	this->_cachedMap[currentEnemy.getPos().second][currentEnemy.getPos().first] = true;
	currentEnemy.eraseFirstElement();
	alreadySet.push_back(currentEnemy.getPos());
      }
    }
  }


}

void arcade::Pacman::setDirection(direction dir) {
  this->_direction = dir;
}

arcade::Pacman::direction arcade::Pacman::getDirection() {
  return this->_direction;
}

const std::vector<std::vector<arcade::TileType>> &arcade::Pacman::getMap() const {
  std::vector<std::vector<arcade::TileType>>	*map = new std::vector<std::vector<arcade::TileType>>;

  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it) {
    map->push_back(std::vector<arcade::TileType>());
    for (auto sub_it = it->begin() ; sub_it != it->end() ; ++sub_it) {
      arcade::TileType		cellType;

      switch (*sub_it) {
	case arcade::cellType::EMPTY:
	  cellType = arcade::TileType::EMPTY;
	  break;
	case arcade::cellType::WALL:
	  cellType = arcade::TileType::BLOCK;
	  break;
	case arcade::cellType::GHOST:
	  cellType = arcade::TileType::EVIL_DUDE;
	  break;
	case arcade::cellType::PACMAN:
	  cellType = arcade::TileType::OTHER;
	  break;
	case arcade::cellType::COIN:
	  cellType = arcade::TileType::POWERUP;
	  break;
	case arcade::cellType::BOOST:
	  cellType = arcade::TileType::POWERUP;
	  break;
	case arcade::cellType::FRUIT:
	  cellType = arcade::TileType::POWERUP;
	  break;
	default:
	  cellType = arcade::TileType::EMPTY;
	  break;
      }
      map->at(std::distance(this->_map.begin(), it)).push_back(cellType);
    }
  }
  return *map;
}

void arcade::Pacman::update() {
    this->movePlayer();
}

void arcade::Pacman::display() {
  this->_banner->draw(rgb(255, 236, 240, 241));
  this->_banner->draw(pos(325, 5), "Playing Pacman", text(rgb(255, 0, 0, 0), 25));
  std::stringstream score;
  score << this->_total;
  this->_banner->draw(pos(0, 0), score.str(), text(rgb(255, 0, 0, 0), 25));
  if (this->_canEatEnemies) {
    std::stringstream remainingTime;
    remainingTime << 7 - this->_timeElapsed;
    this->_banner->draw(pos(800, 0), remainingTime.str(), text(rgb(255, 0, 0, 0), 25));
  }
  for (int y = 0; y < Pacman::mapSize ; y++)
    for (int x = 0; x < Pacman::mapSize ; x++) {
      if (this->_cachedMap[y][x]) {
	this->_frame->draw(pos(x * Pacman::cellSize, y * Pacman::cellSize),
			   rectangle(pos(Pacman::cellSize, Pacman::cellSize),
				     rgb(255, 0, 0, 0)));
	switch (this->_map[y][x])
	{
	  case WALL:
	    this->_frame->draw(pos(x * Pacman::cellSize, y * Pacman::cellSize),
			       *this->_wall);
	    break;
	  case EMPTY:
	    this->_frame->draw(pos(x * Pacman::cellSize, y * Pacman::cellSize),
			       rectangle(pos(Pacman::cellSize, Pacman::cellSize),
					 rgb(255, 0, 0, 0)));
	    break;
	  case COIN:
	    this->_frame->draw(pos(x * Pacman::cellSize + Pacman::cellSize / 2,
				   y * Pacman::cellSize + Pacman::cellSize / 2),
			       circle(rgb(255, 236, 240, 241), 5));
	    break;
	  case BOOST:
	    this->_frame->draw(pos(x * Pacman::cellSize + Pacman::cellSize / 2,
				   y * Pacman::cellSize + Pacman::cellSize / 2),
			       circle(rgb(255, 236, 240, 241), 11));
	    break;
	  default:
	    break;
	}
      }
    }
  if (this->_cachedMap[_playerPosition.second][_playerPosition.first])
    this->drawPacman();
  for (auto &current : this->_ennemies)
    if (current.getPathSize() > 0) {
      if (current.getState() == DEAD)
	this->_frame->draw(
	pos(current.getPos().first * Pacman::cellSize,
	    current.getPos().second * Pacman::cellSize),
	this->_sprite->getPicture(current.getDeadId()));
      else
	this->_frame->draw(
	  pos(current.getPos().first * Pacman::cellSize,
	      current.getPos().second * Pacman::cellSize),
	(this->_canEatEnemies) ? this->_sprite->getPicture(48 + this->_move) : this->_sprite->getPicture(current.getId() + this->_move));
    }
}

bool arcade::Pacman::isDead() {
  int nbCoinsRemaining = 0;

  for (auto &y : this->_map)
    for (auto &x : y)
      if (x == COIN || x == BOOST)
	nbCoinsRemaining += 1;

  if (nbCoinsRemaining == 0)
    return false;
  if (this->_canEatEnemies)
    return false;
  for (auto &currentEnemy : this->_ennemies) {
    if (currentEnemy.getState() != DEAD)
      if (currentEnemy.getPos().first == this->_playerPosition.first && currentEnemy.getPos().second == this->_playerPosition.second)
	return true;
  }
  return false;
}

void arcade::Pacman::cleanMap() {
  for (auto &y : this->_map)
    for (auto &x : y)
      x  = EMPTY;
}

void arcade::Pacman::eat() {
  if (this->_canEatEnemies) {
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    this->_timeElapsed = std::chrono::duration_cast<std::chrono::seconds>(now - this->_canEatEnemiesTime).count();
    if (this->_timeElapsed >= 7)
      this->_canEatEnemies = false;
    else {
      for (auto &ghost : this->_ennemies)
	if (ghost.getState() != DEAD) {
	  if (ghost.getPos().first == _playerPosition.first && ghost.getPos().second == _playerPosition.second) {
	    ghost.setState(DEAD);
	  }
	}
    }
  }
  switch (this->_map[this->_playerPosition.second][this->_playerPosition.first]) {
    case COIN:
      this->_total += 1;
      this->_map[this->_playerPosition.second][this->_playerPosition.first] = EMPTY;
      this->_cachedMap[this->_playerPosition.second][this->_playerPosition.first] = true;
      break;
    case BOOST:
      this->_total += 5;
      this->_map[this->_playerPosition.second][this->_playerPosition.first] = EMPTY;
      this->_cachedMap[this->_playerPosition.second][this->_playerPosition.first] = true;
      this->_canEatEnemies = true;
      this->_canEatEnemiesTime = std::chrono::system_clock::now();
      break;
    default:
      break;
  }
}

const std::pair<int, int> &arcade::Pacman::getHead() const {
  return this->_playerPosition;
}

void arcade::Pacman::addNewGhost() {
  std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
  long timeElapsed = std::chrono::duration_cast<std::chrono::seconds>(
    now - this->_startedGameTime).count();
  if (timeElapsed > 2 && this->_ennemies.size() == 0)
    this->_ennemies.push_back(Ghost({10, 9}, 34, 52, HUNTING));
  else if (timeElapsed > 5 && this->_ennemies.size() == 1)
    this->_ennemies.push_back(Ghost({9, 9}, 26, 52, HUNTING));
  else if (timeElapsed > 10 && this->_ennemies.size() == 2)
    this->_ennemies.push_back(Ghost({11, 9}, 10, 52, HUNTING));
  else if (timeElapsed > 15 && this->_ennemies.size() == 3)
    this->_ennemies.push_back(Ghost({10, 8}, 2, 52, HUNTING));
}

void arcade::Pacman::displayDead() {
  std::stringstream	name;
  std::stringstream	score_value;
  std::vector<std::pair<std::string, std::string>> scores;
  std::vector<std::pair<std::string, std::string>>::iterator it;
  unsigned int		idx;

  idx = 0;
  name << this->_input.getValue() << "|";
  score_value << this->_total;
  this->_frame->draw(rgb(255, 52, 73, 94));
  this->_frame->draw(pos(420 - (std::string("Game Over ").length() * 10 / 2), 30), std::string("Game Over "), text(rgb(255, 255, 255, 255), 20));
  this->_frame->draw(pos(420 - (std::string("Enter your pseudo ").length() * 10 / 2), 100), std::string("Enter your pseudo"), text(rgb(255, 255, 255, 255), 20));
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
  this->_frame->draw(pos(560 - (score_value.str().length() / 2 * 40), 440), score_value.str(), text(rgb(255, 255, 255, 255), 80));
  this->_frame->draw(pos(420 - (std::string("Press 8 to restart").length() / 2 * 10), 680), std::string("Press 8 to restart"), text(rgb(255, 255, 255, 255), 20));
  this->_frame->draw(pos(420 - (std::string("Press 9 to go back to menu").length() / 2 * 10), 720), std::string("Press 9 to go back to menu"), text(rgb(255, 255, 255, 255), 20));
}

void arcade::Pacman::registerScore() {
  this->_score.add(this->_input.getValue(), this->_total);
  this->_score.save(".pacman.score");
  this->_scoreEntered = true;
}

void arcade::Pacman::drawPacman() {
  uint64_t id;

  switch (this->_direction)
  {
    case LEFT:
      id = 44;
      break;
    case RIGHT:
      id = 40;
      break;
    case UP:
      id = 46;
      break;
    case DOWN:
      id = 42;
      break;
  }
  this->_frame->draw(pos(_playerPosition.first * Pacman::cellSize + 4, _playerPosition.second * Pacman::cellSize + 4),
		     this->_sprite->getPicture(id + this->_move));
  this->_move += 1;
  this->_move %= 2;
}

extern "C" arcade::IGame *createGame()
{
  return new arcade::Pacman();
}

extern "C" void Play()
{
  arcade::Pacman	*Pacman = new arcade::Pacman();
  arcade::ProtocolHandler	*ProtocolHandler = new arcade::ProtocolHandler();
  arcade::IEvent const		*event;

  while (ProtocolHandler->getCommand()) {
    if (ProtocolHandler->getCommandType() == arcade::CommandType::WHERE_AM_I) {
      ProtocolHandler->setHead(Pacman->getHead());
      ProtocolHandler->setLength(1);
      ProtocolHandler->dumpPosition();
    }
    else if (ProtocolHandler->getCommandType() == arcade::CommandType::GET_MAP) {
      ProtocolHandler->setMap(Pacman->getMap());
      ProtocolHandler->dumpMap();
    }
    else {
      event = &ProtocolHandler->getEvent();
      Pacman->receiveEvent(*event);
      if (ProtocolHandler->getCommandType() == arcade::CommandType::PLAY) {
	Pacman->isDead();
	Pacman->eat();
	Pacman->update();
      }
    }
  }
}