/*
** load_room.c for room in /home/montag_v/rendu/gfx_tekadventure
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Sun Apr 17 15:44:51 2016 valentin montagne
** Last update Sun Apr 17 23:52:11 2016 Gauthier Cler
*/

#include	<lapin.h>
#include	"adventure.h"

int		find_scope_room(t_bunny_ini *ini, char *what, char **scope, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      if ((scope[i] =
	   (char *)bunny_ini_get_field(ini, what, "room_names", i)) == NULL)
	return (format(2, "find_scope : Couldn't read the file .ini\n"));
      i++;
    }
  return (SUCCESS);
}

int		fill_room(t_bunny_ini *ini,
			  t_room *room,
			  char *scope,
			  int current)
{
  int		nb;
  char		**names;
  char		*name;

  if ((name =
       my_strdup(bunny_ini_get_field(ini, scope, "background", 0))) == NULL)
    return (format(2, "fill_room : No background at %d\n", current));
  if ((room->background = bunny_load_picture(name)) == NULL)
    return (format(2, "fill_room : Couldn't load picture : %s\n", name));
  if ((nb = my_atoi(bunny_ini_get_field(ini, scope, "nb_elems", 0))) < 0)
      return (format(2, "fill_room : %s Error nb_elems < 0\n", scope));
  if ((names = bunny_malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (format(2, "Couldn't malloc\n"));
  names[nb] = NULL;
  if (find_scope(ini, scope, names, nb) == ERROR)
    return (format(2, "fill_room : Couldn't find scope : %s\n", scope));
  if ((room->elems = bunny_malloc(sizeof(t_elem) * (nb + 1))) == NULL)
    return (format(2, "Coudln't malloc.\n"));
  if (load_loop_d(room->elems, ini, names, nb) == ERROR)
    return (ERROR);
  if ((room->graphs = load_graph(ini, scope)) == NULL)
    return (format(2, "fill_room : Couldn't load graph in %s\n", scope));
  return (SUCCESS);
}

t_room		*load_rooms(t_bunny_ini *ini, char *scope)
{
  t_room	*rooms;
  char		**names;
  int		nb;
  int		i;

  if ((nb = my_atoi(bunny_ini_get_field(ini, scope, "nb_rooms", 0))) < 0)
    return (p_error("Error nb_rooms < 0\n"));
  if ((names = bunny_malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (p_error("Couldn't malloc.\n"));
  names[nb] = NULL;
  if ((rooms = bunny_malloc(sizeof(t_room) * (nb + 1))) == NULL)
    return (p_error("Couldn't malloc.\n"));
  if (find_scope_room(ini, scope, names, nb) == ERROR)
    return (p_error("load_room : Couldn't find scope\n"));
  i = 0;
  while (i < nb)
    {
      if (fill_room(ini, &rooms[i], names[i], i) == ERROR)
	return (NULL);
      i++;
    }
  rooms[i].background = NULL;
  return (rooms);
}
