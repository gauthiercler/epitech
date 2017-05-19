/*
** my_strcat.c for my_strcat in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 19 15:46:31 2016 Gauthier Cler
** Last update Fri Feb 12 15:21:23 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"../include/info.h"

char	*my_strcat(char *str1, char *str2)
{
  int	i;
  int	j;
  char	*res;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) *
		    my_strlen(str1) + my_strlen(str2) + 1)) == NULL)
    malloc_error();
  while (str1[i])
    res[j++] = str1[i++];
  i = 0;
  while (str2[i])
    res[j++] = str2[i++];
  res[j] = '\0';
  return (res);
}
