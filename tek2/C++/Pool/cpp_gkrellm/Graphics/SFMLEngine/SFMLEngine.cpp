/*
** SFMLEngine.cpp for cpp_gkrellm in /home/foret_a/Lab/cpp_gkrellm/Graphics/SFMLEngine/SFMLEngine.cpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 21 12:01:55 2017 Antoine FORET
** Last update Sat Jan 21 12:01:55 2017 Antoine FORET
*/

# include <iostream>
# include "SFMLEngine.hpp"
# include "Config/Config.hpp"

SFMLEngine::SFMLEngine(const std::vector<IMonitorModule *> &modules) : _window(nullptr), _moduleBuffer(nullptr), _titleModules{nullptr, nullptr, nullptr}, _selectedIndex(0), _inOption(false), _haveToReload(true) {
  this->_window = new sf::RenderWindow(sf::VideoMode(Config::width, Config::height), Config::name, sf::Style::Titlebar | sf::Style::Close);
  this->_moduleBuffer = new sf::RenderTexture();
  if (this->_window == nullptr || this->_moduleBuffer == nullptr ||
      !this->_moduleBuffer->create(Config::width, Config::moduleHeight))
    throw std::exception();
  if (!this->_font.loadFromFile(Config::fontPath))
    std::clog << "[Warning] Unable to load font " << Config::fontPath << std::endl;
  if (!this->_settingTexture.loadFromFile(Config::settingPath))
    std::clog << "[Warning] Unable to load image " << Config::settingPath << std::endl;
  if (!this->_settingsAsserts[0].loadFromFile(Config::checkedPath))
    std::clog << "[Warning] Unable to load image " << Config::checkedPath << std::endl;
  if (!this->_settingsAsserts[1].loadFromFile(Config::crossedPath))
    std::clog << "[Warning] Unable to load image " << Config::crossedPath << std::endl;
  this->_settingsAsserts[0].setSmooth(true);
  this->_settingsAsserts[1].setSmooth(true);
  this->_settingsSprites[0].setTexture(this->_settingsAsserts[0]);
  this->_settingsSprites[1].setTexture(this->_settingsAsserts[1]);
  this->_settingsSprites[0].setScale(0.1, 0.1);
  this->_settingsSprites[1].setScale(0.05, 0.05);
  this->_settingTexture.setSmooth(true);
  this->_settingSprite.setTexture(this->_settingTexture);
  this->_settingSprite.setScale(0.25, 0.25);
  this->_settingSprite.setPosition(Config::width - 40, (Config::height - Config::moduleHeight) / 2 - 14);
  this->_moduleSprite.setTexture(this->_moduleBuffer->getTexture());
  this->_moduleSprite.setPosition(0, Config::height - Config::moduleHeight);
  this->_window->setFramerateLimit(20);
  this->_writter.setFont(this->_font);

  this->reloadBar(modules);

  std::clog << "[Info] SFMLEngine setup with 20 as framerate" << std::endl;
}

SFMLEngine::~SFMLEngine() {
  if (this->_window != nullptr)
    delete this->_window;
  std::clog << "[Info] SFMLEngine deleted" << std::endl;
}

bool SFMLEngine::display(const std::vector<IMonitorModule *> &modules,
			 const std::vector<IMonitorModule *> &registeredModules) {
  if (this->_haveToReload)
    this->reloadBar(modules);
  this->_window->clear(sf::Color(44, 62, 80));
  this->_moduleBuffer->clear(sf::Color(52, 74, 94));
  if (this->_titleModules[1] != nullptr && !this->_inOption)
    this->_titleModules[1]->display(*this->_moduleBuffer, this->_writter);
  else
    this->displayOptions(registeredModules);
  this->displayModuleTitle();
  this->_window->draw(this->_settingSprite);
  this->_window->draw(this->_moduleSprite);
  this->_window->display();
  this->eventManager(modules, registeredModules);
  return true;
}

bool SFMLEngine::isOpen() const {
  return this->_window->isOpen();
}

