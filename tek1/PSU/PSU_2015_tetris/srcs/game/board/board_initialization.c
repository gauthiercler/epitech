/*
** board_initialization.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/board/board_initialization.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Mar  09 20:09:47 2016 Anas Buyumad
** Last update Wed Mar  09 20:09:47 2016 Anas Buyumad
*/

#include	"tetris.h"

void	void_line(int *line, int width)
{
  int	i;

  i = 0;
  while (i < width)
  {
    line[i] = 0;
    i += 1;
  }
}

int	**initiate_board(int width, int height)
{
  int	**board;
  int	i;

  i = 0;
  if ((board = malloc(sizeof(int *) * height)) == NULL)
    return (NULL);
  while (i < height)
  {
    if ((board[i] = malloc(sizeof(int) * width)) == NULL)
      return (NULL);
    void_line(board[i], width);
    i += 1;
  }
  return (board);
}