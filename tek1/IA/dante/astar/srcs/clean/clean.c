/*
** clean.c for clean in /home/gogo/rendu/dante/profondeur/srcs/clean/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 15:32:11 2016 Gauthier Cler
** Last update Mon May  2 12:23:28 2016 Gauthier Cler
*/

#include		"solver.h"

void			clean_node(t_node *list)
{
  t_node		*tmp;

  while (list != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}

void			clean_list(t_list *list)
{
  t_list		*tmp;

  tmp = NULL;
  while (list != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}

void			clean_map(char **map)
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
