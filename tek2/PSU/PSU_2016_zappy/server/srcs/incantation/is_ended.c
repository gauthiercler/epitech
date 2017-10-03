/*
** is_ended.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/incantation/is_ended.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 24 16:50:45 2017 Antoine FORET
** Last update Sat Jun 24 16:50:45 2017 Antoine FORET
*/

#include	"incantation.h"

bool		incantation_is_ended(t_incantation *self)
{
  return (self->time_remaining == 0);
}