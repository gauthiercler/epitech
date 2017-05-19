/*
** xmalloc.c for solver in /home/gogo/rendu/dante/profondeur/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:10:27 2016 Gauthier Cler
** Last update Wed Apr 27 23:10:29 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"solver.h"

void		*xmalloc(unsigned int size)
{
  void		*res;

  if ((res = malloc(size)) == NULL)
    {
      format(2, "Malloc Error, program will quit.\n");
      exit(0);
    }
  return (res);
}
