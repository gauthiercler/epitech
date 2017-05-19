/*
** put_nb.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 13 12:30:30 2016 Buyumad Anas
** Last update Wed May  4 15:40:24 2016 montag_v
*/

#include	<unistd.h>
#include	"raytracer.h"

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
