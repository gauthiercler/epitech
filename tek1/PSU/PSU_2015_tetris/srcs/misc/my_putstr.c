/*
** my_putstr.c for my_putstr in /tmp/PSU_2015_tetris/srcs/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  1 17:51:17 2016 Gauthier Cler
** Last update Thu Mar 17 18:20:36 2016 Gauthier Cler
*/

#include	"tetris.h"

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 27)
	write(1, "^E", 2);
      else
	write(1, &str[i], 1);
      i += 1;
    }
}
