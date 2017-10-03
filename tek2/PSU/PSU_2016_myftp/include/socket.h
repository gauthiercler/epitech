/*
** socket.h for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/include/socket.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun May 14 22:56:07 2017 Gauthier Cler
** Last update Sun May 14 22:56:07 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYFTP_SOCKET_H
# define PSU_2016_MYFTP_SOCKET_H

# include			<stdbool.h>
# include			"structures.h"

bool				create_socket(t_socket *sock, uint16_t port);
bool				accept_connection(t_client *client,
						      t_socket *sock);
bool				get_ip_address(t_socket *socket);
void				send_response(t_client *client,
						  enum e_action_state);
bool				handle_client(t_client *client,
						  t_server *server);
int				get_client_input(t_client *client);
void				close_previous_connection(t_client *client);
bool				activate_data_socket(t_client *client,
							 t_socket *sock);

#endif /* !PSU_2016_MYFTP_SOCKET_H */
