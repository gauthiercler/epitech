/*
** WindowManager.cpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/WindowManager.cpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:04:42 2017 Anthony LECLERC
** Last update jeu. mai 04 15:04:42 2017 Anthony LECLERC
*/

#include "Error.hpp"
#include "managers/WindowManager.hpp"

indie::WindowManager::WindowManager(const irr::u32 width, const irr::u32 height,
				    const std::wstring &caption,
				    const bool fullscreen) :
    _device(nullptr)
{
  irr::SIrrlichtCreationParameters params = irr::SIrrlichtCreationParameters();
  params.AntiAlias = 2;
  params.DriverType = irr::video::EDT_OPENGL;
  params.WindowSize = irr::core::dimension2d<irr::u32>(width, height);
  params.Fullscreen = fullscreen;
  params.EventReceiver = nullptr;
  params.HighPrecisionFPU = false;
  params.Vsync = true;
  params.Stencilbuffer = true;
  this->_device = irr::createDeviceEx(params);
  if (!this->_device)
    throw IrrlichtError("Device can not be initialize");
  this->_device->setWindowCaption(caption.c_str());
}

indie::WindowManager::~WindowManager() {
}

bool indie::WindowManager::run() {
  return this->_device->run();
}

irr::IrrlichtDevice &indie::WindowManager::getDevice() const {
  return *this->_device;
}

bool indie::WindowManager::beginScene() {
  return this->getDevice().getVideoDriver()->beginScene(true, true, 0);
}

bool indie::WindowManager::endScene() {
  return this->getDevice().getVideoDriver()->endScene();
}

indie::WindowManager::WindowManager() {

}

void indie::WindowManager::setGUITransparency(irr::u32 alpha) {
  irr::video::SColor		color;

  for (irr::s32 iterator = 0 ; iterator < irr::gui::EGDC_COUNT ; iterator++) {
    this->getDevice().getGUIEnvironment()->getSkin()->getColor(static_cast<irr::gui::EGUI_DEFAULT_COLOR>(iterator));
    color.setAlpha(alpha);
    this->getDevice().getGUIEnvironment()->getSkin()->setColor(static_cast<irr::gui::EGUI_DEFAULT_COLOR>(iterator), color);
  }
}