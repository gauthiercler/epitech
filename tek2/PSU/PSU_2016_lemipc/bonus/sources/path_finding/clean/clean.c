/*
** clean.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/path_finding/clean/clean.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 28 16:00:40 2017 Gauthier Cler
** Last update Tue Mar 28 16:00:40 2017 Gauthier Cler
*/

#include		"solver.h"

void			clean_cached_map(t_player *player)
{
  int			idx;

  idx = 0;
  while (idx < arena_ss)
  {
    free(player->arena_map[idx]);
    idx += 1;
  }
  free(player->arena_map);
}

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
