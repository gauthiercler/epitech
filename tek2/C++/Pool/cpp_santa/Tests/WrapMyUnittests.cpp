/*
** WrapMyUnittests.cpp for cpp_santa in /home/foret_a/Lab/cpp_santa/Tests/WrapMyUnittests.cpp
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jan 14 15:41:34 2017 Antoine FORET
** Last update Sat Jan 14 15:41:34 2017 Antoine FORET
*/

#include <iostream>
#include "Classes/Box.hpp"
#include "Classes/GiftPaper.hpp"

AObject				*MyUnitTests(AObject **stack)
{
  unsigned int			i = 0;

  while (stack[i] != NULL && stack[i + 1] != NULL)
  {
    if (!stack[i]->isWrappable() || !stack[i + 1]->canWrap()) {
      std::cerr << "Unable to wrap " << stack[i + 1]->getName() << " into " << stack[i]->getName() << std::endl;
      return NULL;
    }
    (static_cast<AWrap*>(stack[i + 1]))->wrapMeThat(stack[i]);
    i++;
  }
  return stack[i];
}