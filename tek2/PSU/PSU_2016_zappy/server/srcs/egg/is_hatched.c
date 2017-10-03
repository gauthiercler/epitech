/*
** is_hatched.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/egg/is_hatched.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 24 19:14:22 2017 Antoine FORET
** Last update Sat Jun 24 19:14:22 2017 Antoine FORET
*/

#include	"egg.h"

bool		egg_is_hatched(t_egg *self)
{
  return (self->time_hatching == 0);
}