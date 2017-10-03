/*
** destroy.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/egg_list/destroy.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 23 18:00:10 2017 Clement Nancelle
** Last update Fri Jun 23 18:00:11 2017 Clement Nancelle
*/

#include		<malloc.h>
#include		"egg.h"

void			egg_list_destroy(t_egg_list *self)
{
  if (self->list != NULL)
    self->list->destroy(self->list);
  free(self);
}