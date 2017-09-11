/*
** MapManager.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MapManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:28:06 2017 Anthony LECLERC
** Last update jeu. mai 04 15:28:06 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_MAPMANAGER_HPP
#define CPP_INDIE_STUDIO_MAPMANAGER_HPP

#include <string>
#include <cstdint>
#include <list>
#include <memory>
#include <maps/MapInfo.hpp>
#include "Map.hpp"

namespace indie {
  /**
   * @brief Map Manager.
   */
  class Map;
  class APlayer;

  class MapManager {

  public:
    MapManager(irr::scene::ISceneManager *smgr);

    virtual ~MapManager();

    enum class MapTile {
      EMPTY = 0,
      BLOCK,
      BRICK,
      BOMB,
      BONUS,
      MAX_VALUE
    };

    void	displayMap() const;
    void	generate(irr::s32 sizeX = _minMapSize, irr::s32 sizeY = _minMapSize, double density = 0.5);
    void        generate(MapAttributes const& attr);
    std::shared_ptr<Map>        create(CollisionManager &Collmgr);
    bool        setPlayer(std::shared_ptr<APlayer> player);

    std::shared_ptr<Map>        getMap();
    std::vector<std::vector<MapTile> > const& get() const;
    void	set(uint64_t x, uint64_t y, MapTile item);

  private:
    irr::scene::ISceneNode		*_root;
    double				_density;
    bool				_hasMap;
    std::shared_ptr<Map>		_map;
    MapAttributes 			_attr;
    std::vector<std::vector<MapTile>>	_mapi;
    const static irr::s32		_minMapSize = 11;

    irr::video::ITexture    *_brickT;
    irr::video::ITexture    *_boxT;
    void	reset();
    void	generateBricks();
    void	generateBlocks();
    void        generateBorders();
    uint64_t	getLineEmptyCells(const std::vector<MapTile> &line) const;
    void	genPlayerSpawn();
    bool	isBorder(uint64_t posX, uint64_t posY) const;
  };
}


#endif //CPP_INDIE_STUDIO_MAPMANAGER_HPP
