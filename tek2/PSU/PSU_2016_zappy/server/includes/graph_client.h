/*
** graphical_transmitter.h for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/includes/graphical_transmitter.h
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Mon Jun 26 15:57:05 2017 Montagne Valentin
** Last update Mon Jun 26 15:57:05 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_GRAPHICAL_TRANSMITTER_H
# define PSU_2016_ZAPPY_GRAPHICAL_TRANSMITTER_H

# define		MAXBUFFSIZE_MAPSIZE	(32)
# define		MAXBUFFSIZE_CELLCONTENT	(128)
# define		MAXBUFFSIZE_PLAYERSPAWN	(64)
# define		MAXBUFFSIZE_PLAYERPOS	(64)
# define		MAXBUFFSIZE_PLAYERLVL	(32)
# define		MAXBUFFSIZE_PLAYERINV	(128)
# define		MAXBUFFSIZE_PLAYEREND	(32)
# define		MAXBUFFSIZE_PLAYERBROAD	(32)
# define		MAXBUFFSIZE_PLAYERINC	(64)
# define		MAXBUFFSIZE_PLAYERINCND	(32)
# define		MAXBUFFSIZE_EGGSPAWN	(64)
# define		MAXBUFFSIZE_EGGOPEN	(32)
# define		MAXBUFFSIZE_PLAYERDEATH	(32)
# define		MAXBUFFSIZE_TIME	(32)
# define		MAXBUFFSIZE_ENDOFGAME	(512)
# define		MAXBUFFSIZE_BROADCAST	(512)
# define		MAXBUFFSIZE_DISCONNECT	(256)

typedef			struct s_graph_client		t_graph_client;
typedef			struct s_graph_client_list	t_graph_client_list;

# include 		<stdbool.h>
# include 		"tcp_socket.h"
# include 		"position.h"
# include 		"inventory.h"
# include		"egg.h"
# include		"circular_buffer.h"
# include		"map.h"

struct			s_graph_client_list
{
  t_list		*list;

  bool			(*apply)(t_graph_client_list *self,
				       t_list_action action, void *params);
  void			(*empty)(t_graph_client_list *self);

  void			(*pop)(t_graph_client_list *self,
				     t_graph_client *client);
  bool			(*push)(t_graph_client_list *self,
				      t_graph_client *client);

  bool			(*new_player)(t_graph_client_list *self,
					    t_player *player);

  void			(*destroy)(t_graph_client_list *self);
};

t_graph_client_list	*new_graph_client_list();
void			graph_client_list_destroy(t_graph_client_list *self);

bool			graph_client_list_apply(
  t_graph_client_list *self, t_list_action action, void *params);
void			graph_client_list_empty(t_graph_client_list *self);

void			graph_client_list_pop(t_graph_client_list *self,
						  t_graph_client *client);
bool			graph_client_list_push(t_graph_client_list *self,
						   t_graph_client *client);

bool			graph_client_list_new_player(
  t_graph_client_list *self, t_player *player);

struct			s_graph_client
{
  t_client		*client;
  t_circular_buffer	*input_buffer;
  t_circular_buffer	*output_buffer;

  bool			(*send_map_size)(t_graph_client *self,
					       unsigned int x,
					       unsigned int y);
  bool			(*send_cell_content)(t_graph_client *self,
						   t_position *position,
						   t_tile *cell);
  bool			(*send_player_spawn)(t_graph_client *self,
						   t_player *player);
  bool			(*send_player_position)(t_graph_client *self,
						      t_player *player);
  bool			(*send_player_lvl)(t_graph_client *self,
						 t_player *player);
  bool			(*send_player_inventory)(t_graph_client *self,
						       t_player *player);
  bool			(*send_player_end)(t_graph_client *self,
						 unsigned int id);
  bool			(*send_player_broadcast)(t_graph_client *self,
						       unsigned int id,
						       char *msg);
  bool			(*send_player_inc)(t_graph_client *self,
						 t_player *player);
  bool			(*send_player_end_inc)(t_graph_client *self,
						     t_position pos,
						     bool success);
  bool			(*send_player_death)(t_graph_client *self,
						   unsigned int id);
  bool			(*send_egg_spawn)(t_graph_client *self,
						t_egg *egg);
  bool			(*send_egg_open)(t_graph_client *self,
					       unsigned int egg_id);
  bool			(*send_time)(t_graph_client *self,
					   unsigned int time);
  bool			(*send_end_game)(t_graph_client *self,
					       char *team_name);
  bool			(*send_msg)(t_graph_client *self,
					  char *msg);
  bool			(*send_unknown)(t_graph_client *self);
  bool			(*send_map)(t_graph_client *self, t_map *map);
  bool			(*send_players_spawn)(t_graph_client *self,
						    t_player_list *players);
  bool			(*send_eggs_spawn)(t_graph_client *self,
						 t_team_list *teams);

  bool			(*send)(t_graph_client *self, const char *msg);
  bool			(*send_network)(t_graph_client *self);
  bool			(*need_write)(t_graph_client *self);

  void			(*destroy)(t_graph_client *self);
};

t_graph_client 		*new_graphical_transmitter(t_client *client);
void			graph_client_destroy(t_graph_client *self);

bool			send_map_size(t_graph_client *self,
					     unsigned int x,
					     unsigned int y);
bool			send_cell_content(t_graph_client *self,
					      t_position *position,
						 t_tile *cell);
bool			send_player_spawn(t_graph_client *self,
						 t_player *player);
bool			send_player_position(t_graph_client *self,
						    t_player *player);
bool			send_player_lvl(t_graph_client *self,
					       t_player *player);
bool			send_player_inventory(t_graph_client *self,
						     t_player *player);
bool			send_player_end(t_graph_client *self,
					       unsigned int id);
bool			send_player_broadcast(t_graph_client *self,
						     unsigned int id,
						     char *msg);
bool			send_player_inc(t_graph_client *self,
					       t_player *player);
bool			send_player_end_inc(t_graph_client *self,
						   t_position pos,
						   bool success);
bool			send_player_death(t_graph_client *self,
						 unsigned int id);
bool			send_egg_spawn(t_graph_client *self,
					      t_egg *egg);
bool			send_egg_open(t_graph_client *self,
					     unsigned int egg_id);
bool			send_time(t_graph_client *self,
					 unsigned int time);
bool			send_end_game(t_graph_client *self,
					     char *team_name);
bool			send_msg(t_graph_client *self,
					char *msg);
bool			send_unknown(t_graph_client *self);
bool			send_map(t_graph_client *self, t_map *map);
bool			send_players_spawn(t_graph_client *self,
					 t_player_list *players);
bool			send_eggs_spawn(t_graph_client *self,
					    t_team_list *team);

bool			graph_client_send(t_graph_client *self,
					      const char *msg);
bool			graph_client_send_network(t_graph_client *self);
bool			graph_client_need_write(t_graph_client *self);

#endif /* !PSU_2016_ZAPPY_GRAPHICAL_TRANSMITTER_H */
