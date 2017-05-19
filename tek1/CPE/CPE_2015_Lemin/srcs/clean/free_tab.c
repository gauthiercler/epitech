/*
** free_tab.c for free_tab in /home/gogo/rendu/CPE_2015_Lemin/srcs/clean/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 23 01:01:36 2016 Gauthier Cler
** Last update Sun Apr 24 18:07:29 2016 Gauthier Cler
*/

#include		<stdlib.h>
#include		"lemin.h"

void			free_tab(char **tab)
{
  int			i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i])
	{
	  free(tab[i]);
	  i += 1;
	}
      free(tab);
    }
}
