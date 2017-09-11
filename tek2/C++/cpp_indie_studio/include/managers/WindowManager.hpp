/*
** WindowManager.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/WindowManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:04:42 2017 Anthony LECLERC
** Last update jeu. mai 04 15:04:42 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_WINDOWMANAGER_HPP
#define CPP_INDIE_STUDIO_WINDOWMANAGER_HPP

#include <irrlicht/irrlicht.h>
#include <string>
#include "VideoDriverManager.hpp"
#include "RessourceManager.hpp"

namespace indie {

  /**
   * @brief Window Manager
   */
  class WindowManager {
  private:
    irr::IrrlichtDevice *_device;
  public:

    /**
     * @brief Class constructor
     * @param width
     * @param height
     * @param caption
     * @param fullscreen
     */
    WindowManager(const irr::u32 width,
		  const irr::u32 height,
		  const std::wstring &caption,
		  const bool fullscreen = false);

    /**
     * @brief Class default constructor
     */
    WindowManager();

    /**
     * @brief Class constructor
     */
    ~WindowManager();

    /**
     * @brief Run the window
     * @return bool
     */
    bool			run();

    /**
     * @brief Stat the scene rendering
     * @return bool
     */
    bool			beginScene();

    /**
     * @brief End the scene rendering
     * @return bool
     */
    bool			endScene();

    void			setGUITransparency(irr::u32 alpha);

    /**
     * @brief Return the
     * @return irr::IrrlichtDevice &
     */
    irr::IrrlichtDevice		&getDevice() const;
  };
}

#endif //CPP_INDIE_STUDIO_WINDOWMANAGER_HPP
