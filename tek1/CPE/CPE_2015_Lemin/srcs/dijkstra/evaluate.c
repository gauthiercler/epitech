/*
** evaluate.c for lemin in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin/srcs/dijkstra/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 14:22:37 2016 Buyumad Anas
** Last update Mon Apr 25 23:18:16 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

int		all_visited(t_graph *graphs)
{
  int		i;

  i = 0;
  while (graphs[i].name != NULL)
    {
      if (graphs[i].visited == false && graphs[i].isol == false)
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

int		pick_lower_weight(t_graph *graphs)
{
  int		i;
  int		pick;
  int		weight;

  i = 0;
  pick = -1;
  weight = -1;
  while (graphs[i].name != NULL)
    {
      if ((weight >= 0) && (graphs[i].weight < weight) && (graphs[i].weight >= 0)
	  && (graphs[i].visited == false)
	  && (graphs[i].isol == false))
	{
	  pick = i;
	  weight = graphs[i].weight;
	}
      if ((weight == -1) && (graphs[i].weight >= 0)
	  && (graphs[i].visited == false) && (graphs[i].isol == false))
	{
	  pick = i;
	  weight = graphs[i].weight;
	}
      i += 1;
    }
  return (pick);
}

void		evaluate_weights(t_graph *graphs)
{
  int		index;

  while (all_visited(graphs) == ERROR)
    {
      index = pick_lower_weight(graphs);
      if (index == -1)
	return ;
      evaluate_neighbors(graphs, &graphs[index]);
    }
}
