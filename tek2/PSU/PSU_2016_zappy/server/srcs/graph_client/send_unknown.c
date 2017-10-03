/*
** send_unknown.c for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/srcs/graph_client/send_unknown.c
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Wed Jun 28 16:14:07 2017 Montagne Valentin
** Last update Wed Jun 28 16:14:07 2017 Montagne Valentin
*/

#include		<string.h>
#include		<stdio.h>
#include		"graph_client.h"

bool			send_unknown(t_graph_client *self)
{
  return (self->client->send(self->client, "suc", 3, true) != -1);
}