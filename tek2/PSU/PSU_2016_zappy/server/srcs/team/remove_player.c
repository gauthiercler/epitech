/*
** remove_player.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/remove_player.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 11:05:12 2017 Antoine FORET
** Last update Wed Jun 28 11:05:12 2017 Antoine FORET
*/

#include	"team.h"

bool		team_remove_player(t_team *self, t_player *player)
{
  return (self->players->pop(self->players, player));
}