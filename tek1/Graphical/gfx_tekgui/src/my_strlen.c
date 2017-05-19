/*
** my_strlen.c for my_strlen in /home/gogo/rendu/gfx_tekgui/src
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb 15 13:51:55 2016 Gauthier Cler
** Last update Mon Feb 15 13:51:55 2016 Gauthier Cler
*/

#include	"tekgui.h"

int	my_strlen(char *str)
{
  long int	i;

  if (str[0] == 0)
    return (0);
  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}
