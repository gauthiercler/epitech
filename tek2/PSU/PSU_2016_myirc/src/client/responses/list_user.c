/*
** list_user.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/responses/list_user.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jun 06 15:38:32 2017 Gauthier Cler
** Last update Tue Jun 06 15:38:32 2017 Gauthier Cler
*/

#include	<unistd.h>
#include	"common/misc.h"
#include	"client/misc.h"

void		list_user(t_client *client)
{
  if (operational && client->response.nb_args >= 1)
  {
    display_time();
    write_in_fd(STDOUT_FILENO, " -|- %s\n", client->response.args[1]);
  }
}