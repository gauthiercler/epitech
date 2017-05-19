/*
** flags_parser.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing/flags/flags_parser.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Feb  28 00:17:02 2016 Anas Buyumad
** Last update Thu Mar 17 17:41:56 2016 Gauthier Cler
*/

#include	"tetris.h"

int		flags_parser(t_init *setup, int ac, char **av)
{
  int		i;

  i = 1;
  while (av[i])
    {
      command_action_keys(setup, ac, av, &i);
      level_action(setup, ac, av, &i);
      map_action(setup, av[i]);
      if ((my_strcmp(av[i], "-w") == 0)
	  || (my_strcmp(av[i], "--without-next") == 0))
	setup->blind_mode = true;
      i += 1;
    }
  return (SUCCESS);
}
