/*
** Serialize.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Serialize.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 16 13:07:55 2017 Anthony LECLERC
** Last update ven. juin 16 13:07:55 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_SERIALIZE_HPP
#define CPP_INDIE_STUDIO_SERIALIZE_HPP

#include <memory>
#include <entity/APlayer.hpp>
#include "MapInfo.hpp"

namespace indie {

  class SerializeMap {
    typedef MapAttributes In;
  };

  class SerializeBomb {
  public:
    typedef ABomb In;
    typedef BombInfo Out;
  public:
    Out& serialize(Out& out, In const& data) const;
    Out&& serialize(In const& data) const;
  };

  class SerializePlayer {
  public:
    typedef std::shared_ptr<APlayer> In;
    typedef PlayerInfos Out;

    Out& serialize(Out& out, In const& data) const;
    Out&& serialize(In const& data) const;
  };

}

#endif //CPP_INDIE_STUDIO_SERIALIZE_HPP
