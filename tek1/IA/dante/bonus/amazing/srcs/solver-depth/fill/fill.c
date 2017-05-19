/*
** fill.c for fill in /home/gogo/rendu/dante/profondeur/srcs/fill/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 15:55:03 2016 Gauthier Cler
** Last update Sun May 22 19:17:43 2016 Gauthier Cler
*/

#include		"solver.h"

void			fill_map(char **map, t_list_depth *list, int *counter)
{
  t_list_depth		*tmp;

  *counter = 0;
  tmp = list;
  while (tmp != NULL)
    {
      map[tmp->y][tmp->x] = VISITED;
      tmp = tmp->next;
      *counter += 1;
    }
}

void			empty_map(char **map)
{
  int			x;
  int			y;

  y = 0;
  while (map[y])
    {
      x = 0;
      while (map[y][x])
	{
	  if (map[y][x] == VISITED || map[y][x] == WAITING)
	    map[y][x] = POSSIBLE;
	  x += 1;
	}
      y += 1;
    }
}
