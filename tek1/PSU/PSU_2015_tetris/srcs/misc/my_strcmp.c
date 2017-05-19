/*
** my_strcmp.c for tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/misc
** 
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
** 
** Started on  Thu Feb 25 19:07:27 2016 Anas Buyumad
** Last update Tue Mar  1 17:18:48 2016 Gauthier Cler
*/

#include "tetris.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (ERROR);
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
