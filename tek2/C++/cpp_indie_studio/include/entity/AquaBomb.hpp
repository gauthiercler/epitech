/*
** BlueBomb.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/entity/BlueBomb.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Wed Jun 14 15:44:26 2017 Vincent DUSAUTOIR
** Last update Wed Jun 14 15:44:26 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_BLUEBOMB_HPP
#define CPP_INDIE_STUDIO_BLUEBOMB_HPP

#include "Engine.hpp"
#include "ABomb.hpp"

namespace indie {
  class AquaBomb : public ABomb {
  public:

    /**
     * @brief Class Contructor
     * @param power see ABomb
     * @param timer see ABomb
     * @param attackTime see ABomb
     */
    AquaBomb(irr::scene::ISceneManager *smgr,
	     APlayer &player,
	     irr::u64 power = 1,
	     irr::f32 timer = 2.5,
	     irr::u64 attackTime = 2);

    virtual ~AquaBomb();


    /**
     * @brief Clone method
     * @return Pointer to copy of this instance (BasicBomb)
     */
    virtual ABomb *clone() override;

    virtual bool	killAtPos(Map &map, irr::core::vector2di pos);
  };
}

#endif //CPP_INDIE_STUDIO_BLUEBOMB_HPP
