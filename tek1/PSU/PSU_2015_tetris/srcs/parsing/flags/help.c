/*
** help.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing/flags/help.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Feb  25 18:56:47 2016 Anas Buyumad
** Last update Thu Mar 17 17:47:51 2016 Gauthier Cler
*/

#include	"tetris.h"

int		help_display(char *binary_name)
{
  my_putstr("Usage: ");
  my_putstr(binary_name);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("--help                 Display this help\n");
  my_putstr("-l --level={num}       Start Tetris at level num\n");
  my_putstr("-kl --key-left={K}     Move tetrimino on LEFT with key K\n");
  my_putstr("-kr --key-right={K}    Move tetrimino on RIGHT with key K\n");
  my_putstr("-kt --key-turn={K}     Turn tetrimino with key K\n");
  my_putstr("-kd --key-drop={K}     Set default DROP on key K\n");
  my_putstr("-kq --key-quit={K}     Quit program when press key K\n");
  my_putstr("-kp --key-pause={K}    Pause and restart game when press key K");
  my_putstr("\n");
  my_putstr("--map-size={row,col}   Set game size at row, col\n");
  my_putstr("-w --without-next      Hide next tetrimino\n");
  my_putstr("-d --debug             Debug mode\n");
  return (SUCCESS);
}

int	help_mode(char	**av)
{
  int	i;

  i = 1;
  while (av[i])
    {
      if ((my_strcmp(av[i], "--help")) == 0)
	{
	  help_display(av[0]);
	  return (SUCCESS);
	}
      i += 1;
    }
  return (ERROR);
}
