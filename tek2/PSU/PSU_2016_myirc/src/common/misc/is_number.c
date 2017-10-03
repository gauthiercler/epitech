/*
** is_number.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/common/misc/is_number.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Jun 05 20:39:40 2017 Gauthier Cler
** Last update Mon Jun 05 20:39:40 2017 Gauthier Cler
*/

#include	<stdbool.h>
#include	<ctype.h>

bool		is_number(const char *string)
{
  while (*string)
  {
    if (!isdigit(*string))
      return (false);
    string++;
  }
  return (true);
}