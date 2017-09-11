/*
** Camera.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/Camera.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 09 14:20:39 2017 Anthony LECLERC
** Last update ven. juin 09 14:20:39 2017 Anthony LECLERC
*/

#include "Camera.hpp"

indie::Camera::Camera(irr::scene::ICameraSceneNode *camera, Map const&):
    _camera(camera)
{
  _camera->setFarValue(100000);
}


irr::scene::ISceneNode *indie::Camera::getSceneNode() const
{
  return _camera;
}

void indie::Camera::setPosition(irr::core::vector3df const &pos)
{
  _camera->setPosition(pos);
}

void indie::Camera::setTexture(irr::video::ITexture *)
{}

void indie::Camera::setVisible(bool state)
{
  _camera->setVisible(state);
}

void indie::Camera::init(indie::Map const &map) {
  _camera->setTarget(map.getSceneNode()->getPosition());
  _camera->setPosition( { map.getSceneNode()->getPosition().X,
                          map.getSceneNode()->getPosition().Y + 1200,
			  static_cast<irr::f32>(map.getSceneNode()->getPosition().Z - (map.getWidth() * map.Tilesize) / 2.5)} );
}