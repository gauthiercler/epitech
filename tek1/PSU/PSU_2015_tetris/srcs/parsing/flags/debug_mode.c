/*
** debug_mode.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing/flags/debug_mode.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar  03 14:44:15 2016 Anas Buyumad
** Last update Tue Mar 15 16:26:07 2016 Gauthier Cler
*/

#include	"tetris.h"

int	debug_mode(char **av)
{
  int	i;

  i = 1;
  while (av[i])
    {
      if ((my_strcmp(av[i], "-d") == 0) || (my_strcmp(av[i], "--debug") == 0))
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}
