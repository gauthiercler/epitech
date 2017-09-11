/*
** MeshManager.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/MeshManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 14:43:47 2017 Anthony LECLERC
** Last update jeu. mai 04 14:43:47 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_MESHMANAGER_HPP
#define CPP_INDIE_STUDIO_MESHMANAGER_HPP

#include <unordered_map>
#include <irrlicht/IrrlichtDevice.h>
#include <irrlicht/irrlicht.h>
#include "Error.hpp"
#include "VideoDriverManager.hpp"

namespace indie {
/**
 * @brief Ressource manager class
 */
  class RessourceManager {
  private:
    irr::scene::ISceneManager	*_smgr;
    irr::IrrlichtDevice		&_device;

    std::unordered_map<std::string, irr::scene::IMesh *> 		_staticMeshes;
    std::unordered_map<std::string, irr::scene::IAnimatedMesh *>	_animatedMeshes;
    std::unordered_map<std::string, irr::video::ITexture *> 		_textures;
    std::unordered_map<std::string, irr::gui::IGUIFont *>		_fonts;

    void loadStaticMesh(std::string const& path, std::string const& name);
    void loadAnimatedMesh(std::string const& path, std::string const& name);
    void loadFont(std::string const &path, std::string const &name);
    void loadMenuRessources(void);
    void load(void);

  public:
    typedef std::shared_ptr<RessourceManager> Ptr;

    void loadTexture(std::string const& path, std::string const& name);

    /**
     * @brief CLass constructor
     * @param mgr
     * @param device
     */
    RessourceManager(irr::scene::ISceneManager *mgr,
		     irr::IrrlichtDevice &device);

    /**
     * @brief Get the static mesh with name given as parameter. Throw if identifier does not exist
     * @param name
     * @return irr::scene::IMesh
     */
    irr::scene::IMesh		*getStaticMesh(std::string const& name);

    /**
     * @brief Get the dynamic mesh with name given as parameter. Throw an exception if identifier does not exist
     * @param name
     * @return irr::scene::IAnimatedMesh
     */
    irr::scene::IAnimatedMesh	*getAnimatedMesh(std::string const& name);

    /**
     * @brief Get the Texture with name given as parameter. Throw an exception if identifier does not exist
     * @param name
     * @return irr::video::ITexture
     */
    irr::video::ITexture 	*getTexture(std::string const& name);

    /**
     * @brief Get the Font with name given as parameter. Throw an exception  if identifier does not exist
     * @param name
     * @return irr::gui:IGuiFont
     */
    irr::gui::IGUIFont		*getFont(std::string const &name);

    /**
     * @brief Class Destructor
     */
    ~RessourceManager();
  };
}

#endif //CPP_INDIE_STUDIO_MESHMANAGER_HPP
