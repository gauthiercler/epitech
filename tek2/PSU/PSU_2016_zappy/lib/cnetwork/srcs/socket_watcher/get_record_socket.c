/*
** get_record_socket.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/get_record_socket.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 14:15:13 2017 Antoine FORET
** Last update Tue May 23 14:15:13 2017 Antoine FORET
*/

#include			"socket_watcher.h"

static SOCKET			tcp_resolver(void *socket)
{
  return (((t_tcp_socket *)socket)->socket);
}

static SOCKET			client_resolver(void *socket)
{
  return (tcp_resolver(((t_client *)socket)->socket));
}

static const t_socket_resolver	resolver[] = {
  {ST_CLIENT, client_resolver},
  {ST_TCP, tcp_resolver},
  {0, NULL}
};

static SOCKET			get_socket(const t_socket_resolver *resolver,
						t_socket_tracked *record)
{
  if (resolver->converter == NULL)
    return (SOCKET_ERROR);
  if (resolver->type == record->type)
    return (resolver->converter(record->socket));
  else
    return (get_socket(&resolver[1], record));
}

SOCKET				socket_watcher_get_record_socket(
  t_socket_watcher		*self,
  t_socket_tracked		*record)
{
  (void)(self);
  return (get_socket(resolver, record));
}