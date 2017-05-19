/*
** check_arguments.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/usage/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:56:09 2016 Buyumad Anas
** Last update Fri Apr 29 00:57:38 2016 Buyumad Anas
*/

#include	"perfection.h"

int		check_arguments(char **av)
{
  if (atoi(av[1]) <= 0)
    return (format(2, "Invalid width. (W <= 0)\n"));
  else if (atoi(av[2]) <= 0)
    return (format(2, "Invalid height. (H <= 0)\n"));
  else if (atoi(av[3]) != 1 && atoi(av[3]) != 0)
    return (format(2, "Invalid mode. (M != 1/0)\n"));
  else if (av[4] == NULL)
    return (format(2, "Invalid filename. (F = NULL)\n"));
  else if (str_len(av[4]) == 0)
    return (format(2, "Invalid filename. (F = NULL)\n"));
  else if (atoi(av[5]) != 1 && atoi(av[5]) != 0)
    return (format(2, "Invalid Type of Generation. (T != 1/0)"));
  else if (atoi(av[6]) != 1 && atoi(av[6]) != 0)
    return (format(2, "Invalid Debug. (D != 1/0)\n"));
  return (SUCCESS);
}
