/*
** structures.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/server/structures.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu May 25 16:17:40 2017 Anas Buyumad
** Last update Thu May 25 16:17:41 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_SERVER_STRUCTURES_H
# define PSU_2016_MYIRC_SERVER_STRUCTURES_H

# include			<stdbool.h>
# include			"common/ring_buffer.h"
# include			"common/structures.h"
# include			"config.h"

typedef struct s_cmd_type	t_cmd_type;
typedef struct s_cmd_buffer	t_cmd_buffer;
typedef struct s_channel_mgr	t_channel_mgr;
typedef struct s_client		t_client;
typedef struct s_client_mgr	t_client_mgr;
typedef struct s_server		t_server;

struct 				s_cmd_type
{
  char				*key;
  enum e_cmd_type		value;
};

struct				s_cmd_buffer
{
  t_command			buffer[COMMAND_BUFFER_SIZE];
  t_command			*head;
  t_command			*tail;
};

struct				s_channel_mgr
{
  t_channel			channels[MAX_CHANNELS];
};

struct				s_client
{
  bool				connected;
  bool				registered;
  t_socket			socket;
  int16_t			id;
  char				name[CLIENT_NAME_SIZE + 1];
  int8_t			channels[MAX_CLIENT_CHANNELS];
  uint8_t			active_channels;
  t_ring_buffer			ring_buffer;
  bool				discard_command;
};

struct				s_client_mgr
{
  t_client			clients[MAX_CLIENTS];
};

struct				s_server
{
  t_socket			socket;
  t_cmd_buffer			buffer;
  t_watcher			watcher;
  t_client_mgr			client_mgr;
  t_channel_mgr			channel_mgr;
};

#endif /* !PSU_2016_MYIRC_SERVER_STRUCTURES_H */