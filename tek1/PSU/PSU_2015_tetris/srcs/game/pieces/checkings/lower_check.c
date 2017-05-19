/*
** lower_check.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/pieces/checkings/lower_check.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Mar  11 13:15:50 2016 Anas Buyumad
** Last update Wed Mar 16 18:41:11 2016 Anas Buyumad
*/

#include	"tetris.h"

int	lower_check_left(t_init *setup, t_falling *falling_piece)
{
  int	x;
  int	y;

  y = 0;
  while (y < (int)falling_piece->token->height)
    {
      x = 0;
      while (x < (int)falling_piece->token->width)
	{
	  if (falling_piece->pos_y + y + 1 >= (int)setup->map.height)
	    return (ERROR);
	  if (falling_piece->token->pos_4[y][x] == '*')
	    {
	      if (setup->board[falling_piece->pos_y + y + 1]
		  [falling_piece->pos_x + x] > 0)
		return (ERROR);
	    }
	  x += 1;
	}
      y += 1;
    }
  return (SUCCESS);
}

int	lower_check_down(t_init *setup, t_falling *falling_piece)
{
  int	x;
  int	y;

  y = 0;
  while (y < (int)falling_piece->token->height)
    {
      x = 0;
      while (x < (int)falling_piece->token->width)
	{
	  if (falling_piece->pos_y + y + 1 >= (int)setup->map.height)
	    return (ERROR);
	  if (falling_piece->token->pos_3[y][x] == '*')
	    {
	      if (setup->board[falling_piece->pos_y + y + 1]
		  [falling_piece->pos_x + x] > 0)
		return (ERROR);
	    }
	  x += 1;
	}
      y += 1;
    }
  return (SUCCESS);
}

int	lower_check_right(t_init *setup, t_falling *falling_piece)
{
  int	x;
  int	y;

  y = 0;
  while (y < (int)falling_piece->token->height)
    {
      x = 0;
      while (x < (int)falling_piece->token->width)
	{
	  if (falling_piece->pos_y + y + 1 >= (int)setup->map.height)
	    return (ERROR);
	  if (falling_piece->token->pos_2[y][x] == '*')
	    {
	      if (setup->board[falling_piece->pos_y + y + 1]
		  [falling_piece->pos_x + x] > 0)
		return (ERROR);
	    }
	  x += 1;
	}
      y += 1;
    }
  return (SUCCESS);
}

int	lower_check_straight(t_init *setup, t_falling *falling_piece)
{
  int	x;
  int	y;

  y = 0;
  while (y < (int)falling_piece->token->height)
    {
      x = 0;
      while (x < (int)falling_piece->token->width)
	{
	  if (falling_piece->pos_y + y + 1 >= (int)setup->map.height)
	    return (ERROR);
	  if (falling_piece->token->pos_1[y][x] == '*')
	    {
	      if (setup->board[falling_piece->pos_y + y + 1]
		  [falling_piece->pos_x + x] > 0)
		return (ERROR);
	    }
	  x += 1;
	}
      y += 1;
    }
  return (SUCCESS);
}

int	lower_check(t_init *setup, t_falling *falling_piece)
{
  if (falling_piece->token->state == 1)
    return (lower_check_straight(setup, falling_piece));
  else if (falling_piece->token->state == 2)
    return (lower_check_right(setup, falling_piece));
  else if (falling_piece->token->state == 3)
    return (lower_check_down(setup, falling_piece));
  else if (falling_piece->token->state == 4)
    return (lower_check_left(setup, falling_piece));
  return (ERROR);
}
