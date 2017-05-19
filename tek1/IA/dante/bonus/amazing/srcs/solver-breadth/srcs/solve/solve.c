/*
** solve.c for solve in /home/gogo/rendu/dante/profondeur/srcs/solve/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:37:38 2016 Gauthier Cler
** Last update Sat May 21 19:10:38 2016 Buyumad Anas
*/

#include		"amazing.h"

int			already_in_pileb(t_pileb *pile, int x, int y)
{
  t_pileb		*tmp;

  tmp = pile;
  while (tmp)
    {
      if (tmp->x == x && tmp->y == y)
	return (ERROR);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int			is_possibleb(t_pileb *pile, t_mapbreadth *map, int direction,
				       t_posb *pos)
{
  int			x;
  int			y;

  x = get_pos_x_b(pile->x, direction);
  y = get_pos_y_b(pile->y, direction);
  if ((x >= map->size_x || x < 0) || (y >= map->size_y || y < 0))
    return (ERROR);
  if (map->array[y][x] == WALL_BREADTH || map->array[y][x] == VISITED
      || map->array[y][x] == WAITING)
    return (ERROR);
  pos->x = x;
  pos->y = y;
  return (SUCCESS);
}

void			add_sonsb(t_pileb **pile, t_pileb **tmp, t_mapbreadth *map)
{
  t_posb		pos;

  if (is_possibleb(*pile, map, NORTH_BREADTH, &pos) == SUCCESS)
    add_end_saveb(tmp, pos, *pile, map);
  if (is_possibleb(*pile, map, SOUTH_BREADTH, &pos) == SUCCESS)
    add_end_saveb(tmp, pos, *pile, map);
  if (is_possibleb(*pile, map, EAST_BREADTH, &pos) == SUCCESS)
    add_end_saveb(tmp, pos, *pile, map);
  if (is_possibleb(*pile, map, WEST_BREADTH, &pos) == SUCCESS)
    add_end_saveb(tmp, pos, *pile, map);
}

t_listb			*solving_iteb(t_amazing *amazing, t_mapbreadth *map,
				      t_pileb *pile)
{
  t_pileb		*visited;
  t_posb		pos;
  t_pileb		*tmp;
  t_posb		save;

  visited = NULL;
  tmp = pile;
  while (pile != NULL)
    {
      if (map->array[pile->y][pile->x] == EXIT)
	{
	  pos.x = pile->x;
	  pos.y = pile->y;
	  save.x = pile->father_x;
	  save.y = pile->father_y;
	  clean_pileb(pile);
	  return (find_pathb(visited, save.x, save.y, pos));
	}
      map->array[pile->y][pile->x] = VISITED;
      add_sonsb(&pile, &tmp, map);
      switch_listb(&visited, &pile);
      draw_maze_breadth(amazing);
      SDL_Flip(amazing->Screen);
    }
  return (NULL);
}

t_listb			*solve_maze_b(t_amazing *amazing, t_mapbreadth *map)
{
  t_listb		*list;
  t_pileb		*pile;
  t_posb		start_pos;

  start_pos.x = START_X;
  start_pos.y = START_Y;
  pile = NULL;
  list = NULL;
  add_end_pileb(&pile, start_pos, -1, -1);
  if (map->array[START_Y][START_X] != POSSIBLE)
    return (NULL);
  if (map->array[map->size_y - 1][map->size_x - 1] != POSSIBLE)
    return (NULL);
  map->array[map->size_y - 1][map->size_x - 1] = EXIT;
  list = solving_iteb(amazing, map, pile);
  return (list);
}
