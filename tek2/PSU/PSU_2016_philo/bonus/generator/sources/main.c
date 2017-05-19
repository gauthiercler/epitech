/*
** main.c for PSU_2016_philo in /home/gogo/rendu/tek2/PSU_2016_philo/sources/main.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Mar 06 17:48:24 2017 Gauthier Cler
** Last update Mon Mar 06 17:48:35 2017 Gauthier Cler
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"philo.h"

bool			active_simulation;
pthread_barrier_t	barrier;

int			philo(size_t nb_philo, size_t eat_value)
{
  t_node		*list;

  printf("%lu\n", nb_philo);
  list = NULL;
  if (!create_list(nb_philo, &list, eat_value))
    return (EXIT_FAILURE);
  if (pthread_barrier_init(&barrier, NULL, (unsigned int)nb_philo) != 0)
    return (EXIT_FAILURE);
  if (!start_simulation(list))
    return (EXIT_FAILURE);
  clean_list(&list);
  pthread_barrier_destroy(&barrier);
  return (EXIT_SUCCESS);
}

int			main(int ac, char **av)
{
  t_arg			args;
  int			ret;

  ret = EXIT_SUCCESS;
//  RCFStartup(ac, av);
  init_opt(&args);
  if (get_opt(ac, av, &args) == true && args.philo_value > 1)
    ret = philo(args.philo_value, args.eat_value);
  else
  {
    if (args.philo_value < 2)
      fprintf(stderr, "Need a minium of 2 philosophers\n");
    ret = EXIT_FAILURE;
  }
//  RCFCleanup();
  return (ret);
}