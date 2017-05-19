/*
** action_piece.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/pieces/action_piece.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar  10 23:07:00 2016 Anas Buyumad
** Last update Wed Mar 16 18:48:06 2016 Anas Buyumad
*/

#include	"tetris.h"

void    rotate_token(t_falling *falling_piece)
{
  int   tmp;

  falling_piece->token->state += 1;
  if (falling_piece->token->state > 4)
    falling_piece->token->state = 1;
  tmp = falling_piece->token->width;
  falling_piece->token->width = falling_piece->token->height;
  falling_piece->token->height = tmp;
  // remeber to do unint piece so that the state and w/h go back to normal.
}

void	action_piece(t_falling *falling_piece, int action)
{
  if (action == LOWER_PIECE)
    falling_piece->pos_y += 1;
  else if (action == ROTATE_PIECE)
    rotate_token(falling_piece);
  else if (action == PUSH_LEFT_PIECE)
    falling_piece->pos_x -= 1;
  else if (action == PUSH_RIGHT_PIECE)
    falling_piece->pos_x += 1;
}
