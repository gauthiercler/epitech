/*
** change_nickname.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/commands/change_nickname.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 30 18:41:39 2017 Gauthier Cler
** Last update Tue May 30 18:41:39 2017 Gauthier Cler
*/

#include	<string.h>
#include	<unistd.h>
#include	"client/commands.h"
#include	"common/misc.h"

void		change_nickname(t_client *client)
{
  if (operational)
  {
    if (client->command.nb_args >= 1)
    {
      write_in_fd(client->socket.fd, "%s %s%s",
		  "NICK", client->command.args[1], CRLF);
      if (strlen(client->name) == 0)
	write_in_fd(client->socket.fd, "%s x x x x%s", "USER", CRLF);
    }
    else
      write_in_fd(STDOUT_FILENO, "/nick $nickname\n");
  }
}