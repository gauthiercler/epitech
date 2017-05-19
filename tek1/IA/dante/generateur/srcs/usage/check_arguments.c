/*
** check_arguments.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/usage/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:56:09 2016 Buyumad Anas
** Last update Fri May 27 14:58:37 2016 Gauthier Cler
*/

#include	<string.h>
#include	"perfection.h"

int		check_arguments(char **av)
{
  if (atoi(av[1]) <= 0)
    return (format(2, "Invalid width. (W <= 0)\n"));
  else if (atoi(av[2]) <= 0)
    return (format(2, "Invalid height. (H <= 0)\n"));
  if (av[3] == NULL)
    return (SUCCESS);
  else if (strcmp(av[3], "parfait") != 0)
    return (format(2, "Invalid mode\n"));
  return (SUCCESS);
}
