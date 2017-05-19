/*
** grid.c for grid in /home/gauthier/rendu/gfx_fdf2/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec 15 13:40:41 2015 Gauthier Cler
** Last update Fri Dec 18 22:28:09 2015 Gauthier Cler
*/

#include	"fdf.h"

void			grid(t_bunny_pixelarray *pix,
			     t_color *color,
			     t_bunny_ini *ini)
{
  t_bunny_position	pos[2];
  int			i;
  int			length;
  int			width;

  width =  my_getnbr((char *)bunny_ini_get_field(ini, "forme1", "length", 0));
  length = my_getnbr((char *)bunny_ini_get_field(ini, "forme1", "width", 0));
  i = 0;
  while (i <= length)
    {
      tekisoproject(&pos[0], 50 * i, 0, 0);
      tekisoproject(&pos[1], 50 * i, 50 * width, 0);
      tekline(pix, pos, color);
      i++;
    }
  i = 0;
  while (i <= width)
    {
      tekisoproject(&pos[0], 0, 50 * i, 0);
      tekisoproject(&pos[1], 50 * length, 50 * i, 0);
      tekline(pix, pos, color);
      i++;
    }
}
