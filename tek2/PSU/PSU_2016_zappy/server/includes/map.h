/*
** map.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/includes/map.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 21 10:18:53 2017 Antoine FORET
** Last update Wed Jun 21 10:18:53 2017 Antoine FORET
*/

#ifndef MAP_H_
# define MAP_H_

typedef		struct s_map			t_map;
typedef		enum e_cardinal			t_cardinal;
typedef		struct s_vector_orientation	t_vector_orientation;

enum		e_cardinal
{
  EC_NORTH = 1,
  EC_NORTH_EAST,
  EC_EAST,
  EC_SOUTH_EAST,
  EC_SOUTH,
  EC_SOUTH_WEST,
  EC_WEST,
  EC_NORTH_WEST,
  EC_NONE
};

# include	"config.h"
# include	"tile.h"

struct		s_vector_orientation
{
  double	start_angle;
  double	end_angle;
  t_cardinal	cardinal;
};

struct		s_map
{
  t_tile	**tiles;
  t_player_list	*players;
  size_t	width;
  size_t	height;

  void		(*convert)(t_map *self, t_position *position);

  bool		(*take)(t_map *self, t_position *position, t_ore ore);
  bool		(*drop)(t_map *self, t_position *position, t_ore ore);
  void		(*spawn_resources)(t_map *self, t_config *config, float rate);
  t_cardinal	(*direction)(t_map *self, t_position *from, t_position *to);

  t_tile	*(*get_tile_by_position)(t_map *self, t_position *position);
  t_tile	*(*get_tile_by_player)(t_map *self, t_player *player);

  bool		(*move)(t_map *self, t_player *player, t_position *target);
  bool		(*add_player)(t_map *self, t_player *player, t_egg *egg);
  bool		(*remove_player)(t_map *self, t_player *player);

  void		(*destroy)(t_map *self);
};

t_map		*new_map(size_t width, size_t height);
void		map_destroy(t_map *self);

void		map_convert(t_map *self, t_position *position);
bool		map_take(t_map *self, t_position *position, t_ore ore);
bool		map_drop(t_map *self, t_position *position, t_ore ore);
void		map_spawn_resources(t_map *self, t_config *config, float rate);
t_cardinal	map_direction(t_map *self, t_position *from, t_position *to);

t_tile		*map_get_tile_by_position(t_map *self, t_position *position);
t_tile		*map_get_tile_by_player(t_map *self, t_player *player);

bool		map_move(t_map *self, t_player *player, t_position *target);
bool		map_add_player(t_map *self, t_player *player, t_egg *egg);
bool		map_remove_player(t_map *self, t_player *player);

#endif /* !MAP_H_ */
