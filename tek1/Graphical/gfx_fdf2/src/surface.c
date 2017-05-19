/*
** surface.c for surface in /home/gauthier/rendu/gfx_fdf2/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Dec 17 14:09:32 2015 Gauthier Cler
** Last update Sun Dec 20 00:24:09 2015 Gauthier Cler
*/

#include "fdf.h"

void			ini_cylinder(t_bunny_pixelarray *pix,
				     t_bunny_ini *ini,
				     t_color *color)
{
  t_surface		s;
  t_bunny_position	pos;
  int			height;

  s.radius =
    my_getnbr((char *)(bunny_ini_get_field(ini, "forme1", "radius", 0)));
  height =
    my_getnbr((char *)(bunny_ini_get_field(ini, "forme1", "height", 0)));
  s.u = 0;
  s.v = 0;
  while (s.v != height)
    {
      while (s.u != 480)
	{
	  s.x = s.radius * cos(s.u);
	  s.y = s.radius * sin(s.u);
	  s.z = s.v;
	  tekisoproject(&pos, s.x + 200, s.y + 200, s.z);
	  tekpixel(pix, &pos, color);
	  s.u++;
	}
      s.u = 0;
      s.v++;
    }
}

void			ini_mobius(t_bunny_pixelarray *pix,
				   t_bunny_ini *ini,
				   t_color *color)
{
  t_surface		s;
  t_bunny_position	pos[2];
  int			angle;
  int			stch;

  angle = my_getnbr((char *)(bunny_ini_get_field(ini, "forme1", "angle", 0)));
  stch = my_getnbr((char *)(bunny_ini_get_field(ini, "forme1", "stretch", 0)));
  s.v = 0;
  s.u = 0;
  while (s.v != 360)
    {
      tekisoproject(&pos[0], s.x, s.y, s.z);
      while (s.u != stch)
	{
	  s.x = (angle + s.u * cos(s.v)) * cos(s.v) + 200;
	  s.y = (angle + s.u * cos(s.v)) * sin(s.v) + 200;
	  s.z = s.u * sin(s.v);
	  tekisoproject(&pos[1], s.x, s.y, s.z);
	  pos[0] = pos[1];
	  tekline(pix, pos, color);
	  s.u++;
	}
      s.u = 0;
      s.v++;
    }
}

void			ini_cone(t_bunny_pixelarray *pix,
				 t_bunny_ini *ini,
				 t_color *color)
{
  t_surface		s;
  t_bunny_position	pos;
  int			size;

  s.radius =
    my_getnbr((char *)(bunny_ini_get_field(ini, "forme1", "radius", 0)));
  size = my_getnbr((char *)(bunny_ini_get_field(ini, "forme1", "size", 0)));
  s.v = 0;
  s.u = 0;
  while (s.v != s.radius)
    {
      while (s.u != size)
	{
	  s.x = s.u * cos(s.v);
	  s.y = s.u * sin(s.v);
	  s.z = s.u;
	  tekisoproject(&pos, s.x + 200, s.y + 200, s.z);
	  tekpixel(pix, &pos, color);
	  s.u++;
	}
      s.u = 0;
      s.v++;
    }
}

void			ini_coussin(t_bunny_pixelarray *pix,
				    t_bunny_ini *ini,
				    t_color *color)
{
  t_surface		s;
  t_bunny_position	pos;

s.radius =
    my_getnbr((char *)(bunny_ini_get_field(ini, "forme1", "angle", 0)));
  s.v = 0;
  s.u = 0;
  while (s.v != 360)
    {
      while (s.u != 360)
	{
	  s.x = s.radius * sin(s.u);
	  s.y = s.radius * sin(s.v);
	  s.z = (s.radius * cos(s.u) * cos(s.v)) / sqrt(2);
	  tekisoproject(&pos, s.x, s.y, s.z);
	  tekpixel(pix, &pos, color);
	  s.u++;
	}
      s.u = 0;
      s.v++;
    }
}
