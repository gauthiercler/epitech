/*
** MapInfo.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MapInfo.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 15 16:14:02 2017 Anthony LECLERC
** Last update jeu. juin 15 16:14:02 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_MAPINFO_HPP
# define CPP_INDIE_STUDIO_MAPINFO_HPP

#include	<iostream>
#include	<irrlicht/irrTypes.h>
#include	<vector>
#include        <list>
#include	<string>
#include	<irrlicht/vector2d.h>
#include        <irrlicht/path.h>
#include <game/IA.hpp>

namespace indie {
  struct MapInfo {

    std::string name;
    irr::io::path mapName;
    irr::io::path mapDisplay;
    irr::u32 maxPlayers;
    irr::u32 width;
    irr::u32 length;
    std::list<irr::core::vector2di> spawns;
  };

  struct TileInfo {
    std::string name;
    std::string texturePath;
    std::vector<irr::core::vector2di> pos;
  };

  struct MapData {
    std::vector<TileInfo> walls;
    std::vector<std::string> powerUps;
  };

  struct MapAttributes {
    MapInfo infos;
    MapData data;
  };

  struct BombInfo {
    irr::core::vector3df pos;
    irr::u64 power;
    irr::f32 timer;
    irr::u32 type;
  };

  union PlayerType {
    IADiff bind;
    irr::u32 id;
  };

  struct PlayerInfos {
    std::vector<BombInfo> bombs;
    irr::u64 max;
    irr::u64 speed;
    BombInfo proto;
    irr::core::vector3df pos;
    size_t score;
    std::string name;
    PlayerType infos;
    bool isIA;
  };

  struct MapSaveInfos {
    MapAttributes attr;
    std::vector<PlayerInfos> players;
  };

  std::ostream &operator<<(std::ostream &os, MapInfo const &infos);
  std::ostream &operator<<(std::ostream &os, MapData const &infos);
  std::ostream &operator<<(std::ostream &os, TileInfo const& infos);
  std::ostream &operator<<(std::ostream &os, MapAttributes const& infos);
}

#endif //CPP_INDIE_STUDIO_MAPINFO_HPP
