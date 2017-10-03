/*
** display_response.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/display_response.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jun 04 20:48:08 2017 Gauthier Cler
** Last update Sun Jun 04 20:48:08 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	<memory.h>
#include	"client/misc.h"
#include	"common/misc.h"

static void	display_args(t_client *client)
{
  int		idx;

  idx = 0;
  while (client->response.args[idx])
  {
    if (!is_number(client->response.args[idx]) &&
	strncmp(client->response.args[idx], client->name,
		strlen(client->response.args[idx])) != 0)
      write_in_fd(STDOUT_FILENO, " %s ", client->response.args[idx]);
    idx += 1;
  }
}

void		display_response(t_client *client)
{
  display_time();
  write_in_fd(STDOUT_FILENO, " -|-");
  display_args(client);
  if (client->response.message)
    write_in_fd(STDOUT_FILENO, " %s\n", client->response.message);
  else
    write_in_fd(STDOUT_FILENO, "\n");
}