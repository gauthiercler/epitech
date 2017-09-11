/*
** MapFileManager.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MapFileManager.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 06:19:29 2017 Anthony LECLERC
** Last update ven. juin 16 06:19:29 2017 Anthony LECLERC
*/

#include <maps/MapLoader.hpp>
#include <Engine.hpp>
#include <maps/ConfigMapLoader.hpp>
#include <maps/MapSaver.hpp>
#include "maps/MapFileManager.hpp"

indie::MapFileManager::MapFileManager() {

}

indie::MapFileManager::~MapFileManager() {

}

void indie::MapFileManager::load(irr::io::path const& mapConfig) {
  ConfigMapLoader config;

  try {
    config.load(mapConfig.c_str());
  }
  catch (ParserExcept const& e)
  {
    std::cerr << "Config file parse error" << std::endl;
    throw IrrlichtError(std::string(e.what()) + ": Error when reading config file '" + mapConfig.c_str() + "'");
  }
  MapLoader mapLoader;
  for (auto&& path : config.getMapFiles())
  {
    try {
      MapSaveInfos saveInfo;

      mapLoader.load(config.getMapsDirectory().c_str() + std::string("/") + path.c_str());

      saveInfo.attr = mapLoader.getAttributes();
      /// TODO: Map data
      _mapsData.emplace_back(path.c_str(), mapLoader.getAttributes());
      PlayerInfos player;
      player.infos.id = 1;
      player.pos.X = 2;
      player.pos.Z = 3;
      player.speed = 2;
      player.isIA = false;
      player.score = 100;
      player.name = "issou";
      /// TODO: Bombs info
      BombInfo bomb;
      bomb.power = 3;
      bomb.type = 1;
      bomb.pos = {5.0, 0, 7.0};
      bomb.timer = 3;
      player.proto = bomb;
      saveInfo.players.push_back(player);
      MapSaver save(saveInfo);
      save.save("maps/test.json.save");
      std::cout << mapLoader.getAttributes() << std::endl;

    }
    catch (ParserExcept const& e)
    {
      std::cerr << e.what() << "Ignoring file" << std::endl;
    }
  }

}

std::vector<std::pair<irr::io::path, indie::MapAttributes>> const &
indie::MapFileManager::getFiles() const {
  return _mapsData;
}
