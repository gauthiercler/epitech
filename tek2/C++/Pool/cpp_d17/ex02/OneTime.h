/*
** OneTime.h for cpp_d17 in /home/gogo/rendu/tek2/cpp_d17/ex02/OneTime.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 20 11:17:48 2017 Gauthier CLER
** Last update Fri Jan 20 11:17:48 2017 Gauthier CLER
*/

#ifndef CPP_D17_ONETIME_HPP
#define CPP_D17_ONETIME_HPP


#include <string>
#include <map>
#include "IEncryptionMethod.h"

class OneTime  : virtual public IEncryptionMethod{
public:
  OneTime(const std::string &key);
  ~OneTime();
  virtual void encryptChar(char plainhar);
  virtual void decryptChar(char cypherchar);
  virtual void	reset();
  void		setShiftValue(int value);
  int		getShiftValue() const;
private:
  std::string		_key;
  int			_shiftValue;
  std::map<char, int>	_array;
};


#endif //CPP_D17_ONETIME_HPP
