/*
** pop_egg.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/egg_list/pop_egg.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Wed Jun 28 16:01:18 2017 Clement Nancelle
** Last update Wed Jun 28 16:01:18 2017 Clement Nancelle
*/

#include		"egg.h"

bool		egg_list_pop_egg(t_egg_list *self, t_egg *egg)
{
  return (self->list->pop_data(self->list, egg));
}