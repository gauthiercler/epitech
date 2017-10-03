/*
** push.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/egg_list/push.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 23 18:06:32 2017 Clement Nancelle
** Last update Fri Jun 23 18:06:32 2017 Clement Nancelle
*/

#include		"egg.h"

bool			egg_list_push(t_egg_list *self, t_egg *egg)
{
  return (self->list->push_back(self->list, egg));
}