/*
** parse_action_single.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing/flags/parse_action_single.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Mar  04 18:00:36 2016 Anas Buyumad
** Last update Thu Mar 17 17:38:06 2016 Gauthier Cler
*/

#include	"tetris.h"

int parse_sequence(t_init *setup, char *arg, int start, int mode)
{
  arg += start;
  if (mode == 1)
    assess_key(setup, 1, arg);
  else if (mode == 2)
    assess_key(setup, 2, arg);
  else if (mode == 3)
    assess_key(setup, 3, arg);
  else if (mode == 4)
    assess_key(setup, 4, arg);
  else if (mode == 5)
    assess_key(setup, 5, arg);
  else if (mode == 6)
    assess_key(setup, 6, arg);
  return (SUCCESS);
}

int	parse_action_single(t_init *setup, char *arg)
{
  if (my_strncmp(arg, "--key-left=", 11) == 0)
    parse_sequence(setup, arg, 11, 1);
  else if (my_strncmp(arg, "--key-right=", 12) == 0)
    parse_sequence(setup, arg, 12, 2);
  else if (my_strncmp(arg, "--key-turn=", 11) == 0)
    parse_sequence(setup, arg, 11, 3);
  else if (my_strncmp(arg, "--key-drop=", 11) == 0)
    parse_sequence(setup, arg, 11, 4);
  else if (my_strncmp(arg, "--key-quit=", 11) == 0)
    parse_sequence(setup, arg, 11, 5);
  else if (my_strncmp(arg, "--key-pause=", 12) == 0)
    parse_sequence(setup, arg, 12, 6);
  else
    return (ERROR);
  return (SUCCESS);
}
