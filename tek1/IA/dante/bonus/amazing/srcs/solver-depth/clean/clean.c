/*
** clean.c for clean in /home/gogo/rendu/dante/profondeur/srcs/clean/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Thu Apr 28 15:32:11 2016 Gauthier Cler
** Last update Tue May  3 20:57:54 2016 Buyumad Anas
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

void			clean_list(t_list_depth *list)
{
  t_list_depth		*tmp;

  tmp = NULL;
  while (list != NULL)
    {
      tmp = list->next;
      free(list);
      list = tmp;
    }
}
