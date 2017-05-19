/*
** Misc.hpp for cpp_nanotekspice in /home/gogo/rendu/tek2/cpp_nanotekspice/sources/classes/misc/Misc.hpp
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Feb 15 00:15:11 2017 Gauthier Cler
** Last update Wed Feb 15 00:15:11 2017 Gauthier Cler
*/

#ifndef CPP_NANOTEKSPICE_MISC_H
#define CPP_NANOTEKSPICE_MISC_H

#include <string>
#include <vector>

namespace nts {

  class Misc {
  public:
    static std::string		trim(std::string &str);

    template <class T>
    static void			deleteVector(T *vector)
    {
      if (!vector)
	return ;
      typename T::iterator it;
      for (it = vector->begin(); it != vector->end(); ++it)
      {
	delete *it;
      }
    }
  };

}


#endif //CPP_NANOTEKSPICE_MISC_H
