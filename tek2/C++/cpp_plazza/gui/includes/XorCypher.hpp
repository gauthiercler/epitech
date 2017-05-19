/*
** XorCypher.hpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/includes/XorCypher.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 25 13:30:58 2017 Vincent DUSAUTOIR
** Last update Tue Apr 25 13:30:58 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_XORCYPHER_HPP
#define CPP_PLAZZA_XORCYPHER_HPP

#include "ACypher.hpp"

namespace plazza {

  /**
   * @brief Class used for encrypt & decrypt using XOR
   */
  class				XorCypher : public ACypher {
    std::string			_key;

  public:

  /**
   * @brief CLass constructor
   */
    XorCypher();

    /**
     * @brief Class destructor
     */
    virtual ~XorCypher();

    virtual void		encrypt(std::string &buffer);
    virtual void		decrypt(std::string &buffer);

    /**
     * @brief Get current cypher key
     * @return
     */
    const std::string		&getKey() const;

    /**
     * @brief Set current cypher key
     * @param key
     */
    void			setKey(const std::string &key);
  };

}

#endif //CPP_PLAZZA_XORCYPHER_HPP
