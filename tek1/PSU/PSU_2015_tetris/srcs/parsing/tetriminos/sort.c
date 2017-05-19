/*
** sort.c for sort in /tmp/PSU_2015_tetris/srcs/parsing/tetriminos
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sat Mar  5 15:10:09 2016 Gauthier Cler
** Last update Sat Mar  5 15:10:58 2016 Gauthier Cler
*/

#include	"tetris.h"

int     my_strcmp_sort(char *str1, char *str2)
{
  int   i;

  i = 0;
  while (str1[i])
    {
      if (str1[i] > str2[i])
	return (1);
      else if (str1[i] < str2[i])
	return (-1);
      i++;
    }
  if (str2[i] != 0)
    return (-1);
  else
    return (0);
}

int             sort_ascii(t_token *tokens, int nb_tokens)
{
  int           i;
  t_token       tmp;

  i = 0;
  while (i < nb_tokens - 1)
    {
      if (my_strcmp_sort(tokens[i].name, tokens[i + 1].name) == 1)
	{
	  tmp = tokens[i];
	  tokens[i] = tokens[i + 1];
	  tokens[i + 1] = tmp;
	  return (ERROR);
	}
      i += 1;
    }
  return (SUCCESS);
}
