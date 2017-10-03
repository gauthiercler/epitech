/*
** server.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/includes/server.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 21 10:14:19 2017 Antoine FORET
** Last update Wed Jun 21 10:14:19 2017 Antoine FORET
*/

#ifndef PSU_2016_ZAPPY_SERVER_H_
# define PSU_2016_ZAPPY_SERVER_H_

# define		NB_DEFAULT_TEAMS		(4)

typedef			struct s_server			t_server;
typedef			struct s_player_cleanout	t_player_cleanout;
typedef			struct s_player_ref		t_player_ref;

# include		"tcp_socket.h"
# include		"socket_watcher.h"
# include		"map.h"
# include		"team.h"
# include		"player.h"
# include		"chrono.h"
# include		"egg.h"
# include		"parser.h"
# include		"config.h"
# include		"graph_client.h"

struct			s_player_ref
{
  t_player		*player;
  t_server		*server;
  unsigned int		pass_to;
};

struct			s_player_cleanout
{
  t_socket_watcher	*watcher;
  t_player_list		*list;
  t_graph_client_list	*gfx;
};

struct			s_server
{
  bool			running;
  t_config		config;
  float			tick_stack;

  t_tcp_socket		*socket_ai;
  t_tcp_socket		*socket_gfx;

  t_map			*map;
  t_chrono		*chrono;

  t_team_list		*teams;
  t_player_list		*players;
  t_player_list		*connection_queue;
  t_graph_client_list	*gfx;

  t_parser		*parser;
  t_socket_watcher	*watcher;

  bool			(*run)(t_server *server);
  bool			(*initialize)(t_server *self, int argc,
					    const char *argv[]);
  bool			(*generate_map)(t_server *self);
  bool			(*listen_ai)(t_server *self);
  bool			(*listen_gfx)(t_server *self);

  long			(*compute_timeout)(t_server *self);

  void			(*sync_gfx)(t_server *self);
  void			(*generate_tracking)(t_server *self);
  void			(*handle_network)(t_server *self);
  void			(*accept_clients)(t_server *self);
  void			(*receive_data)(t_server *self);
  void			(*send_data)(t_server *self);
  void			(*clean_players)(t_server *self);
  void			(*clean_gfx)(t_server *self);

  void			(*handle_connection_queue)(t_server *self);
  void			(*handle_players)(t_server *self);
  void			(*tick)(t_server *self);

  void			(*place_resources)(t_server *self, float rate);

   void			(*destroy)(t_server *self);
};

t_server		*new_server();
void			server_destroy(t_server *self);

void			server_place_resources(t_server *self, float rate);
void			server_sync_gfx(t_server *self);

bool			server_run(t_server *self);
bool			server_initialize(t_server *self,
					      int argc,
					      const char *argv[]);
bool			server_generate_map(t_server *self);
bool			server_listen_ai(t_server *self);
bool			server_listen_gfx(t_server *self);

long			server_compute_timeout(t_server *self);

void			server_handle_network(t_server *self);
void			server_generate_tracking(t_server *self);
void			server_accept_clients(t_server *self);
void			server_receive_data(t_server *self);
void			server_send_data(t_server *self);
void			server_clean_players(t_server *self);
void			server_clean_gfx(t_server *self);

void			server_handle_connection_queue(t_server *self);
void			server_handle_players(t_server *self);
void			server_tick(t_server *self);
void			from_egg(t_player *player, t_server *server,
				     t_team *team);

#endif /* !PSU_2016_ZAPPY_SERVER_H_ */
