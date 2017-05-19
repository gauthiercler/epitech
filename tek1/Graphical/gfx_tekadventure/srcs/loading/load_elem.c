/*
** load_elem.c for load_elem in /home/montag_v/rendu/gfx_tekadventure
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Wed Apr 13 19:03:42 2016 valentin montagne
** Last update Sun Apr 17 20:09:04 2016 Gauthier Cler
*/

#include	<lapin.h>
#include	"adventure.h"

int		load_elem(t_bunny_ini *ini, t_elem *elem, char *scope)
{
  if ((elem->name =
       my_strdup(bunny_ini_get_field(ini, scope, "name", 0))) == NULL)
    return (format(2, "load_elem : Couldn't read the .ini file\n"));
  elem->pos.x = my_atoi(bunny_ini_get_field(ini, scope, "position", 0));
  elem->pos.y = my_atoi(bunny_ini_get_field(ini, scope, "position", 1));
  elem->ratio = my_atoi(bunny_ini_get_field(ini, scope, "ratio", 0));
  elem->interaction.type = my_atoi(bunny_ini_get_field(ini, scope, "type", 0));
  elem->interaction.value =
    my_atoi(bunny_ini_get_field(ini, scope, "value", 0));
  elem->base_pos.x = elem->pos.x;
  elem->base_pos.y = elem->pos.y;
  elem->exists = true;
  elem->tick = 0;
  return (SUCCESS);
}
