/*
** destroy.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team_list/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 09:43:39 2017 Antoine FORET
** Last update Wed Jun 28 09:43:39 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"team.h"

void		team_list_destroy(t_team_list *self)
{
  if (self->list != NULL)
    self->list->destroy(self->list);
  free(self);
}