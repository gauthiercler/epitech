/*
** send_cell_content.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_cell_content.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 11:31:14 2017 Montagne Valentin
** Last update Wed Jun 28 11:31:14 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_cell_content(t_graph_client *self,
					      t_position *pos,
					      t_tile *cell)
{
  char			msg[MAXBUFFSIZE_CELLCONTENT];
  t_inventory		*inventory;

  inventory = cell->inventory;
  if (snprintf(msg, MAXBUFFSIZE_CELLCONTENT, "bct %d %d %d %d %d "
		 "%d %d %d %d\n", pos->x, pos->y,
	  inventory->food, inventory->linemate, inventory->deraumere,
	  inventory->sibur, inventory->mendiane, inventory->phiras,
	  inventory->thystame) == -1)
    return (false);
  return (self->send(self, msg));
}