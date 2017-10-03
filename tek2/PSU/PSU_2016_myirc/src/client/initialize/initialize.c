/*
** initialize.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/initialize/initialize.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 29 16:43:08 2017 Gauthier Cler
** Last update Mon May 29 16:43:08 2017 Gauthier Cler
*/

#include	<memory.h>
#include	"client/structures.h"

void		initialize_client(t_client *client)
{
  memset(client, 0, sizeof(t_client));
  initialize_ring_buffer(&client->ring_buffer);
  client->response.message = NULL;
  client->response.args = NULL;
  client->response.prefix = NULL;
}