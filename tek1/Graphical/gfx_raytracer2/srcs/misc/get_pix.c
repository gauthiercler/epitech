/*
** get_pix.c for raytracer in /home/gogo/rendu/gfx_raytracer2/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun May 15 23:03:19 2016 Gauthier Cler
** Last update Fri May 20 14:32:56 2016 Gauthier Cler
*/

#include		"raytracer.h"

t_bunny_pixelarray	*get_pix(char *name, t_texture *textures,
				 t_bunny_position *size)
{
  int			i;

  i = 0;
  while (textures[i].name != NULL)
    {
      if (my_strcmp(textures[i].name, name) == SUCCESS)
	{
	  size->x = textures[i].size_x;
	  size->y = textures[i].size_y;
	  return (textures[i].texture);
	}
      i += 1;
    }
  return (NULL);
}
