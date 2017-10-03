/*
** flush_disconnected_clients.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/client_manager/actions/flush_disconnected_clients.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 11:12:10 2017 Anas Buyumad
** Last update Thu Jun 01 11:12:10 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"server/channel_manager.h"
#include	"server/client_manager.h"
#include	"server/engine.h"

void		flush_client_from_channels(t_server *server,
					       t_client *client)
{
  size_t	iterator;
  t_channel	*channel;

  iterator = 0;
  while (iterator < MAX_CLIENT_CHANNELS)
  {
    if (client->channels[iterator] > 0)
    {
      channel = get_channel_by_id(&server->channel_mgr,
				  (uint8_t)client->channels[iterator]);
      if (channel)
	part_single_channel(server, client, channel->name);
    }
    iterator += 1;
  }
}

void		flush_disconnected_clients(t_server *server)
{
  size_t	iterator;

  iterator = 0;
  while (iterator < MAX_CLIENTS)
  {
    if (!server->client_mgr.clients[iterator].connected)
      if (server->client_mgr.clients[iterator].id > 0)
      {
	fprintf(stdout, "[Flushing Client]\n");
	dump_client(&server->client_mgr.clients[iterator]);
	flush_client_from_channels(server,
				   &server->client_mgr.clients[iterator]);
	remove_client_by_id(&server->client_mgr,
			    server->client_mgr.clients[iterator].id);
      }
    iterator += 1;
  }
}