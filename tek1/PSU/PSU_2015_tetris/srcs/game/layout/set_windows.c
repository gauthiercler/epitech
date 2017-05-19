/*
** set_windows.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/layout/set_windows.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Mar  07 17:53:55 2016 Anas Buyumad
** Last update Thu Mar 17 18:49:47 2016 Gauthier Cler
*/

#include	"tetris.h"

void    im_hidden(int *i, int *x, int *y)
{
  *i = 0;
  *x = -1;
  *y = 0;
}

int	set_windows(t_init *setup)
{
  draw_window_outline(setup->windows.main_screen, "Main-Window");
  draw_window_outline(setup->windows.next_piece, "Next");
  draw_window_outline(setup->windows.misc, "Informations");
  draw_window_outline(setup->windows.board, "Board");
  set_informations(setup);
  curs_set(0);
  return (SUCCESS);
}
