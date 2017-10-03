/*
** close_connection.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/misc/close_connection.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jun 01 09:47:47 2017 Gauthier Cler
** Last update Thu Jun 01 09:47:47 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<memory.h>
#include	"common/error.h"
#include	"client/structures.h"

void		close_connection(t_client *client)
{
  if (client->connected)
  {
    if (close(client->socket.fd) == SYSCALL_FAIL)
      throw_error("close", __func__, &operational, CRITICAL);
    memset(client->channels, 0,
	   CHANNEL_NAME_SIZE + 1);
    memset(client->name, 0, CLIENT_NAME_SIZE + 1);
    client->connected = false;
  }
}