/*
** PowSkullMalus.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/entity/PowSkullMalus.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 22:55:39 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 22:55:39 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_POWSKULLMALUS_HPP
#define CPP_INDIE_STUDIO_POWSKULLMALUS_HPP

#include "APowerUp.hpp"

namespace indie {
  class PowSkullMalus : public APowerUp {
  public:
    PowSkullMalus(irr::scene::ISceneManager *smgr);
    virtual void power(APlayer &player) override;
  };
}

#endif //CPP_INDIE_STUDIO_POWSKULLMALUS_HPP
