/*
** load_graphs.c for load_graphs in /home/montag_v/rendu/gfx_tekadventure
**
** Made by valentin montagne
** Login   <montag_v@epitech.net>
**
** Started on  Sun Apr 17 16:55:35 2016 valentin montagne
** Last update Sun Apr 17 21:43:58 2016 Buyumad Anas
*/

#include	<lapin.h>
#include	"adventure.h"

int		fill_graph(t_bunny_ini *ini,
			   t_graph *graph,
			   char *scope,
			   int current)
{
  char		*number;
  int		nb;
  int		i;

  number = my_strdup("1");
  number[0] += current;
  if ((graph->pos.x = my_atoi(bunny_ini_get_field(ini, scope, number, 0))) < 0)
    return (format(2, "%s : posX < 0\n", scope));
  if ((graph->pos.y = my_atoi(bunny_ini_get_field(ini, scope, number, 1))) < 0)
    return (format(2, "%s : posY < 0\n", scope));
  if ((graph->size.x = my_atoi(bunny_ini_get_field(ini, scope, number, 2))) < 0)
    return (format(2, "%s : sizeX < 0\n", scope));
  if ((graph->size.y = my_atoi(bunny_ini_get_field(ini, scope, number, 3))) < 0)
    return (format(2, "%s : sizeY < 0\n", scope));
  if ((nb = my_atoi(bunny_ini_get_field(ini, scope, number, 4))) <= 0)
    return (format(2, "%s : nb < 0\n", scope));
  graph->nb_links = nb;
  if ((graph->links = bunny_malloc(sizeof(int) * nb)) == NULL)
    return (format(2, "Couldn't malloc\n"));
  i = -1;
  while (++i < nb)
    if ((graph->links[i] =
	 my_atoi(bunny_ini_get_field(ini, scope, number, 5 + i))) < 0)
      return (format(2, "number < 0 at %d\n", i));
  return (SUCCESS);
}

t_graph         *load_graph(t_bunny_ini *ini,
                           char *scope)
{
  char          *name;
  int           nb;
  int           i;
  t_graph       *graphs;

  if ((name = (char *)bunny_ini_get_field(ini, scope, "graph", 0)) == NULL)
    return (p_error("load_graph : Couldn't find graph\n"));
  if ((nb = my_atoi(bunny_ini_get_field(ini, name, "nb_graphs", 0))) < 0)
    return (p_error("load_graph : nb_graphs < 0\n"));
  if ((graphs = bunny_malloc(sizeof(t_graph) * (nb + 1))) == NULL)
    return (p_error("load_graph : Couldn't malloc.\n"));
  i = 0;
  while (i < nb)
    {
      if (fill_graph(ini, &graphs[i], name, i) == ERROR)
	return (p_error("load_graph : Couldn't load a graph\n"));
      i++;
    }
  graphs[i].links = NULL;
  return (graphs);
}
