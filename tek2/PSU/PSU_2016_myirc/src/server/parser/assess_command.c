/*
** assess_command.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/parser/assess_command.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu May 25 18:01:14 2017 Anas Buyumad
** Last update Thu May 25 18:01:14 2017 Anas Buyumad
*/

#include		<stdlib.h>
#include		<memory.h>
#include		"server/structures.h"

static const t_cmd_type	commands[] =
  {
    {"QUIT", QUIT},
    {"NICK", SET_NICKNAME},
    {"USERS", LIST_USERS},
    {"USER", REGISTER},
    {"LIST", LIST_CHANNELS},
    {"JOIN", JOIN_CHANNEL},
    {"PART", LEAVE_CHANNEL},
    {"NAMES", LIST_CHANNEL_USERS},
    {"PRIVMSG", SEND_MESSAGE},
    {"SENDFILE", SEND_FILE},
    {"ACCEPTFILE", ACCEPT_FILE},
    {NULL, NONE}
  };

enum e_cmd_type		assess_command(char *command)
{
  size_t		idx;

  idx = 0;
  while (commands[idx].key != NULL &&
	 strncmp(commands[idx].key, command,
		 strlen(commands[idx].key)) != 0)
    idx += 1;
  return (commands[idx].value);
}