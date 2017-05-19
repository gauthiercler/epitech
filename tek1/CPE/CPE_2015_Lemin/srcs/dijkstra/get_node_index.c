/*
** get_node_index.c for lemin in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin/srcs/dijkstra/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 14:54:06 2016 Buyumad Anas
** Last update Mon Apr 25 17:30:02 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

int		get_end_index(t_graph *graphs)
{
  int		i;

  i = 0;
  while (graphs[i].name != NULL)
    {
      if (graphs[i].pos == END)
	return (i);
      i += 1;
    }
  return (ERROR);
}

int		get_start_index(t_graph *graphs)
{
  int		i;

  i = 0;
  while (graphs[i].name != NULL)
    {
      if (graphs[i].pos == START)
	return (i);
      i += 1;
    }
  return (ERROR);
}

int		get_node_index(t_graph *graphs, char *name)
{
  int		i;

  i = 0;
  while (graphs[i].name != NULL)
    {
      if (my_strcmp(graphs[i].name, name) == SUCCESS)
	return (i);
      i += 1;
    }
  return (ERROR);
}
