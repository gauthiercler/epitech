/*
** create_list.c for PSU_2016_philo in /home/gogo/rendu/tek2/PSU_2016_philo/sources/list/create_list.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 07 18:31:12 2017 Gauthier Cler
** Last update Tue Mar 07 18:31:12 2017 Gauthier Cler
*/

#include	<stdbool.h>
#include	<stdlib.h>
#include	"philo.h"

t_stick		*create_stick()
{
  t_stick	*stick;

  stick = malloc(sizeof(t_stick));
  if (!stick)
    return (NULL);
  if (pthread_mutex_init(&stick->mutex, NULL) != 0)
    return (NULL);
  return (stick);
}

static void	init_philo_attr(t_philo *philo, size_t eat_value)
{
  static size_t	handed = 0;

  philo->max_portions = eat_value;
  if (handed == 0)
    philo->handed_side = true;
  else
    philo->handed_side = false;
  handed += 1;
}

t_philo		*create_philo(size_t eat_value)
{
  t_philo	*philo;

  philo = malloc(sizeof(t_philo));
  if (!philo)
    return (NULL);
  init_philo_attr(philo, eat_value);
  return (philo);
}

static bool	push_front(size_t type, t_node *last_ptr,
			      t_node **list, size_t eat_value)
{
  t_node	*node;

  node = malloc(sizeof(t_node));
  if (!node)
    return (display_error());
  if (type == PHILO)
  {
    if (!(node->data.philo = create_philo(eat_value)))
      return (display_error());
    node->node_type = PHILO;
  }
  else
  {
    if (!(node->data.stick = create_stick()))
      return (display_error());
    node->node_type = STICK;
  }
  node->prev = last_ptr;
  if (last_ptr)
    last_ptr->next = node;
  node->next = *list;
  if ((*list) != NULL)
    (*list)->prev = node;
  *list = node;
  return (true);
}

bool		create_list(const size_t nb_philo, t_node **list,
				size_t eat_value)
{
  size_t	counter;
  t_node	*last_ptr;

  last_ptr = NULL;
  counter = 0;
  while (counter < nb_philo * 2)
  {
    if (!push_front(counter % 2, last_ptr, list, eat_value))
      return (false);
    if (counter == 0)
      last_ptr = *list;
    counter += 1;
  }
  return (true);
}