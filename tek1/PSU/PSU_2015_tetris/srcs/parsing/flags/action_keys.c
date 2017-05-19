/*
** dirkeys_flags.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing/flags/dirkeys_flags.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Feb  28 00:24:43 2016 Anas Buyumad
** Last update Thu Mar 17 17:41:03 2016 Gauthier Cler
*/

#include	"tetris.h"

int		command_action_keys(t_init *setup, int ac, char **av, int *i)
{
  int		status;

  if (((my_strcmp(av[*i], "-kl")) == 0) || (my_strcmp(av[*i], "-kr") == 0) ||
      (my_strcmp(av[*i], "-kt") == 0) || (my_strcmp(av[*i], "-kd") == 0) ||
      (my_strcmp(av[*i], "-kq") == 0) || (my_strcmp(av[*i], "-kp") == 0))
    {
      if (*i + 1 < ac)
	{
	  status = parse_action_duo(setup, av[*i], av[*i + 1]);
	  *i += 1;
	  return (status);
	}
    }
  else if (((my_strncmp(av[*i], "--key-left=", 11)) == 0)
	   || (my_strncmp(av[*i], "--key-right=", 12) == 0)
	   || (my_strncmp(av[*i], "--key-turn=", 11) == 0)
	   || (my_strncmp(av[*i], "--key-drop=", 11) == 0)
	   || (my_strncmp(av[*i], "--key-quit=", 11) == 0)
	   || (my_strncmp(av[*i], "--key-pause=", 12) == 0))
    return ((status = parse_action_single(setup, av[*i])));
  else
    return (ERROR);
  return (SUCCESS);
}
