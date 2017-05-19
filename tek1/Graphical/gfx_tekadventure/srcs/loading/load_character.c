/*
** load_character.c for load_character in /home/gogo/rendu/gfx_tekadventure/srcs/loading
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 16 16:01:42 2016 Gauthier Cler
** Last update Sun Apr 17 23:29:17 2016 Gauthier Cler
*/

#include	"adventure.h"

int		load_sprite(t_sprite *sprite, char *field, t_bunny_ini *ini)
{
  if ((sprite->pix =
       bunny_load_picture(bunny_ini_get_field(ini, "character",
					      field, 0))) == NULL)
    return (format(2, "Couldn't load %s\n", field));
  if ((sprite->size = my_atoi(bunny_ini_get_field(ini, "character",
						  field, 1))) == -1)
    return (format(2, "Couldn't load size"));
  if ((sprite->nb_frame = my_atoi(bunny_ini_get_field(ini, "character",
						      field, 2))) == -1)
    return (format(2, "Couldn't load nb_frame"));
  sprite->current_frame = 1;
  return (SUCCESS);
}

int		load_character(t_character *character, char *filename)
{
  t_bunny_ini	*ini;

  if ((ini = bunny_load_ini(filename)) == NULL)
    return (format(2, "Couldn't load %s\n", filename));
  if (load_sprite(&character->stay_right, "stay_right", ini) == ERROR)
    return (ERROR);
  if (load_sprite(&character->stay_left, "stay_left", ini) == ERROR)
    return (ERROR);
  if (load_sprite(&character->move_right, "move_right", ini) == ERROR)
    return (ERROR);
  if (load_sprite(&character->move_left, "move_left", ini) == ERROR)
    return (ERROR);
  character->size_x = character->stay_right.pix->buffer.width;
  character->size_y = character->stay_right.pix->buffer.height;
  character->mode = 2;
  character->position.x = 0;
  character->position.y = 450;
  character->in_graph = false;
  bunny_delete_ini(ini);
  return (SUCCESS);
}
