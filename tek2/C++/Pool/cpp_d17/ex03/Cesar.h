/*
** Cesar.h for cpp_d17 in /home/gogo/rendu/tek2/cpp_d17/ex02/Cesar.h
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 20 11:17:24 2017 Gauthier CLER
** Last update Fri Jan 20 11:17:24 2017 Gauthier CLER
*/

#ifndef CPP_D17_CESAR_HPP
#define CPP_D17_CESAR_HPP


#include "IEncryptionMethod.h"

class Cesar : virtual public IEncryptionMethod{
public:
  Cesar();
  virtual ~Cesar();
  virtual void	encryptChar(char plainchar);
  virtual void	decryptChar(char cipherchar);
  virtual void	reset();
  void		setShiftValue(int value);
  int		getShiftValue() const;
private:
  int		_shiftValue;
};


#endif //CPP_D17_CESAR_HPP
