/*
** engine.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/server/engine.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 17:55:59 2017 Anas Buyumad
** Last update Thu Jun 01 17:55:59 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_SERVER_ENGINE_H
# define PSU_2016_MYIRC_SERVER_ENGINE_H

# include			"server/structures.h"

# define SERVER_PREFIX		(":epireboot.net")
# define CRLF			("\r\n")
# define INVALID_NICK_CHARS	("#&")
# define CHANNEL_SUFFIX	("#&")

typedef struct s_cmd_mgr	t_cmd_mgr;

enum e_responses_codes
{
  RPL_WELCOME = 1,
  RPL_LISTSTART = 321,
  RPL_LIST = 322,
  RPL_LISTEND = 323,
  RPL_NAMREPLY = 353,
  RPL_ENDOFNAMES = 366,
  RPL_USERSSTART = 392,
  RPL_USERS = 393,
  RPL_ENDOFUSERS = 394,
  RPL_NOUSERS = 395,
  ERR_NOSUCHNICK = 401,
  ERR_NOSUCHCHANNEL = 403,
  ERR_CANNOTSENDTOCHAN = 404,
  ERR_TOOMANYCHANNELS = 405,
  ERR_NORECIPIENT = 411,
  ERR_NOTEXTTOSEND = 412,
  ERR_NONICKNAMEGIVEN = 431,
  ERR_ERRONEUSNICKNAME = 432,
  ERR_NICKNAMEINUSE = 433,
  ERR_NOTONCHANNEL = 442,
  ERR_NOTREGISTERED = 451,
  ERR_NEEDMOREPARAMS = 461,
  ERR_ALREADYREGISTERED = 462
};

struct				s_cmd_mgr
{
  enum e_cmd_type		key;
  void				(*run)(t_server *server,
					     t_command *command);
};

void				process_commands(t_server *server);
void				run_command(t_server *server,
						t_command *command);
void				quit(t_server *server, t_command *command);
void				set_nickname(t_server *server,
						 t_command *command);
void				register_user(t_server *server,
						  t_command *command);
void				list_channels(t_server *server,
						  t_command *command);
void				join_channel(t_server *server,
						 t_command *command);
void				leave_channel(t_server *server,
						  t_command *command);
void				list_users(t_server *server,
					       t_command *command);
void				list_channel_users(t_server *server,
						       t_command *command);
void				send_message(t_server *server,
						 t_command *command);
void				send_file(t_server *server,
					      t_command *command);
void				accept_file(t_server *server,
						t_command *command);
void				invalid_command(t_server *server,
						    t_command *command);
void				throw_error_need_more_params(
  t_client *client, char *command);
void				throw_error_no_nickname_given(
  t_client *client);
void				throw_error_erroneus_nickname(
  t_client *client, char *nickname);
void				throw_error_nickname_in_use(
  t_client *client, char *nickname);
void			throw_error_no_such_channel(
  t_client *client, char *channel_name);
void				throw_error_not_on_channel(
  t_client *client, char *channel_name);
void				throw_error_too_many_channels(
  t_client *client, char *channel_name);
void				join_broadcast(t_client_mgr *manager,
						   t_client *user,
						   t_channel *channel);
void				part_single_channel(t_server *server,
							t_client *client,
							char *channel_name);
void				part_broadcast(t_client_mgr *manager,
						   t_client *user,
						   t_channel *channel);
void				stop_channel_listing(t_client *client);
void				list_channel(t_client *client,
						 t_channel *channel);
void				start_channel_listing(t_client *client);
void				welcome_user(t_client *client);
void				start_users_listing(t_client *client);
void				stop_users_listing(t_client *client);
void				list_server_users(t_client_mgr *manager,
						      t_client *client);
void				throw_error_no_users(t_client *client);
void				throw_error_no_such_nick(t_client *client,
					     char *name);
void				throw_error_cannot_send_to_channel(
  t_client *client, char *channel_name);
void				throw_error_no_text_to_send(
  t_client *client);
void				throw_error_no_recipient(t_client *client,
							     char *command);
void				stop_names_listing(t_client *client,
						       char *channel_name);
void				list_names(t_client_mgr *manager,
					       t_client *client,
					       t_channel *channel);
void				throw_error_already_registered(
  t_client *client);
void				throw_error_not_registered(
  t_client *client);
void				reply_rename_user(t_client *client,
						      char *oldname);

#endif /* !PSU_2016_MYIRC_SERVER_ENGINE_H */