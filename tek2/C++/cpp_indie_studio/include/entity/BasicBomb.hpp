/*
** BasicBomb.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/BasicBomb.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  sam. juin 10 14:18:53 2017 Anthony LECLERC
** Last update sam. juin 10 14:18:53 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_BASICBOMB_HPP
# define CPP_INDIE_STUDIO_BASICBOMB_HPP

#include "Engine.hpp"
#include "ABomb.hpp"

namespace indie {
  class BasicBomb : public ABomb {
  public:

    /**
     * @brief Class Contructor
     * @param power see ABomb
     * @param timer see ABomb
     * @param attackTime see ABomb
     */
    BasicBomb(irr::scene::ISceneManager *smgr,
	      APlayer &player,
              irr::u64 power = 1,
              irr::f32 timer = 2.5,
              irr::u64 attackTime = 2);

    virtual ~BasicBomb();

    /**
     * @brief Clone method
     * @return Pointer to copy of this instance (BasicBomb)
     */
    virtual ABomb *clone() override;

  };
}

#endif //CPP_INDIE_STUDIO_BASICBOMB_HPP
