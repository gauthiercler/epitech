/*
** ADecrypt.hpp for cpp_plazza in /home/ventinc/epitech/cpp/cpp_plazza/includes/ADecrypt.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Tue Apr 25 11:26:35 2017 Vincent DUSAUTOIR
** Last update Tue Apr 25 11:26:35 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_ADECRYPT_HPP
#define CPP_PLAZZA_ADECRYPT_HPP

#include <string>

namespace plazza {
  /**
   * @brief Abstract class for cyphering
   */
  class			ACypher {

  public:
    virtual ~ACypher();

    /**
     * @brief encrypt string
     * @param buffer
     */
    virtual void	encrypt(std::string &buffer) = 0;

    /**
     * @brief decrypt string
     * @param buffer
     */
    virtual void	decrypt(std::string &buffer) = 0;

    /**
     * @brief Alias to decrypt member function
     * @param buffer
     * @return
     */
    ACypher	&operator<<(std::string &buffer);

    /**
     * @brief Alias to encrypt member function
     * @param buffer
     * @return
     */
    ACypher	&operator>>(std::string &buffer);
  };
}

#endif //CPP_PLAZZA_ADECRYPT_HPP
