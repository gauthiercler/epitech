/*
** check_directions.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/generation/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 22:31:40 2016 Buyumad Anas
** Last update Sat May 21 17:31:55 2016 Gauthier Cler
*/

#include	"perfection.h"

int		is_supposed_correct(t_map *map, t_cell *supposed, int direction)
{
  if (direction == NORTH)
    {
      if (supposed->pos_y < 0)
	return (ERROR);
    }
  else if (direction == EAST)
    {
      if (supposed->pos_x >= map->width)
	return (ERROR);
    }
  else if (direction == SOUTH)
    {
      if (supposed->pos_y >= map->height)
	return (ERROR);
    }
  else if (direction == WEST)
    {
      if (supposed->pos_x < 0)
	return (ERROR);
    }
  return (SUCCESS);
}

int		check_imperfect_walls(t_map *map, t_list *cell, int direction)
{
  t_cell	supposed;

  supposed.pos_x = get_pos_x(cell, direction);
  supposed.pos_y = get_pos_y(cell, direction);
  if (is_supposed_correct(map, &supposed, direction) == ERROR)
    return (ERROR);
  else if (map->cells[supposed.pos_y][supposed.pos_x] == WALL)
    return (ERROR);
  return (SUCCESS);
}

int		check_surroundings(t_list *list, t_map *map, t_list *cell,
				   int direction)
{
  t_cell	supposed;

  (void)list;
  supposed.pos_x = get_pos_x(cell, direction);
  supposed.pos_y = get_pos_y(cell, direction);
  if (is_supposed_correct(map, &supposed, direction) == ERROR)
    return (OUT);
  else if ((map->cells[supposed.pos_y][supposed.pos_x] == PATH) &&
	   (is_not_link(&cell->link, &supposed) == SUCCESS))
    return (IMP);
  else if (map->cells[supposed.pos_y][supposed.pos_x] == 8 &&
	   (is_not_link(&cell->link, &supposed) == SUCCESS))
    return (IMP);
  return (SUCCESS);
}

int		check_directions(t_list *list, t_map *map, t_list *cell,
				 int direction)
{
  t_cell	supposed;

  (void)list;
  supposed.pos_x = get_pos_x(cell, direction);
  supposed.pos_y = get_pos_y(cell, direction);
  if (is_supposed_correct(map, &supposed, direction) == ERROR)
    return (OUT);
  else if ((map->cells[supposed.pos_y][supposed.pos_x] == PATH) ||
	   (map->cells[supposed.pos_y][supposed.pos_x] == WALL))
    return (IMP);
  else if (map->cells[supposed.pos_y][supposed.pos_x] == 8)
    return (IMP);
  return (SUCCESS);
}
