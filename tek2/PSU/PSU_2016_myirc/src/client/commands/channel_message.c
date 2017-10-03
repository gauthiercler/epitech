/*
** channel_message.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/commands/channel_message.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 30 18:45:17 2017 Gauthier Cler
** Last update Tue May 30 18:45:18 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include	"client/misc.h"
#include	"client/channels.h"
#include	"common/misc.h"
#include	"client/commands.h"

void		channel_message(t_client *client)
{
  char		*channel_name;

  if (operational)
  {
    display_time();
    channel_name = get_max_channel_name(client->channels);
    if (strlen(channel_name) > 0)
    {
      write_in_fd(client->socket.fd,
		  "%s %s :%s%s",
		  "PRIVMSG",
		  channel_name,
		  client->command.raw_input,
		  CRLF);
      write_in_fd(STDOUT_FILENO, " %s <%s> %s\n", channel_name,
		  client->name,
		  client->command.raw_input);
    }
    else
      write_in_fd(STDOUT_FILENO, " -|- %s\n", "No Channels joined");
  }
}