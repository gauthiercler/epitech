/*
** my_strcpy.c for my_strcpy in /home/gogo/rendu/PSU_2015_minishell2/src/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Mar 16 09:07:07 2016 Gauthier Cler
** Last update Wed Mar 16 09:08:03 2016 Gauthier Cler
*/

#include	"mysh.h"

void		my_strcpy(char *src, char *dest)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i += 1;
    }
}
