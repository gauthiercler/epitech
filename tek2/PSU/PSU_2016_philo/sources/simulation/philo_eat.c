/*
** philo_eat.c for PSU_2016_philo in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_philo/sources/simulation/philo_eat.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Mar 12 17:09:14 2017 Anas Buyumad
** Last update Sun Mar 12 17:09:14 2017 Anas Buyumad
*/

#include	"philo.h"

void		philo_eat(t_node *node)
{
  if (node->data.philo->handed_side)
  {
    philo_pick_right(node);
    philo_pick_left(node);
  }
  else
  {
    philo_pick_left(node);
    philo_pick_right(node);
  }
  lphilo_eat();
  node->data.philo->max_portions -= 1;
  if (node->data.philo->handed_side)
  {
    philo_release_right(node);
    philo_release_left(node);
  }
  else
  {
    philo_release_left(node);
    philo_release_right(node);
  }
}