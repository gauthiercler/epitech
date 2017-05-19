/*
** is_room.c for is_room in /home/montag_v/rendu/CPE_2015_Lemin
**
** Made by montag_v
** Login   <montag_v@epitech.net>
**
** Started on  Thu Apr 21 14:21:15 2016 montag_v
** Last update Mon Apr 25 22:25:14 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"lemin.h"

int		is_room(char *line)
{
  char		**param;
  int		i;

  if (line == NULL)
    return (NULL_STR);
  i = 0;
  if ((param = my_str_to_wordtab(line)) == NULL)
    return (NULL_STR);
  while (param[i] != NULL)
    i++;
  free_array(param);
  if (i != 3)
    return (ERROR);
  return (SUCCESS);
}
