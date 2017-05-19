/*
** xmalloc.c for xmalloc in /home/gogo/rendu/PSU_2015_minishell2/src/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun Apr  3 20:01:19 2016 Gauthier Cler
** Last update Mon Apr  4 11:28:46 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

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
