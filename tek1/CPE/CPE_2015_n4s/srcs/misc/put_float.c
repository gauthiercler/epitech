/*
** put_float.c for n4s in /home/skyrise/Work/Repositories/Epitech/CPE/CPE_2015_n4s/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 23 21:29:30 2016 Buyumad Anas
** Last update Tue May 24 17:41:43 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	"ia.h"

int		put_float(int fd, float number, int nb)
{
  int		i;

  i = 0;
  if (number < 0.0)
    {
      write(fd, "-", 1);
      number *= -1;
    }
  put_nb(fd, (int)number);
  while (i < nb)
    {
      (i == 0) ? write(fd, ".", 1) : 0;
      number -= (int)number;
      number *= 10;
      put_nb(fd, (int)number);
      i += 1;
    }
  return (SUCCESS);
}
