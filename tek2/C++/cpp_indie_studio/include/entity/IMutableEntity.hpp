/*
** IMutableEntity.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/IMutableEntity.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juin 10 14:10:50 2017 Anthony LECLERC
** Last update sam. juin 10 14:10:50 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_IMUTABLEENTITY_HPP
#define CPP_INDIE_STUDIO_IMUTABLEENTITY_HPP

#include "IEntity.hpp"

namespace indie {
  class IMutableEntity : public IEntity {
  public:
    virtual ~IMutableEntity() {}

    virtual void setMesh(irr::scene::IAnimatedMesh *mesh) = 0;

  };
}


#endif //CPP_INDIE_STUDIO_IMUTABLEENTITY_HPP
