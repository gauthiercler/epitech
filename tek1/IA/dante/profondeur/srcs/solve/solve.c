/*
** solve.c for solve in /home/gogo/rendu/dante/profondeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:37:38 2016 Gauthier Cler
** Last update Sun May  1 12:36:49 2016 Gauthier Cler
*/

#include		"solver.h"

int			already_in_pile(t_pile *pile, int x, int y)
{
  t_pile		*tmp;

  tmp = pile;
  while (tmp)
    {
      if (tmp->x == x && tmp->y == y)
	return (ERROR);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int			is_possible(t_pile *pile, t_map *map, int direction,
				       t_pos *pos)
{
  int			x;
  int			y;

  x = get_pos_x(pile->x, direction);
  y = get_pos_y(pile->y, direction);
  if ((x >= map->size_x || x < 0) || (y >= map->size_y || y < 0))
    return (ERROR);
  if (map->array[y][x] == WALL || map->array[y][x] == VISITED
      || map->array[y][x] == WAITING)
    return (ERROR);
  pos->x = x;
  pos->y = y;
  return (SUCCESS);
}

void			add_sons(t_pile **pile, t_pile *visited, t_map *map)
{
  t_pos			pos;
  t_pos			father;

  father.x = visited->x;
  father.y = visited->y;
  if (is_possible(visited, map, WEST, &pos) == SUCCESS)
    add_pile(pile, pos, father, map);
  if (is_possible(visited, map, NORTH, &pos) == SUCCESS)
    add_pile(pile, pos, father, map);
  if (is_possible(visited, map, SOUTH, &pos) == SUCCESS)
    add_pile(pile, pos, father, map);
  if (is_possible(visited, map, EAST, &pos) == SUCCESS)
    add_pile(pile, pos, father, map);
}

t_list			*solving_ite(t_map *map, t_pile *pile)
{
  t_pile		*visited;
  t_pos			pos;
  t_pos			save;

  visited = NULL;
  while (pile != NULL)
    {
      if (map->array[pile->y][pile->x] == EXIT)
	{
	  pos.x = pile->x;
	  pos.y = pile->y;
	  save.x = pile->father_x;
	  save.y = pile->father_y;
	  clean_pile(pile);
	  return (find_path(visited, save.x, save.y, pos));
	}
      map->array[pile->y][pile->x] = VISITED;
      switch_list(&visited, &pile);
      add_sons(&pile, visited, map);
    }
  return (NULL);
}

t_list			*solve_maze(t_map *map)
{
  t_list		*list;
  t_pile		*pile;
  t_pos			start_pos;

  start_pos.x = START_X;
  start_pos.y = START_Y;
  pile = NULL;
  list = NULL;
  add_end_pile(&pile, start_pos, -1, -1);
  if (map->array[START_Y][START_X] != POSSIBLE)
    return (NULL);
  if (map->array[map->size_y - 1][map->size_x - 1] != POSSIBLE)
    return (NULL);
  map->array[map->size_y - 1][map->size_x - 1] = EXIT;
  list = solving_ite(map, pile);
  return (list);
}