void SFMLEngine::eventManager(const std::vector<IMonitorModule *> &modules,
			      const std::vector<IMonitorModule *> &registeredModules) {
  sf::Event event;

  while (this->_window->pollEvent(event)) { // Manage each current event
    switch (event.type) {
      case sf::Event::Closed:
	this->_window->close();
	break;
      case sf::Event::MouseButtonPressed:
	this->manageClick(modules, registeredModules);
	break;
      default:
	break;
    }
  }
}

void SFMLEngine::displayModules(const std::vector<IMonitorModule *> &modules) {
  std::vector<IMonitorModule *>::const_iterator it = modules.begin();
  unsigned int index = 0;

  while (it != modules.end())
  {
    if ((*it)->isEnabled())
    {
      (*it)->display(*this->_moduleBuffer, this->_writter);
      index++;
    }
    ++it;
  }
  this->_window->draw(this->_moduleSprite);
  this->_window->draw(this->_writter);
}

void SFMLEngine::displayModuleTitle()
{
  sf::Vector2<float> mousePos(sf::Mouse::getPosition(*this->_window));

  if (this->_titleModules[0] != nullptr)
  {
    this->configWrite(this->_titleModules[0]->getIdentifier(),		// Label
		      (Config::width - 110) / 6 * 1,			// x
		      (Config::height - Config::moduleHeight) / 2,	// y
		      sf::Color(189, 195, 199),				// Basic color
		      sf::Color(236, 240, 231),				// Hover color
		      sf::Text::Regular,				// Style
		      0.5);						// Scale
    this->_titlePos[0] = this->_writter.getGlobalBounds();
    this->_window->draw(this->_writter);
  }

  if (this->_titleModules[2] != nullptr)
  {
    this->configWrite(this->_titleModules[2]->getIdentifier(),
		      (Config::width - 110) / 6 * 5,
		      (Config::height - Config::moduleHeight) / 2,
		      sf::Color(189, 195, 199),
		      sf::Color(236, 240, 231),
		      sf::Text::Regular,
		      0.5);
    this->_titlePos[2] = this->_writter.getGlobalBounds();
    this->_window->draw(this->_writter);
  }

  if (this->_titleModules[1] != nullptr)
  {
    this->configWrite(this->_titleModules[1]->getIdentifier(),
		      (Config::width - 110) / 2,
		      (Config::height - Config::moduleHeight) / 2,
		      sf::Color(236, 240, 231),
		      sf::Color(236, 240, 231),
		      sf::Text::Regular,
		      1);
    this->_titlePos[1] = this->_writter.getGlobalBounds();
    this->_window->draw(this->_writter);
  }
}

void SFMLEngine::configWrite(const std::string &label,
			      unsigned int x,
			      unsigned int y,
			      sf::Color color,
			      sf::Color hovered,
			      sf::Text::Style style,
			      float scale)
{
  sf::Vector2<float> mousePos(sf::Mouse::getPosition(*this->_window));

  this->_writter.setString(label);
  this->_writter.setColor(color);
  this->_writter.setScale(scale, scale);
  this->_writter.setStyle(style);

  float size_x = this->_writter.getLocalBounds().width * this->_writter.getScale().x;
  float size_y = this->_writter.getLocalBounds().height * this->_writter.getScale().y;

  this->_writter.setPosition(x - size_x / 2, y - size_y / 2);
  if (this->_writter.getGlobalBounds().contains(mousePos))
    this->_writter.setColor(hovered);
}

