/*
** main.c for main in /home/cler_g/rendu/PSU_2015_my_select
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.net>
**
** Started on  Fri Dec  4 15:03:01 2015 Gauthier Cler
** Last update Sat Dec 12 16:16:35 2015 Gauthier Cler
*/

#include	"info.h"

int	main(int ac, char **av)
{
  if (ac == 1)
    return (0);
  my_select(ac, av);
  return (0);
}

int			my_select(int ac, char **av)
{
  struct winsize	size;
  t_info		*info;
  int	nb_arg;
  int	ch;
  SCREEN	*screen;

  nb_arg = ac - 1;
  ioctl(0, TIOCGWINSZ, &size);
  info = fill_struct(ac, av, info, size);
  screen = newterm(NULL, stderr, stdin);
  curs_set(0);
  noecho();
  keypad(stdscr, true);
  disp_struct(info, nb_arg);
  attron(A_UNDERLINE);
  mvaddstr(0, 0, info[0].name);
  attroff(A_UNDERLINE);
  move(0, 0);
  ch = loop_select(info, size, nb_arg, screen);
  refresh();
  endwin();
  delscreen(screen);
  curs_set(1);
  exit_condition(info, ch, nb_arg);
  return (0);
}

t_info	*fill_struct(int ac, char **av, t_info *info, struct winsize size)
{
  t_var	var;
  int	i;

  i = -1;
  var = init_fill_struct(var);
  info  = malloc(sizeof(t_info) * ac - 1);
  while (++i < ac - 1)
    {
      if (my_strlen(av[i + 1]) > var.cor)
	var.cor = my_strlen(av[i + 1]);
      info[i].name = my_strdup(av[i + 1]);
      info[i].x = var.x;
      info[i].y = var.y;
      info[i].highlight = false;
      var.y++;
      if (var.y == size.ws_row)
	{
	  var.x += var.cor + 1;
	  var.y = 0;
	  var.cor = 0;
	}
      if (my_strlen(info[i].name) > size.ws_col - var.x)
	exit(0);
    }
  return (info);
}

t_var	init_fill_struct(t_var var)
{
  var.cor = 0;
  var.x = 0;
  var.y = 0;
  return (var);
}

void	disp_struct(t_info *info, int nb_arg)
{
  int	i;

  i = 0;
  while (i != nb_arg)
    {
      if (info[i].highlight == true)
	attron(A_REVERSE);
      mvaddstr(info[i].y, info[i].x, info[i].name);
      attroff(A_REVERSE);
      i++;
    }
}
