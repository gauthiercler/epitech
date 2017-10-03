/*
** retrieve_command.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/parser/retrieve_command.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 13:20:39 2017 Anas Buyumad
** Last update Mon May 29 13:20:39 2017 Anas Buyumad
*/

#include		<memory.h>
#include		<stdio.h>
#include		<arpa/inet.h>
#include		<unistd.h>
#include		"common/error.h"
#include		"server/client_manager.h"
#include		"server/buffer.h"
#include		"server/parser.h"

bool			build_buffer_command(t_cmd_buffer *buffer,
						 t_client *client)
{
  char			bytes[RING_BUFFER_SIZE];
  int16_t 		input_size;

  if (operational)
  {
    if (buffer_is_full(buffer))
      return (false);
    memset(bytes, 0, RING_BUFFER_SIZE);
    input_size = ring_buffer_get_input_size(&client->ring_buffer);
    if (ring_buffer_is_empty(&client->ring_buffer) ||
	input_size == INVALID_INPUT || input_size == NON_CONFORM)
      return (false);
    if (!pop_bytes(&client->ring_buffer, (uint16_t)input_size, bytes))
      return (false);
    client->discard_command ?
      client->discard_command = false :
    build_command(buffer, client, bytes);
    return (true);
  }
  return (false);
}

static void		read_input_data(t_client *client)
{
  ssize_t 		read_bytes;
  uint16_t 		free_space;
  char 			bytes[RING_BUFFER_SIZE];

  if (operational)
  {
    memset(bytes, 0, RING_BUFFER_SIZE);
    free_space = get_ring_buffer_free_space(&client->ring_buffer);
    if (!free_space)
      return ;
    read_bytes = read(client->socket.fd, bytes, free_space);
    if (read_bytes == SYSCALL_FAIL)
      throw_error("read", __func__, &client->connected, CRITICAL);
    else if (read_bytes == 0)
    {
      fprintf(stdout, "[EOF]\n");
      dump_client(client);
      client->connected = false;
    }
    else
    {
      bytes[read_bytes] = '\0';
      push_bytes(&client->ring_buffer, bytes, read_bytes);
    }
  }
}

void			retrieve_command(t_cmd_buffer *buffer,
					     t_client *client)
{
  if (operational)
  {
    if (!build_buffer_command(buffer, client))
    {
      if (operational && ring_buffer_is_full(&client->ring_buffer))
      {
	fprintf(stdout, "[Building Command :: Discard]\n"
	  "IP -> %s\nID -> %d\nName -> %s\n\n",
		inet_ntoa(client->socket.address.sin_addr),
		client->id,
		strlen(client->name) ? client->name : "(None)");
	client->discard_command = true;
	ring_buffer_discard_data(&client->ring_buffer);
      }
      read_input_data(client);
    }
  }
}