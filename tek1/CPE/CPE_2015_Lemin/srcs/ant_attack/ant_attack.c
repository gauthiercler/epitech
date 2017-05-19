/*
** ant_attack.c for lemin in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin/srcs/ant_attack/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 17:59:36 2016 Buyumad Anas
** Last update Mon Apr 25 15:56:32 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

int		attack_finished(t_graph *graphs, t_fourmi *fourmis)
{
  int		index;
  int		i;

  i = 0;
  index = get_end_index(graphs);
  while (fourmis[i].node != NULL)
    {
      if (my_strcmp(fourmis[i].node, graphs[index].name) == ERROR)
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

char		*get_next_node(t_path *path, char *current_node)
{
  t_path	*tmp;

  tmp = path;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->name, current_node) == SUCCESS)
	{
	  if (tmp->next != NULL)
	    return (tmp->next->name);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

void		empty_current_node(t_lemin *lemin, char *current_node)
{
  t_path	*tmp;
  int		index;

  tmp = lemin->path;
  while (tmp != NULL)
    {
      if (my_strcmp(current_node, tmp->name) == SUCCESS)
	{
	  index = get_node_index(lemin->graph, current_node);
	  if (lemin->graph[index].pos == 0)
	    {
	      if (lemin->graph[index].capacity == 1)
		lemin->graph[index].capacity = 0;
	    }
	}
      tmp = tmp->next;
    }
}

char		*attack_next_node(t_lemin *lemin, char *current_node)
{
  char		*next_node;
  int		index;

  next_node = get_next_node(lemin->path, current_node);
  index = get_node_index(lemin->graph, next_node);
  if (lemin->graph[index].pos == 0)
    {
      if (lemin->graph[index].capacity == 0)
	{
	  lemin->graph[index].capacity = 1;
	  empty_current_node(lemin, current_node);
	  return (next_node);
	}
    }
  else if (lemin->graph[index].pos == END)
    {
      empty_current_node(lemin, current_node);
      return (next_node);
    }
  return (NULL);
}

void		attack(t_lemin *lemin)
{
  int		i;
  int		index;
  char		*next_node;
  int		nb;

  i = 0;
  nb = 0;
  index = get_end_index(lemin->graph);
  while (lemin->fourmis[i].node != NULL)
    {
      if (my_strcmp(lemin->fourmis[i].node, lemin->graph[index].name) != SUCCESS)
	{
	  if ((next_node = attack_next_node(lemin, lemin->fourmis[i].node)) != NULL)
	    {
	      free(lemin->fourmis[i].node);
	      if ((lemin->fourmis[i].node = my_strdup(next_node)) == NULL)
		return ;
	      (nb == 0) ? format(1, "P%d-%s", i + 1, next_node) : 0;
	      (nb > 0) ? format(1, " P%d-%s", i + 1, next_node) : 0;
	      (nb == 0) ? nb += 1 : 0;
	    }
	}
      i += 1;
    }
  (nb != 0) ? format(1, "\n") : 0;
}
