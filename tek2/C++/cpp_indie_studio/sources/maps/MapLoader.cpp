/*
** MapLoader.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MapLoader.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 00:34:26 2017 Anthony LECLERC
** Last update ven. juin 16 00:34:26 2017 Anthony LECLERC
*/

#include		<iostream>
#include		<fstream>
#include 		<maps/Errors.hpp>
#include                <Engine.hpp>
#include		"maps/MapLoader.hpp"
#include		"rapidjson/istreamwrapper.h"

void indie::MapLoader::load(std::string const &file) {
  this->open(file);
  this->_name = file;
  this->_infos.infos.name = this->getMember(_doc, "name", Parser::IsJsonString).GetString();
  this->_infos.infos.mapName = this->getMember(_doc, "map_name", Parser::IsJsonString).GetString();
  this->_infos.infos.mapDisplay = this->getMember(_doc, "map_display", Parser::IsJsonString).GetString();
  this->_infos.infos.maxPlayers = this->getMember(_doc, "playersMax", Parser::IsJsonUint).GetUint();
  this->_infos.infos.width = this->getMember(_doc, "width", Parser::IsJsonUint).GetUint();
  this->_infos.infos.length = this->getMember(_doc, "length", Parser::IsJsonUint).GetUint();
  auto spawnArray = this->getMember(_doc, "spawns", Parser::IsJsonArray).GetArray();
  if (spawnArray.Capacity() != this->_infos.infos.maxPlayers)
    throw ParserInvalidMember(file + ": Invalid number of spawn points");

  auto parseCoords = [&, this](auto &vt, auto &field) {
      for (auto&& spawnPoint : field) {
	if (spawnPoint.Capacity() != 2)
	  throw ParserInvalidMember(file + ": Invalid number of coordinates for spawn point");
	vt.emplace_back(getMember(spawnPoint[0], Parser::IsJsonUint).GetUint(),
					       getMember(spawnPoint[1], Parser::IsJsonUint).GetUint());
	if (vt.back().X > static_cast<int>(this->_infos.infos.width)) throw ParserInvalidValue("Entity pos X");
      }
  };

  parseCoords(this->_infos.infos.spawns, spawnArray);

  auto wallProps = getMember(_doc, "wall", Parser::IsJsonObject).GetObject();

  auto parseBox = [&](char const  *scope) {
      TileInfo tile;
      auto field = getMember(wallProps, scope, Parser::IsJsonObject).GetObject();
      tile.texturePath = getMember(field, "texture", Parser::IsJsonString).GetString();

      std::size_t last = tile.texturePath.find_last_of("/\\");
      std::string textureID = tile.texturePath.substr(last + 1);
      Engine::get().getRessourceManager().loadTexture(tile.texturePath, textureID);
      tile.texturePath = textureID;

      auto posArray = getMember(field, "positions", Parser::IsJsonArray).GetArray();
      parseCoords(tile.pos, posArray);
      tile.name = scope;
      _infos.data.walls.push_back(tile);
  };
  parseBox("Brick");
  parseBox("Box");
}

void indie::MapLoader::save(std::string const &) {
// TODO: static_cast<void>(Issou)
}

indie::MapLoader::MapLoader() :
    AJsonParser()
{}

void indie::MapLoader::clear() {
  _infos = MapAttributes();
  _name = std::string();
}

indie::MapAttributes const &indie::MapLoader::getAttributes() const {
  return _infos;
}
