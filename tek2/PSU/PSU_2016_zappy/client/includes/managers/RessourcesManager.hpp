/*
** RessourceManager.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/includes/managers/RessourceManager.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Jun 20 17:39:50 2017 Vincent DUSAUTOIR
** Last update Tue Jun 20 17:39:50 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_RESSOURCEMANAGER_HPP
#define PSU_2016_ZAPPY_RESSOURCEMANAGER_HPP

#include <string>
#include <SFML/Graphics/Font.hpp>
#include <map>
#include <memory>

namespace	zappy {
  class			RessourcesManager{
    std::map<std::string, std::shared_ptr<sf::Font>> _fonts;
    std::map<std::string, std::shared_ptr<sf::Texture>> _textures;
    std::vector<std::pair<double, std::string>>		_floors;

  public:
    RessourcesManager();
    ~RessourcesManager();

    void			load();
    void			loadFont(const std::string &path, const std::string &name);
    std::shared_ptr<sf::Font>	getFont(const std::string &name);
    void			loadTexture(const std::string &path, const std::string &name);
    std::shared_ptr<sf::Texture>	getTexture(const std::string &name);
    std::string			getRandomFloor();
  };
}

#endif //PSU_2016_ZAPPY_RESSOURCEMANAGER_HPP
