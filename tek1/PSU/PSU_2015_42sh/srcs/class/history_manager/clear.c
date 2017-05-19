/*
** clear.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/clear.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 21:46:34 2016 Antoine FORET
** Last update Sun Jun  5 20:51:48 2016 Gauthier Cler
*/

#include		<malloc.h>
#include		"class/history_manager.h"

/*
** Free memory used by history entries
** @params self
** @return void
*/
static void		history_destruct_entries(t_history_manager *self)
{
  unsigned int		index;
  t_history_entry	*entry;

  index = 0;
  while (index < self->size)
    {
      if ((entry = self->entries[index]) != NULL)
	entry->destruct(entry);
      index++;
    }
  free(self->entries);
}

/*
** Clean current history buffer
** @params self
** @return void
*/
void			history_manager_clear(t_history_manager *self)
{
  if (self->entries != NULL)
    history_destruct_entries(self);
  self->entries = NULL;
  self->size = 0;
}
