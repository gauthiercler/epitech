/*
** structures.h for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/include/structures.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 10 09:55:56 2017 Gauthier Cler
** Last update Wed May 10 09:55:56 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYFTP_STRUCTURES_H
# define PSU_2016_MYFTP_STRUCTURES_H

# include			<stdio.h>
# include			<netinet/in.h>

typedef struct s_socket		t_socket;
typedef struct s_client		t_client;
typedef struct s_user		t_user;
typedef struct s_server		t_server;
typedef union u_port		t_port;
typedef struct s_data_socket	t_data_socket;

enum				e_action_state
{
  GREETINGS,
  LOGIN_SUCCESS,
  UNKNOWN_COMMAND,
  LOGIN_USER_FIRST,
  LOGIN_USER_PASS,
  SPECIFY_PASS,
  NULL_STATE,
  CANT_SWITCH_GUEST,
  ALREADY_LOGGED_IN,
  BAD_LOGIN,
  NOOP_OK,
  QUIT,
  HELP_OK,
  CWD_FAILED,
  CWD_OK,
  ENTER_PASSIVE,
  DATA_NOT_ENABLED,
  BEFORE_LIST,
  AFTER_LIST,
  FILE_OPEN_FAILED,
  FILE_CREATE_FAILED,
  TRANSFER_COMPLETE,
  DELETE_OK,
  DELETE_FAILED,
  PERMISSION_DENIED,
  ILLEGAL_PORT,
  PORT_OK,
  CONNECTION_FAILED,
  OK_SEND_DATA
};

enum				e_connection_type
{
  ACTIVE,
  PASSIVE,
};

union				u_port
{
  uint16_t			full;
  uint8_t			byte[2];
};

struct				s_command_tab
{
  const char			*command_name;
  void				(*func_ptr)(t_client *client);
};

struct				s_code_tab
{
  enum e_action_state		state;
  int				code;
  const char			*message;
};

struct				s_socket
{
  int				fd;
  struct sockaddr_in		addr;
  t_port			port;
};

struct				s_data_socket
{
  t_socket			socket;
  enum e_connection_type	type;
  bool				active;
};

struct				s_user
{
  char				*name;
  bool				logged;
};

struct				s_client
{

  FILE				*stream_fd;
  t_socket			socket;
  t_data_socket			data_socket;
  t_user			user;
  size_t			message_length;
  char				*input;
  char				**args;
  char				*path;
  char				*base_path;
  bool				active;
};

struct				s_server
{
  t_socket			socket;
};

#endif /* !PSU_2016_MYFTP_STRUCTURES_H */
