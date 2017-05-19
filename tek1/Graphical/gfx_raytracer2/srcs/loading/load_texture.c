/*
** load_texture.c for load_texture in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Fri May 13 15:57:38 2016 montag_v
** Last update Sun May 15 20:13:27 2016 Buyumad Anas
*/

#include	<raytracer.h>

static int	load_one(t_texture *texture, char *name)
{
  texture->name = my_strdup(name);
  if ((texture->texture = bunny_load_pixelarray(name)) == NULL)
    return (format(2, "Error couldn't load texture %s\n", name));
  texture->size_x = texture->texture->clipable.buffer.width;
  texture->size_y = texture->texture->clipable.buffer.height;
  return (SUCCESS);
}

int		load_texture(t_bunny_ini *ini, t_texture **texture)
{
  int		i;
  int		nb_texture;
  char		**names;

  if ((nb_texture
       = my_atoi(bunny_ini_get_field(ini, "texture", "nb_texture", 0))) < 0)
    return (format(2, "Error nb_texture < 0\n"));
  if (((*texture) = bunny_malloc(sizeof(t_texture) * (nb_texture + 1))) == NULL)
    return (format(2, "Couldn't malloc\n"));
  if ((names = bunny_malloc(sizeof(char *) * (nb_texture + 1))) == NULL)
      return (format(2, "Couldn't malloc\n"));
  if (find_scope(ini, names, "texture", nb_texture) == ERROR)
    return (ERROR);
  i = 0;
  while (i < nb_texture)
    {
      if (load_one(&(*texture)[i], names[i]) == ERROR)
	return (ERROR);
      i += 1;
    }
  (*texture)[i].name = NULL;
  (*texture)[i].texture = NULL;
  return (SUCCESS);
}
