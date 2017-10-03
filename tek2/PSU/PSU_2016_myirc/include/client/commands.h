/*
** commands.h for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/include/client/commands.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 30 18:49:28 2017 Gauthier Cler
** Last update Tue May 30 18:49:28 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYIRC_COMMANDS_H
# define PSU_2016_MYIRC_COMMANDS_H

# include		"structures.h"

void			accept_file(t_client *client);
void			change_nickname(t_client *client);
void			channel_message(t_client *client);
void			connect_to_server(t_client *client);
void			join_channel(t_client *client);
void			leave_channel(t_client *client);
void			list_channel_users(t_client *client);
void			list_channels(t_client *client);
void			list_users(t_client *client);
void			private_message(t_client *client);
void			send_file(t_client *client);
enum e_cmd_type		assess_command(const char *command);
void			execute_command(t_client *client);
void			broadcast_message(t_client *client);
void			not_connected_message();

#endif /* !PSU_2016_MYIRC_COMMANDS_H */