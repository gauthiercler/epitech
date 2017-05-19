/*
** dijkstra.c for lemin in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin/srcs/dijkstra/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 14:12:54 2016 Buyumad Anas
** Last update Mon Apr 25 23:30:40 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

int		add_path(t_path **p, char *val)
{
  t_path	*save;

  if ((save = malloc(sizeof(t_list))) == NULL)
    return (ERROR);
  if ((save->name = my_strdup(val)) == NULL)
    return (ERROR);
  save->next = *p;
  *p = save;
  return (SUCCESS);
}

t_path		*gen_path(t_graph *graphs)
{
  t_path	*path;
  int		index;
  int		prev;

  prev = -1;
  path = NULL;
  if ((index = get_end_index(graphs)) == -1)
    return (NULL);
  if (add_path(&path, graphs[index].name) == ERROR)
    return (NULL);
  while (graphs[index].antecedent != NULL)
    {
      index = get_node_index(graphs, graphs[index].antecedent);
      if (index == prev)
	return (path);
      prev = index;
      if (add_path(&path, graphs[index].name) == ERROR)
	return (NULL);
    }
  return (path);
}

t_path		*dijkstra(t_graph *graphs)
{
  evaluate_weights(graphs);
  return (gen_path(graphs));
}
