/*
** main.c for PSU_2016_zappy in /home/gogo/rendu/tek2/PSU_2016_zappy/server/main.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Jun 20 10:31:40 2017 Gauthier Cler
** Last update Tue Jun 20 10:31:40 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"server.h"

int		main(int argc, const char *argv[])
{
  t_server	*server;

  server = new_server();
  if (server == NULL)
  {
    fprintf(stderr, "[ERROR] Unable to create server\n");
    return (EXIT_FAILURE);
  }
  server->initialize(server, argc, argv);
  server->run(server);
  server->destroy(server);
  return (EXIT_SUCCESS);
}
