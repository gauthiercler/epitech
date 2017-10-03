/*
** pop.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/egg_list/pop.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 23 18:01:59 2017 Clement Nancelle
** Last update Fri Jun 23 18:01:59 2017 Clement Nancelle
*/

#include		"egg.h"

bool			egg_list_pop(t_egg_list *self)
{
  return (self->list->pop_front(self->list));
}