/*
** set_settings.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/terminal_settings/set_settings.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat Mar  05 15:11:17 2016 Anas Buyumad
** Last update Thu Mar 17 17:36:23 2016 Gauthier Cler
*/

#include		"tetris.h"

void			set_term_settings(int reset)
{
  static struct termios old_term;
  static struct termios new_term;

  if (reset == 0)
    {
      ioctl(0, TCGETS, &old_term);
      new_term = old_term;
      new_term.c_lflag &= ~(ECHO | ICANON);
      ioctl(0, TCSETS, &new_term);
      curs_set(0);
    }
  else if (reset == 1)
    ioctl(0, TCSETS, &old_term);
  else if (reset == 2)
    {
      ioctl(0, TCGETS, &new_term);
      new_term.c_cc[VTIME] = 1;
      new_term.c_cc[VMIN] = 0;
      ioctl(0, TCSETS, &new_term);
    }
}
