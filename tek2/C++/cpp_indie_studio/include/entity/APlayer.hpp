/*
** APlayer.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/APlayer.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. juin 15 20:44:41 2017 Anthony LECLERC
** Last update jeu. juin 15 20:44:41 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_APLAYER_HPP
#define CPP_INDIE_STUDIO_APLAYER_HPP

#include <game/Score.hpp>
#include "IrrlichtWrapper.hpp"
#include "IBombSpawner.hpp"
#include "IMutableEntity.hpp"


namespace indie {
  class IPlayerController;

  class APlayer : public IMutableEntity {
  protected:
    irr::scene::IAnimatedMeshSceneNode	*_node;
    irr::scene::ISceneNodeAnimatorCollisionResponse *_collision;
    std::string _textureID;

    BombSpawner _bombSpawn;
    std::string _name;

    bool 	_running;
    bool	_dropping;
    bool	_goDrop;
    bool	_isDead;
    size_t	_speed;
    Score	_score;

  public:

    APlayer(irr::scene::ISceneManager *scene,
    std::string const& meshID,
	std::string const& textureID = "",
	std::string const& name = "HumanPlayer",
	    bool visible = true);
    virtual ~APlayer();

    virtual irr::scene::ISceneNode *getSceneNode() const override;
    virtual void	setTexture(irr::video::ITexture *texture) override;

    void 		move(irr::core::vector3df const& );
    void 		putBomb();
    void 		run();
    void 		stand();
    bool		isRunning() const;
    bool		isDropping() const;
    void		updateDropAnimation();
    void 		setBombType(std::unique_ptr<ABomb> proto);
    void		addBomb();
    void		addPower(int value);
    void		addMalus(int value);
    void		addSpeed(int mod);

    size_t		getSpeed() const;

    virtual irr::scene::ITriangleSelector *getCollisionTriangle() const override;
    virtual void 	onDeath(Map &map);
    virtual bool 	isDead() const;
    virtual void 	setMesh(irr::scene::IAnimatedMesh *mesh);

    virtual bool 	setDeath(bool death);

    virtual bool 	isKillable() const;
    virtual bool 	isCrossable() const;

    virtual EntityType	getType() const;
    const std::string	&getName() const;
    Score		&getScore();
    BombSpawner		&getSpawner() ;
    virtual void	remove();
  };
}


#endif //CPP_INDIE_STUDIO_APLAYER_HPP
