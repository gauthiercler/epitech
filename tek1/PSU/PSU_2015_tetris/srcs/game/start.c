/*
** startup.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/Startup/startup.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon Feb  22 17:52:39 2016 Anas Buyumad
** Last update Thu Mar 17 20:28:47 2016 Gauthier Cler
*/

#include	"tetris.h"

int start_error(int error)
{
  if (error == 1)
    {
      my_putstr("The main screen couldn't be created. ");
      my_putstr("Please resize the terminal.\n");
      my_putstr("Minimal size is : 20x40");
    }
  else if (error == 2)
    my_putstr("An error occurred while setting up the screen.\n");
  return (ERROR);
}

int   burn_screen(t_init *setup)
{
  wclear(setup->windows.main_screen);
  delwin(setup->windows.main_screen);
  wclear(setup->windows.next_piece);
  delwin(setup->windows.next_piece);
  wclear(setup->windows.misc);
  delwin(setup->windows.misc);
  wclear(setup->windows.board);
  delwin(setup->windows.board);
  wclear(stdscr);
  delwin(stdscr);
  return (SUCCESS);
}

int   start_screen(t_init *setup)
{
  int term_size[2];

  initscr();
  getmaxyx(stdscr, term_size[1], term_size[0]);
  if ((setup->windows.main_screen =
       newwin(term_size[1], term_size[0], 0, 0)) == NULL)
    return (start_error(1));
  if ((setup->windows.next_piece =
       subwin(setup->windows.main_screen,
	      term_size[1] / 5, term_size[0] / 5, 2, 2)) == NULL)
    return (start_error(2));
  if ((setup->windows.misc =
       subwin(setup->windows.main_screen, term_size[1] / 2
	      , term_size[0] / 5, 4 + (term_size[1] / 5), 2)) == NULL)
    return (start_error(2));
  if ((setup->windows.board =
       subwin(setup->windows.main_screen, setup->map.height * 1 + 2,
	      setup->map.width * 2 + 2, 2 , 10 + (term_size[0] / 5))) == NULL)
    return (start_error(2));
  return (SUCCESS);
}

int   start_color_pairs()
{
  start_color();
  init_pair(BORDER_COLOR, COLOR_WHITE, COLOR_BLACK);
  init_pair(TITLE_COLOR, COLOR_RED, COLOR_BLACK);
  init_pair(BG_COLOR, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_RED);
  init_pair(2, COLOR_GREEN, COLOR_GREEN);
  init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(4, COLOR_BLUE, COLOR_BLUE);
  init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(6, COLOR_CYAN, COLOR_CYAN);
  init_pair(7, COLOR_WHITE, COLOR_WHITE);
  return (SUCCESS);
}

int		start_game(t_init *setup)
{
  load_highscore(setup);
  if (start_screen(setup) == ERROR)
    return (ERROR);
  if (start_color_pairs() == ERROR)
    return (ERROR);
  if (set_windows(setup) == ERROR)
    return (ERROR);
  if ((setup->board =
       initiate_board(setup->map.width, setup->map.height)) == NULL)
    return (ERROR);
  main_loop(setup);
  burn_screen(setup);
  return (SUCCESS);
}
