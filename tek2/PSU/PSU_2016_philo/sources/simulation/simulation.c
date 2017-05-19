/*
** simulation.c for PSU_2016_philo in /home/gogo/rendu/tek2/PSU_2016_philo/sources/simulation/simulation.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 08 14:34:19 2017 Gauthier Cler
** Last update Wed Mar 08 14:34:19 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"philo.h"

static bool	start_threads(t_node *list)
{
  t_node	*tmp;

  tmp = list;
  while (tmp)
  {
    if (tmp->node_type == PHILO)
      if (pthread_create(&tmp->data.philo->handle, NULL,
			 simulation, (void *)tmp) != 0)
	return (custom_error("Can't create thread"));
    tmp = tmp->next;
    if (tmp == list)
      break ;
  }
  return (true);
}

static void	wait_threads(t_node *list)
{
  t_node	*tmp;
  int		count;

  count = 0;
  tmp = list;
  while (tmp)
  {
    if (tmp->node_type == PHILO)
    {
      pthread_join(tmp->data.philo->handle, NULL);
      count += 1;
    }
    tmp = tmp->next;
    if (tmp == list)
      break ;
  }
}

bool		start_simulation(t_node *list)
{
  active_simulation = true;
  if (!start_threads(list))
  {
    active_simulation = false;
    return (false);
  }
  wait_threads(list);
  return (true);
}

static bool	delayed_philo_eat(t_node *node, unsigned int tempo)
{
  usleep(tempo);
  if (active_simulation)
  {
    philo_eat(node);
    if (node->data.philo->max_portions == 0)
    {
      active_simulation = false;
      return (true);
    }
    pthread_barrier_wait(&barrier);
  }
  return (false);
}

void		*simulation(void *arg)
{
  t_node	*node;

  node = (t_node *)arg;
  pthread_barrier_wait(&barrier);
  while (node->data.philo->max_portions && active_simulation == true)
  {
    if (active_simulation)
    {
      philo_think(node);
      pthread_barrier_wait(&barrier);
    }
    if (delayed_philo_eat(node, (unsigned int)rand() % 2000) == true)
      return (arg);
    if (active_simulation)
    {
      philo_sleep(node);
      pthread_barrier_wait(&barrier);
    }
  }
  active_simulation = false;
  return (arg);
}