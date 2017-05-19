/*
** philo_think.c for PSU_2016_philo in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_philo/sources/simulation/philo_think.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun Mar 12 15:19:53 2017 Anas Buyumad
** Last update Sun Mar 12 15:19:53 2017 Anas Buyumad
*/

#include	"philo.h"

void		philo_think(t_node *node)
{
  if (node->data.philo->handed_side)
    philo_pick_right(node);
  else
    philo_pick_left(node);
  lphilo_think();
  if (node->data.philo->handed_side)
    philo_release_right(node);
  else
    philo_release_left(node);
}