/*
** MapLoader.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MapLoader.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 00:32:15 2017 Anthony LECLERC
** Last update ven. juin 16 00:32:15 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_MAPLOADER_HPP
#define CPP_INDIE_STUDIO_MAPLOADER_HPP

#include "MapInfo.hpp"
#include "maps/Errors.hpp"
#include "rapidjson/document.h"
#include "AJsonParser.hpp"

namespace indie {

  class MapLoader : public AJsonParser {
  private:

    MapAttributes _infos;
    std::string _name;

  public:
    MapLoader();
    virtual void clear() override;
    virtual void load(std::string const& file) override;
    virtual void save(std::string const& file) override;

    MapAttributes const& getAttributes() const;
  };
}

#endif //CPP_INDIE_STUDIO_MAPLOADER_HPP
