/*
** my_strdup.c for my_strdup in /home/gauthier/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec  8 17:50:42 2015 Gauthier Cler
** Last update Tue Dec  8 17:50:48 2015 Gauthier Cler
*/

#include "info.h"

char    *my_strdup(char *str)
{
  char  *res;
  int   i;
  int   j;

  i = 0;
  j = my_strlen(str);
  res = malloc(sizeof(char) * j + 1);
  res[j] = '\0';
  while (str[i])
    {
      res[i] = str[i];
      i++;
    }
  return (res);
}
