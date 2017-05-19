/*
** clean_list.c for PSU_2016_philo in /home/gogo/rendu/tek2/PSU_2016_philo/sources/list/clean_list.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Mar 07 18:30:51 2017 Gauthier Cler
** Last update Tue Mar 07 18:30:51 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	"philo.h"

static void	clean_struct(t_node *node)
{
  if (node->node_type == STICK)
  {
    pthread_mutex_destroy(&node->data.stick->mutex);
    free(node->data.stick);
  }
  else
  {
    free(node->data.philo);
  }
}

static void	delete_node(t_node **list)
{
  t_node	*tmp;

  if (!(*list))
    return ;
  tmp = *list;
  if (tmp->next == tmp)
  {
    clean_struct(*list);
    free(*list);
    *list = NULL;
  }
  else
  {
    *list = tmp->next;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    clean_struct(tmp);
    free(tmp);
  }
}

void		clean_list(t_node **list)
{
  while ((*list))
    delete_node(list);
}