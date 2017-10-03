/*
** dump.c for PSU_2016_zappy in /home/clement/Documents/rendu/c_reseau/PSU_2016_zappy/server/srcs/egg_list/dump.c
**
** Made by Clement Nancelle
** Login   <clement.nancelle@epitech.eu>
**
** Started on  Fri Jun 23 17:50:42 2017 Clement Nancelle
** Last update Fri Jun 23 17:50:42 2017 Clement Nancelle
*/

#include		<stdio.h>
#include		"egg.h"

static void		dump_egg(t_egg *egg)
{
  printf("Egg is at pos (%d;%d) and need %f tick to hatch\n",
	 egg->position.x,
	 egg->position.y,
	 egg->time_hatching);
}

void			egg_list_dump(t_egg_list *self)
{
  self->list->dump(self->list, (t_list_dump)dump_egg);
}