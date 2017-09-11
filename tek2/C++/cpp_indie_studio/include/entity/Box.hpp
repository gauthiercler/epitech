/*
** Box.hpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/include/entity/Box.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 12 16:49:45 2017 Gauthier Cler
** Last update Mon Jun 12 16:49:46 2017 Gauthier Cler
*/

#ifndef CPP_INDIE_STUDIO_BOX_HPP
# define CPP_INDIE_STUDIO_BOX_HPP

#include "ACube.hpp"

namespace indie {
  class Box : public ACube {
  public:
    Box(irr::scene::ISceneManager *smgr);
    virtual ~Box();

    virtual void onDeath(Map &map) override;
  };
}

#endif /* !CPP_INDIE_STUDIO_BOX_HPP*/
