/*
** fill_graph.c for lemin in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 15:12:18 2016 Anas Buyumad
** Last update Mon Apr 25 20:40:21 2016 montag_v
*/

#include	<stdlib.h>
#include	"lemin.h"

int		epur_wordtab(char **param)
{
  int		i;

  i = 0;
  while (param[i] != NULL)
    {
      if ((param[i] = epur_str(param[i])) == NULL)
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

int		fill_room(t_graph *graph, t_list *list, int *i, int pos)
{
  char		**param;

  if ((param = my_str_to_wordtab(list->valeur)) == NULL)
    return (ERROR);
  if (epur_wordtab(param) == ERROR)
    return (ERROR);
  if ((graph->name = my_strdup(param[0])) == NULL)
    return (ERROR);
  graph->coo.x = my_atoi(param[1]);
  graph->coo.y = my_atoi(param[2]);
  graph->pos = pos;
  (graph->pos == START) ? (graph->weight = 0) : (graph->weight = -1);
  graph->capacity = 0;
  graph->links = NULL;
  graph->visited = false;
  graph->antecedent = NULL;
  graph->isol = false;
  *i += 1;
  free_array(param);
  return (SUCCESS);
}

int		skip_one(t_graph *graph, t_list **list, int *i, int mode)
{
  static int	nb_start = 0;
  static int	nb_end = 0;

  if (((*list) = (*list)->next) == NULL)
    return (ERROR);
  if (is_room((*list)->valeur) == ERROR)
    return (ERROR);
  if (fill_room(&graph[*i], (*list), i, mode) == ERROR)
    return (ERROR);
  if (mode == START)
    nb_start += 1;
  else if (mode == END)
    nb_end += 1;
  if (nb_start > 1 || nb_end > 1)
    return (ERROR);
  return (SUCCESS);
}

int		fill_graph(t_graph *graph, t_list *list)
{
  int		i;

  i = 0;
  while (list != NULL)
    {
      if ((list->valeur = epur_str(list->valeur)) == NULL)
	return (ERROR);
      if (my_strcmp(list->valeur, START_STRING) == SUCCESS)
	{
	  if (skip_one(graph, &list, &i, START) == ERROR)
	    return (ERROR);
	}
      else if (my_strcmp(list->valeur, END_STRING) == SUCCESS)
	{
	  if (skip_one(graph, &list, &i, END) == ERROR)
	    return (ERROR);
	}
      else if (is_room(list->valeur) == SUCCESS)
	fill_room(&graph[i], list, &i, 0);
      else if (my_strncmp(list->valeur, COMMENT_STRING, 1) == ERROR)
	return (is_link(list->valeur));
      list = list->next;
    }
  return (SUCCESS);
}
