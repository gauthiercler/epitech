/*
** leave_channel.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/commands/leave_channel.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 30 18:43:18 2017 Gauthier Cler
** Last update Tue May 30 18:43:18 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	"client/commands.h"
#include	"common/misc.h"

void		leave_channel(t_client *client)
{
    if (operational)
    {
      if (client->command.nb_args == 1)
	write_in_fd(client->socket.fd, "%s %s%s", "PART",
		    client->command.args[1], CRLF);
      else
	write_in_fd(STDOUT_FILENO, "Invalid number of arguments\n");
    }
}