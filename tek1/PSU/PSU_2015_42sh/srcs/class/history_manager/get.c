/*
** get.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/get.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 19:41:29 2016 Antoine FORET
** Last update Sun Jun  5 20:52:41 2016 Gauthier Cler
*/

#include		<string.h>
#include		"class/history_manager.h"

/*
** Get an entry based on it's id
** @params history manager, wanted id
** @return success -> pointer to entry, failure -> NULL
*/
t_history_entry		*history_manager_get(t_history_manager *self,
					     unsigned int id)
{
  unsigned int		index;

  index = 0;
  while (index < self->size)
    {
      if ((unsigned int)self->entries[index]->id == id)
	return (self->entries[index]);
      index++;
    }
  return (NULL);
}

/*
** check if an entry is already created
** @params self, timestamp, command
** @return success -> TRUE, failure -> FALSE
*/
t_history_entry		*history_manager_get_unique(t_history_manager *self,
						    time_t timestamp,
						    const char *command)
{
  unsigned int		index;
  t_history_entry	*entry;

  index = 0;
  while (index < self->size)
    {
      entry = self->entries[index];
    if (entry->timestamp == timestamp && strcmp(entry->command, command) == 0)
	return (entry);
      index++;
    }
  return (NULL);
}
