/*
** structures.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/client/structures.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu May 25 18:33:41 2017 Anas Buyumad
** Last update Thu May 25 18:33:41 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_CLIENT_STRUCTURES_H
# define PSU_2016_MYIRC_CLIENT_STRUCTURES_H

# include			"common/ring_buffer.h"
# include			"common/structures.h"

typedef struct s_cmd_type	t_cmd_type;
typedef struct s_client		t_client;
typedef struct s_response	t_response;

struct				s_cmd_type
{
  char				*key;
  enum e_cmd_type		type;
  void				(*ptr)(t_client *client);
};

struct				s_response
{
  char				*prefix;
  uint8_t			nb_args;
  char				*message;
  char				**args;
};

struct				s_client
{
  t_socket			socket;
  t_channel			channels[MAX_CLIENT_CHANNELS];
  t_command			command;
  t_response			response;
  t_watcher			watcher;
  t_ring_buffer			ring_buffer;
  char				name[CLIENT_NAME_SIZE + 1];
  bool				connected;
  bool				discard_command;
};

#endif /* !PSU_2016_MYIRC_STRUCTURES_H */