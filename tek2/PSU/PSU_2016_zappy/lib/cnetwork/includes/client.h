/*
** tcp_client.h for cpp_libs in /home/foret_a/Lab/cpp_libs/Network/C/includes/tcp_client.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Apr 27 09:10:18 2017 Antoine FORET
** Last update Thu Apr 27 09:10:18 2017 Antoine FORET
*/

#ifndef CPP_LIBS_CLIENT_H_
# define CPP_LIBS_CLIENT_H_

typedef		struct s_client		t_client;

# include	"tcp_socket.h"

struct		s_client
{
  t_tcp_socket	*socket;

  ssize_t	(*send)(t_client *self, void *data, size_t size,
			 bool blocking);
  ssize_t	(*receive)(t_client *self, void *data, size_t size,
			    bool blocking);

  ssize_t	(*receive_until)(t_client *self,
				  char **data,
				  const char *delimiter);

  const char	*(*get_ip)(t_client *self);
  uint16_t	(*get_port)(t_client *self);
  const char	*(*get_host_ip)(t_client *self);
  uint16_t	(*get_host_port)(t_client *self);

  bool		(*enable_keep_alive)(t_client *self);
  bool		(*disable_keep_alive)(t_client *self);
  bool		(*keep_alive_status)(t_client *self);

  void		(*disconnect)(t_client *self);
  bool		(*is_connected)(t_client *self);

  void		(*destroy)(t_client *self);
};

t_client	*new_tcp_client(SOCKET sock);
t_client	*new_tcp_client_connect(const char *ip, uint16_t port);
void		tcp_client_destroy(t_client *self);

ssize_t		tcp_client_send(t_client *self, void *data, size_t size,
				       bool blocking);
ssize_t		tcp_client_receive(t_client *self, void *data, size_t size,
					  bool blocking);

ssize_t		tcp_client_receive_until(t_client *self,
						char **data,
						const char *delimiter);

const char	*client_get_ip(t_client *self);
uint16_t	client_get_port(t_client *self);
const char	*client_get_host_ip(t_client *self);
uint16_t	client_get_host_port(t_client *self);
void		tcp_client_disconnect(t_client *self);
bool		tcp_client_is_connected(t_client *self);

bool		tcp_client_enable_keep_alive(t_client *self);
bool		tcp_client_disable_keep_alive(t_client *self);
bool		tcp_client_keep_alive_status(t_client *self);

#endif /* !CPP_LIBS_CLIENT_H_ */
