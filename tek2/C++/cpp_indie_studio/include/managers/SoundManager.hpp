/*
** SoundManager.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/SoundManager.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  jeu. mai 04 15:06:29 2017 Anthony LECLERC
** Last update jeu. mai 04 15:06:29 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_SOUNDMANAGER_HPP
#define CPP_INDIE_STUDIO_SOUNDMANAGER_HPP

#include <SFML/Audio.hpp>
#include <memory>
#include <unordered_map>
#include "Error.hpp"

namespace indie {

  /**
   * @brief Sound Manager
   */
  class SoundManager {

    typedef std::shared_ptr<sf::SoundBuffer> bufferPtr;
    typedef std::shared_ptr<sf::Sound> soundPtr;

  private:

    std::unordered_map<std::string, std::pair<bufferPtr, soundPtr>>	_sounds;

    void loadSound(std::string const &path, std::string const &name);
    void load(void);

  public:
    SoundManager();

    void playSound(std::string const &name);
    void pauseSound(std::string const &name);
    void stopSound(std::string const &name);
    void resetSound(std::string const &name);
    void enableSoundLoop(std::string const &name);
    void disableSoundLoop(std::string const &name);
    void setSoundVolume(std::string const &name, float volume);

    void switchGlobalVolume(void);
    float getGlobalVolume(void);
    ~SoundManager();
  };
}


#endif //CPP_INDIE_STUDIO_SOUNDMANAGER_HPP
