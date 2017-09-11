/*
** Brick.cpp for cpp_indie_studio in /home/gogo/rendu/tek2/cpp_indie_studio/sources/entity/Brick.cpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 12 18:10:10 2017 Gauthier Cler
** Last update Mon Jun 12 18:10:11 2017 Gauthier Cler
*/

#include <irrlicht/ISceneManager.h>
#include <entity/Brick.hpp>

indie::Brick::Brick(irr::scene::ISceneManager *smgr) : ACube(smgr, "brick", false, false, EntityType::BRICK){

}

indie::Brick::~Brick() {

}
