/*
** draw_outline.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/layout/draw_outline.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  05 16:56:11 2016 Anas Buyumad
** Last update Thu Mar 17 18:52:35 2016 Gauthier Cler
*/

#include	"tetris.h"

void	draw_right_outline(WINDOW *window, int max_size[2])
{
  int	x;
  int	y;

  x = max_size[0] - 1;
  y = 0;
  while (y < max_size[1])
  {
    if (y == 0)
      mvwaddch(window, y, x, ACS_URCORNER);
    else
      mvwaddch(window, y, x, ACS_VLINE);
    y += 1;
  }
}

void	draw_left_outline(WINDOW *window, int max_size[2])
{
  int	x;
  int	y;

  x = 0;
  y = max_size[1] - 1;
  while (y > 0)
  {
    if (y == max_size[1] - 1)
      mvwaddch(window, y, x, ACS_LLCORNER);
    else
      mvwaddch(window, y, x, ACS_VLINE);
    y -= 1;
  }
}

void	draw_upper_outline(WINDOW *window, int max_size[2], char *name)
{
  int	x;
  int	y;
  int	i;

  im_hidden(&i, &x, &y);
  while (++x < max_size[0])
    {
      if (x == 0)
	mvwaddch(window, y, x, ACS_ULCORNER);
      else if (x == 1 && name[i] != '\0')
	{
	  while (name[i])
	    {
	      wattron(window, COLOR_PAIR(TITLE_COLOR));
	      mvwaddch(window, y, x, name[i++]);
	      x += 1;
	    }
	}
      if (name[i] == '\0')
	{
	  wattroff(window, COLOR_PAIR(TITLE_COLOR));
	  mvwaddch(window, y, x, ACS_HLINE);
	}
    }
}

void	draw_lower_outline(WINDOW *window, int max_size[2])
{
  int	x;
  int	y;

  x = max_size[0] - 1;
  y = max_size[1] - 1;
  while (x >= 0)
  {
    if (x == max_size[0] - 1)
      mvwaddch(window, y, x, ACS_LRCORNER);
    else
      mvwaddch(window, y, x, ACS_HLINE);
    x -= 1;
  }
}

void	draw_window_outline(WINDOW *window, char *name)
{
  int	max_size[2];

  getmaxyx(window, max_size[1], max_size[0]);
  draw_upper_outline(window, max_size, name);
  draw_right_outline(window, max_size);
  draw_lower_outline(window, max_size);
  draw_left_outline(window, max_size);
  wrefresh(window);
}
