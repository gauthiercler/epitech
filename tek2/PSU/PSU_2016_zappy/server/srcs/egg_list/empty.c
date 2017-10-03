/*
** empty.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/egg_list/empty.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 29 09:39:31 2017 Montagne Valentin
** Last update Thu Jun 29 09:39:31 2017 Montagne Valentin
*/

#include 		<stdlib.h>
#include		"egg.h"

static bool		delete_egg(t_egg *self)
{
  if (self != NULL)
    self->destroy(self);
  return (true);
}

void			egg_list_empty(t_egg_list *self)
{
  self->apply(self, (t_list_action)(delete_egg), NULL);
}
