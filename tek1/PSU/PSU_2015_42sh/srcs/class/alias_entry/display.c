/*
** display.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/alias_entry/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 12:36:57 2016 Vincent Dusautoir
** Last update Sun Jun  5 17:18:00 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"libc.h"

/*
** Display an alias
** @params self, alias, fd
** @return void
*/
void		alias_entry_display(t_alias_entry *self, t_bool alias,
				    int fd)
{
  unsigned int	index;

  index = 0;
  if (alias == TRUE)
    dprintf(fd, "%s\t", self->alias);
  if (alias == TRUE && count(self->command) > 1)
    dprintf(fd, "(");
  while (self->command[index])
    {
      dprintf(fd, "%s", self->command[index]);
      index++;
      if (self->command[index] != NULL)
      dprintf(fd, " ");
    }
  if (alias == TRUE && count(self->command) > 1)
    dprintf(fd, ")");
  dprintf(fd, "\n");
}
