/*
** find_path.c for tekadventure in /home/doleanv/Premiere_annee/infographie/gfx_tekadventure/srcs/graphs
**
** Made by Doleans Vianney
** Login   <vianney.doleans@epitech.eu>
**
** Started on  Thu Apr 14 14:58:40 2016 Doleans Vianney
** Last update Sun Apr 17 20:00:12 2016 Gauthier Cler
*/

#include		<adventure.h>

int		count_link(t_graph *graph)
{
  int		i;

  i = 0;
  while (graph[i].links != NULL)
    i++;
  return (i);
}

int		check_path(int	*path, int max, int size)
{
  int		i;
  int		e;
  int		active;

  i = 0;
  while (i < max)
    {
      active = 0;
      e = 0;
      while (e < size)
	{
	  if (path[e] == i)
	    active++;
	  if (active > 1)
	    return (1);
	  e++;
	}
      i++;
    }
  return (0);
}

void		research_path(t_graph *graph, int origin,
			      int destination, t_path *path)
{
  bool		active;
  int		y;
  int		pos;

  pos = origin;
  y = 0;
  active = false;
  while (active == false)
    {
      path->path[y] = graph[pos].links[rand() % graph[pos].nb_links];
      pos = path->path[y];
      if (y == path->nb_path || check_path(path->path, path->nb_path, y) == 1)
	{
	  y = 0;
	  pos = origin;
	}
      else if (pos == destination)
	active = true;
      else
	y++;
    }
  path->nb_path = y + 1;
}

t_path		*find_path(t_graph *graph, int origin, int destination)
{
  t_path	*path;

  if ((path = bunny_malloc(sizeof(t_path))) == NULL)
    return (NULL);
    path->nb_path = count_link(graph);
  if ((path->path = bunny_malloc(sizeof(int) * path->nb_path)) == NULL)
    return (NULL);
  research_path(graph, origin, destination, path);
  return (path);
}
