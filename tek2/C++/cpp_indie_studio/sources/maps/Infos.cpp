/*
** Infos.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Infos.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 03:30:06 2017 Anthony LECLERC
** Last update ven. juin 16 03:30:06 2017 Anthony LECLERC
*/

#include <iomanip>
#include "maps/MapInfo.hpp"

namespace indie {
  std::ostream &padOutput(std::ostream &os, std::uint16_t pad) {
    return (os << std::left << std::setfill(' ') << std::setw(pad));
  }

  std::ostream& operator<<(std::ostream& os, MapInfo const& infos) {
    os << "Width: ";
    padOutput(os, 9) << infos.width << "Lenght: " << infos.length << std::endl;
    padOutput(os, 16) << "Name: " << "< " << infos.name << " >" << std::endl;
    padOutput(os, 16) << "Name Path:" << "< " << infos.mapName.c_str() << " >" << std::endl;
    padOutput(os, 16) << "Screen Path:" << "< " << infos.mapDisplay.c_str() << " >" << std::endl;
    padOutput(os, 16) << "Max Players:" << "< " << infos.maxPlayers << " >" << std::endl;
    padOutput(os, 15) << "Spawn positions:";
    for (auto && pos : infos.spawns)
    {
      os << " { " << pos.X << ";" << pos.Y << " }";
    }
    os << std::endl;
    return os;
  }

  std::ostream &operator<<(std::ostream &os, TileInfo const &infos) {
    padOutput(os, 16) << "Types: " + infos.name
		      << "Texture file: " + infos.texturePath << std::endl;
    padOutput(os, 15) << "Positions:";
    for (auto && pos : infos.pos)
    {
      os << " { " << pos.X << ";" << pos.Y << " }";
    }
    os << std::endl;
    return os;
  }

  std::ostream& operator<<(std::ostream& os, MapData const& infos)
  {
    for (auto &&v : infos.walls) {
      os << v;
    }
    return os;
  }

  std::ostream &operator<<(std::ostream &os, MapAttributes const &infos) {
    return (os << infos.infos << infos.data);
  }

}
