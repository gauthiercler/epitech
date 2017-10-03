/*
** lem_ipc.h for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/includes/lem_ipc.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 22 09:43:48 2017 Gauthier Cler
** Last update Wed Mar 22 09:43:48 2017 Gauthier Cler
*/

#ifndef PSU_2016_LEMIPC_LEM_IPC_H
# define PSU_2016_LEMIPC_LEM_IPC_H

# ifndef ARENA_SS
#  define ARENA_SS	(25)
# endif /* !ARENA_SS */

# ifndef ARENA_SIZE
#  define ARENA_SIZE	(ARENA_SS * ARENA_SS)
# endif /* !ARENA_SIZE */

# ifndef ORDER_SIZE
#  define ORDER_SIZE	(128)
# endif /* !ORDER_SIZE */

# ifndef MAX_PLAYERS
#  define MAX_PLAYERS	(200)
# endif /* !MAX_PLAYERS */

# ifndef ROUND_DELAY
#  define ROUND_DELAY	(70000)
# endif /* !ROUND_DELAY */

# ifndef FAILED_CALL
#  define FAILED_CALL	(-1)
# endif /* !FAILED_CALL */

# ifndef UNDEFINED
#  define UNDEFINED	(-1)
# endif /* !UNDEFINED */

# ifndef MAP_SEM_ID
#  define MAP_SEM_ID	("GateKeeper")
# endif /* !MAP_SEM_ID */

# ifndef FREE_CELL
#  define FREE_CELL	(' ')
# endif /* !MAP_SEM_ID */

# ifndef TOMB_CELL
#  define TOMB_CELL	('X')
# endif /* !TOMB_CELL */

# ifndef CT
#  define CT(x, y)	(y * ARENA_SS + x)
# endif /* !CT */

# ifndef BROADCAST
#  define BROADCAST	(1)
# endif /* !FAILED_CALL */

# ifndef END_BCAST
#  define END_BCAST	(2)
# endif /* !FAILED_CALL */

# ifndef CAPTAIN_DIES
#  define CAPTAIN_DIES	("The captain is dead !")
# endif /* !CAPTAIN_DIES */

# include		<unistd.h>
# include		<stdlib.h>
# include		<stdbool.h>
# include		<semaphore.h>
# include		<stdint.h>

typedef	struct s_ipc	t_ipc;
typedef struct s_memory	t_memory;
typedef struct s_player	t_player;
typedef struct s_pos	t_pos;
typedef struct s_order	t_order;
typedef struct s_team_s	t_team_s;
typedef enum s_dir	t_dir;

enum			s_dir
{
  LEFT,
  RIGHT,
  UP,
  DOWN,
  NONE
};

struct			s_ipc
{
  key_t			key;
  int			shmid;
  t_memory		*memory;
};

struct			s_memory
{
  int			winning_team;
  int			concurrent_players;
  char			arena[ARENA_SIZE];
};

struct			s_pos
{
  int			x;
  int			y;
};

struct			s_order
{
  long			order_type;
  char			order_content[ORDER_SIZE];
};

struct			s_team_s
{
  key_t			channel_key;
  int			channel;
  int			team_channel;
  bool			is_captain;
  t_order		order;
  t_pos			target;
};

struct			s_player
{
  t_pos			pos;
  int			team;
  bool			alive;
  bool			streamer;
  sem_t			*arena_handler;
  char			**arena_map;
  t_team_s		team_strat;
};

bool			custom_error(const char *error);
bool			display_error(const char *error);
bool			init_ipc(t_ipc *data, char *key, t_player *player);
bool			init_player(t_player *player, int team);
bool			parse_args(const char *string_team);
bool			lem_ipc(char *path_to_key, char *team);
bool			clean_ipc(t_ipc *ipc, t_player *player);
bool			insert_player_in_arena(char *arena, t_player *player);
bool			get_free_spot(char *arena, t_pos *pos);
bool			run_simulation(t_ipc *data, t_player *player);
bool			is_winner(char *arena, t_player *player);
bool			close_semaphore(t_player *player);
bool			is_alive(char *arena, t_player *player);
bool			move(char *arena, t_player *player, t_dir direction);
void			display_arena(char *arena);
bool			move_left(t_pos *pos, t_player *player);
bool			move_right(t_pos *pos, t_player *player);
bool			move_up(t_pos *pos, t_player *player);
bool			move_down(t_pos *pos, t_player *player);
bool			target(t_ipc *data, t_player *player,
				   t_pos *target_pos);
bool			attack(t_ipc *data, t_player *player,
				   t_pos *target_pos);
void			update_arena(char *source, char **dest);
bool			is_last_of_team(char *arena, t_player *player);
bool			close_channel(t_player *player);
void			startup_match(void);
bool			arena_is_empty(char *arena);
bool			exit_arena(t_ipc *data, t_player *player, bool won);
char			broadcast(t_ipc *data, t_player *player);
void			clean_cached_map(t_player *player);
void			clean_cached_map(t_player *player);
void			init_random();
uint64_t		xrand();
bool			emit_order(t_player *player, char *message);
bool			receive_order(t_player *player);
void			determine_target(char *arena, t_player *player);
bool			command(t_ipc *data, t_player *player);
bool			follow_command(t_ipc *data, t_player *player);
bool			check_prox_allies(char *arena, t_player *player,
					      int range);

#endif /* !PSU_2016_LEMIPC_LEM_IPC_H */