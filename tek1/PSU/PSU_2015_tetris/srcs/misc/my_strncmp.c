/*
** my_strncmp.c for my_strncmp in /tmp/PSU_2015_tetris/srcs/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  1 16:26:14 2016 Gauthier Cler
** Last update Thu Mar 17 18:21:14 2016 Gauthier Cler
*/

#include	"tetris.h"

int     my_strncmp(char *s1, char *s2, int count)
{
  int   i;

  i = 0;
  while (i < count)
    {
      if (s1[i] != s2[i])
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
