/*
** display_board.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/board/display_board.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Mar  09 20:22:24 2016 Anas Buyumad
** Last update Thu Mar 17 18:05:18 2016 Gauthier Cler
*/

#include	"tetris.h"

void	display_elem(WINDOW *board_win, int color, int width, int y)
{
  static int	im_hidden = 1;

  wattron(board_win, COLOR_PAIR((short int)color));
  mvwaddch(board_win, y + 1, im_hidden, ' ');
  mvwaddch(board_win, y + 1, im_hidden + 1, ' ');
  wattroff(board_win, COLOR_PAIR((short int)color));
  im_hidden += 2;
  if (im_hidden >= width * 2)
    im_hidden = 1;
}

void	display_board(int **board, int width, int height, WINDOW *board_win)
{
  int		x;
  int		y;

  y = 0;
  while (y < height)
  {
    x = 0;
    while (x < width)
    {
      display_elem(board_win, board[y][x], width, y);
      x += 1;
    }
    y += 1;
  }
  wrefresh(board_win);
}
