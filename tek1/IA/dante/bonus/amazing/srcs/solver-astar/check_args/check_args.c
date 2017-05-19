/*
** check_args.c for check_args in /home/gogo/rendu/dante/profondeur/srcs/check_args/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sun May  1 14:10:17 2016 Gauthier Cler
** Last update Sun May 22 16:52:01 2016 Buyumad Anas
*/

#include		"astar.h"

int			check_args(int ac, char **av, bool *color, bool *count)
{
  int			i;

  i = 2;
  while (i < ac)
    {
      if (my_strcmp(av[i], "--color") == SUCCESS)
	*color = true;
      else if (my_strcmp(av[i], "--count") == SUCCESS)
	*count = true;
      else
	return (ERROR);
      i += 1;
    }
  return (SUCCESS);
}
