/*
** check_links.c for check_links in /home/montag_v/rendu/CPE_2015_Lemin
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Fri Apr 22 14:43:26 2016 montag_v
** Last update Sun Apr 24 23:26:51 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

int		check_list(t_graph *graph, t_list *list)
{
  int		j;
  int		i;

  i = 0;
  j = 0;
  while (list->valeur[j] != '-')
    j += 1;
  while (graph[i].name != NULL)
    {
      if (my_strncmp(list->valeur, graph[i].name, j) == SUCCESS)
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}

int		check_list_links(t_graph *graph, t_list *list)
{
  while (list != NULL)
    {
      if (is_link(list->valeur) == SUCCESS)
	if (check_list(graph, list) == ERROR)
	  return (ERROR);
      list = list->next;
    }
  return (SUCCESS);
}

int		check_links(t_graph *graph)
{
  int		i;

  i = 0;
  while (graph[i].name != NULL)
    {
      if (graph[i].links[0] == NULL)
	graph[i].isol = true;
      i += 1;
    }
  return (SUCCESS);
}
