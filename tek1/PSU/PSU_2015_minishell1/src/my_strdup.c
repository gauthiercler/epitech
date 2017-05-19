/*
** my_strdup.c for my_strdup$ in /home/gauthier/rendu/PSU_2015_minishell1/src
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Jan 19 18:31:48 2016 Gauthier Cler
** Last update Sat Jan 23 18:26:52 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"../include/info.h"

char    *my_strdup(char *str)
{
  char  *res;
  int   i;
  int   j;

  i = 0;
  j = my_strlen(str);
  if ((res = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    malloc_error();
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  res[i] = '\0';
  return (res);
}
