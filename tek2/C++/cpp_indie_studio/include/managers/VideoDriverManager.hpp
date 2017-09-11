/*
** VideoDriverManager.hpp for cpp_indie_studio in /home/ventinc/epitech/cpp/cpp_indie_studio/include/managers/VideoDriverManager.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Fri May 05 12:20:59 2017 Vincent DUSAUTOIR
** Last update Fri May 05 12:21:00 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_INDIE_STUDIO_VIDEODRIVERMANAGER_HPP
#define CPP_INDIE_STUDIO_VIDEODRIVERMANAGER_HPP

#include <irrlicht/IVideoDriver.h>
#include <memory>

namespace indie{
  class VideoDriverManager : public irr::video::IVideoDriver {
  public:
    typedef std::shared_ptr<VideoDriverManager> Ptr;
    VideoDriverManager() {};
    virtual ~VideoDriverManager() {};
  };
}

#endif //CPP_INDIE_STUDIO_VIDEODRIVERMANAGER_HPP
