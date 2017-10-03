/*
** validate.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/incantation/validate.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 24 16:51:18 2017 Antoine FORET
** Last update Sat Jun 24 16:51:18 2017 Antoine FORET
*/

#include	"incantation.h"

static bool	validate_players(t_incantation *self, t_tile *tile)
{
  return (tile->nb_players(tile) == self->needs->player &&
      tile->nb_players_at(tile, self->needs->level) == self->needs->player);
}

static bool	validate_ressources(t_incantation *self, t_tile *tile)
{
  return (self->needs->deraumere == tile->inventory->deraumere &&
	  self->needs->linemate == tile->inventory->linemate &&
	  self->needs->mendiane == tile->inventory->mendiane &&
	  self->needs->phiras == tile->inventory->phiras &&
	  self->needs->sibur == tile->inventory->sibur &&
	  self->needs->thystame == tile->inventory->thystame);
}

bool		incantation_validate(t_incantation *self, t_tile *tile)
{
  return (validate_players(self, tile) && validate_ressources(self, tile));
}