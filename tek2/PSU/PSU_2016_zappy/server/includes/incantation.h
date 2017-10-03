/*
** incantation.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/includes/incantation.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 14:34:06 2017 Antoine FORET
** Last update Thu Jun 22 14:34:06 2017 Antoine FORET
*/

#ifndef PSU_2016_ZAPPY_INCANTATION_H_
# define PSU_2016_ZAPPY_INCANTATION_H_

typedef			struct s_incantation		t_incantation;
typedef			struct s_incantation_needs	t_incantation_needs;

# include		<stdbool.h>
# include		"tile.h"

struct			s_incantation_needs
{
  unsigned int		level;
  unsigned int		player;
  unsigned int		linemate;
  unsigned int		deraumere;
  unsigned int		sibur;
  unsigned int		mendiane;
  unsigned int		phiras;
  unsigned int		thystame;
};

struct				s_incantation
{
  const t_incantation_needs	*needs;
  unsigned int			time_remaining;

  void				(*tick)(t_incantation *self,
					      unsigned int nb_ticks);

  bool				(*is_ended)(t_incantation *self);
  bool				(*validate)(t_incantation *self,
						  t_tile *tile);

  void				(*destroy)(t_incantation *self);
};

t_incantation			*new_incantation(unsigned int time,
						      unsigned int level);
void				incantation_destroy(t_incantation *self);

void				incantation_tick(t_incantation *self,
						     unsigned int nb_tick);

bool				incantation_is_ended(t_incantation *self);
bool				incantation_validate(t_incantation *self,
							 t_tile *tile);

#endif /* !PSU_2016_ZAPPY_INCANTATION_H_ */
