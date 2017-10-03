/*
** client_manager.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/server/client_manager.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sun May 28 01:56:45 2017 Anas Buyumad
** Last update Sun May 28 01:56:45 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_SERVER_CLIENT_MANAGER_H
# define PSU_2016_MYIRC_SERVER_CLIENT_MANAGER_H

# define NO_CLIENT	(-1)

# include		"server/structures.h"

t_client		*get_client_by_id(t_client_mgr *manager,
					  int16_t client_id);
t_client		*get_client_by_name(t_client_mgr *manager,
					    const char *name);
bool			is_connected_to_channel(t_client *client,
						    int8_t channel_id);
size_t			get_nb_connected_clients(t_client_mgr *manager);
bool			rename_client(t_client_mgr *manager,
					  t_client *client,
					  const char *new_name);
bool			add_channel_to_client(t_client *client,
						  int8_t channel_id);
bool			remove_channel_of_client(t_client *client,
						     int8_t channel_id);
bool			add_client(t_client_mgr *manager, t_socket *socket);
bool			remove_client_by_name(t_client_mgr *manager,
						  char *name);
bool			remove_client_by_id(t_client_mgr *manager,
						int16_t client_id);
int16_t			get_max_client_id(t_client_mgr *manager);
int16_t			get_available_client_id(t_client_mgr *manager);
void			flush_disconnected_clients(t_server *server);
void			flush_client_from_channels(t_server *server,
					       t_client *client);
void			flush_clients_buffers(t_cmd_buffer *buffer,
						  t_client_mgr *manager);
void			dump_client(t_client *client);
uint16_t		get_nb_connected_on_channel(t_client_mgr *manager,
					    int8_t channel_id);

#endif /* !PSU_2016_MYIRC_SERVER_CLIENT_MANAGER_H */