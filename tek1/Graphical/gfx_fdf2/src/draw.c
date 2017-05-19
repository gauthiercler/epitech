/*
** draw.c for draw in /home/gauthier/rendu/gfx_fdf2/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Dec 17 23:54:29 2015 Gauthier Cler
** Last update Sun Dec 20 20:56:52 2015 Gauthier Cler
*/

#include	"fdf.h"

void			ini_line(t_bunny_pixelarray *pix,
				 t_bunny_ini *ini,
				 t_color *color)
{
  t_bunny_position	pos[2];
  int			buff[6];
  int			i;
  int			j;

  i = 0;
  while (bunny_ini_get_field(ini, "forme1", "data", i) != NULL)
    {
      j = 0;
      while (j < 6)
	{
	  buff[j] =
	    my_getnbr((char *)bunny_ini_get_field(ini, "forme1", "data", i + j));
	  j++;
	}
      i += 6;
      tekisoproject(&pos[0], buff[0], buff[1], buff[2]);
      tekisoproject(&pos[1], buff[3], buff[4], buff[5]);
      tekline(pix, pos, color);
    }
}

void			ini_polygon(t_bunny_pixelarray *pix,
				    t_bunny_ini *ini,
				    t_color *color)
{
  t_bunny_position	pos[2];
  int			buff[9];
  int			i;
  int			j;

  i = 0;
  while (bunny_ini_get_field(ini, "forme1", "data", i) != NULL)
    {
      j = -1;
      while (++j < 9)
	buff[j] =
	  my_getnbr((char *)bunny_ini_get_field(ini, "forme1", "data", i + j));
      i += 9;
      tekisoproject(&pos[0], buff[0], buff[1], buff[2]);
      tekisoproject(&pos[1], buff[3], buff[4], buff[5]);
      tekline(pix, pos, color);
      pos[0] = pos[1];
      tekisoproject(&pos[1], buff[6], buff[7], buff[8]);
      tekline(pix, pos, color);
      pos[0] = pos[1];
      tekisoproject(&pos[1], buff[0], buff[1], buff[2]);
      tekline(pix, pos, color);
    }
}

void			ini_pixel(t_bunny_pixelarray *pix,
				  t_bunny_ini *ini,
				  t_color *color)
{
  t_bunny_position	pos;
  int			buff[3];
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (bunny_ini_get_field(ini, "forme1", "data", i) != NULL)
    {
      j = 0;
      while (j < 3)
	{
	  buff[j] =
	    my_getnbr((char *)bunny_ini_get_field(ini, "forme1", "data", i + j));
	  j++;
	}
      i += 3;
      tekisoproject(&pos, buff[0], buff[1], buff[2]);
      tekpixel(pix, &pos, color);
    }
}

void			ini_sphere(t_bunny_pixelarray *pix,
				   t_bunny_ini *ini,
				   t_color *color)
{
  t_surface		s;
  t_bunny_position	pos;

  s.radius = my_getnbr((char*)bunny_ini_get_field(ini, "forme1", "radius", 0));
  s.u = 0;
  s.v = 0;
  while (s.v != 360)
    {
      while (s.u != 360)
	{
	  s.x = s.radius * cos(s.u) * cos(s.v) + 200;
	  s.y = s.radius * cos(s.u) * sin(s.v) + 200;
	  s.z = s.radius * sin(s.u);
	  tekisoproject(&pos, s.x, s.y, s.z);
	  tekpixel(pix, &pos, color);
	  s.u++;
	}
      s.u = 0;
      s.v++;
    }
}

void			ini_tore(t_bunny_pixelarray *pix,
				 t_bunny_ini *ini,
				 t_color *color)
{
  t_surface		s;
  t_bunny_position	pos;
  int			axe;

  s.radius =
    my_getnbr((char *)bunny_ini_get_field(ini, "forme1", "radius", 0));
  axe = my_getnbr((char *)bunny_ini_get_field(ini, "forme1", "distance", 0));
  s.u = 0;
  s.v = 0;
  while (s.v != 360)
    {
      while (s.u != 360)
	{
	  s.x = (axe + s.radius * cos(s.u)) * cos(s.v) + 200;
	  s.y = (axe + s.radius * cos(s.u)) * sin(s.v) + 200;
	  s.z = s.radius * sin(s.u);
	  tekisoproject(&pos, s.x, s.y, s.z);
	  tekpixel(pix, &pos, color);
	  s.u++;
	}
      s.u = 0;
      s.v++;
    }
}
