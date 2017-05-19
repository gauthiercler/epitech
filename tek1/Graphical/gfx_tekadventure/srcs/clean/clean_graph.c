/*
** clean_graph.c for clean_grap in /home/gogo/rendu/gfx_tekadventure
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun Apr 17 20:12:07 2016 Gauthier Cler
** Last update Sun Apr 17 20:12:34 2016 Gauthier Cler
*/

#include		"adventure.h"

void                    clean_graph(t_graph *graphs)
{
  int                   i;

  i = 0;
  while (graphs[i].links != NULL)
    {
      bunny_free(graphs[i].links);
      i += 1;
    }
}
