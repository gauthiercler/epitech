/*
** insert.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/insert.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 19:37:54 2016 Antoine FORET
** Last update Sun Jun  5 20:53:16 2016 Gauthier Cler
*/

#include		<malloc.h>
#include		"config.h"
#include		"bool.h"
#include		"class/history_manager.h"

/*
** Insert an entry to the history manager
** @params self, entry to add
** @return success -> TRUE, failure -> FALSE
*/
t_bool			history_manager_insert(t_history_manager *self,
					       t_history_entry *entry)
{
  unsigned int		index;
  size_t		new_size;
  t_history_entry	**tmp;

  if (self->size % BLOCK_HISTORY == 0)
    {
      index = 0;
      new_size = (self->size / BLOCK_HISTORY + 1) * BLOCK_HISTORY  + 1;
      if ((tmp = malloc(sizeof(t_history_entry *) * new_size)) == NULL)
	return (FALSE);
      while (index < self->size)
	{
	  tmp[index] = self->entries[index];
	  index++;
	}
      if (self->entries != NULL)
	free(self->entries);
      self->entries = tmp;
    }
  self->entries[self->size] = entry;
  self->size++;
  self->current_command++;
  return (TRUE);
}
