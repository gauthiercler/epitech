/*
** socket.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/common/socket.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 18:52:31 2017 Anas Buyumad
** Last update Mon May 29 18:52:32 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_COMMON_SOCKET_H
# define PSU_2016_MYIRC_COMMON_SOCKET_H

# include	"common/structures.h"

void		create_socket(t_socket *sock);
void		init_socket(t_socket *sock, uint16_t port, in_addr_t ip);
void		bind_socket(t_socket *sock);
void		listen_on_socket(t_socket *sock);
bool		connect_socket(t_socket *socket);

#endif /* !PSU_2016_MYIRC_SOCKET_H */