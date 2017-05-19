/*
** my_strcat.c for my_strcat in /home/gogo/rendu/PSU_2015_tetris/srcs/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Feb 29 20:42:20 2016 Gauthier Cler
** Last update Thu Mar 17 18:20:48 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"tetris.h"

char	*my_strcat(char *str1, char *str2)
{
  char	*res;
  int	i;
  int	j;
  int	len;

  if (str1 == NULL || str2 == NULL)
    return (NULL);
  len = my_strlen(str1) + my_strlen(str2);
  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) * len + 1)) == NULL)
    return (NULL);
  while (str1[i])
    res[j++] = str1[i++];
  i = 0;
  while (str2[i])
    res[j++] = str2[i++];
  return (res);
}
