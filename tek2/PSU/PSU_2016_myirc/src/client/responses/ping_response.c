/*
** ping_response.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/ping_response.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jun 04 23:15:15 2017 Gauthier Cler
** Last update Sun Jun 04 23:15:15 2017 Gauthier Cler
*/

#include	"common/misc.h"
#include	"client/structures.h"

void		ping_response(t_client *client)
{
  if (operational)
  {
    if (client->response.message)
      write_in_fd(client->socket.fd, "%s %s%s", "PONG",
		  client->response.message, CRLF);
  }
}