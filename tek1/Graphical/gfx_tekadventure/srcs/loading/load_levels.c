/*
** load_levels.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/loading/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 13 12:22:02 2016 Buyumad Anas
** Last update Sun Apr 17 23:51:18 2016 Gauthier Cler
*/

#include	"adventure.h"

int		find_scope(t_bunny_ini *ini, char *what, char **scope, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      if ((scope[i] =
	   (char *)bunny_ini_get_field(ini, what, "names", i)) == NULL)
	return (format(2, "find_scope : Couldn't read the file .ini\n"));
      i++;
    }
  return (SUCCESS);
}

int		load_levels(t_level *levels, char *filename)
{
  char		**scope;
  t_bunny_ini	*ini;
  int		i;

  i = 0;
  if ((ini = bunny_load_ini(filename)) == NULL)
    return (format(2, "load_levels : Couldn't load the file %s.\n", filename));
  if ((scope = bunny_malloc(sizeof(char *) * (NB_LEVELS + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  scope[NB_LEVELS] = NULL;
  if (find_scope(ini, "level", scope, NB_LEVELS) == ERROR)
    return (ERROR);
  while (i < NB_LEVELS)
    {
      if (load_level(&levels[i], ini, scope[i]) == ERROR)
	return (ERROR);
      i += 1;
    }
  bunny_delete_ini(ini);
  return (SUCCESS);
}
