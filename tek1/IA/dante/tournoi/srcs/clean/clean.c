/*
** clean.c for clean in /home/gogo/rendu/dante/profondeur/srcs/clean/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 15:32:11 2016 Gauthier Cler
** Last update Sun May  1 11:42:27 2016 Gauthier Cler
*/

#include		"solver.h"

void			clean_pile(t_pile *pile)
{
  t_pile		*tmp;

  while (pile != NULL)
    {
      tmp = pile->next;
      free(pile);
      pile = tmp;
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
