/*
** falling_piece_init.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/initialisation/falling_piece_init.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Mar  14 18:47:28 2016 Anas Buyumad
** Last update Thu Mar 17 18:16:58 2016 Gauthier Cler
*/

#include "tetris.h"

int	check_obstacle(t_init *setup, t_falling *falling_piece)
{
  int	x;
  int	y;

  y = 0;
  while (y < (int)falling_piece->token->height)
    {
      x = 0;
      while (x < (int)falling_piece->token->width)
	{
	  if (falling_piece->token->pos_1[y][x] == '*')
	    {
	      if (setup->board[falling_piece->pos_y + y]
		  [falling_piece->pos_x + x] > 0)
		return (ERROR);
	    }
	  x += 1;
	}
      y += 1;
    }
  return (SUCCESS);
}

int	falling_piece_init(t_init *setup, t_falling *falling_piece,
			   t_falling *next_piece, bool *gen_next)
{
  if (falling_piece->token == NULL)
    {
      init_falling_piece(setup, falling_piece);
      alter_piece(setup, falling_piece, DO_NOTHING);
    }
  if (*gen_next)
    {
      init_falling_piece(setup, next_piece);
      if (!setup->blind_mode)
	display_next_piece(next_piece, setup->windows.next_piece);
      *gen_next = false;
    }
  return (SUCCESS);
}

int	init_falling_piece(t_init *setup, t_falling *falling_piece)
{
  falling_piece->token = select_token(setup);
  falling_piece->pos_x = (setup->map.width / 2)
			 - (falling_piece->token->width / 2);
  falling_piece->pos_y = 0;
  return (SUCCESS);
}
