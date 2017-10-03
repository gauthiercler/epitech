/*
** size.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/egg_list/size.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 23 17:34:37 2017 Clement Nancelle
** Last update Fri Jun 23 17:34:37 2017 Clement Nancelle
*/

#include		<stddef.h>
#include		"egg.h"

size_t			egg_list_size(t_egg_list *self)
{
  return (self->list->size(self->list));
}