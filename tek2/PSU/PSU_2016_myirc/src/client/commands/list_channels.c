/*
** list_channels.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/commands/list_channels.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 30 18:41:53 2017 Gauthier Cler
** Last update Tue May 30 18:41:53 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	"common/misc.h"
#include	"client/commands.h"

void		list_channels(t_client *client)
{
  if (operational)
  {
    if (client->command.nb_args == 0)
      write_in_fd(client->socket.fd, "%s%s", "LIST", CRLF);
    else
      write_in_fd(STDOUT_FILENO, "Invalid Number of arguments\n");
  }
}