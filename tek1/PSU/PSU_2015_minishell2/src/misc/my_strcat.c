/*
** my_strcat.c for my_strcat in /home/gogo/rendu/PSU_2015_minishell2/src/misc
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Mar 29 14:18:51 2016 Gauthier Cler
** Last update Sun Apr  3 20:31:44 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"mysh.h"

char		*my_strcat(char *str1, char *str2)
{
  int		count;
  char		*res;
  int		i;

  if (str1 == NULL || str2 == NULL)
    return (0);
  count = my_strlen(str1) + my_strlen(str2);
  res = xmalloc(sizeof(char) * count + 1);
  i = 0;
  count = 0;
  while (str1[i])
    {
      res[count] = str1[i];
      count += 1;
      i += 1;
    }
  i = 0;
  while (str2[i])
    {
      res[count++] = str2[i];
      i += 1;
    }
  res[count] = '\0';
  return (res);
}
