/*
** check_env.c for check_env in /home/gogo/rendu/gfx_tekadventure/srcs/env
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Apr 16 18:55:37 2016 Gauthier Cler
** Last update Sat Apr 16 19:00:58 2016 Gauthier Cler
*/

#include	"adventure.h"

int		check_env(char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (my_strcmp(env[i], "DISPLAY=:0") == SUCCESS)
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}
