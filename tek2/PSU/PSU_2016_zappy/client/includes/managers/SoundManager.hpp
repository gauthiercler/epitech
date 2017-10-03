/*
** SoundManager.hpp for PSU_2016_zappy in /home/ventinc/epitech/PSU/PSU_2016_zappy/client/sources/managers/SoundManager.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Jun 29 10:40:36 2017 Vincent DUSAUTOIR
** Last update Thu Jun 29 10:40:36 2017 Vincent DUSAUTOIR
*/

#ifndef PSU_2016_ZAPPY_SOUNDMANAGER_HPP
#define PSU_2016_ZAPPY_SOUNDMANAGER_HPP

#include <SFML/Audio.hpp>
#include <memory>
#include <unordered_map>

namespace zappy {

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

#endif //PSU_2016_ZAPPY_SOUNDMANAGER_HPP
