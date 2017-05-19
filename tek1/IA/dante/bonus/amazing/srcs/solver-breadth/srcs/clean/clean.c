/*
** clean.c for clean in /home/gogo/rendu/dante/profondeur/srcs/clean/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 15:32:11 2016 Gauthier Cler
** Last update Sat May 21 15:43:47 2016 Buyumad Anas
*/

#include		"breadth.h"

void			clean_pileb(t_pileb *pile)
{
  t_pileb		*tmp;

  while (pile != NULL)
    {
      tmp = pile->next;
      free(pile);
      pile = tmp;
    }
}

void			clean_listb(t_listb *list)
{
  t_listb		*tmp;

  tmp = NULL;
  while (list != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}

void			clean_mapb(char **map)
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
