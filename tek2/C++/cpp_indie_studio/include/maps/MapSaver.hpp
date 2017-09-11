/*
** MapSaver.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MapSaver.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 18 10:25:39 2017 Anthony LECLERC
** Last update dim. juin 18 10:25:39 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_MAPSAVER_HPP
#define CPP_INDIE_STUDIO_MAPSAVER_HPP

#include <entity/APlayer.hpp>
#include	"IJsonLoader.hpp"
#include "MapInfo.hpp"
#include "Serialize.hpp"

namespace indie {
  class MapSaver : public IJsonLoader {

  private:
    MapAttributes _attr;

    SerializePlayer _playerS;

    MapSaveInfos _infos;
    rapidjson::Document _doc;

  public:
    MapSaver(MapSaveInfos const& map);

    virtual void clear() override;

    virtual void load(std::string const &string) override;

    virtual void save(std::string const &string) override;

    virtual void open(std::string const &string) override;
  };
}


#endif //CPP_INDIE_STUDIO_MAPSAVER_HPP
