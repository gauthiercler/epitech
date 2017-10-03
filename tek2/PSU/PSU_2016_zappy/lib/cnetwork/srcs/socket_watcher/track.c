/*
** track.c for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/srcs/socket_watcher/track.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 11:50:59 2017 Antoine FORET
** Last update Tue May 23 11:50:59 2017 Antoine FORET
*/

#include		<malloc.h>
#include		"socket_watcher.h"

static t_socket_tracked	*generate_track_record(t_socket_watcher *self,
						      void *socket,
						      enum e_socket_type type,
						      int domain)
{
  t_socket_tracked	*record;

  record = malloc(sizeof(t_socket_tracked));
  if (record == NULL)
    return (NULL);
  record->socket = socket;
  record->type = type;
  record->action = domain;
  record->real_socket = self->get_record_socket(self, record);
  record->next = NULL;
  return (record);
}

static bool		update_track_record(t_socket_tracked *record,
					       int domain)
{
  record->action = domain;
  return (true);
}

static bool		insert_track_record(t_socket_watcher *self,
					       t_socket_tracked *record)
{
  record->next = self->tracked_sockets;
  self->tracked_sockets = record;
  return (true);
}

bool			socket_watcher_track(t_socket_watcher *self,
						 void *socket,
						 enum e_socket_type type,
						 int domain)
{
  t_socket_tracked	*record;

  record = self->get_record(self, socket);
  if (record != NULL)
    return (update_track_record(record, domain));
  else
  {
    record = generate_track_record(self, socket, type, domain);
    if (record == NULL)
      return (false);
    else
      return (insert_track_record(self, record));
  }
}