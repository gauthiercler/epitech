/*
** keys.c for keys in /home/gauthier/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec  8 15:12:33 2015 Gauthier Cler
** Last update Sun Dec 13 23:06:11 2015 Gauthier Cler
*/

#include "info.h"

void	key_down(t_info *info, t_cursor cursor,
		 struct winsize size, int nb_arg)
{
  if (pos_arg_name(info, cursor) == nb_arg - 1)
    {
      attron(A_UNDERLINE);
      if (info[0].highlight == true)
	attron(A_REVERSE);
      mvaddstr(info[0].y, info[0].x, info[0].name);
      attroff(A_UNDERLINE | A_REVERSE);
      if (info[nb_arg - 1].highlight == true)
	attron(A_REVERSE);
      mvaddstr(info[nb_arg - 1]. y,
	       info[nb_arg - 1].x, info[nb_arg - 1].name);
      attroff(A_REVERSE);
      move(info[0].y, info[0].x);
    }
  else
    key_down_else(info, cursor, size, nb_arg);
}

void	key_down_else(t_info *info, t_cursor cursor,
		      struct winsize size, int nb_arg)
{
  int	i;

  if (cursor.y != size.ws_row - 1)
    {
      cursor.y++;
      i = pos_arg_name(info, cursor);
    }
  else
    {
      i = pos_arg_name(info, cursor);
      i++;
    }
  attron(A_UNDERLINE);
  if (info[i].highlight == true)
    attron(A_REVERSE);
  mvaddstr(info[i].y, info[i].x, info[i].name);
  attroff(A_UNDERLINE | A_REVERSE);
  if (info[i - 1].highlight == true)
    attron(A_REVERSE);
  mvaddstr(info[i - 1]. y , info[i - 1].x, info[i - 1].name);
  attroff(A_REVERSE);
  move(info[i].y, info[i].x);
}

void	key_up(t_info *info, t_cursor cursor,
	       struct winsize size, int nb_arg)
{
  int	i;

  if (cursor.x == 0 && cursor.y == 0)
    {
      if (info[0].highlight == true)
	attron(A_REVERSE);
      mvaddstr(info[0].y, info[0].x, info[0].name);
      attroff(A_REVERSE);
      attron(A_UNDERLINE);
      if (info[nb_arg - 1].highlight == true)
	attron(A_REVERSE);
      mvaddstr(info[nb_arg - 1]. y,
	       info[nb_arg - 1].x, info[nb_arg - 1].name);
      attroff(A_UNDERLINE | A_REVERSE);
      move(info[nb_arg - 1].y, info[nb_arg - 1].x);
    }
  else
    key_up_else(info, cursor, size, nb_arg);
}

void		key_up_else(t_info *info, t_cursor cursor,
			    struct winsize size, int nb_arg)
{
  int		i;

  if (cursor.y != 0)
    {
      cursor.y--;
      i = pos_arg_name(info, cursor);
    }
  else
    {
      i = pos_arg_name(info, cursor);
      i--;
    }
  attron(A_UNDERLINE);
  if (info[i].highlight == true)
    attron(A_REVERSE);
  mvaddstr(info[i].y, info[i].x, info[i].name);
  attroff(A_UNDERLINE | A_REVERSE);
  if (info[i + 1].highlight == true)
    attron(A_REVERSE);
  mvaddstr(info[i + 1]. y , info[i + 1].x, info[i + 1].name);
  attroff(A_REVERSE);
  move(info[i].y, info[i].x);
}

int		key_delete(t_info *info, t_cursor cursor,
			   SCREEN *screen, int nb_arg)
{
  int		i;
  int		j;
  int		k;
  t_info	tmp;

  case_delete_exit(nb_arg, screen);
  j = nb_arg;
  i = pos_arg_name(info, cursor);
  k = i;
  while (j > i)
    {
      info[j].x = info[j - 1].x;
      info[j].y = info[j - 1].y;
      j--;
    }
  while (i < nb_arg)
    {
      tmp = info[i + 1];
      info[i + 1] = info[i];
      info[i] = tmp;
      i++;
    }
  nb_arg--;
  delete_next(info, nb_arg, k, i);
  return (nb_arg);
}
