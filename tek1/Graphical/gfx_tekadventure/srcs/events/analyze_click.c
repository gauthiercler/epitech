/*
** analyze_click.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/events/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Thu Apr 14 17:52:37 2016 Buyumad Anas
** Last update Sun Apr 17 21:15:23 2016 Buyumad Anas
*/

#include	"adventure.h"

int		touches_graph(t_position *pos_graph,
			      const t_bunny_position *pos)
{
  if ((pos->x > pos_graph->x) && (pos->x < pos_graph->x + 75) &&
      (pos->y > pos_graph->y) && (pos->y < pos_graph->y + 75))
    return (SUCCESS);
  return (ERROR);
}

int		is_graph(t_level *level, const t_bunny_position *pos)
{
  int		i;

  i = 0;
  while (level->rooms[level->selected - 1].graphs[i].links != NULL)
    {
      if (touches_graph(&level->rooms[level->selected - 1].graphs[i].pos,
			pos) == SUCCESS)
	return (3);
      i += 1;
    }
  return (0);
}

int		analyze_click(t_adventure *adventure, const t_bunny_position *pos)
{
  int		value;

  if (adventure->levels[adventure->current_level].selected > 0)
    {
      if ((value =
	   is_graph(&adventure->levels[adventure->current_level], pos)) == 3)
	return (value);
    }
  value = find_hitboxes(adventure, pos);
  return (value);
}
