/*
** MapSaver.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MapSaver.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  dim. juin 18 10:25:39 2017 Anthony LECLERC
** Last update dim. juin 18 10:25:39 2017 Anthony LECLERC
*/

#include <fstream>
#include "MapSaver.hpp"
#include "rapidjson/ostreamwrapper.h"
#include "rapidjson/writer.h"

indie::MapSaver::MapSaver(MapSaveInfos const& map)
    : _infos(map)
{}

void indie::MapSaver::clear() {
  _doc.SetNull();
}

void indie::MapSaver::load(std::string const &) {

}

void indie::MapSaver::save(std::string const &file) {
  this->clear();

  std::ofstream out(file);
  _doc.SetObject();

  rapidjson::Value v(rapidjson::kObjectType);

  rapidjson::Value val;
  val.SetString(rapidjson::StringRef(_infos.attr.infos.name.c_str()));
  _doc.AddMember("name", val, _doc.GetAllocator());
  _doc.AddMember("width", rapidjson::Value(_infos.attr.infos.width), _doc.GetAllocator());
  _doc.AddMember("length", rapidjson::Value(_infos.attr.infos.length), _doc.GetAllocator());
  _doc.AddMember("map_name", rapidjson::StringRef(_infos.attr.infos.mapName.c_str()), _doc.GetAllocator());
  _doc.AddMember("map_display", rapidjson::StringRef(_infos.attr.infos.mapDisplay.c_str()), _doc.GetAllocator());
  rapidjson::Value playerArray(rapidjson::kArrayType);
  std::cout << "Players in map: " << _infos.players.size() << std::endl;
  for (auto& player : _infos.players)
  {
    rapidjson::Value playerData(rapidjson::kArrayType);
    rapidjson::Value bombProto(rapidjson::kObjectType);
    rapidjson::Value bombProtoData(rapidjson::kArrayType);
    playerData.PushBack(rapidjson::StringRef(player.name.c_str()), _doc.GetAllocator());
    playerData.PushBack(player.pos.X, _doc.GetAllocator());
    playerData.PushBack(player.pos.Z, _doc.GetAllocator());
    playerData.PushBack(player.speed, _doc.GetAllocator());
    bombProtoData.PushBack(player.proto.type, _doc.GetAllocator());
    bombProtoData.PushBack(player.max, _doc.GetAllocator());
    bombProtoData.PushBack(player.proto.power, _doc.GetAllocator());
    bombProto.AddMember("proto", bombProtoData, _doc.GetAllocator());
    rapidjson::Value bombSpawned(rapidjson::kObjectType);
    rapidjson::Value bombList(rapidjson::kArrayType);
    for (auto& bomb : player.bombs)
    {
      rapidjson::Value bInfosArray(rapidjson::kArrayType);

      bInfosArray.PushBack(bomb.pos.X, _doc.GetAllocator());
      bInfosArray.PushBack(bomb.pos.Z, _doc.GetAllocator());
      bInfosArray.PushBack(bomb.type, _doc.GetAllocator());
      bInfosArray.PushBack(bomb.power, _doc.GetAllocator());
      bInfosArray.PushBack(bomb.timer, _doc.GetAllocator());
      bombList.PushBack(bInfosArray, _doc.GetAllocator());
    }
    bombSpawned.AddMember("bombs", bombList, _doc.GetAllocator());
    playerData.PushBack(bombProto, _doc.GetAllocator());
    playerArray.PushBack(playerData, _doc.GetAllocator());
  }
  _doc.AddMember("players", playerArray, _doc.GetAllocator());
  rapidjson::Value wallList(rapidjson::kObjectType);
  std::cout << "Attributes: " << _infos.attr << std::endl;
  for (auto& bloc : _infos.attr.data.walls)
  {
    rapidjson::Value wallType(rapidjson::kObjectType);
    rapidjson::Value wallPositions(rapidjson::kArrayType);
    for (auto& pos : bloc.pos) {
      rapidjson::Value wallPos(rapidjson::kArrayType);
      wallPos.PushBack(pos.X, _doc.GetAllocator());
      wallPos.PushBack(pos.Y, _doc.GetAllocator());
      wallPositions.PushBack(wallPos, _doc.GetAllocator());
    }
    wallType.AddMember("texture", rapidjson::Value().SetString(rapidjson::StringRef(bloc.texturePath.c_str())), _doc.GetAllocator());
    wallType.AddMember("positions", wallPositions, _doc.GetAllocator());
    wallList.AddMember(rapidjson::StringRef(bloc.name.c_str()), wallType, _doc.GetAllocator());
  }
  _doc.AddMember("wall", wallList, _doc.GetAllocator());

  rapidjson::OStreamWrapper os(out);
  rapidjson::Writer<rapidjson::OStreamWrapper> writer(os);

  _doc.Accept(writer);

}

void indie::MapSaver::open(std::string const &) {

}
