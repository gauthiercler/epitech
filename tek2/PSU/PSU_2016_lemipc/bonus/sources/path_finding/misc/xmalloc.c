/*
** xmalloc.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/path_finding/misc/xmalloc.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 16:05:19 2017 Gauthier Cler
** Last update Tue Mar 28 16:05:19 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	"solver.h"

void		*xmalloc(unsigned int size)
{
  void		*res;

  if ((res = malloc(size)) == NULL)
    {
      display_error("malloc");
      exit(0);
    }
  return (res);
}
