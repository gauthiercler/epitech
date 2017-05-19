/*
** fill_links.c for lemin in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 15:12:32 2016 Anas Buyumad
** Last update Sun Apr 24 18:03:45 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

int		count_links(char *name, t_list *list)
{
  int		i;

  i = 0;
  while (list != NULL)
    {
      if (my_strncmp(list->valeur, name, str_len(name)) == SUCCESS)
	i += 1;
      list = list->next;
    }
  return (i);
}

int		is_valid(t_graph *graph, char *name)
{
  int		i;

  i = 0;
  while (graph[i].name != NULL)
    {
      if (my_strcmp(graph[i].name, name) == SUCCESS)
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}

int		fill_link(t_graph *all, t_graph *graph, t_list *list)
{
  int		link;

  link = 0;
  while (list != NULL)
    {
      if (((my_strncmp(list->valeur,
		       graph->name, str_len(graph->name))) == SUCCESS)
	  && is_link(list->valeur) == SUCCESS
	  && is_valid(all, list->valeur + str_len(graph->name) + 1) == SUCCESS)
	{
	  if ((graph->links[link] =
	       my_strdup(list->valeur + str_len(graph->name) + 1)) == NULL)
	    return (ERROR);
	  link += 1;
	}
      list = list->next;
    }
  graph->links[link] = NULL;
  return (SUCCESS);
}

int		fill_links(t_graph *graph, t_list *list)
{
  int		j;
  int		nb_link;

  j = 0;
  while (graph[j].name != NULL)
    {
      nb_link = count_links(graph[j].name, list);
      if (nb_link > 0)
	{
	  if ((graph[j].links
	       = malloc(sizeof(char *) * (nb_link + 1))) == NULL)
	    return (format(2, "Couldn't malloc\n."));
	  if (fill_link(graph, &graph[j], list) == ERROR)
	    return (ERROR);
	}
      j += 1;
    }
  return (SUCCESS);
}
