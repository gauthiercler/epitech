/*
** APowerUp.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/APowerUp.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 14 17:47:41 2017 Anthony LECLERC
** Last update mer. juin 14 17:47:41 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_APOWERUP_HPP
#define CPP_INDIE_STUDIO_APOWERUP_HPP

#include	<string>
#include        "entity/APlayer.hpp"

namespace indie {
  class APowerUp : public IEntity {
  private:
    bool _isDead;
    EntityType _type;
  protected:
    irr::scene::IAnimatedMeshSceneNode *_node;
  public:
    APowerUp(irr::scene::ISceneManager *smgr,
             std::string const& meshID);
    ~APowerUp();

    virtual irr::scene::ISceneNode *getSceneNode() const override;

    virtual void setTexture(irr::video::ITexture *texture) override;

    virtual void setVisible(bool state) override;

    virtual void update(Map &map) override;

    virtual void onDeath(Map &map) override;

    virtual bool isDead() const override;

    virtual bool setDeath(bool death) override;

    virtual bool isKillable() const override;

    virtual bool isCrossable() const override;

    /**
     * @brief Method to call on a player to set bonus/malus on him.
     * @param player Target
     */
    virtual void power(APlayer &player) = 0;

    virtual irr::scene::ITriangleSelector *
    getCollisionTriangle() const override;

    virtual EntityType getType() const;

    virtual void remove();
  };
}


#endif //CPP_INDIE_STUDIO_APOWERUP_HPP
