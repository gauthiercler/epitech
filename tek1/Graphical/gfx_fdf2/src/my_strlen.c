/*
** my_strlen.c for my_strlen in /home/gauthier/rendu/gfx_fdf2/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec 15 23:30:14 2015 Gauthier Cler
** Last update Wed Dec 16 11:14:07 2015 Gauthier Cler
*/

#include	"fdf.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
