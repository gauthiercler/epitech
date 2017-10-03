/*
** egg.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/includes/egg.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu Jun 22 15:28:00 2017 Antoine FORET
** Last update Thu Jun 22 15:28:07 2017 Antoine FORET
*/

#ifndef PSU_2016_ZAPPY_T_EGG_H_
# define PSU_2016_ZAPPY_T_EGG_H_

typedef		struct s_egg		t_egg;
typedef		struct s_egg_list	t_egg_list;

# include	<list.h>
# include	"position.h"
# include	"team.h"
# include	"config.h"

struct		s_egg_list
{
  t_list	*list;

  size_t	(*size)(t_egg_list *self);
  void		(*dump)(t_egg_list *self);

  t_egg		*(*first)(t_egg_list *self);

  bool		(*push)(t_egg_list *self, t_egg *egg);
  bool		(*pop)(t_egg_list *self);
  bool		(*pop_egg)(t_egg_list *self, t_egg *egg);
  bool		(*apply)(t_egg_list *self,
			       t_list_action action, void *params);
  void		(*empty)(t_egg_list *self);

  void		(*destroy)(t_egg_list *self);
};

t_egg_list	*new_egg_list();
void		egg_list_destroy(t_egg_list *self);

size_t		egg_list_size(t_egg_list *self);
void		egg_list_dump(t_egg_list *self);

t_egg		*egg_list_front(t_egg_list *self);

bool		egg_list_push(t_egg_list *self, t_egg *egg);
bool		egg_list_pop(t_egg_list *self);
bool		egg_list_pop_egg(t_egg_list *self, t_egg *egg);
bool		egg_list_apply(t_egg_list *self, t_list_action action,
				   void *params);
void		egg_list_empty(t_egg_list *self);

struct		s_egg
{
  unsigned int	id;
  t_position	position;
  t_team	*team;

  float		time_hatching;

  void		(*tick)(t_egg *self, float nb_ticks);

  bool		(*is_hatched)(t_egg *self);

  void		(*destroy)(t_egg *self);
};

t_egg		*new_egg(t_config *config, const t_position *position, t_team *team);
void		egg_destroy(t_egg *self);

void		egg_tick(t_egg *self, float nb_ticks);

bool		egg_is_hatched(t_egg *self);

#endif /* !PSU_2016_ZAPPY_T_EGG_H_ */
