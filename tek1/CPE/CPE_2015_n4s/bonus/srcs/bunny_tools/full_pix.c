/*
** init_black.c for init_black in /home/montag_v/rendu/lightning_2020
** 
** Made by valentin montagne
** Login   <montag_v@epitech.net>
** 
** Started on  Tue Nov 10 14:56:23 2015 valentin montagne
** Last update Tue Nov 10 15:04:10 2015 valentin montagne
*/

#include <lapin.h>

void	full_pix(t_bunny_pixelarray *pix, unsigned int color)
{
  int	*pixel;
  int	i;
  int	size;

  i = 0;
  pixel = pix->pixels;
  size = pix->clipable.buffer.width * pix->clipable.buffer.height;
  while (i <= size)
    {
      pixel[i] = color;
      i++;
    }
}
