/*
** MapLoader.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MapLoader.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 15 16:11:46 2017 Anthony LECLERC
** Last update jeu. juin 15 16:11:46 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_IJSONLOADER_HPP
#define CPP_INDIE_STUDIO_IJSONLOADER_HPP

#include		<string>
#include		"rapidjson/document.h"

namespace indie {
  class IJsonLoader {
  public:
    virtual ~IJsonLoader() {}

    virtual void clear() = 0;
    virtual void load(std::string const&) = 0;
    virtual void save(std::string const&) = 0;
    virtual void open(std::string const&) = 0;
  };

  struct Parser {
    using ObjectType = rapidjson::Document::ValueType;

    static bool IsJsonString(ObjectType const& object) { return object.IsString(); }
    static bool IsJsonInt(ObjectType const& object) { return object.IsInt(); }
    static bool IsJsonUint(ObjectType const& object) { return object.IsUint(); }
    static bool IsJsonArray(ObjectType const& object) { return object.IsArray(); }
    static bool IsJsonObject(ObjectType const& object) { return object.IsObject(); }
  };
}

#endif //CPP_INDIE_STUDIO_MAPLOADER_HPP
