/*
** initialize.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/initialize/initialize.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat May 27 18:00:25 2017 Anas Buyumad
** Last update Sat May 27 18:00:27 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<memory.h>
#include	<arpa/inet.h>
#include	"common/socket.h"
#include	"server/buffer.h"

static void	initialize_server_socket(t_socket *socket, uint16_t port)
{
  create_socket(socket);
  init_socket(socket, port, INADDR_ANY);
  bind_socket(socket);
  listen_on_socket(socket);
}

void		initialize_server(t_server *server, uint16_t port)
{
  memset(server, 0, sizeof(t_server));
  initialize_buffer(&server->buffer);
  initialize_server_socket(&server->socket, port);
  fprintf(stdout,
	  "[SERVER INIT]\nSocket FD : %d\nListening on port %d... at %s\n",
	  server->socket.fd, ntohs(server->socket.address.sin_port),
	  inet_ntoa(server->socket.address.sin_addr));
}