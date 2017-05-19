/*
** xmalloc.c for xmalloc in /home/gogo/rendu/dante/generation/perfection/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 17:13:51 2016 Gauthier Cler
** Last update Tue Apr 26 17:17:07 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"perfection.h"

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
