/*
** run_command.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/run_command.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 17:55:42 2017 Anas Buyumad
** Last update Thu Jun 01 17:55:42 2017 Anas Buyumad
*/

#include		<stdlib.h>
#include		"common/misc.h"
#include		"server/engine.h"
#include		"server/parser.h"

static const t_cmd_mgr	commands[] =
  {
    {QUIT, &quit},
    {SET_NICKNAME, &set_nickname},
    {REGISTER, &register_user},
    {LIST_CHANNELS, &list_channels},
    {JOIN_CHANNEL, &join_channel},
    {LEAVE_CHANNEL, &leave_channel},
    {LIST_USERS, &list_users},
    {LIST_CHANNEL_USERS, &list_channel_users},
    {SEND_MESSAGE, &send_message},
    {SEND_FILE, &send_file},
    {ACCEPT_FILE, &accept_file},
    {NONE, &invalid_command},
    {NONE, NULL}
  };

void			run_command(t_server *server, t_command *command)
{
  size_t		iterator;

  iterator = 0;
  dump_command(command);
  while (commands[iterator].run != NULL)
  {
    if (command->type == commands[iterator].key)
    {
      commands[iterator].run(server, command);
      if (command->args)
	free_array(command->args);
    }
    iterator += 1;
  }
}