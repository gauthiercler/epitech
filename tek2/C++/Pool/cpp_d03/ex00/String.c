/*
** String.c for cpp_d03 in /home/gogo/rendu/tek2/cpp_d03/ex00/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Jan  6 09:23:54 2017 Gauthier Cler
** Last update Sat Jan  7 09:32:52 2017 Gauthier Cler
*/

#include	<string.h>
#include	<stdlib.h>
#include	"String.h"

void	StringInit(String *this, char const *s)
{
  if (this){
    if (s)
      this->str = strdup(s);
    else
      this->str = NULL;
  }
}

void	StringDestroy(String *this)
{
  if (this){
    if (this->str){
      free(this->str);
      this->str = NULL;
    }
  }
}
