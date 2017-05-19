/*
** solve.c for solve in /home/gogo/rendu/dante/profondeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:37:38 2016 Gauthier Cler
** Last update Sun May 22 22:22:28 2016 Gauthier Cler
*/

#include		"amazing.h"

void			add_son(t_nodea **open, t_nodea **closed, t_mapa *map,
				int direction)
{
  t_nodea		new;
  t_nodea		*old;

  new.father.x = (*closed)->pos.x;
  new.father.y = (*closed)->pos.y;
  new.g = (*closed)->g + 1;
  if (is_possiblea(*closed, map, direction, &new.pos) == ERROR)
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

void			add_sons_loop(t_nodea **open, t_nodea **closed,
				      t_mapa *map)
{
  add_son(open, closed, map, SOUTH_A);
  add_son(open, closed, map, EAST_A);
  add_son(open, closed, map, NORTH_A);
  add_son(open, closed, map, WEST_A);
}

int			heuristic(int node_x, int node_y)
{
  return (abs(node_x - goal_x) + abs(node_y - goal_y));
}

t_lista			*a_star(t_mapa *map, t_nodea *open, t_amazing *amazing)
{
  t_nodea		*closed;
  t_nodea		*selected;
  closed = NULL;

  while (open != NULL)
    {
      selected = get_lower_node(open);
      if (selected->pos.x == goal_x && selected->pos.y == goal_y)
	return (find_patha(open, closed, selected));
      map->array[selected->pos.y][selected->pos.x] = VISITED;
      switch_lista(&closed, &open, selected);
      add_sons_loop(&open, &closed, map);
      draw_maze_star(amazing);
      SDL_Flip(amazing->Screen);
    }
  return (NULL);
}

t_lista			*solve_maze_a(t_amazing *amazing, t_mapa *map)
{
  t_nodea		*open;
  t_nodea		start;

  (void)amazing;
  open = NULL;
  start.pos.x = START_X;
  start.pos.y = START_Y;
  start.father.x = -1;
  start.father.y = -1;
  start.g = 0;
  start.f = start.g + heuristic(START_X, START_Y);
  add_node(&open, start);
  goal_x = amazing->solve_astar.map.size_x - 1;
  goal_y = amazing->solve_astar.map.size_y - 1;
  if (map->array[START_Y][START_X] != POSSIBLE)
    return (NULL);
  if (map->array[map->size_y - 1][map->size_x - 1] != POSSIBLE)
    return (NULL);
  map->array[map->size_y - 1][map->size_x - 1] = EXIT;
  return (a_star(map, open, amazing));
}
