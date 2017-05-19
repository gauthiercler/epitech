/*
** fill.c for fill in /home/gogo/rendu/dante/profondeur/srcs/fill/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 15:55:03 2016 Gauthier Cler
** Last update Sun May 22 16:46:42 2016 Buyumad Anas
*/

#include		"astar.h"

void			fill_mapa(char **map, t_lista *list, int *counter)
{
  t_lista		*tmp;

  *counter = 0;
  tmp = list;
  while (tmp != NULL)
    {
      map[tmp->y][tmp->x] = VISITED;
      tmp = tmp->next;
      *counter += 1;
    }
}

void			empty_mapa(char **map)
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
