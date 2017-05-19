/*
** skip_char.c for skip_char in /home/montag_v/rendu/CPE_2015_Lemin
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Thu Apr 21 14:24:33 2016 montag_v
** Last update Fri Apr 22 10:21:15 2016 montag_v
*/

#include	<stdlib.h>
#include	"lemin.h"

char		*epur_str(char *line)
{
  char		*str;
  int		j;
  int		i;

  i = 0;
  j = 0;
  while ((line[i] == ' ' || line[i] == '\t') && line[i])
    i += 1;
  if (line[i] == '\0')
    return (NULL);
  if ((str = malloc(sizeof(char) * (str_len(line + i) + 1))) == NULL)
    return (NULL);
  while (line[i] != '\0')
    {
      str[j] = line[i];
      j += 1;
      i += 1;
    }
  j -= 1;
  while ((str[j] == ' ' || str[j] == '\t') && j != 0)
    j--;
  str[j + 1] = '\0';
  free(line);
  return (str);
}
