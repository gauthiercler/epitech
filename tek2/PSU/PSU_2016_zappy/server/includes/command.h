/*
** response.h for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/include/parser/response.h
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Fri Jun 23 14:36:31 2017 Montagne Valentin
** Last update Fri Jun 23 14:36:31 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_RESPONSE_H
# define PSU_2016_ZAPPY_RESPONSE_H

typedef			struct s_command		t_command;
typedef			struct s_command_list		t_command_list;

# include				<stdlib.h>
# include				<stdbool.h>
# include 				"list.h"
# include				"player.h"
# include				"server.h"
# include                                "command_type.h"

typedef bool				(*t_player_response)
  					(t_player *player, t_server *server);

struct					s_command
{
  t_command_type			type;
  size_t 				tick;
  void					*params;
  bool					has_data;
  bool					response_result;
  t_player_response 			response;

  void					(*fill)(t_command *self,
						      t_command_type type,
						      size_t tick,
						      t_player_response resp);
  void					(*add_data)(t_command *self,
							  void *params);
  void					(*exec)(t_command *self,
						      t_server *server,
						      t_player *player);
  void					(*destroy)(t_command *self);

};

t_command				*new_command();
void					destroy_command(
  						t_command *self);
void					command_fill(t_command *self,
						 t_command_type type,
						 size_t	tick,
						 t_player_response resp);
void					command_add_data(t_command *self,
							     void *data);
void					command_exec(t_command *self,
							 t_server *server,
							 t_player *player);

struct					s_command_list
{
  t_list				*list;

  size_t				(*size)(t_command_list *self);

  bool					(*push)(t_command_list *self,
					      t_command *data);
  bool					(*pop)(t_command_list *self,
					     t_command *data);
  bool					(*apply)(t_command_list *self,
					       t_list_action action,
					       void *params);
  void					(*empty)(t_command_list *self);
  t_command				*(*first)(t_command_list *self);
  void					(*destroy)(t_command_list *self);
};

t_command_list				*new_command_list();

size_t					command_list_size(
  						t_command_list *self);
bool					command_list_push(
  						t_command_list *self,
						t_command *data);
bool					command_list_pop(
  						t_command_list *self,
						t_command *data);
bool					command_list_apply(
  						t_command_list *self,
						t_list_action action,
						void *params);
void					command_list_empty(
  						t_command_list *self);
void					command_list_destroy(
  						t_command_list *self);

t_command				*command_list_first
  						(t_command_list *self);

#endif /* !PSU_2016_ZAPPY_RESPONSE_H */
