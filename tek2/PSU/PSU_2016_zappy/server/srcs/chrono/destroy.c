/*
** destroy.c for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/srcs/chrono/destroy.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Fri Jun 23 16:10:10 2017 Antoine FORET
** Last update Fri Jun 23 16:10:10 2017 Antoine FORET
*/

#include	<malloc.h>
#include	"chrono.h"

void		chrono_destroy(t_chrono *self)
{
  free(self);
}