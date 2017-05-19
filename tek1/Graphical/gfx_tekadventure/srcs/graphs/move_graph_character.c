/*
** move_graph_character.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/graphs/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 17 22:08:25 2016 Buyumad Anas
** Last update Sun Apr 17 23:13:03 2016 Gauthier Cler
*/

#include	"adventure.h"

void		move_graph_character(t_adventure *adventure)
{
  static int	i = 0;
  static int	ratio = 0;
  t_room	*room;

  if (i < adventure->character.graph->nb_path)
    {
      room = &adventure->levels[adventure->current_level].
	rooms[adventure->levels[adventure->current_level].selected - 1];
      adventure->character.position.x =
	room->graphs[adventure->character.graph->path[i]].pos.x;
      adventure->character.position.y =
	room->graphs[adventure->character.graph->path[i]].pos.y
	- adventure->character.size_y + adventure->character.size_y / 3;
      ratio += 1;
      if (ratio == 20)
	{
	  ratio = 0;
	  i += 1;
	}
    }
  else
    {
      i = 0;
      adventure->character.moving_graph = false;
    }
}
