/*
** tile.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/includes/tile.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 14:40:41 2017 Antoine FORET
** Last update Thu Jun 22 14:40:41 2017 Antoine FORET
*/

#ifndef PSU_2016_ZAPPY_TILE_H_
# define PSU_2016_ZAPPY_TILE_H_

typedef		struct s_tile		t_tile;

# include	"player.h"
# include	"egg.h"

struct		s_tile
{
  t_player_list	*player_list;
  t_egg_list	*egg_list;
  t_inventory	*inventory;

  void		(*spawn)(t_tile *self, t_config *config, float rate);

  bool		(*add_player)(t_tile *self, t_player *player);
  bool		(*remove_player)(t_tile *self, t_player *player);
  size_t	(*nb_players)(t_tile *self);
  size_t	(*nb_players_at)(t_tile *self, unsigned int level);
  bool		(*is_player_on)(t_tile *self, t_player *player);

  bool		(*add_egg)(t_tile *self, t_egg *egg);
  bool		(*remove_egg)(t_tile *self, t_egg *egg);

  bool		(*add_ore)(t_tile *self, t_ore ore);
  bool		(*remove_ore)(t_tile *self, t_ore ore);
  char		*(*to_str)(t_tile *self);

  void		(*destroy)(t_tile *self);
};

t_tile		*new_tile();
void		tile_destroy(t_tile *self);

void		tile_spawn(t_tile *self, t_config *config, float rate);

bool		tile_add_player(t_tile *self, t_player *player);
bool		tile_remove_player(t_tile *self, t_player *player);
char		*tile_to_str(t_tile *self);
size_t		tile_nb_players(t_tile *self);
size_t		tile_nb_player_at(t_tile *self, unsigned int level);
bool		tile_is_player_on(t_tile *self, t_player *player);

bool		tile_add_egg(t_tile *self, t_egg *egg);
bool		tile_remove_egg(t_tile *self, t_egg *egg);

bool		tile_add_ore(t_tile *self, t_ore ore);
bool		tile_remove_ore(t_tile *self, t_ore ore);

#endif /* !PSU_2016_ZAPPY_TILE_H_ */
