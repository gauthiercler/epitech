/*
** help_message.c for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/src/commands/help_message.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 10:40:59 2017 Gauthier Cler
** Last update Wed May 10 10:41:00 2017 Gauthier Cler
*/

#include	"socket.h"
#include	"macro.h"
#include	"ftp.h"

void		help_message(t_client *client)
{
  size_t	idx;

  if (dprintf(client->socket.fd, "%d-The following commands are recognized.%s",
	  214, CRLF) < 0)
  {
    client->active = false;
    return ;
  }
  idx = 0;
  while (get_command_at_idx(idx))
  {
    if (dprintf(client->socket.fd, "%s%s%s", (idx == 0) ? " " : "",
	    get_command_at_idx(idx),
	    (get_command_at_idx(idx + 1) ? " " : CRLF)) < 0)
    {
      client->active = false;
      return ;
    }
    idx += 1;
  }
  send_response(client, HELP_OK);
}