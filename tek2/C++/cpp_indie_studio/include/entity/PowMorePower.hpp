/*
** PowMorePower.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/entity/PowMorePower.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 09:30:11 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 09:30:11 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_POWMOREPOWER_HPP
# define CPP_INDIE_STUDIO_POWMOREPOWER_HPP

#include "APowerUp.hpp"

namespace indie {
  class PowMorePower : public APowerUp {
  public:
    PowMorePower(irr::scene::ISceneManager *smgr);
    virtual void power(APlayer &player) override;
  };
}

#endif //CPP_INDIE_STUDIO_POWMOREPOWER_HPP
