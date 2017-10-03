/*
** structures.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/common/structures.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu May 25 16:19:50 2017 Anas Buyumad
** Last update Thu May 25 16:19:50 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_COMMON_STRUCTURES_H
# define PSU_2016_MYIRC_COMMON_STRUCTURES_H

# include			<netinet/in.h>
# include			<stdbool.h>
# include			"config.h"

typedef struct s_channel	t_channel;
typedef struct s_command	t_command;
typedef struct s_socket		t_socket;
typedef struct s_watcher	t_watcher;

extern bool			operational;

struct				s_channel
{
  bool				active;
  char				name[CHANNEL_NAME_SIZE + 1];
  int8_t			id;
};

struct				s_command
{
# ifdef SERVER_C
  int16_t 			client_id;
# endif
  enum e_cmd_type		type;
  char				**args;
  uint8_t			nb_args;
  char				raw_input[MSG_MAX_SIZE + 1];
};

struct				s_socket
{
  int				fd;
  struct sockaddr_in		address;
};

struct				s_watcher
{
  int				max;
  int				ready_fds;
  fd_set			read_watcher;
  fd_set			exception_watcher;
  struct timeval		timeout;
};

#endif /* !PSU_2016_MYIRC_COMMON_STRUCTURES_H */