/*
** PowerUpFactory.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/PowerUpFactory.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  mer. juin 14 16:13:56 2017 Anthony LECLERC
** Last update mer. juin 14 16:13:56 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_POWERUPFACTORY_HPP
#define CPP_INDIE_STUDIO_POWERUPFACTORY_HPP

#include <irrlicht/irrTypes.h>
#include <vector>
#include <memory>
#include <irrlicht/ISceneManager.h>

namespace indie {

  class APowerUp;

  class IPowerUpSpawner {
  public:
    virtual ~IPowerUpSpawner() {}
    virtual irr::u32 frequency() = 0;
    virtual APowerUp *spawn() = 0;
  };

  template<typename T>
  class PowerUpSpawner : public IPowerUpSpawner
  {
  private:
    irr::u32	_frequency;
    irr::scene::ISceneManager *_smgr;
  public:
    PowerUpSpawner(irr::scene::ISceneManager *smgr, irr::u32 frequency) :
        _frequency(frequency),
        _smgr(smgr)
        {}
    PowerUpSpawner(PowerUpSpawner<T>&& other) : _frequency(other._frequency) {}

    virtual ~PowerUpSpawner() {}
    virtual irr::u32 frequency() { return _frequency; }

    virtual APowerUp *spawn()
    {
      return new T(_smgr);
    };

  };

  class PowerUpFactory {

  private:

    static std::vector<std::unique_ptr<IPowerUpSpawner> > Factories;
  public:

    PowerUpFactory() = delete;
    ~PowerUpFactory() = delete;
    PowerUpFactory(PowerUpFactory const&) = delete;
    PowerUpFactory(PowerUpFactory &&) = delete;

    template<typename T>
    static void registerFactory(irr::scene::ISceneManager *smgr, irr::u32 frequency) {
      Factories.push_back(std::make_unique<PowerUpSpawner<T> >(smgr, frequency));
    };

    static APowerUp *spawn();

    static void clear();
  };

}

#endif //CPP_INDIE_STUDIO_POWERUPFACTORY_HPP
