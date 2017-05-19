/*
** resize.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/layout/resize.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar  17 18:05:18 2016 Anas Buyumad
** Last update Thu Mar  17 18:05:18 2016 Anas Buyumad
*/

#include	"tetris.h"

int	res_term(t_init *setup)
{
  if (tick[1] == 1)
  {
    wclear(setup->windows.misc);
    wclear(setup->windows.next_piece);
    wclear(setup->windows.board);
    wclear(setup->windows.main_screen);
    wclear(stdscr);
    if (start_screen(setup) == ERROR)
      return (ERROR);
    if (start_color_pairs() == ERROR)
      return (ERROR);
    if (set_windows(setup) == ERROR)
      return (ERROR);
    if ((setup->board =
	     initiate_board(setup->map.width, setup->map.height)) == NULL)
      return (ERROR);
    tick[1] = 0;
  }
  return (SUCCESS);
}