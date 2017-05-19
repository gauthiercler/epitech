/*
** XorCracker.hpp for cpp_plazza in /home/ventinc/epitech/cpp/xorcracker/XorCracker.hpp
**
** Made by Vincent DUSAUTOIR
** Login   <vincent.dusautoir@epitech.eu>
**
** Started on  Thu Apr 27 15:41:40 2017 Vincent DUSAUTOIR
** Last update Thu Apr 27 15:41:40 2017 Vincent DUSAUTOIR
*/

#ifndef CPP_PLAZZA_XORCRACKER_HPP
#define CPP_PLAZZA_XORCRACKER_HPP

#include <string>
#include <vector>
#include <map>

namespace plazza
{
  class XorCracker {
    std::string	_buffer;
    size_t	_maxKeyLength;
    size_t	_knownKeyLength;
    std::map<size_t, double> _fitnesses;

  public:
    XorCracker();
    ~XorCracker();

    void				setMaxKeyLength(const size_t keyLength);
    size_t				getMaxKeyLength() const;
    void				setBuffer(const std::string &buffer);
    void				run(const std::string &buffer);
    void				run();
    const std::map<size_t, double>	&getFitnesses() const;
    void				setKnownKeyLength(const size_t keyLength);
    size_t				getKnownKeyLength() const;
    std::string				getKeyXor();
    size_t				getKeyCaesar();

  private:
    size_t			getMaxFitnessKeyLength() const;
    size_t			countEquals(const size_t keyLength);
    std::map<char, size_t>	charCountAtOffset(const size_t keyLength, const size_t offset);
    size_t			getMaxCount(const std::map<char, size_t> &chars);
  };
}


#endif //CPP_PLAZZA_XORCRACKER_HPP
