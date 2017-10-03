/*
** assess_command.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/client/parser/assess_command.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu May 25 18:33:17 2017 Anas Buyumad
** Last update Thu May 25 18:33:17 2017 Anas Buyumad
*/

#include		<stdlib.h>
#include		<memory.h>
#include		"client/commands.h"

static const t_cmd_type	commands[] =
  {
    {"/server", CONNECT, &connect_to_server},
    {"/nick", SET_NICKNAME, &change_nickname},
    {"/list", LIST_CHANNELS, &list_channels},
    {"/join", JOIN_CHANNEL, &join_channel},
    {"/part", LEAVE_CHANNEL, &leave_channel},
    {"/users", LIST_USERS, &list_users},
    {"/names", LIST_CHANNEL_USERS, &list_channel_users},
    {"/msg", SEND_MESSAGE, &private_message},
    {"/msg", SEND_FILE, &send_file},
    {"/accept_file", ACCEPT_FILE, &accept_file},
    {NULL, NONE, &channel_message}
  };

enum e_cmd_type		assess_command(const char *command)
{
  size_t		idx;

  idx = 0;
  while (commands[idx].key != NULL &&
	 strncmp(commands[idx].key, command,
		 strlen(commands[idx].key)) != 0)
    idx += 1;
  return (commands[idx].type);
}

void			execute_command(t_client *client)
{
  int			idx;

  idx = 0;
  while (commands[idx].type != client->command.type)
    idx += 1;
  if (client->command.type != CONNECT && !client->connected)
    not_connected_message();
  else
    commands[idx].ptr(client);
}