/*
** misc.c for misc in /home/gogo/rendu/CPE_2015_Allum1
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Feb 10 20:38:36 2016 Gauthier Cler
** Last update Fri Feb 19 14:18:08 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"alu.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

int             is_num(char *str)
{
  int           i;

  i = 0;
  if (my_strlen(str) == 0)
    return (0);
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i += 1;
    }
  return (1);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
