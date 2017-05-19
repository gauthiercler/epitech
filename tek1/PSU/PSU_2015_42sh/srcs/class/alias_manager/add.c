/*
** add.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/alias_manager/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Sun Jun  5 12:20:26 2016 Vincent Dusautoir
** Last update Sun Jun  5 19:35:13 2016 Vincent Dusautoir
*/

#include	<stdlib.h>
#include	"libc.h"
#include	"class/alias_manager.h"

/*
** Add an alias
** @params self, alias, cmd
** @return void
*/
void		alias_manager_add(t_alias_manager *self, char *alias,
				  char **cmd)
{
  t_alias_entry	*check;
  unsigned int	index;

  index = 0;
  if ((check = self->get(self, alias)) == NULL)
    self->entries = new_alias_entry(alias, cmd, &self->entries);
  else
    {
      while (check->command[index])
	free(check->command[index++]);
      free(check->command);
      check->command = array_dup(cmd);
    }
}
