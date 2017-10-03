/*
** socket_watcher.h for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cnetwork/includes/socket_watcher.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Tue May 23 09:53:26 2017 Antoine FORET
** Last update Tue May 23 09:53:26 2017 Antoine FORET
*/

#ifndef SOCKET_WATCHER_H_
# define SOCKET_WATCHER_H_

# include		"tcp_socket.h"
# include		"client.h"

# define		TRACK_READ			(1 << 0)
# define		TRACK_WRITE			(1 << 1)

typedef			struct s_socket_watcher		t_socket_watcher;
typedef			struct s_socket_tracked		t_socket_tracked;
typedef			struct s_socket_resolver	t_socket_resolver;

enum			e_socket_type
{
  ST_TCP,
  ST_CLIENT
};

enum			e_socket_action
{
  SA_READ,
  SA_WRITE
};

struct			s_socket_resolver
{
  enum e_socket_type	type;
  SOCKET		(*converter)(void *);
};

struct			s_socket_tracked
{
  void			*socket;
  enum e_socket_type	type;
  int			action;
  SOCKET		real_socket;
  t_socket_tracked	*next;
};

struct			s_socket_watcher
{
  t_socket_tracked	*tracked_sockets;
  fd_set		write_fds;
  fd_set		read_fds;

  bool			(*track)(t_socket_watcher *self,
				       void *socket,
				       enum e_socket_type type,
				       int domain);
  void			(*untrack)(t_socket_watcher *self, void *socket);
  void			(*untrack_all)(t_socket_watcher *self);

  bool			(*wait)(struct s_socket_watcher *self, long timeout);

  bool			(*can_read)(t_socket_watcher *self, void *socket);
  bool			(*can_write)(t_socket_watcher *self, void *socket);

  SOCKET		(*get_record_socket)(t_socket_watcher *self,
					     t_socket_tracked *record);
  t_socket_tracked	*(*get_record)(t_socket_watcher *self, void *socket);

  void			(*generate_tracking)(t_socket_watcher *self);
  void			(*clear_tracking)(t_socket_watcher *self);

  void			(*destroy)(t_socket_watcher *self);
};

t_socket_watcher	*new_socket_watcher();
void			socket_watcher_destroy(t_socket_watcher *self);

bool			socket_watcher_track(t_socket_watcher *self,
						 void *socket,
						 enum e_socket_type type,
						 int domain);
void			socket_watcher_untrack(t_socket_watcher *self,
						   void *socket);
void			socket_watcher_untrack_all(t_socket_watcher *self);

bool			socket_watcher_wait(t_socket_watcher *self,
						long timeout);

bool			socket_watcher_can_read(t_socket_watcher *self,
						    void *socket);
bool			socket_watcher_can_write(t_socket_watcher *self,
						     void *socket);

SOCKET			socket_watcher_get_record_socket(
  t_socket_watcher *self,
  t_socket_tracked *record);
t_socket_tracked	*socket_watcher_get_record(t_socket_watcher *self,
						   void *socket);

void			socket_watcher_generate_tracking(
  t_socket_watcher *self);
void			socket_watcher_clear_tracking(t_socket_watcher *self);

#endif /* !SOCKET_WATCHER_H_ */
