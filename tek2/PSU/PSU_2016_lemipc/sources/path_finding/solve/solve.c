/*
** solve.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/path_finding/solve/solve.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 15:57:16 2017 Gauthier Cler
** Last update Tue Mar 28 15:57:16 2017 Gauthier Cler
*/

#include		"solver.h"

t_pos			target_pos;

void			add_son(t_node **open, t_node **closed, char **map,
				int direction)
{
  t_node		new;
  t_node		*old;

  new.father.x = (*closed)->pos.x;
  new.father.y = (*closed)->pos.y;
  new.g = (*closed)->g + 1;
  if (is_possible(*closed, map, direction, &new.pos) == ERROR)
    return ;
  new.f = (*closed)->g + heuristic(new.pos.x, new.pos.y);
  if (map[new.pos.y][new.pos.x] != WAITING)
    {
      map[new.pos.y][new.pos.x] = WAITING;
      add_node(open, new);
    }
  else
    {
      old = get_node(*open, new);
      if (new.g < old->g)
	{
	  old->g = new.g;
	  old->f = new.f;
	  old->father.x = new.father.x;
	  old->father.y = new.father.y;
	}
    }
}

void			add_sons_loop(t_node **open, t_node **closed,
				      char **map)
{
  add_son(open, closed, map, SOUTH);
  add_son(open, closed, map, EAST);
  add_son(open, closed, map, NORTH);
  add_son(open, closed, map, WEST);
}

int			heuristic(int node_x, int node_y)
{
  return (abs(node_x - target_pos.x) + abs(node_y - target_pos.y));
}

t_list			*a_star(char **map, t_node *open, t_pos *target)
{
  t_node		*closed;
  t_node		*selected;

  closed = NULL;
  while (open != NULL)
    {
      selected = get_lower_node(open);
      if (selected->pos.x == target->x && selected->pos.y == target->y)
	return (find_path(open, closed, selected));
    if (selected->pos.x < ARENA_SS &&
	selected->pos.x >= 0 &&
	selected->pos.y < ARENA_SS &&
	selected->pos.y >= 0)
      map[selected->pos.y][selected->pos.x] = VISITED;
    switch_list(&closed, &open, selected);
    add_sons_loop(&open, &closed, map);
  }
  clean_node(open);
  clean_node(closed);
  return (NULL);
}

t_list			*path_finding(char **map, t_pos *start_pos,
					    t_pos *target)
{
  t_node		*open;
  t_node		start;

  open = NULL;
  target_pos.x = target->x;
  target_pos.y = target->y;
  start.pos.x = start_pos->x;
  start.pos.y = start_pos->y;
  start.father.x = -1;
  start.father.y = -1;
  start.g = 0;
  start.f = start.g + heuristic(start.pos.x, start.pos.y);
  add_node(&open, start);
  map[target->y][target->x] = EXIT;
  return (a_star(map, open, target));
}
