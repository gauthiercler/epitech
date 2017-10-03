/*
** tab_to_str.c for PSU_2016_zappy in /home/montag_v/rendu/PSU_2016_zappy/server/srcs/parser/ai/response/tab_to_str.c
**
** Made by Valentin MONTAGNE
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Sun Jul 02 18:55:54 2017 Valentin MONTAGNE
** Last update Sun Jul 02 18:55:54 2017 Valentin MONTAGNE
*/

#include		<stdlib.h>
#include		<string.h>

unsigned int		get_len(char **cells)
{
  unsigned int		len;
  unsigned int		i;

  len = 0;
  i = 0;
  while (cells[i])
  {
    len += strlen(cells[i]) + 1;
    i += 1;
  }
  return (len);
}

char 			*tab_to_str(char **cells)
{
  char			*str;
  unsigned int		i;

  str = malloc(4 + get_len(cells));
  if (str == NULL)
    return (NULL);
  strcpy(str, "[");
  if (cells[0][0] == '\0')
    strcat(str, " ");
  i = 0;
  while (cells[i])
  {
    strcat(str, cells[i]);
    if (cells[i + 1] != NULL)
      strcat(str, ",");
    i += 1;
  }
  strcat(str, " ]\n");
  return (str);
}