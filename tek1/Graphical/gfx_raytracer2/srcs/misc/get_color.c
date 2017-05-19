/*
** get_color.c for get_color in /home/gogo/rendu/gfx_raytracer2/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun May 15 23:52:38 2016 Gauthier Cler
** Last update Mon May 16 00:34:53 2016 Gauthier Cler
*/

#include	"raytracer.h"

unsigned int	get_color(t_bunny_pixelarray *pix, int x, int y)
{
  int         	i;
  unsigned int	*pixel;

  pixel = (unsigned int *)pix->pixels;
  i = x + y * pix->clipable.buffer.width;
  return (pixel[i]);
}
