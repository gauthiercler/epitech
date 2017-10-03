/*
** private_message.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/commands/private_message.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 30 18:45:02 2017 Gauthier Cler
** Last update Tue May 30 18:45:02 2017 Gauthier Cler
*/

#include 	<unistd.h>
#include	<memory.h>
#include	"common/misc.h"
#include	"client/commands.h"

void		private_message(t_client *client)
{
  char		*message;

  if (operational)
  {
    if (client->command.nb_args >= 2)
    {
      message = strstr(client->command.raw_input, client->command.args[1])
		+ strlen(client->command.args[1]);
      while (*message == ' ')
	message++;
      write_in_fd(client->socket.fd,
		  "%s %s :%s%s",
		  "PRIVMSG",
		  client->command.args[1],
		  message,
		  CRLF);
      write_in_fd(STDOUT_FILENO, "<%s> %s\n", client->name,
		  message);
    }
    else
      write_in_fd(STDOUT_FILENO, "%s\n",
		  "/msg : Not enough arguments given");
  }
}