/*
** solve.c for solve in /home/gogo/rendu/dante/profondeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:37:38 2016 Gauthier Cler
** Last update Tue May 31 00:11:38 2016 Gauthier Cler
*/

#include		"solver.h"

void			add_son(t_node **open, t_node **closed, t_map *map,
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
  if (map->array[new.pos.y][new.pos.x] != WAITING)
    {
      map->array[new.pos.y][new.pos.x] = WAITING;
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
				      t_map *map)
{
  add_son(open, closed, map, SOUTH);
  add_son(open, closed, map, EAST);
  add_son(open, closed, map, NORTH);
  add_son(open, closed, map, WEST);
}

int			heuristic(int node_x, int node_y)
{
  return (abs(node_x - goal_x) + abs(node_y - goal_y));
}

t_list			*a_star(t_map *map, t_node *open)
{
  t_node		*closed;
  t_node		*selected;
  closed = NULL;

  while (open != NULL)
    {
      selected = get_lower_node(open);
      if (selected->pos.x == goal_x && selected->pos.y == goal_y)
	return (find_path(open, closed, selected));
      map->array[selected->pos.y][selected->pos.x] = VISITED;
      switch_list(&closed, &open, selected);
      add_sons_loop(&open, &closed, map);
    }
  return (NULL);
}

t_list			*solve_maze(t_map *map)
{
  t_node		*open;
  t_node		start;

  open = NULL;
  start.pos.x = START_X;
  start.pos.y = START_Y;
  start.father.x = -1;
  start.father.y = -1;
  start.g = 0;
  start.f = start.g + heuristic(START_X, START_Y);
  add_node(&open, start);
  if (map->array[START_Y][START_X] != POSSIBLE)
    return (NULL);
  if (map->array[map->size_y - 1][map->size_x - 1] != POSSIBLE)
    return (NULL);
  map->array[map->size_y - 1][map->size_x - 1] = EXIT;
  return (a_star(map, open));
}
