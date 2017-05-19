/*
** free_tab.c for free_tab in /home/gogo/rendu/PSU_2015_minishell2/src/clean
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr  2 20:38:21 2016 Gauthier Cler
** Last update Wed Apr 13 13:59:57 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i])
	{
	  if (tab[i] != NULL)
	    free(tab[i]);
	  i += 1;
	}
      free(tab);
    }
}
