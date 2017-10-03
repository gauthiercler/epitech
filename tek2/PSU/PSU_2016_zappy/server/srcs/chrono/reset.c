/*
** reset.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/chrono/reset.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 23 16:02:26 2017 Antoine FORET
** Last update Fri Jun 23 16:02:26 2017 Antoine FORET
*/

#include	"chrono.h"

void		chrono_reset(t_chrono *self)
{
  gettimeofday(&self->time, 0);
}