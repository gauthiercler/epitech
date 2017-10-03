/*
** destroy.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 11:01:45 2017 Antoine FORET
** Last update Wed Jun 28 11:01:45 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"team.h"

void		team_destroy(t_team *self)
{
  if (self->players != NULL)
    self->players->destroy(self->players);
  if (self->name != NULL)
    free(self->name);
  if (self->eggs != NULL)
  {
    self->eggs->empty(self->eggs);
    self->eggs->destroy(self->eggs);
  }
  free(self);
}