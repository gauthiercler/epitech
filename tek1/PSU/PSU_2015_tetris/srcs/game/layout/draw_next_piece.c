/*
** draw_next_piece.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/layout/draw_next_piece.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Mar  14 14:10:23 2016 Anas Buyumad
** Last update Thu Mar 17 18:41:12 2016 Gauthier Cler
*/

#include	"tetris.h"

void	clean_next_piece(WINDOW *next_win)
{
  int   dim[2];
  int	y;
  int	x;

  getmaxyx(next_win, dim[1], dim[0]);
  y = 1;
  while (y < dim[1] - 1)
  {
    x = 1;
    while (x < dim[0] - 1)
    {
      wattron(next_win, COLOR_PAIR((short int)BG_COLOR));
      mvwaddch(next_win, y, x, ' ');
      wattroff(next_win, COLOR_PAIR((short int)BG_COLOR));
      x += 1;
    }
    y += 1;
  }
  wrefresh(next_win);
}

void	draw_piece_part(WINDOW *next_win, int color, int width, int y)
{
  static int	im_hidden = 1;

  if (y == - 1)
    im_hidden += 2;
  else
    {
      wattron(next_win, COLOR_PAIR((short int)color));
      mvwaddch(next_win, y + 1, im_hidden, ' ');
      mvwaddch(next_win, y + 1, im_hidden + 1, ' ');
      wattroff(next_win, COLOR_PAIR((short int)color));
      im_hidden += 2;
    }
  if (im_hidden >= width * 2)
    im_hidden = 1;
}

void	display_next_piece(t_falling *next_piece, WINDOW *next_win)
{
  int	y;
  int	x;

  y = 0;
  clean_next_piece(next_win);
  draw_window_outline(next_win, "Next");
  while (y < (int)next_piece->token->height)
  {
    x = 0;
    while (x < (int)next_piece->token->width)
    {
      if (select_piece_part(next_piece->token, x, y
			    , next_piece->token->state) == SUCCESS)
	draw_piece_part(next_win, next_piece->token->color
			, next_piece->token->width, y);
      else
        draw_piece_part(next_win, next_piece->token->color
			, next_piece->token->width, -1);
	x += 1;
    }
    y += 1;
  }
  wrefresh(next_win);
}
