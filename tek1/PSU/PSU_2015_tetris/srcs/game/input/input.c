/*
** input.c for input in /tmp/PSU_2015_tetris/srcs/game/input
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Mar 14 22:57:05 2016 Gauthier Cler
** Last update Thu Mar 17 18:40:31 2016 Gauthier Cler
*/

#include	"tetris.h"

void            move_left(t_init *setup, t_falling *falling_piece)
{
  alter_piece(setup, falling_piece, PUSH_LEFT_PIECE);
}

void            move_right(t_init *setup, t_falling *falling_piece)
{
  alter_piece(setup, falling_piece, PUSH_RIGHT_PIECE);
}

void		drop(t_init *setup, t_falling *falling_piece)
{
  while (alter_piece(setup, falling_piece, LOWER_PIECE) != ERROR)
    alter_piece(setup, falling_piece, LOWER_PIECE);
}

void		rotate(t_init *setup, t_falling *falling_piece)
{
  alter_piece(setup, falling_piece, ROTATE_PIECE);
}

void		key_input(char *buffer, t_init *setup, t_falling *falling_piece)
{
  (my_strcmp(buffer, setup->keymap.left) == 0) ?
    move_left(setup, falling_piece) : 0;
  if (my_strcmp(buffer, setup->keymap.right) == 0)
    move_right(setup, falling_piece);
  if (my_strcmp(buffer, setup->keymap.turn) == 0)
    rotate(setup, falling_piece);
  (my_strcmp(buffer, setup->keymap.drop) == 0) ? drop(setup, falling_piece) : 0;
  (my_strcmp(buffer, setup->keymap.quit) == 0) ? setup->gameover = true : 0;
  (my_strcmp(buffer, setup->keymap.pause) == 0) ?
    pause_loop(setup->keymap.pause, setup->keymap.quit) : 0;
}
