/*
** graph_links.c for graph_links in /home/montag_v/rendu/CPE_2015_Lemin/srcs/parsing
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Fri Apr 22 15:50:39 2016 montag_v
** Last update Mon Apr 25 19:38:44 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

int		pos_graph(t_graph *graph, char *name)
{
  int		i;

  i = 0;
  while (graph[i].name != NULL)
    {
      if (my_strcmp(name, graph[i].name) == SUCCESS)
	return (i);
      i += 1;
    }
  return (ERROR);
}

int		find_link(t_graph *graph, char *name)
{
  int		i;

  i = 0;
  while (graph->links[i] != NULL)
    {
      if (my_strcmp(graph->links[i], name) == SUCCESS)
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}

int		realloc_links(t_graph *graph, char *name)
{
  char		**new;
  int		i;

  i = 0;
  while (graph->links[i] != NULL)
    i += 1;
  if ((new = malloc(sizeof(char *) * (i + 2))) == NULL)
    return (format(2, "Couln't malloc\n."));
  i = 0;
  while (graph->links[i] != NULL)
    {
      new[i] = my_strdup(graph->links[i]);
      i += 1;
    }
  if ((new[i] = my_strdup(name)) == NULL)
    return (ERROR);
  new[i + 1] = NULL;
  free_array(graph->links);
  graph->links = new;
  return (SUCCESS);
}

int		graph_links(t_graph *graph)
{
  int		pos;
  int		i;
  int		j;

  i = 0;
  while (graph[i].name != NULL)
    {
      j = 0;
      while (graph[i].links[j] != NULL)
	{
	  pos = pos_graph(graph, graph[i].links[j]);
	  if (find_link(&graph[pos], graph[i].name) == ERROR)
	    if (realloc_links(&graph[pos], graph[i].name) == ERROR)
	      return (ERROR);
	  j += 1;
	}
      i += 1;
    }
  return (SUCCESS);
}
