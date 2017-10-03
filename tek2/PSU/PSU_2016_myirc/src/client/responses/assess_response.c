/*
** assess_response.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/assess_response.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jun 04 23:08:54 2017 Gauthier Cler
** Last update Sun Jun 04 23:08:54 2017 Gauthier Cler
*/

#include			<memory.h>
#include			"client/responses.h"

static const t_response_type	response_type[] =
  {
    {"PING", &ping_response},
    {"JOIN", &joined_channel},
    {"PART", &leaved_channel},
    {"PRIVMSG", &received_message},
    {"NICK", &changed_username},
    {"001", &welcome_message},
    {"393", &list_user},
    {NULL, NULL}
  };

bool				assess_response(t_client *client)
{
  int				idx;

  if (operational && client->response.args[0])
  {
    idx = 0;
    while (response_type[idx].key != NULL &&
	   strncmp(response_type[idx].key, client->response.args[0],
		   strlen(response_type[idx].key)) != 0)
      idx += 1;
    if (response_type[idx].key == NULL)
      return (false);
    response_type[idx].ptr(client);
  }
  return (true);
}