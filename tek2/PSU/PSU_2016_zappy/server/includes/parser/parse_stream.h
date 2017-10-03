/*
** parse_stream.h for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/include/parser/parse_stream.h
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 23 15:02:34 2017 Montagne Valentin
** Last update Fri Jun 23 15:02:34 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_PARSE_STREAM_H
# define PSU_2016_ZAPPY_PARSE_STREAM_H

# define			NOTICK		(1)
# define			SHORT_TICK	(7)
# define			LIFE_TICK	(42)
# define			INC_TICK	(300)
# define			INC_OBJECTS	(7)
# define			INC_LVL_MAX	(7)

typedef				enum e_inc_objects	t_inc_objects;
typedef				struct s_dictio		t_dictio;

# include                        "parser.h"

typedef t_error			(*dicofct)(char *stream, t_command *r);

enum 				e_inc_objects
{
  I_PLAYERS = 0,
  I_LINEMATE,
  I_DERAUMERE,
  I_SIBUR,
  I_MENDIANE,
  I_PHIRAS,
  I_THYSTAME
};

struct				s_dictio
{
  t_command_type 		type;
  char 				*token;
  size_t 			tick;
  dicofct 			fct;
  t_player_response 		resp;
};

t_error				parse_ai(char *stream, t_command *r);
t_error				parse_broadcast(char *stream,
						       t_command *r);
t_error				parse_take(char *stream,
						  t_command *r);
t_error				parse_drop(char *stream,
						  t_command *r);

bool				response_forward(t_player *player,
						     t_server *server);
bool				response_right(t_player *player,
						     t_server *server);
bool				response_left(t_player *player,
						     t_server *server);
bool				response_look(t_player *player,
						     t_server *server);
bool				response_inventory(t_player *player,
						     t_server *server);
bool				response_broadcast(t_player *player,
						     t_server *server);
bool				response_connect_nbr(t_player *player,
						     t_server *server);
bool				response_fork(t_player *player,
						     t_server *server);
bool				response_eject(t_player *player,
						  t_server *server);
bool				response_take(t_player *player,
						  t_server *server);
bool				response_drop(t_player *player,
						  t_server *server);
bool				response_inc_begin(t_player *player,
						  t_server *server);
bool				response_inc_end(t_player *player,
						     t_server *server);
bool				response_unknown(t_player *player,
						     t_server *server);
bool				check_level(t_player *player,
						unsigned int *data);

t_error				parse_graphical(char *stream, t_command *r);

#endif /* !PSU_2016_ZAPPY_PARSE_STREAM_H */
