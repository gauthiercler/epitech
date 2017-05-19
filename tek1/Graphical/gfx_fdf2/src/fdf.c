/*
** fdf.c for fdf in /home/gauthier/rendu/gfx_fdf2/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Dec 17 09:55:00 2015 Gauthier Cler
** Last update Sun Dec 20 00:21:23 2015 Gauthier Cler
*/

#include "fdf.h"

void            ini_fdf(t_bunny_pixelarray *pix,
			t_bunny_ini *ini,
			t_color *color)
{
  t_bunny_position      pos[2];
  t_bunny_position      save[2];
  int                   buff[6];
  int                   i;
  int                   k;
  int		        w;

  w = my_getnbr((char *)bunny_ini_get_field(ini, "forme1", "width", 0));
  i = 0;
  k = 0;
  while (bunny_ini_get_field(ini, "forme1", "data", i) != NULL)
    {
      i = loop_ini_fdf(ini, i, buff);
      co_ini_fdf(pos, save, buff);
      line_fdf(pix, pos, color);
      if (i > 6 && k % (w + 1) != 0)
	tekline(pix, save, color);
      if (i >= (w + 2) * 6)
	{
	  loop_ini_fdf(ini, i - (w + 2) * 6, buff);
	  tekisoproject(&pos[0], buff[3], buff[4], buff[5]);
	  tekline(pix, pos, color);
	}
      k++;
    }
}

int	loop_ini_fdf(t_bunny_ini *ini, int i, int *buff)
{
  int   j;

  j = 0;
  while (j < 6)
    {
            buff[j] =
	      my_getnbr((char*)bunny_ini_get_field(ini, "forme1", "data", i + j));
	    j++;
    }
  i += 6;
  return (i);
}

void    co_ini_fdf(t_bunny_position *pos,
		   t_bunny_position *save,
		   int *buff)
{
  save[0] = pos[1];
  tekisoproject(&pos[0], buff[0], buff[1], buff[2]);
  tekisoproject(&pos[1], buff[3], buff[4], buff[5]);
  save[1] = pos[1];
}

void	line_fdf(t_bunny_pixelarray *pix,
		 t_bunny_position *pos,
		 t_color *color)
{
  color[0].full = 0xff003399;
  tekline(pix, pos, color);
  color[0].full = 0xff33CCFF;
}
