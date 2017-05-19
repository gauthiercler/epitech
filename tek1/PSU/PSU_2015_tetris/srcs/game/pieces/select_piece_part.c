/*
** select_piece_part.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/pieces/select_piece_part.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar  10 22:38:41 2016 Anas Buyumad
** Last update Wed Mar 16 18:49:37 2016 Anas Buyumad
*/

#include	"tetris.h"

int	select_right(t_token *token, int x, int y)
{
  if (token->pos_4[y][x] == '*')
    return (SUCCESS);
  return (ERROR);
}

int	select_down(t_token *token, int x, int y)
{
  if (token->pos_3[y][x] == '*')
    return (SUCCESS);
  return (ERROR);
}

int	select_left(t_token *token, int x, int y)
{
  if (token->pos_2[y][x] == '*')
    return (SUCCESS);
  return (ERROR);
}

int	select_straight(t_token *token, int x, int y)
{
  if (token->pos_1[y][x] == '*')
    return (SUCCESS);
  return (ERROR);
}

int	select_piece_part(t_token *token, int x, int y, int state)
{
  if (state == 1)
    return (select_straight(token, x, y));
  else if (state == 2)
    return (select_left(token, x, y));
  else if (state == 3)
    return (select_down(token, x, y));
  else if (state == 4)
    return (select_right(token, x, y));
  return (ERROR);
}
