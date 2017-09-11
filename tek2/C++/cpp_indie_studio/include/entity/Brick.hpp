/*
** Brick.hpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/include/entity/Brick.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 12 18:09:14 2017 Gauthier Cler
** Last update Mon Jun 12 18:09:14 2017 Gauthier Cler
*/

#ifndef CPP_INDIE_STUDIO_BRICK_HPP
# define CPP_INDIE_STUDIO_BRICK_HPP

#include "ACube.hpp"

namespace indie {
  class Brick : public ACube {
  public:
    Brick(irr::scene::ISceneManager *smgr);
    virtual ~Brick();
  };
}

#endif /* !CPP_INDIE_STUDIO_BRICK_HPP*/
