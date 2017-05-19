/*
** call_checker.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/pieces/checkings/call_checker.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Mar  11 13:16:14 2016 Anas Buyumad
** Last update Wed Mar 16 18:42:52 2016 Anas Buyumad
*/

#include	"tetris.h"

int	call_checker(t_init *setup, t_falling *falling_piece, int action)
{
  if (action == LOWER_PIECE)
    return (lower_check(setup, falling_piece));
  if (action == ROTATE_PIECE)
    return (rotate_check(setup, falling_piece));
  if (action == PUSH_LEFT_PIECE)
    return (left_check(setup, falling_piece));
  if (action == PUSH_RIGHT_PIECE)
    return (right_check(setup, falling_piece));
  return (ERROR);
}
