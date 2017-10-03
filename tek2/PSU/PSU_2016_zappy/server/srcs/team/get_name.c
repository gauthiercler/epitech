/*
** get_name.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/team/get_name.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 11:48:00 2017 Antoine FORET
** Last update Wed Jun 28 11:48:00 2017 Antoine FORET
*/

#include	"team.h"

const char	*team_get_name(t_team *self)
{
  return (self->name);
}