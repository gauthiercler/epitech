/*
** droidmemory.hh for cpp_d07m in /home/gogo/rendu/tek2/cpp_d08/ex01/droidmemory.hh
**
** Made by Gauthier CLER
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Jan 11 14:38:05 2017 Gauthier CLER
** Last update Wed Jan 11 14:38:05 2017 Gauthier CLER
*/


#ifndef CPP_D07M_DROIDMEMORY_HH
#define CPP_D07M_DROIDMEMORY_HH


#include <cstddef>
#include <ostream>

class DroidMemory {
private:
  size_t	_fingerPrint;
  size_t	_exp;

public:
  DroidMemory();
  DroidMemory(DroidMemory const & memory);
  ~DroidMemory();
  size_t	getFingerPrint() const;
  size_t	getExp() const;
  void		setFingerPrint(size_t fingerPrint);
  void		setExp(size_t  exp);
  DroidMemory &operator<<(DroidMemory const & memory);
  DroidMemory &operator>>(DroidMemory & memory);
  DroidMemory &operator+=(DroidMemory const & memory);
  DroidMemory &operator+=(size_t exp);
  DroidMemory &operator+(DroidMemory const & memory);
  DroidMemory &operator+(size_t exp);
  DroidMemory &operator=(DroidMemory const & memory);
};

std::ostream& operator<<(std::ostream &stream, DroidMemory const &memory);



#endif //CPP_D07M_DROIDMEMORY_HH
