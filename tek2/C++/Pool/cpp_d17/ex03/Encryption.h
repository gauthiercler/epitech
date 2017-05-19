/*
** Encryption.hpp for cpp_d17 in /home/gogo/rendu/tek2/cpp_d17/ex03/Encryption.hpp
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Jan 20 14:29:38 2017 Gauthier CLER
** Last update Fri Jan 20 14:29:38 2017 Gauthier CLER
*/

#ifndef CPP_D17_ENCRYPTION_HPP
#define CPP_D17_ENCRYPTION_HPP


#include <string>
#include "IEncryptionMethod.h"

class Encryption {
public:
  Encryption(IEncryptionMethod &method, void (IEncryptionMethod::*ptr)(char character));
  ~Encryption();
  Encryption &operator()(char character);
  static void encryptString(IEncryptionMethod& encryptionMethod, std::string const& toEncrypt);
  static void decryptString(IEncryptionMethod& encryptionMethod, std::string const& toDecrypt);
private:
  void	(IEncryptionMethod::*_ptr)(char character);
  IEncryptionMethod	*_method;
};


#endif //CPP_D17_ENCRYPTION_HPP
