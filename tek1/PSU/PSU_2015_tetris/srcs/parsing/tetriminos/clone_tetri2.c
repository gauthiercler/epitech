/*
** clone_tetri2.c for clone_tetri2 in /tmp/PSU_2015_tetris/srcs/parsing/tetriminos
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Mar  2 18:04:23 2016 Gauthier Cler
** Last update Wed Mar  2 18:14:58 2016 Gauthier Cler
*/

#include	"tetris.h"

void            fill_4(t_token *tokens, int i)
{
  int           j;
  int           k;
  int           l;
  int           m;

  m = 0;
  j = tokens[i].width - 1;
  while (j >= 0)
    {
      l = 0;
      k = 0;
      while (k < (int)tokens[i].height)
	{
	  tokens[i].pos_4[m][l] = tokens[i].pos_1[k][j];
	  l += 1;
	  k += 1;
	}
      m += 1;
      j -= 1;
    }
}

int             copy_4(t_token *tokens, int i)
{
  int           j;

  j = 0;
  if ((tokens[i].pos_4 =
       malloc(sizeof(char *) * tokens[i].width)) == NULL)
    return (ERROR);
  while (j < (int)tokens[i].width)
    {
      if ((tokens[i].pos_4[j] =
	   malloc(sizeof(char) * tokens[i].height + 1)) == NULL)
	return (ERROR);
      tokens[i].pos_4[j][tokens[i].height] = '\0';
      j += 1;
    }
  fill_4(tokens, i);
  return (SUCCESS);
}
