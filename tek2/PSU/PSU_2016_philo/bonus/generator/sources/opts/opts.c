/*
** opts.c.c for PSU_2016_philo in /home/gogo/rendu/tek2/PSU_2016_philo/sources/opt/opts.c.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Mar 13 16:24:05 2017 Gauthier Cler
** Last update Mon Mar 13 16:24:05 2017 Gauthier Cler
*/

#include	<getopt.h>
#include	<libio.h>
#include	<stdlib.h>
#include	"philo.h"

bool		is_digit(const char *string)
{
  int		idx;

  if (!string)
    return (false);
  idx = 0;
  while (string[idx])
  {
    if (!isdigit(string[idx]))
      return (false);
    idx += 1;
  }
  return (true);
}

void		init_opt(t_arg *args)
{
  args->philo_value = 0;
  args->eat_value = 0;
}

bool		get_opt(int ac, char **av, t_arg *args)
{
  int		arg;
  extern char	*optarg;
  char		*current_arg;

  while ((arg = getopt(ac, av, "p:e:")) != EOF)
  {
    if (arg == 'p')
    {
      current_arg = optarg;
      if (current_arg && is_digit(optarg))
	args->philo_value = (size_t)atoi(current_arg);
    }
    else if (arg == 'e')
    {
      current_arg = optarg;
      if (current_arg && is_digit(current_arg))
	args->eat_value = (size_t)atoi(current_arg);
    }
    else
      return (false);
  }
  return (true);
}