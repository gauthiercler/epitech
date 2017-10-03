/*
** place_ressources.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/server/place_ressources.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 28 11:08:21 2017 Antoine FORET
** Last update Wed Jun 28 11:08:21 2017 Antoine FORET
*/

#include	"server.h"

void		server_place_resources(t_server *self, float rate)
{
  self->map->spawn_resources(self->map, &self->config, rate);
}