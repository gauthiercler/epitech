/*
** gen_anthill.c for gen_anthill in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin/srcs/dijkstra/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 16:06:33 2016 Buyumad Anas
** Last update Fri Apr 22 17:50:38 2016 Buyumad Anas
*/

#include		<stdlib.h>
#include		"lemin.h"

int			find_first_node(t_graph *graph)
{
  int			i;

  i = 0;
  while (graph[i].name != NULL)
    {
      if (graph[i].pos == START)
	return (i);
      i += 1;
    }
  return (ERROR);
}

int			gen_anthill(t_lemin *lemin)
{
  int			i;
  int			start;

  if ((lemin->fourmis = malloc(sizeof(t_fourmi) * (lemin->nb_ant + 1))) == NULL)
    return (format(2, "Couldn't malloc.\n"));
  i = 0;
  start = find_first_node(lemin->graph);
  while (i < lemin->nb_ant)
    {
      if ((lemin->fourmis[i].node = my_strdup(lemin->graph[start].name)) == NULL)
	return (format(2, "Couldn't malloc.\n"));
      i += 1;
    }
  lemin->fourmis[i].node = NULL;
  return (SUCCESS);
}
