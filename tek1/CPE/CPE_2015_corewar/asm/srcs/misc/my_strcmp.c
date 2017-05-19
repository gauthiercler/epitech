/*
** my_strcmp.c for asm in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar 22 18:41:52 2016 Gauthier Cler
** Last update Tue Mar 22 18:41:52 2016 Gauthier Cler
*/

#include	"asm.h"

int		my_strcmp(char *s1, char *s2)
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
