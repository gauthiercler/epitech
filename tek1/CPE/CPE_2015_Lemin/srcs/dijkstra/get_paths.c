/*
** get_paths.c for lemin in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_Lemin/srcs/dijkstra/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Apr 22 14:10:15 2016 Buyumad Anas
** Last update Mon Apr 25 23:19:57 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

void		disp_path(t_path *path)
{
  t_path	*tmp;

  tmp = path;
  while (tmp != NULL)
    {
      format(1, "%s ", tmp->name);
      tmp = tmp->next;
    }
  format(1, "\n");
}

int		check_path(t_path *path, t_graph *graph)
{
  int		start;
  int		end;
  int		res;
  t_path	*tmp;

  tmp = path;
  res = 0;
  start = get_start_index(graph);
  end = get_end_index(graph);
  while (tmp != NULL)
    {
      if (my_strcmp(graph[start].name, tmp->name) == SUCCESS)
	res += 1;
      else if (my_strcmp(graph[end].name, tmp->name) == SUCCESS)
	res += 1;
      tmp = tmp->next;
    }
  if (res == 2)
    return (SUCCESS);
  return (ERROR);
}

int		get_paths(t_lemin *lemin)
{
  lemin->path = dijkstra(lemin->graph);
  if (lemin->path == NULL)
    return (format(2, "path is null.\n"));
  if (check_path(lemin->path, lemin->graph) == ERROR)
    return (format(2, "No path between start and end.\n"));
  return (SUCCESS);
}
