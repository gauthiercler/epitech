/*
** parsing.c for parsing in /home/montag_v/rendu/CPE_2015_Lemin
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Wed Apr 20 17:35:03 2016 montag_v
** Last update Mon Apr 25 22:31:40 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

int		prepare(t_list **list)
{
  char		*str;

  while ((str = get_next_line(0)) != NULL)
    {
      if (add_fin_liste(list, str) == ERROR)
	return (ERROR);
      free(str);
    }
  disp_liste(*list);
  return (SUCCESS);
}

int		nb_fourmi(t_lemin *lemin, t_list **list)
{
  if (((*list)->valeur = epur_str((*list)->valeur)) == NULL)
    return (ERROR);
  lemin->nb_ant = my_atoi((*list)->valeur);
  if (lemin->nb_ant == ERROR || lemin->nb_ant < 0)
    return (format(2, "Nb_ant is invalid.\n"));
  free(list[0]->valeur);
  (*list) = (*list)->next;
  return (SUCCESS);
}

int		count_graph(t_list *list)
{
  int		i;
  int		ret;

  i = 0;
  while (list != NULL)
    {
      if ((ret = is_room(list->valeur)) == SUCCESS)
	i += 1;
      else if (ret == NULL_STR)
	return (ERROR);
      list = list->next;
    }
  return (i);
}

int		parsing(t_lemin *lemin)
{
  int		nb_graph;

  if (prepare(&lemin->list) == ERROR)
    return (ERROR);
  if (liste_len(lemin->list) == 0)
    return (ERROR);
  if (nb_fourmi(lemin, &lemin->list) == ERROR)
    return (ERROR);
  if ((nb_graph = count_graph(lemin->list)) == ERROR
      || nb_graph == 0)
    return (format(2, "no data after nb_ants.\n"));
  if ((lemin->graph = malloc(sizeof(t_graph) * (1 + nb_graph))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  lemin->graph[nb_graph].name = NULL;
  if (fill_graph(lemin->graph, lemin->list) == ERROR)
    return (format(2, "Error syntax\n"));
  if (check_list_links(lemin->graph, lemin->list) == ERROR)
    return (format(2, "Links unknown.\n"));
  if (fill_links(lemin->graph, lemin->list) == ERROR)
    return (ERROR);
  if (graph_links(lemin->graph) == ERROR)
    return (format(2, "Incorrect graph links.\n"));
  if (check_links(lemin->graph) == ERROR)
    return (format(2, "Links invalid.\n"));
  return (SUCCESS);
}
