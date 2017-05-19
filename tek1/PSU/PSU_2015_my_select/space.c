/*
** space.c for space in /home/gauthier/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Dec  9 23:26:37 2015 Gauthier Cler
** Last update Wed Dec  9 23:47:55 2015 Gauthier Cler
*/

#include "info.h"

void	key_space(t_info *info, t_cursor cursor,
		  struct winsize size, int nb_arg)
{
  int	i;

  i = pos_arg_name(info, cursor);
  if (i == nb_arg - 1)
    {
      if (info[i].highlight == false)
	space_end_high(info, i);
      else
	space_end(info, i);
    }
  else
    {
      if (info[i].highlight == false)
	space_high(info, i);
      else
	space(info, i);
    }
}

void	space_end_high(t_info *info, int i)
{
  attron(A_REVERSE);
  mvaddstr(info[i].y, info[i].x, info[i].name);
  attroff(A_REVERSE);
  info[i].highlight = true;
  attron(A_UNDERLINE);
  if (info[0].highlight == true)
    attron(A_REVERSE);
  mvaddstr(info[0].y, info[0].x, info[0].name);
  attroff(A_UNDERLINE | A_REVERSE);
  move(info[0].y, info[0].x);
}

void	space_end(t_info *info, int i)
{
  attron(A_NORMAL);
  mvaddstr(info[i].y, info[i].x, info[i].name);
  attroff(A_NORMAL);
  info[i].highlight = false;
  attron(A_UNDERLINE);
  if (info[0].highlight == true)
    attron(A_REVERSE);
  mvaddstr(info[0].y, info[0].x, info[0].name);
  attroff(A_UNDERLINE | A_REVERSE);
  move(info[0].y, info[0].x);
}

void	space_high(t_info *info, int i)
{
  attron(A_REVERSE);
  addstr(info[i].name);
  attroff(A_REVERSE);
  info[i].highlight = true;
  attron(A_UNDERLINE);
  if (info[i + 1].highlight == true)
    attron(A_REVERSE);
  mvaddstr(info[i + 1].y, info[i + 1].x, info[i + 1].name);
  attroff(A_UNDERLINE | A_REVERSE);
  move(info[i + 1].y, info[i + 1].x);
}

void	space(t_info *info, int i)
{
  attron(A_NORMAL);
  addstr(info[i].name);
  attroff(A_NORMAL);
  info[i].highlight = false;
  attron(A_UNDERLINE);
  if (info[i + 1].highlight == true)
    attron(A_REVERSE);
  mvaddstr(info[i + 1].y, info[i + 1].x, info[i + 1].name);
  attroff(A_UNDERLINE | A_REVERSE);
  move(info[i + 1].y, info[i + 1].x);
}
