/*
** list.h for PSU_2016_zappy in /home/foret_a/Lab/PSU_2016_zappy/lib/cextended/includes/list.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 21 10:29:25 2017 Antoine FORET
** Last update Wed Jun 21 10:29:25 2017 Antoine FORET
*/

#ifndef LIST_H_
# define LIST_H_

# include	<stdbool.h>
# include	<stddef.h>

typedef		struct s_list		t_list;
typedef		struct s_list_node	t_list_node;
typedef		void			(*t_list_dump)(void *data);
typedef		bool			(*t_list_predicate)(
  void *data, void *comp);
typedef		bool			(*t_list_action)(
  void *data, void *params);

struct		s_list_node
{
  void		*data;
  t_list_node	*next;
};

struct		s_list
{
  t_list_node	*list;

  size_t	(*size)(t_list *self);
  void		(*dump)(t_list *self, t_list_dump handler);
  void		*(*search)(t_list *self, t_list_predicate predicate,
				 void *comp);
  bool		(*foreach)(t_list *self, t_list_action action,
				 void *params);

  void		*(*at)(t_list *self, unsigned int idx);
  void		*(*front)(t_list *self);
  void		*(*back)(t_list *self);

  bool		(*push_at)(t_list *self, void *data, unsigned int idx);
  bool		(*push_front)(t_list *self, void *data);
  bool		(*push_back)(t_list *self, void *data);

  bool		(*pop_at)(t_list *self, unsigned int idx);
  bool		(*pop_front)(t_list *self);
  bool		(*pop_back)(t_list *self);
  bool		(*pop_data)(t_list *self, void *data);

  void		(*destroy)(t_list *self);
};

t_list		*new_list();
void		list_destroy(t_list *self);

size_t		list_size(t_list *self);
void		list_dump(t_list *self, t_list_dump handler);
void		*list_search(t_list *self, t_list_predicate predicate,
				 void *comp);
bool		list_foreach(t_list *self, t_list_action action,
				 void *params);

void		*list_at(t_list *self, unsigned int idx);
void		*list_front(t_list *self);
void		*list_back(t_list *self);

bool		list_push_at(t_list *self, void *data, unsigned int idx);
bool		list_push_front(t_list *self, void *data);
bool		list_push_back(t_list *self, void *data);

bool		list_pop_at(t_list *self, unsigned int idx);
bool		list_pop_front(t_list *self);
bool		list_pop_back(t_list *self);
bool		list_pop_data(t_list *self, void *data);

#endif /* !LIST_H_ */
