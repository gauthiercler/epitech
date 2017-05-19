/*
** set_informations.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/game/layout/set_informations.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Mar  14 16:12:01 2016 Anas Buyumad
** Last update Thu Mar 17 20:20:49 2016 Anas Buyumad
*/

#include	"tetris.h"

void	show_highscore(t_init *setup, int dim[2])
{
  wattron(setup->windows.misc, COLOR_PAIR((short int)TITLE_COLOR));
  mvwprintw(setup->windows.misc, 11, 1, "Highscore :");
  wattroff(setup->windows.misc, COLOR_PAIR((short int)TITLE_COLOR));
  wattron(setup->windows.misc, COLOR_PAIR((short int)BORDER_COLOR));
  mvwprintw(setup->windows.misc, 11, dim[0] / 2, "%d", setup->highscore);
  wattroff(setup->windows.misc, COLOR_PAIR((short int)BORDER_COLOR));
}

void	show_score(t_init *setup, int dim[2])
{
  wattron(setup->windows.misc, COLOR_PAIR((short int)TITLE_COLOR));
  mvwprintw(setup->windows.misc, 8, 1, "Score :");
  wattroff(setup->windows.misc, COLOR_PAIR((short int)TITLE_COLOR));
  wattron(setup->windows.misc, COLOR_PAIR((short int)BORDER_COLOR));
  mvwprintw(setup->windows.misc, 8, dim[0] / 2, "%d", setup->score);
  wattroff(setup->windows.misc, COLOR_PAIR((short int)BORDER_COLOR));
}

void	show_rows(t_init *setup, int dim[2])
{
  wattron(setup->windows.misc, COLOR_PAIR((short int)TITLE_COLOR));
  mvwprintw(setup->windows.misc, 5, 1, "Rows :");
  wattroff(setup->windows.misc, COLOR_PAIR((short int)TITLE_COLOR));
  wattron(setup->windows.misc, COLOR_PAIR((short int)BORDER_COLOR));
  mvwprintw(setup->windows.misc, 5, dim[0] / 2, "%d", setup->rows);
  wattroff(setup->windows.misc, COLOR_PAIR((short int)BORDER_COLOR));
}

void	show_level(t_init *setup, int dim[2])
{
  wattron(setup->windows.misc, COLOR_PAIR((short int)TITLE_COLOR));
  mvwprintw(setup->windows.misc, 2, 1, "Level :");
  wattroff(setup->windows.misc, COLOR_PAIR((short int)TITLE_COLOR));
  wattron(setup->windows.misc, COLOR_PAIR((short int)BORDER_COLOR));
  mvwprintw(setup->windows.misc, 2, dim[0] / 2, "%d", setup->level);
  wattroff(setup->windows.misc, COLOR_PAIR((short int)BORDER_COLOR));
}

void	set_informations(t_init *setup)
{
  int	dim[2];

  getmaxyx(setup->windows.misc, dim[1], dim[0]);
  show_level(setup, dim);
  show_rows(setup, dim);
  show_score(setup, dim);
  show_highscore(setup, dim);
  wrefresh(setup->windows.misc);
}
