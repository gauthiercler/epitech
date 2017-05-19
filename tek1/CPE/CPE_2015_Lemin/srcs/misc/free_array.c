/*
** free_array.c for free_array in /home/montag_v/rendu/CPE_2015_Lemin
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Fri Apr 22 14:22:41 2016 montag_v
** Last update Sun Apr 24 18:09:19 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

void		free_array(char **str)
{
  int		i;

  i = 0;
  if (str != NULL)
    {
      while (str[i])
	{
	  free(str[i]);
	  i += 1;
	}
      free(str);
    }
}
