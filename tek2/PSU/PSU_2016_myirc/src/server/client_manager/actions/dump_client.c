/*
** dump_client.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/actions/dump_client.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 15:45:54 2017 Anas Buyumad
** Last update Thu Jun 01 15:45:54 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	<arpa/inet.h>
#include	<memory.h>
#include	"server/structures.h"

void		dump_client(t_client *client)
{
  fprintf(stdout, "IP -> %s\nID -> %d\nName -> %s\n\n",
	  inet_ntoa(client->socket.address.sin_addr),
	  client->id,
	  strlen(client->name) ? client->name : "(None)");
}