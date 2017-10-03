/*
** free_explode.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/lib/cextended/srcs/string_extended/free_explode.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 30 18:02:14 2017 Montagne Valentin
** Last update Fri Jun 30 18:02:14 2017 Montagne Valentin
*/

#include		<stdlib.h>
#include		"string_extended.h"

void			free_explode(char **explode)
{
  unsigned int		i;

  i = 0;
  if (explode != NULL)
  {
    while (explode[i] != NULL)
    {
      free(explode[i]);
      i += 1;
    }
    free(explode);
  }
}