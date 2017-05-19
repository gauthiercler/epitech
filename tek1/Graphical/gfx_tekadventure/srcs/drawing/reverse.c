/*
** reverse.c for reverse in /home/montag_v/rendu/nocss_2020/test
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Thu Apr 14 19:07:34 2016 valentin montagne
** Last update Sat Apr 16 21:12:25 2016 Gauthier Cler
*/

#include	<lapin.h>
#include	"adventure.h"

void		swap(unsigned int *src1, unsigned int *src2)
{
  int		sav;

  sav = *src1;
  *src1 = *src2;
  *src2 = sav;
}

int		reverse(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;
  unsigned int		*pixel;
  int			i;
  int			j;

  pos.y = 0;
  pixel = (unsigned int *)pix->pixels;
  while (pos.y < pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width / 2)
	{
	  i = pos.x + pos.y * pix->clipable.clip_width;
	  j = pix->clipable.clip_width + pos.y * pix->clipable.clip_width;
	  swap(&pixel[i], &pixel[j - pos.x]);
	  pos.x += 1;
	}
      pos.y += 1;
    }
  return (SUCCESS);
}
