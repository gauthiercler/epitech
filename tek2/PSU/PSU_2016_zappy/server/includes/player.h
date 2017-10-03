/*
** player.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/includes/player.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 14:00:28 2017 Antoine FORET
** Last update Thu Jun 22 14:00:28 2017 Antoine FORET
*/

#ifndef PLAYER_H_
# define PLAYER_H_

# define			MIN_LVL		(1)
# define			HUNGRY		(126)
# define			NB_DIRECTION	(4)

# include			<stdbool.h>

# define			PLAYER_RIGHT	(true)
# define			PLAYER_LEFT	(false)

typedef		struct s_player			t_player;
typedef		struct s_player_list 		t_player_list;
typedef		struct s_inventory_take_handler	t_inventory_take_handler;
typedef		struct s_inventory_drop_handler	t_inventory_drop_handler;
typedef		struct s_cardinal_liaison	t_cardinal_liaison;
typedef		enum e_player_direction		t_player_direction;
typedef		struct s_player_offset		t_player_offset;

# include			"inventory.h"
# include			"position.h"
# include			"list.h"
# include 			"team.h"
# include			"circular_buffer.h"
# include			"client.h"
# include			"command.h"
# include			"graph_client.h"
# include			"map.h"

typedef void			(*t_inventory_take)(t_inventory *self);
typedef bool			(*t_inventory_drop)(t_inventory *self);

struct				s_cardinal_liaison
{
  int				value;
  t_cardinal			cardinal;
};

struct				s_player_list
{
  t_list			*list;

  size_t			(*player_at_level)(t_player_list *self,
						      unsigned int level);
  size_t			(*size)(t_player_list *self);

  bool				(*push)(t_player_list *self,
					      t_player *player);
  bool				(*pop)(t_player_list *self,
					     t_player *player);
  bool				(*apply)(t_player_list *self,
					       t_list_action action,
					       void *params);
  void				(*empty)(t_player_list *self);
  void				(*destroy)(t_player_list *self);
};

t_player_list			*new_player_list();
void				player_list_destroy(t_player_list *self);

size_t				player_list_size(t_player_list *self);
size_t				player_list_nb_at_level
  				(t_player_list *self, unsigned int level);

bool				player_list_push(t_player_list *self,
						     t_player *player);
bool				player_list_pop(t_player_list *self,
						    t_player *player);
bool				player_list_apply(t_player_list *self,
						      t_list_action action,
						      void *params);
void				player_list_empty(t_player_list *self);

struct				s_inventory_take_handler
{
  t_ore				ore;
  t_inventory_take 		take;
};

struct				s_inventory_drop_handler
{
  t_ore				ore;
  t_inventory_drop 		drop;
};

enum				e_player_direction
{
  P_NORTH = 0,
  P_EAST,
  P_SOUTH,
  P_WEST,
};

struct				s_player_offset
{
  int				offset;
  t_player_direction		direction;
};

struct				s_player
{
  unsigned int			id;
  t_team			*team;
  unsigned int			level;
  float				hungry;
  t_inventory			*inventory;
  float				tick_stack;
  bool				dead;
  bool				change;

  t_command_list		*command_list;
  t_position			position;
  unsigned int 			direction;

  t_client			*socket;
  t_circular_buffer		*input_buffer;
  t_circular_buffer		*output_buffer;

  bool				(*tick)(t_player *self, float nb_tick);

  bool				(*take)(t_player *self, t_ore ore);
  bool				(*drop)(t_player *self, t_ore ore);

  void				(*move)(t_player *self,
					      unsigned int x, unsigned int y);
  void				(*level_up)(t_player *self,
						  t_graph_client_list *gfx);
  void				(*turn)(t_player *self, bool dir);
  int				(*get_cardinal)(t_player *self,
						     t_cardinal real);

  bool				(*need_write)(t_player *self);
  bool				(*send)(t_player *self, const char *message);
  bool				(*send_network)(t_player *self);

  void				(*disconnect)(t_player *self);

  void				(*destroy)(t_player *self);
};

t_player			*new_player(t_team *team,
					    unsigned int id,
					    t_position *pos,
					    t_client *socket);
void				player_delete(t_player *self);

bool				player_tick(t_player *self,
						float nb_tick);

void				player_turn(t_player *self, bool dir);

bool				player_take(t_player *self, t_ore ore);
bool				player_drop(t_player *self, t_ore ore);

void				player_move(t_player *self,
						unsigned int x,
						unsigned int y);
void				player_level_up(t_player *self,
						    t_graph_client_list *gfx);
int				player_get_cardinal(t_player *self,
						       t_cardinal real);

bool				player_need_write(t_player *self);
bool				player_send(t_player *self,
						const char *message);
bool				player_send_network(t_player *self);

void				player_disconnect(t_player *self);

#endif /* !PLAYER_H_ */