void SFMLEngine::manageClick(const std::vector<IMonitorModule *> &modules,
			     const std::vector<IMonitorModule *> &registeredModules) {
  sf::Vector2<float> mousePos(sf::Mouse::getPosition(*this->_window));

  if (this->_titlePos[0].contains(mousePos) && this->_titleModules[0] != nullptr)
  {
    this->_titleModules[2] = (this->_titleModules[1] != nullptr && this->_titleModules[1]->isEnabled()) ? this->_titleModules[1] : nullptr;
    this->_titleModules[1] = (this->_titleModules[0] != nullptr && this->_titleModules[0]->isEnabled()) ? this->_titleModules[0] : nullptr;
    this->_titleModules[0] = this->prevModule(this->_titleModules[0], modules);
  } else if (this->_titlePos[2].contains(mousePos) && this->_titleModules[2] != nullptr)
  {
    this->_titleModules[0] = (this->_titleModules[1] != nullptr && this->_titleModules[1]->isEnabled()) ? this->_titleModules[1] : nullptr;
    this->_titleModules[1] = (this->_titleModules[2] != nullptr && this->_titleModules[2]->isEnabled()) ? this->_titleModules[2] : nullptr;
    this->_titleModules[2] = this->nextModule(this->_titleModules[2], modules);
  } else if (this->_settingSprite.getGlobalBounds().contains(mousePos))
    this->_inOption = !this->_inOption;
  else if (this->_inOption || modules.size() == 0)
  {
    int elem = static_cast<int>(mousePos.y - (Config::height - Config::moduleHeight) - 50) / 30;
    if (registeredModules.size() > (unsigned int)elem && elem >= 0)
    {
      if (registeredModules[elem]->isEnabled())
	registeredModules[elem]->disable();
      else
	registeredModules[elem]->enable();
      this->_haveToReload = true;
    }
  }
}

IMonitorModule *SFMLEngine::nextModule(IMonitorModule *base, const std::vector<IMonitorModule *> &modules) {
  std::vector<IMonitorModule *>::const_iterator it = modules.begin();

  while (it != modules.end())
  {
    if (*it == base)
    {
      ++it;
      if (it != modules.end())
	return *it;
      else
	return (modules.begin() != modules.end()) ? *modules.begin() : nullptr;
    }
    ++it;
  }
  return (modules.begin() != modules.end() && modules.begin() != it) ? *modules.begin() : nullptr;
}

IMonitorModule *SFMLEngine::prevModule(IMonitorModule *base, const std::vector<IMonitorModule *> &modules) {
  std::vector<IMonitorModule *>::const_iterator it = modules.begin();

  while (it != modules.end())
  {
    if (*it == base && it != modules.begin())
    {
      --it;
      return *it;
    }
    ++it;
  }
  return (modules.begin() != modules.end() && it != modules.begin()) ? *(modules.end() - 1) : nullptr;
}

void SFMLEngine::displayOptions(const std::vector<IMonitorModule *> &modules) {
  float y = 50;
  std::vector<IMonitorModule *>::const_iterator it = modules.begin();

  this->_writter.setScale(0.75, 0.75);
  while (it != modules.end())
  {
    if ((*it)->isEnabled())
    {
      this->_settingsSprites[0].setPosition(10, y - (this->_settingsSprites[0].getLocalBounds().height * this->_settingsSprites[0].getScale().y) / 4);
      this->_moduleBuffer->draw(this->_settingsSprites[0]);
    }
    else
    {
      this->_settingsSprites[1].setPosition(10, y- (this->_settingsSprites[1].getLocalBounds().height * this->_settingsSprites[1].getScale().y) / 4);
      this->_moduleBuffer->draw(this->_settingsSprites[1]);
    }
    this->_writter.setString((*it)->getIdentifier());
    this->_writter.setPosition(40, y - (this->_writter.getLocalBounds().height * this->_writter.getScale().y) / 2);
    this->_moduleBuffer->draw(this->_writter);
    y += 30;
    ++it;
  }
}

void SFMLEngine::reloadBar(const std::vector<IMonitorModule *> &modules) {
  this->_titleModules[0] = nullptr;
  this->_titleModules[1] = nullptr;
  this->_titleModules[2] = nullptr;

  if (modules.begin() != modules.end() && (modules.begin() + 1) != modules.end())
  {
    this->_titleModules[2] = *(modules.begin() + 1);
    this->_titleModules[0] = *(modules.end() - 1);
  }
  if (modules.begin() != modules.end())
    this->_titleModules[1] = *modules.begin();
  this->_haveToReload = false;
}
