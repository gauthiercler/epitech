/*
** check_row.c for check_row in /home/gogo/rendu/PSU_2015_tetris/srcs/game/board
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Wed Mar 16 15:27:04 2016 Gauthier Cler
** Last update Wed Mar 16 22:04:07 2016 Gauthier Cler
*/

#include	"tetris.h"

int		is_complete(int *line, int width)
{
  int		i;

  i = 0;
  while (i < width)
    {
      if (line[i] == 0)
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}

void		copy_to_next(int *src, int *dest, int width)
{
  int		i;

  i = 0;
  while (i < width)
    {
      dest[i] = src[i];
      i += 1;
    }
}

void		remove_line(int **board, int line, int width)
{
  int		i;

  i = line;
  while (i > 0)
    {
      copy_to_next(board[i - 1], board[i], width);
      i -= 1;
    }
}

void		check_completed_row(t_init *setup)
{
  int		i;

  i = 0;
  while (i < (int)setup->map.height)
    {
      if (is_complete(setup->board[i], setup->map.width) == SUCCESS)
	{
	  remove_line(setup->board, i, setup->map.width);
	  setup->rows += 1;
	  setup->score += 100;
	  if (setup->rows % 10 == 0)
	    setup->level += 1;
	  set_informations(setup);
	  setup->linebroken = true;
	}
      i += 1;
    }
}
