/*
** delete.c for delete in /home/gauthier/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Dec 12 15:51:44 2015 Gauthier Cler
** Last update Sat Dec 12 16:04:20 2015 Gauthier Cler
*/

#include "info.h"

int	case_delete_exit(int nb_arg, SCREEN *screen)
{
  if (nb_arg == 1)
    {
      endwin();
      delscreen(screen);
      curs_set(1);
      exit(0);
    }
}

void	delete_next(t_info *info, int nb_arg, int k, int i)
{
  clear();
  disp_struct(info, nb_arg);
  if (k == nb_arg)
    {
      move(0, 0);
      if (info[i].highlight == true)
	attron(A_REVERSE);
      attron(A_UNDERLINE);
      addstr(info[0].name);
      attroff(A_UNDERLINE | A_REVERSE);
      move(0, 0);
    }
  else
    move(info[i].y, info[i].x);
}
