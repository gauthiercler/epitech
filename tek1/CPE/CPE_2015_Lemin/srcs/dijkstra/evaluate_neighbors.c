/*
** evaluate_neighbors.c for lemin in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin/srcs/dijkstra/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 14:49:13 2016 Buyumad Anas
** Last update Mon Apr 25 23:18:48 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

void		evaluate_neighbor(t_graph *graph, t_graph *father)
{
  if (graph->weight == -1)
    {
      graph->weight = father->weight + 1;
      graph->antecedent = my_strdup(father->name);
    }
  else if (graph->weight >= 0 && (father->weight + 1) < graph->weight)
    {
      graph->weight = father->weight + 1;
      graph->antecedent = my_strdup(father->name);
    }
}

void		evaluate_neighbors(t_graph *graphs, t_graph *node)
{
  int		index;
  int		i;

  i = 0;
  while (node->links[i] != NULL)
    {
      index = get_node_index(graphs, node->links[i]);
      if (index >= 0)
	evaluate_neighbor(&graphs[index], node);
      i += 1;
    }
  node->visited = true;
}
