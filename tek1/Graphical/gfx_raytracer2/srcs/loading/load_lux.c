/*
** load_lux.c for load_lux in /home/montag_v/rendu/gfx_raytracer2
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed May  4 14:51:42 2016 montag_v
** Last update Sun May 22 16:05:34 2016 Buyumad Anas
*/

#include	"raytracer.h"

int		load_lux(t_bunny_ini *ini, char *scope, t_lux *lux)
{
  if ((lux->type = my_atoi(bunny_ini_get_field(ini, scope, "type", 0))) < 0)
    return (format(2, "%s Error type < 0\n", scope));
  load_coord(ini, scope, "coord", &lux->origin);
  load_coord(ini, scope, "attenuation", &lux->att);
  lux->intensity =
    my_atof(bunny_ini_get_field(ini, scope, "intensity", 0));
  return (SUCCESS);
}

int		loop_lux(t_bunny_ini *ini, t_lux **lux, int nb_lux)
{
  char		**scope;
  int		i;

  if ((scope = bunny_malloc(sizeof(char *) * (nb_lux + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  if (((*lux) = bunny_malloc(sizeof(t_lux) * (nb_lux + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  if (find_scope(ini, scope, "lux", nb_lux) == ERROR)
    return (ERROR);
  i = 0;
  while (i < nb_lux)
    {
      if (load_lux(ini, scope[i], &(*lux)[i]) == ERROR)
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
