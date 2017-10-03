/*
** inventory.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/includes/inventory.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 14:19:42 2017 Antoine FORET
** Last update Thu Jun 22 14:19:42 2017 Antoine FORET
*/

#ifndef PSU_2016_ZAPPY_INVENTORY_H_
# define PSU_2016_ZAPPY_INVENTORY_H_

# define		INVENTORY_SIZE		(7)
# define		PLAYER_STR		("player")
# define		EGG_STR			("egg")
# define		FOOD_STR		("food")
# define		LINEMATE_STR		("linemate")
# define		DERAUMERE_STR		("deraumere")
# define		SIBUR_STR		("sibur")
# define		MENDIANE_STR		("mendiane")
# define		PHIRAS_STR		("phiras")
# define		THYSTAME_STR		("thystame")

typedef			struct s_inventory	t_inventory;
typedef			enum e_ore		t_ore;

# include		<stdbool.h>

enum			e_ore
{
  EO_FOOD = 0 ,
  EO_LINEMATE = 1,
  EO_DERAUMERE = 2,
  EO_SIBUR = 3,
  EO_MENDIANE = 4,
  EO_PHIRAS = 5,
  EO_THYSTAME = 6
};

struct			s_inventory
{
  unsigned int		food;
  unsigned int		linemate;
  unsigned int		deraumere;
  unsigned int		sibur;
  unsigned int		mendiane;
  unsigned int		phiras;
  unsigned int		thystame;

  void			(*take_food)(t_inventory *self);
  bool			(*drop_food)(t_inventory *self);

  void			(*take_linemate)(t_inventory *self);
  bool			(*drop_linemate)(t_inventory *self);

  void			(*take_deraumere)(t_inventory *self);
  bool			(*drop_deraumere)(t_inventory *self);

  void			(*take_sibur)(t_inventory *self);
  bool			(*drop_sibur)(t_inventory *self);

  void			(*take_mendiane)(t_inventory *self);
  bool			(*drop_mendiane)(t_inventory *self);

  void			(*take_phiras)(t_inventory *self);
  bool			(*drop_phiras)(t_inventory *self);

  void			(*take_thystame)(t_inventory *self);
  bool			(*drop_thystame)(t_inventory *self);

  void			(*destroy)(t_inventory *self);
};

t_inventory		*new_inventory();
void			inventory_destroy(t_inventory *self);

void			inventory_take_food(t_inventory *self);
bool			inventory_drop_food(t_inventory *self);
void			inventory_take_linemate(t_inventory *self);
bool			inventory_drop_linemate(t_inventory *self);
void			inventory_take_deraumere(t_inventory *self);
bool			inventory_drop_deraumere(t_inventory *self);
void			inventory_take_sibur(t_inventory *self);
bool			inventory_drop_sibur(t_inventory *self);
void			inventory_take_mendiane(t_inventory *self);
bool			inventory_drop_mendiane(t_inventory *self);
void			inventory_take_phiras(t_inventory *self);
bool			inventory_drop_phiras(t_inventory *self);
void			inventory_take_thystame(t_inventory *self);
bool			inventory_drop_thystame(t_inventory *self);

#endif /* !PSU_2016_ZAPPY_INVENTORY_H_ */
