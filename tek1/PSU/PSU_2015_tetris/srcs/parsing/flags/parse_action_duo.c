/*
** parse_action_duo.c for PSU_2015_tetris in /home/keyrise/Work/Repositories/Epitech/PSU/PSU_2015_tetris/srcs/parsing/flags/parse_action_duo.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Fri Mar  04 18:00:44 2016 Anas Buyumad
** Last update Thu Mar 17 17:37:57 2016 Gauthier Cler
*/

#include	"tetris.h"

int	parse_action_duo(t_init *setup, char *flag, char *arg)
{
  if (my_strcmp(flag, "-kl") == 0)
    assess_key(setup, 1, arg);
  else if (my_strcmp(flag, "-kr") == 0)
    assess_key(setup, 2, arg);
  else if (my_strcmp(flag, "-kt") == 0)
    assess_key(setup, 3, arg);
  else if (my_strcmp(flag, "-kd") == 0)
    assess_key(setup, 4, arg);
  else if (my_strcmp(flag, "-kq") == 0)
    assess_key(setup, 5, arg);
  else if (my_strcmp(flag, "-kp") == 0)
    assess_key(setup, 6, arg);
  else
    return (ERROR);
  return (SUCCESS);
}
