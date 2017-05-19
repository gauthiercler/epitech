/*
** loop.c for loop in /home/gauthier/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Dec  8 16:31:23 2015 Gauthier Cler
** Last update Sun Dec 13 23:06:33 2015 Gauthier Cler
*/

#include	"info.h"

int		loop_select(t_info *info, struct winsize size,
			    int nb_arg, SCREEN *screen)
{
  int		ch;
  t_cursor	cursor;

  ch = 0;
  while (ch != 10 && ch != 27)
    {
      ch = getch();
      getyx(stdscr, cursor.y, cursor.x);
      if (ch == KEY_DOWN)
	key_down(info, cursor, size, nb_arg);
      if (ch == KEY_UP)
	key_up(info, cursor, size, nb_arg);
      if (ch == 32)
	key_space(info, cursor, size, nb_arg);
      if (ch == KEY_BACKSPACE || ch == KEY_DC)
	nb_arg = key_delete(info, cursor, screen, nb_arg);
    }
  return (ch);
}

int	pos_arg_name(t_info *info, t_cursor cursor)
{
  int	i;

  i = 0;
  while (info[i].x != cursor.x || info[i].y != cursor.y)
    i++;
  return (i);
}

void	exit_condition(t_info *info, int ch, int nb_arg)
{
  if (ch == 10)
    disp_arg(info, nb_arg);
  else
    exit(0);
}

void	disp_arg(t_info *info, int nb_arg)
{
  int	i;
  int	high;
  int	space;

  space = 0;
  high = calc_arg(info, nb_arg);
  i = 0;
  while (i < nb_arg)
    {
      if (info[i].highlight == true)
	{
	  space++;
	  if (space == 1)
	    my_putstr(info[i].name);
	  else
	    {
	      write(1, " ", 1);
	      my_putstr(info[i].name);
	    }
	}
      i++;
    }
  exit(0);
}

int	calc_arg(t_info *info, int nb_arg)
{
  int	i;
  int	high;

  i = 0;
  high = 0;
  while (i < nb_arg)
    {
      if (info[i].highlight == true)
	high++;
      i++;
    }
  return (high);
}
