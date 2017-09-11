/*
** IBombSpawner.hpp for cpp_indie_studio in /home/anthony/repository/cpp_indie_studio/IBombSpawner.hpp
**
** Made by Anthony LECLERC
** Login   <anthony.leclerc@epitech.eu>
**
** Started on  ven. juin 09 19:00:20 2017 Anthony LECLERC
** Last update ven. juin 09 19:00:20 2017 Anthony LECLERC
*/

#ifndef CPP_INDIE_STUDIO_IBOMBSPAWNER_HPP
# define CPP_INDIE_STUDIO_IBOMBSPAWNER_HPP

# include	<memory>
# include	"entity/ABomb.hpp"

namespace indie {
  class APlayer;

  class BombSpawner {
  private:
    size_t      _max;
    std::unique_ptr<ABomb> _proto;
    std::vector<std::shared_ptr<ABomb> > _created;

    APlayer	*_owner;

  public:
    BombSpawner(APlayer *owner, std::unique_ptr<ABomb> bomb, size_t max = 1);
    ~BombSpawner();

    /**
     * @brief Change the internal model of the bomb factory
     * @param proto
     */
    void setPrototype(std::unique_ptr<ABomb> proto);

    /**
     * @brief Getter of the internal bomb factory model.
     * @return Reference to the model.
     */
    ABomb& getProtoype();

    /**
     * @brief Spawn a new bomb.
     * Clone the bomb prototype currently hold by the spawner.
     * @see SetProtoype for setting new bomb model.
     * @return Dynamicly allocated bomb to abstract base class ABomb.
     */
    std::shared_ptr<ABomb> spawn();

    size_t    maxBombs() const;
    size_t    leftBombs();

    BombSpawner& operator++();
    BombSpawner& operator--();
    const std::vector<std::shared_ptr<ABomb>> &getBombs() const;
    void update();
  };

}

#endif //CPP_INDIE_STUDIO_IBOMBSPAWNER_HPP
