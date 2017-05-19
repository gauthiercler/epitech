/*
** history_entry.h for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/includes/class/history_entry.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 19:19:17 2016 Antoine FORET
** Last update Sat Jun 04 19:19:17 2016 Antoine FORET
*/

#ifndef HISTORY_ENTRY_H_
# define HISTORY_ENTRY_H_

typedef			struct s_history_entry t_history_entry;

# include		<time.h>
# include		"bool.h"

void			history_entry_destructor(t_history_entry *self);
void			history_entry_display(t_history_entry *self,
						  t_bool simple, int fd);
t_history_entry		*new_history_entry(unsigned int id,
						  const char *command);
void			history_entry_export(t_history_entry *self, int fd);

struct			s_history_entry
{
  int			id;
  time_t		timestamp;
  char			*command;
  void			(*destruct)(t_history_entry *self);
  void			(*export)(t_history_entry *self, int fd);
  void			(*display)(t_history_entry *self, t_bool simple,
				   int fd);
};

#endif /* !HISTORY_ENTRY_H_ */
