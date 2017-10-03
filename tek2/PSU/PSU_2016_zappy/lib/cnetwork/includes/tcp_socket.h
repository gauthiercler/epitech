/*
** tcp_socket.h for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/includes/tcp_socket.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 08:22:05 2017 Antoine FORET
** Last update Thu Apr 27 08:22:05 2017 Antoine FORET
*/

#ifndef CPP_LIBS_TCP_SOCKET_H_
# define CPP_LIBS_TCP_SOCKET_H_

typedef		struct s_tcp_socket	t_tcp_socket;

# include	<stdint.h>
# include	<stdbool.h>
# include	<stddef.h>
# include	"portability.h"
# include	"client.h"

struct		s_tcp_socket
{
  SOCKET	socket;
  char		*buffer;
  bool		connected;

  bool		(*connect)(t_tcp_socket *self,
				 const char *hostname,
				 uint16_t port);
  ssize_t	(*send)(t_tcp_socket *self, void *data, size_t size,
			 bool blocking);
  ssize_t	(*receive)(t_tcp_socket *self, void *data, size_t size,
			    bool blocking);

  ssize_t	(*receive_until)(t_tcp_socket *self,
				  char **data,
				  const char *delimiter);

  bool		(*bind)(t_tcp_socket *self, uint16_t port);
  bool		(*listen)(t_tcp_socket *self, int max_client);
  t_client	*(*accept)(t_tcp_socket *self);
  void		(*disconnect)(t_tcp_socket *self);

  char		*(*get_ip)(t_tcp_socket *self);
  uint16_t	(*get_port)(t_tcp_socket *self);
  char		*(*get_foreign_ip)(t_tcp_socket *self);
  uint16_t	(*get_foreign_port)(t_tcp_socket *self);
  bool		(*is_connected)(t_tcp_socket *self);

  bool		(*enable_keep_alive)(t_tcp_socket *self);
  bool		(*disable_keep_alive)(t_tcp_socket *self);
  bool		(*keep_alive_status)(t_tcp_socket *self);

  void		(*destroy)(t_tcp_socket *self);
};

t_tcp_socket	*new_tcp_socket();
t_tcp_socket	*new_tcp_socket_explicit(SOCKET sock);
void		tcp_socket_destroy(t_tcp_socket *self);

bool		tcp_socket_connect(t_tcp_socket *self,
				       const char *hostname,
				       uint16_t port);
ssize_t		tcp_socket_send(t_tcp_socket *self, void *data, size_t size,
				       bool blocking);
ssize_t		tcp_socket_receive(t_tcp_socket *self,
					  void *data,
					  size_t size, bool blocking);
ssize_t		tcp_socket_receive_until(t_tcp_socket *self,
						char **data,
						const char *delimiter);

bool		tcp_socket_bind(t_tcp_socket *self, uint16_t port);
bool		tcp_socket_listen(t_tcp_socket *self, int max_client);
t_client	*tcp_socket_accept(t_tcp_socket *self);
void		tcp_socket_disconnect(t_tcp_socket *self);

char		*tcp_socket_get_ip(t_tcp_socket *self);
uint16_t	tcp_socket_get_port(t_tcp_socket *self);
char		*tcp_socket_get_foreign_ip(t_tcp_socket *self);
uint16_t	tcp_socket_get_foreign_port(t_tcp_socket *self);
bool		tcp_socket_is_connected(t_tcp_socket *self);

bool		tcp_socket_enable_keep_alive(t_tcp_socket *self);
bool		tcp_socket_disable_keep_alive(t_tcp_socket *self);
bool		tcp_socket_keep_alive_status(t_tcp_socket *self);

#endif /* !CPP_LIBS_TCP_SOCKET_H_ */
