/*
** put_nb.c for ia in /home/gogo/rendu/CPE_2015_n4s/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 22:06:22 2016 Gauthier Cler
** Last update Tue Apr 26 22:06:23 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"ia.h"

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
