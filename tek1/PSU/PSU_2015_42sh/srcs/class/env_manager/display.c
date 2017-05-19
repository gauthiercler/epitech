/*
** display.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/env/display.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Thu May 19 14:47:23 2016 Antoine FORET
** Last update Sun Jun  5 19:26:43 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	"class/env_manager.h"

/*
** Output all entries from the env object
** @params self, FILE to output (~fd)
** @display all entries with format key=value
** @return void
*/
void		env_manager_display(t_env_manager *self, int fd)
{
  unsigned int	index;
  t_env_entry	*entry;

  index = 0;
  while (index < self->size)
    {
      if ((entry = self->get(self, index)) != NULL)
	dprintf(fd, "%s=%s\n", entry->key, entry->value);
      index++;
    }
}
