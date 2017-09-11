/*
** MapFileManager.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MapFileManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 06:19:29 2017 Anthony LECLERC
** Last update ven. juin 16 06:19:29 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_MAPFILEMANAGER_HPP
#define CPP_INDIE_STUDIO_MAPFILEMANAGER_HPP

#include <irrlicht/path.h>
#include "maps/MapInfo.hpp"

namespace indie {
  class MapFileManager {
  private:
    std::vector<std::pair<irr::io::path, MapAttributes> > _mapsData;
  public:
    MapFileManager();
    ~MapFileManager();

    void load(irr::io::path const& cfgFile);
    std::vector<std::pair<irr::io::path, MapAttributes> > const& getFiles() const;
  };
}


#endif //CPP_INDIE_STUDIO_MAPFILEMANAGER_HPP
