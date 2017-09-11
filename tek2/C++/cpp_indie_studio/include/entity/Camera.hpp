/*
** Camera.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Camera.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 09 14:20:39 2017 Anthony LECLERC
** Last update ven. juin 09 14:20:39 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_CAMERA_HPP
#define CPP_INDIE_STUDIO_CAMERA_HPP

#include	<irrlicht/ICameraSceneNode.h>
#include	"IEntity.hpp"
#include 	"game/Map.hpp"

namespace indie {
  class Camera
  {
  private:
    irr::scene::ICameraSceneNode *_camera;
  public:
    Camera(irr::scene::ICameraSceneNode *camera, Map const& map);

    virtual ~Camera() {};

    void init(Map const& map);

    virtual irr::scene::ISceneNode *getSceneNode() const;

    virtual void setPosition(irr::core::vector3df const &pos);

    virtual void setTexture(irr::video::ITexture *texture);

    virtual void setVisible(bool state);

  };
}

#endif //CPP_INDIE_STUDIO_CAMERA_HPP
