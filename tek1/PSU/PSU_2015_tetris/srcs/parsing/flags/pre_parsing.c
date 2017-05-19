/*
** pre_parsing.c for pre_parsing in /home/gogo/rendu/PSU_2015_tetris/srcs/parsing/flags
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Tue Mar 15 16:29:52 2016 Gauthier Cler
** Last update Thu Mar 17 17:48:11 2016 Gauthier Cler
*/

#include	"tetris.h"

int	lexer_duo(int ac, char **av, int *i)
{
  if (((my_strcmp(av[*i], "-kl")) == 0)
      || (my_strcmp(av[*i], "-kr") == 0)
      || (my_strcmp(av[*i], "-kt") == 0)
      || (my_strcmp(av[*i], "-kd") == 0)
      || (my_strcmp(av[*i], "-kq") == 0)
      || (my_strcmp(av[*i], "-kp") == 0)
      || (my_strcmp(av[*i], "-l") == 0))
    {
      if (*i + 1 < ac)
	{
	  *i += 2;
	  return (SUCCESS);
	}
    }
  return (ERROR);
}

int	lexer(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (((my_strncmp(av[i], "--key-left=", 11)) == 0)
	  || (my_strncmp(av[i], "--key-right=", 12) == 0)
	  || (my_strncmp(av[i], "--key-turn=", 11) == 0)
	  || (my_strncmp(av[i], "--key-drop=", 11) == 0)
	  || (my_strncmp(av[i], "--key-quit=", 11) == 0)
	  || (my_strncmp(av[i], "--key-pause=", 12) == 0)
	  || (my_strcmp(av[i], "-w") == 0)
	  || (my_strcmp(av[i], "--without-next") == 0)
	  || (my_strncmp(av[i], "--level=", 8) == 0)
	  || (my_strcmp(av[i], "-d") == 0)
	  || (my_strcmp(av[i], "--debug") == 0)
	  || (my_strcmp(av[i], "--help") == 0)
	  || (my_strncmp(av[i], "--map-size=", 11) == 0))
	i += 1;
      else if (lexer_duo(ac, av, &i) == ERROR)
	return (ERROR);
    }
  return (SUCCESS);
}
