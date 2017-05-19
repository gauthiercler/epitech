/*
** clean.c for clean in /home/gogo/rendu/dante/profondeur/srcs/clean/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 15:32:11 2016 Gauthier Cler
** Last update Sun May 22 16:58:29 2016 Buyumad Anas
*/

#include		"astar.h"

void			clean_node(t_nodea *list)
{
  t_nodea		*tmp;

  while (list != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}

void			clean_lista(t_lista *list)
{
  t_lista		*tmp;

  tmp = NULL;
  while (list != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}

void			clean_mapa(char **map)
{
  int			i;

  i = 0;
  while (map[i])
    {
      free(map[i]);
      i += 1;
    }
  free(map);
}
