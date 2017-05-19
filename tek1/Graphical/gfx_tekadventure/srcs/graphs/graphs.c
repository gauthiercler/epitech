/*
** graphs.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/graphs/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Sun Apr 17 21:17:30 2016 Buyumad Anas
** Last update Sun Apr 17 23:51:47 2016 Gauthier Cler
*/

#include	"adventure.h"

int		get_destination(t_graph *graphs, const t_bunny_position *pos)
{
  int		i;

  i = 0;
  while (graphs[i].links != NULL)
    {
      if ((pos->x > graphs[i].pos.x) && (pos->x < graphs[i].pos.x + 75) &&
	  (pos->y > graphs[i].pos.y) && (pos->y < graphs[i].pos.y + 75))
	return (i);
      i += 1;
    }
  return (0);
}

void		display_path(t_path *path)
{
  int		i;

  i = 0;
  while (i < path->nb_path)
    {
      i += 1;
    }
}

void		graph(t_adventure *adventure, const t_bunny_position *pos)
{
  int		destination;
  t_room	*room;

  room =
      &adventure->levels[adventure->current_level].
  rooms[adventure->levels[adventure->current_level].selected - 1];
  if ((destination = get_destination(room->graphs, pos)) ==
      adventure->character.current_graph)
    return ;
  adventure->character.graph =
      find_path(room->graphs, adventure->character.current_graph, destination);
  adventure->character.moving_graph = true;
  adventure->character.current_graph = destination;
  display_path(adventure->character.graph);
}
