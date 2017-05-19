/*
** alter_piece.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/pieces/alter_piece.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar  10 22:05:07 2016 Anas Buyumad
** Last update Wed Mar 16 18:49:17 2016 Anas Buyumad
*/

#include	"tetris.h"

void	clean_current_pos(t_init *setup, t_falling *falling_piece)
{
  int   x;
  int   y;

  y = 0;
  while (y < (int)falling_piece->token->height)
  {
    x = 0;
    while (x < (int)falling_piece->token->width)
    {
      if (select_piece_part(falling_piece->token, x, y,
			    falling_piece->token->state) == SUCCESS)
        setup->board[falling_piece->pos_y + y][falling_piece->pos_x + x] = 0;
      x += 1;
    }
    y += 1;
  }
}

int	set_in_board(t_init *setup, t_falling *falling_piece, int state)
{
  int   x;
  int   y;

  y = 0;
  while (y < (int)falling_piece->token->height)
  {
    x = 0;
    while (x < (int)falling_piece->token->width)
    {
      if (select_piece_part(falling_piece->token, x, y, state) == SUCCESS)
        setup->board[falling_piece->pos_y + y][falling_piece->pos_x + x] =
	  (int)falling_piece->token->color;
      x += 1;
    }
    y += 1;
  }
  return (SUCCESS);
}

int	alter_piece(t_init *setup, t_falling *falling_piece, int action)
{
  int	status;

  if (setup->linebroken)
  {
    setup->linebroken = false;
    return (ERROR);
  }
  status = SUCCESS;
  clean_current_pos(setup, falling_piece);
  if (call_checker(setup, falling_piece, action) == SUCCESS)
    action_piece(falling_piece, action);
  else
    status = ERROR;
  set_in_board(setup, falling_piece, falling_piece->token->state);
  display_board(setup->board, setup->map.width, setup->map.height,
                setup->windows.board);
  return (status);
}
