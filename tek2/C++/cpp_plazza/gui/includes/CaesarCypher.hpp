/*
** CaesarCypher.hpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/includes/CaesarCypher.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 25 16:28:03 2017 Vincent DUSAUTOIR
** Last update Tue Apr 25 16:28:03 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_CAESARCYPHER_HPP
#define CPP_PLAZZA_CAESARCYPHER_HPP

#include "ACypher.hpp"

namespace plazza {

  /**
   * @brief Caesar cypher class
   */
  class CaesarCypher : public ACypher {

    size_t		_moved;

  public:
    /**
     * @brief Class constructor
     */
    CaesarCypher();

    /**
     * @brief Class destructor
     */
    virtual ~CaesarCypher();

    virtual void		encrypt(std::string &buffer);
    virtual void		decrypt(std::string &buffer);

    /**
     * @brief Get actual shift
     * @return size_t
     */
    size_t			getMoved() const;

    /**
     * @brief set actual shift
     * @param moved
     */
    void			setMoved(const size_t moved);
  };

}

#endif //CPP_PLAZZA_CAESARCYPHER_HPP
