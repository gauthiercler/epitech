/*
** PowMoreBomb.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/PowMoreBomb.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 14 21:02:18 2017 Anthony LECLERC
** Last update mer. juin 14 21:02:18 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_POWMOREBOMB_HPP
#define CPP_INDIE_STUDIO_POWMOREBOMB_HPP

#include "APowerUp.hpp"

namespace indie {
  class PowMoreBomb : public APowerUp {
  public:
    PowMoreBomb(irr::scene::ISceneManager *smgr);
    virtual void power(APlayer &player) override;
  };
}


#endif //CPP_INDIE_STUDIO_POWMOREBOMB_HPP
