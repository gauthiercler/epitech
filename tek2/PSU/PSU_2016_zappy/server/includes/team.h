/*
** team.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/server/includes/team.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 21 10:22:35 2017 Antoine FORET
** Last update Wed Jun 21 10:22:35 2017 Antoine FORET
*/

#ifndef TEAM_H_
# define TEAM_H_

typedef		struct s_team		t_team;
typedef		struct s_team_list	t_team_list;

# include	<stddef.h>
# include	"player.h"
# include	"egg.h"
# include	"config.h"

struct		s_team_list
{
  t_list	*list;

  size_t	(*nb_team)(t_team_list *self);

  bool		(*add_team)(t_team_list *self, t_team *team);
  bool		(*remove_team)(t_team_list *self, t_team *team);
  bool		(*apply)(t_team_list *self, t_list_action action,
			       void *params);
  void		(*empty)(t_team_list *self);
  t_team	*(*get_team)(t_team_list *self, const char *name);

  void		(*dump)(t_team_list *self);

  void		(*destroy)(t_team_list *self);
};

t_team_list	*new_team_list();
void		team_list_destroy(t_team_list *self);

bool		team_list_apply(t_team_list *self, t_list_action action,
				    void *params);
bool		team_list_add_team(t_team_list *self, t_team *team);
bool		team_list_remove_team(t_team_list *self, t_team *team);
void		team_list_empty(t_team_list *self);
t_team		*team_list_get_team(t_team_list *self, const char *name);

void		team_list_dump(t_team_list *self);

struct		s_team
{
  char		*name;
  t_player_list	*players;
  t_egg_list	*eggs;
  unsigned int	slots;

  size_t	(*nb_at_level)(t_team *self, unsigned int level);
  const char	*(*get_name)(t_team *self);

  bool		(*add_player)(t_team *self, t_player *player);
  bool		(*remove_player)(t_team *self, t_player *player);

  size_t	(*nb_eggs)(t_team *self);
  t_egg		*(*first_egg)(t_team *self);
  bool		(*push_egg)(t_team *self, t_position *position,
				  t_config *config);
  void		(*pop_egg)(t_team *self);

  size_t	(*place_available)(t_team *self, size_t vanilla_space);

  void		(*destroy)(t_team *self);
};

t_team		*new_team(const char *name);
void		team_destroy(t_team *self);

size_t		team_nb_at_level(t_team *self, unsigned int level);
const char	*team_get_name(t_team *self);

bool		team_add_player(t_team *self, t_player *player);
bool		team_remove_player(t_team *self, t_player *player);

size_t		team_place_available(t_team *self, size_t vanilla_space);

size_t		team_nb_eggs(t_team *self);
t_egg		*team_first_egg(t_team *self);
bool		team_push_egg(t_team *self, t_position *position,
				  t_config *config);
void		team_pop_egg(t_team *self);

#endif /* !TEAM_H_ */
