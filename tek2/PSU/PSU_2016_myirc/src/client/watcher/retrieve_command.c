/*
** retrieve_command.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/watcher/retrieve_command.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jun 01 15:50:57 2017 Gauthier Cler
** Last update Thu Jun 01 15:50:57 2017 Gauthier Cler
*/

#include		<stdio.h>
#include		<unistd.h>
#include		<stdbool.h>
#include		<memory.h>
#include		"client/responses.h"
#include		"client/parser.h"
#include		"common/error.h"

void			read_input_data(t_client *client)
{
  ssize_t 		read_bytes;
  uint16_t 		free_space;
  char 			bytes[RING_BUFFER_SIZE];

  memset(bytes, 0, RING_BUFFER_SIZE);
  free_space = get_ring_buffer_free_space(&client->ring_buffer);
  if (!free_space)
    return ;
  read_bytes = read(client->socket.fd, bytes, free_space);
  if (read_bytes == SYSCALL_FAIL)
    throw_error("read", __func__, &client->connected, CRITICAL);
  else if (read_bytes == 0)
    client->connected = false;
  else
  {
    bytes[read_bytes] = '\0';
    push_bytes(&client->ring_buffer, bytes, read_bytes);
  }
}

bool			build_buffer_command(t_client *client)
{
  char			bytes[RING_BUFFER_SIZE];
  int16_t 		input_size;

  memset(bytes, 0, RING_BUFFER_SIZE);
  input_size = ring_buffer_get_input_size(&client->ring_buffer);
  if (ring_buffer_is_empty(&client->ring_buffer) ||
      input_size == INVALID_INPUT)
    return (false);
  if (!pop_bytes(&client->ring_buffer, (uint16_t)input_size, bytes))
    return (false);
  if (client->discard_command)
    client->discard_command = false;
  else
  {
    if (parse_response(&client->response, bytes))
    {
      if (!assess_response(client))
	display_response(client);
      clean_response(&client->response);
    }
  }
  return (true);
}