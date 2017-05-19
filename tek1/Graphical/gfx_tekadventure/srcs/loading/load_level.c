/*
** load_level.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/loading/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 13 15:06:15 2016 Buyumad Anas
** Last update Sun Apr 17 17:49:11 2016 valentin montagne
*/

#include	<string.h>
#include	"adventure.h"

int		load_level(t_level *level, t_bunny_ini *ini, char *scope)
{
  int		i;
  int		nb;
  char		**names;

  i = 0;
  if ((nb = my_atoi(bunny_ini_get_field(ini, scope, "nb_decor", 0))) < 0)
    return (format(2, "%s Error nb_decor < 0\n", scope));
  if ((names = bunny_malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  names[nb] = NULL;
  if (find_scope(ini, scope, names, nb) == ERROR)
    return (format(2, "load_level : Couldn't find scope : %s\n", scope));
  while (i < 3)
    {
      if (load_decor(&level->decors[i], ini, names[i]) == ERROR)
	return (format(2, "load_level : Couldn't find elem : %s\n", names[i]));
      i++;
    }
  if ((level->rooms = load_rooms(ini, scope)) == NULL)
    return (format(2, "load_level : Couldn't load rooms in elem : %s\n", scope));
  level->selected = 0;
  return (SUCCESS);
}
