/*
** apply.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/egg_list/apply.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 17:56:32 2017 Montagne Valentin
** Last update Wed Jun 28 17:56:32 2017 Montagne Valentin
*/

#include	"egg.h"

bool		egg_list_apply(t_egg_list *self, t_list_action action,
				   void *params)
{
  return (self->list->foreach(self->list, action, params));
}
