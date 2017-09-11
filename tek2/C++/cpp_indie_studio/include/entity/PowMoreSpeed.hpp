/*
** PowMoreSpeed.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/entity/PowMoreSpeed.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 23:07:56 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 23:07:56 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_POWMORESPEED_HPP
#define CPP_INDIE_STUDIO_POWMORESPEED_HPP

#include "APowerUp.hpp"

namespace indie {
  class PowMoreSpeed : public APowerUp {
  public:
    PowMoreSpeed(irr::scene::ISceneManager *smgr);
    virtual void power(APlayer &player) override;
  };
}

#endif //CPP_INDIE_STUDIO_POWMORESPEED_HPP
