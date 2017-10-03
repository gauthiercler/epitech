/*
** front.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/egg_list/front.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 23 17:57:04 2017 Clement Nancelle
** Last update Fri Jun 23 17:57:04 2017 Clement Nancelle
*/

#include		"egg.h"

t_egg			*egg_list_front(t_egg_list *self)
{
  return (self->list->front(self->list));
}