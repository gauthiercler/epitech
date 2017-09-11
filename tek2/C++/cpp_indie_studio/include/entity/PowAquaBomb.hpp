/*
** PowAquaBomb.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/entity/PowAquaBomb.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 15 22:18:02 2017 Vincent DUSAUTOIR
** Last update Thu Jun 15 22:18:02 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_POWAQUABOMB_HPP
#define CPP_INDIE_STUDIO_POWAQUABOMB_HPP

#include "APowerUp.hpp"

namespace indie {
  class PowAquaBomb : public APowerUp {
  public:
    PowAquaBomb(irr::scene::ISceneManager *smgr);
    virtual void power(APlayer &player) override;
  };
}

#endif //CPP_INDIE_STUDIO_POWAQUABOMB_HPP
