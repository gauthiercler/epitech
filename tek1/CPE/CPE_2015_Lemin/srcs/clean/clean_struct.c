/*
** clean_struct.c for clean_struct in /home/gogo/rendu/CPE_2015_Lemin/srcs/clean/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 23 00:38:23 2016 Gauthier Cler
** Last update Sat Apr 23 01:13:08 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

void		clean_fourmis(t_fourmi *fourmis)
{
  int		i;

  i = 0;
  while (fourmis[i].node != NULL)
    {
      free(fourmis[i].node);
      i += 1;
    }
  free(fourmis);
}

void		clean_path(t_path *path)
{
  t_path	*tmp;

  tmp = NULL;
  while (path != NULL)
    {
      tmp = path->next;
      free(path->name);
      free(path);
      path = tmp;
    }
}

void		clean_input(t_list *list)
{
  t_list	*tmp;

  tmp = NULL;
  while (list != NULL)
    {
      tmp = list->next;
      free(list->valeur);
      free(list);
      list = tmp;
    }
}

void		clean_graph(t_graph *graph)
{
 int		i;

 i = 0;
 while (graph[i].name != NULL)
    {
      free(graph[i].name);
      free(graph[i].antecedent);
      free_tab(graph[i].links);
      i += 1;
    }
  free(graph);
}

void		clean_struct(t_lemin *lemin)
{
  clean_fourmis(lemin->fourmis);
  clean_path(lemin->path);
  clean_input(lemin->list);
  clean_graph(lemin->graph);
}
