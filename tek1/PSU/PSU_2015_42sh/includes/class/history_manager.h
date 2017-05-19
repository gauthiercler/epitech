/*
** history_manager.h for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/includes/class/history_manager.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 16:29:50 2016 Antoine FORET
** Last update Sat Jun 04 16:29:50 2016 Antoine FORET
*/

#ifndef HISTORY_MANAGER_H_
# define HISTORY_MANAGER_H_

typedef			struct s_history_manager t_history_manager;
typedef			struct s_history_option t_history_option;
typedef			struct s_history_replacer t_history_replacer;

# include		"class/history_entry.h"
# include		"class/env_manager.h"
# include		"class/parser.h"
# include		"bool.h"

void			history_manager_destructor(t_history_manager *self);
t_history_manager	*new_history_manager();
void			history_manager_display(t_history_manager *self,
						    int fd);
t_history_entry		*history_manager_get(t_history_manager *self,
						    unsigned int id);
t_bool			history_manager_insert(t_history_manager *self,
						     t_history_entry *entry);
t_bool			history_manager_add(t_history_manager *self,
						  char *command);
void			history_manager_clear(t_history_manager *self);
void			history_manager_sort_by(t_history_manager *self,
						    t_bool asc,
						    t_bool (*checker)
						      (t_history_entry *current,
						       t_history_entry *next,
						       t_bool asc));
t_bool			sort_by_time(t_history_entry *current,
					   t_history_entry *next,
					   t_bool asc);
t_bool			sort_by_id(t_history_entry *current,
					 t_history_entry *next,
					 t_bool asc);
void			history_manager_init_option(t_history_manager *self,
							t_env_manager *env);
void			history_manager_export(t_history_manager *self,
						   const char *path);
void			history_manager_import(t_history_manager *self,
						   const char *path);
void			history_manager_merge(t_history_manager *self,
						  const char *path);
t_history_entry		*history_manager_get_unique(t_history_manager *self,
							   time_t timestamp,
							   const char *command);
t_history_entry		*history_manager_get_from_start(t_history_manager *self,
							unsigned int offset);
t_history_entry		*history_manager_get_from_end(t_history_manager *self,
						      unsigned int offset);
char			**history_manager_run(t_history_manager *self,
						  t_parser *parser,
						  char **request);
t_bool			history_manager_replacer_run(t_history_replacer *self,
							   unsigned int index);
void			init_history_manager_replacer(t_history_replacer *self,
						      t_history_manager *,
						      t_parser *parser,
						      char **request);
void			history_replacer_set(t_history_replacer *self,
						 unsigned int target);
t_bool			history_manager_add_request(t_history_manager *self,
							  char **request);

struct			s_history_option
{
  t_bool		reverse;
  t_bool		clear;
  t_bool		simple;
  t_bool		export;
  t_bool		import;
  t_bool		merge;
  int			to_show;
  char			*file;
};

struct			s_history_replacer
{
  unsigned int		id;
  t_parser		*parser;
  t_history_manager	*manager;
  char			**request;
  t_bool		updated;
  t_bool		(*run)(t_history_replacer *self, unsigned int index);
  void			(*set)(t_history_replacer *self, unsigned int target);
};

struct			s_history_manager
{
  unsigned int		current_command;
  t_history_entry	**entries;
  unsigned int		size;
  t_history_option	options;
  t_history_replacer	replacer;
  void			(*destruct)(t_history_manager *self);
  void			(*display)(t_history_manager *self, int fd);
  t_history_entry	*(*get)(t_history_manager *self, unsigned int index);
  t_bool		(*insert)(t_history_manager *self,
				  t_history_entry *entry);
  t_bool		(*add)(t_history_manager *self, char *command);
  void			(*clear)(t_history_manager *self);
  void			(*init_options)(t_history_manager *self,
					      t_env_manager *env);
  void			(*export)(t_history_manager *self, const char *path);
  void			(*import)(t_history_manager *self, const char *path);
  void			(*merge)(t_history_manager *self, const char *path);
  t_history_entry	*(*get_unique)(t_history_manager *self,
					time_t timestamp, const char *command);
  t_history_entry	*(*get_form_start)(t_history_manager *self,
					    unsigned int offset);
  t_history_entry	*(*get_from_end)(t_history_manager *self,
					 unsigned int offset);
  void			(*sort)(t_history_manager *self, t_bool asc,
				      t_bool (*checker)
					(t_history_entry *current,
					 t_history_entry *next,
					 t_bool asc));
  char			**(*run)(t_history_manager *self,
				       t_parser *parser,
				       char **request);
  t_bool		(*add_request)(t_history_manager *self, char **request);
};

#endif /* !HISTORY_MANAGER_H_ */
