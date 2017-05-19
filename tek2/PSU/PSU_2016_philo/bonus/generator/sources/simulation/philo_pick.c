/*
** philo_pick.c for PSU_2016_philo in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_philo/sources/simulation/philo_pick.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Mar 15 18:06:02 2017 Anas Buyumad
** Last update Wed Mar 15 18:06:02 2017 Anas Buyumad
*/

#include	"philo.h"

void		philo_pick_right(t_node *node)
{
  pthread_mutex_lock(&node->next->data.stick->mutex);
  lphilo_take_chopstick(&node->next->data.stick->mutex);
}

void		philo_pick_left(t_node *node)
{
  pthread_mutex_lock(&node->prev->data.stick->mutex);
  lphilo_take_chopstick(&node->prev->data.stick->mutex);
}

void		philo_release_right(t_node *node)
{
  lphilo_release_chopstick(&node->next->data.stick->mutex);
  pthread_mutex_unlock(&node->next->data.stick->mutex);
}

void		philo_release_left(t_node *node)
{
  lphilo_release_chopstick(&node->prev->data.stick->mutex);
  pthread_mutex_unlock(&node->prev->data.stick->mutex);
}