/*
** ini.c for ini in /home/gauthier/rendu/gfx_fdf2/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec 15 17:35:23 2015 Gauthier Cler
** Last update Sun Dec 20 20:40:03 2015 Gauthier Cler
*/

#include	"fdf.h"

void		read_ini(t_bunny_pixelarray *pix,
			 t_bunny_ini *ini,
			 t_color *color)
{
  const char	*shape;
  const	char	*type;

  shape = bunny_ini_get_field(ini, "forme1", "shape", 0);
  type = bunny_ini_get_field(ini, "forme1", "type", 0);
  if (my_strcmp((char *)shape, "pixel") == 1)
    read_ini_pixel(pix, ini, color, type);
  else if (my_strcmp((char *)shape, "line") == 1)
    read_ini_line(pix, ini, color, type);
  else if (my_strcmp((char *)shape, "polygon") == 1)
    ini_polygon(pix, ini, color);
}

void	read_ini_line(t_bunny_pixelarray *pix,
		      t_bunny_ini *ini,
		      t_color *color,
		      const char *type)
{
  if (my_strcmp((char *)type, "fdf") == 1)
    ini_fdf(pix, ini, color);
  else if (my_strcmp((char *)type, "mobius") == 1)
    ini_mobius(pix, ini, color);
  else
    ini_line(pix, ini, color);
}

void	read_ini_pixel(t_bunny_pixelarray *pix,
		       t_bunny_ini *ini,
		       t_color *color,
		       const char *type)
{
  if (my_strcmp((char *)type, "sphere") == 1)
    ini_sphere(pix, ini, color);
  else if (my_strcmp((char *)type, "tore") == 1)
    ini_tore(pix, ini, color);
    else if (my_strcmp((char *)type, "coussin") == 1)
    ini_coussin(pix, ini, color);
  else if (my_strcmp((char *)type, "cone") == 1)
    ini_cone(pix, ini, color);
  else if (my_strcmp((char *)type, "cylinder") == 1)
    ini_cylinder(pix, ini, color);
  else
    ini_pixel(pix, ini, color);
}
