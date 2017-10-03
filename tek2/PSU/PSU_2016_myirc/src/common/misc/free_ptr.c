/*
** free_ptr.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/common/misc/free_ptr.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jun 01 18:03:14 2017 Gauthier Cler
** Last update Thu Jun 01 18:03:14 2017 Gauthier Cler
*/

#include	<stdlib.h>

void		free_ptr(void **ptr)
{
  if (*ptr)
  {
    free(*ptr);
    *ptr = NULL;
  }
}