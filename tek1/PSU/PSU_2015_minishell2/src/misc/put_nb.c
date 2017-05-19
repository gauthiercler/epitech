/*
** put_nb.c for mysh in /home/gogo/rendu/PSU_2015_minishell2/src/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar 29 16:21:54 2016 Gauthier Cler
** Last update Tue Mar 29 16:21:56 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"mysh.h"

int		put_nb(int fd, int nb)
{
  int		i;
  int		k;

  i = 1;
  if (nb < 0)
    {
      nb = -(nb);
      write(fd, "-", 1);
    }
  while (nb / i >= 10)
    i = i * 10;
  while (i > 0)
    {
      k = ((nb / i) % 10) + '0';
      write(fd, &k, 1);
      k -= '0';
      i = i / 10;
    }
  if (fd == 2)
    return (ERROR);
  return (SUCCESS);
}
