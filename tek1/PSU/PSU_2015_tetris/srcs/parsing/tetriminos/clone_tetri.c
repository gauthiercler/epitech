/*
** clone_tetri.c for clone_tetri in /tmp/PSU_2015_tetris/srcs/parsing/tetriminos
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar  1 15:53:10 2016 Gauthier Cler
** Last update Wed Mar  2 18:14:36 2016 Gauthier Cler
*/

#include	"tetris.h"

void		fill_2(t_token *tokens, int i)
{
  int		j;
  int		k;
  int		l;
  int		m;

  m = 0;
  j = 0;
  while (j < (int)tokens[i].width)
    {
      l = 0;
      k = tokens[i].height - 1;
      while (k >= 0)
	{
	  tokens[i].pos_2[m][l] = tokens[i].pos_1[k][j];
	  l += 1;
	  k -= 1;
	}
      m += 1;
      j += 1;
    }
}

int		copy_2(t_token *tokens, int i)
{
  int		j;

  j = 0;
  if ((tokens[i].pos_2 =
       malloc(sizeof(char *) * tokens[i].width)) == NULL)
    return (ERROR);
  while (j < (int)tokens[i].width)
    {
      if ((tokens[i].pos_2[j] =
	   malloc(sizeof(char) * tokens[i].height + 1)) == NULL)
	return (ERROR);
      tokens[i].pos_2[j][tokens[i].height] = '\0';
      j += 1;
    }
  fill_2(tokens, i);
  return (SUCCESS);
}

void		fill_3(t_token *tokens, int i)
{
  int		j;
  int		k;
  int		l;
  int		m;

  m = 0;
  j = tokens[i].height - 1;
  while (j >= 0)
    {
      l = 0;
      k = tokens[i].width - 1;
      while (k >= 0)
	{
	  tokens[i].pos_3[m][l] = tokens[i].pos_1[j][k];
	  l += 1;
	  k -= 1;
	}
      m += 1;
      j -= 1;
    }
}

int		copy_3(t_token *tokens, int i)
{
  int		j;

  j = 0;
  if ((tokens[i].pos_3 =
       malloc(sizeof(char *) * tokens[i].height)) == NULL)
    return (ERROR);
  while (j < (int)tokens[i].height)
    {
      if ((tokens[i].pos_3[j] =
	   malloc(sizeof(char) * tokens[i].width + 1)) == NULL)
	return (ERROR);
      tokens[i].pos_3[j][tokens[i].width] = '\0';
      j += 1;
    }
  fill_3(tokens, i);
  return (SUCCESS);
}

int		clone_tetri(t_token *tokens, int i)
{
  if (tokens[i].valid == false)
    {
      tokens[i].pos_2 = NULL;
      tokens[i].pos_3 = NULL;
      tokens[i].pos_4 = NULL;
      return (SUCCESS);
    }
  if (copy_2(tokens, i) == ERROR)
    return (ERROR);
  if (copy_3(tokens, i) == ERROR)
    return (ERROR);
  if (copy_4(tokens, i) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
