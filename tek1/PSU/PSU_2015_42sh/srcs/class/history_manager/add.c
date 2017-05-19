/*
** add.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/add.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 19:45:46 2016 Antoine FORET
** Last update Sun Jun  5 20:51:39 2016 Gauthier Cler
*/

#include		<malloc.h>
#include		<string.h>
#include		"bool.h"
#include		"libc.h"
#include		"class/history_manager.h"

/*
** Add an entry based on its command
** @params self, command string
** @return success -> TRUE, failure -> FALSE
*/
t_bool			history_manager_add(t_history_manager *self,
					    char *command)
{
  t_history_entry	*entry;

  if (strcmp(purge(command), "") == 0)
    return (TRUE);
  if ((entry = new_history_entry(self->current_command, command)) == NULL)
    return (FALSE);
  return (self->insert(self, entry));
}

/*
** add an entry to current history stack based on its request
** @params self, request
** @return void
*/
t_bool			history_manager_add_request(t_history_manager *self,
						    char **request)
{
  char			*command;
  t_bool		result;

  if ((command = string_from_tab(request)) == NULL)
    return (FALSE);
  result = self->add(self, command);
  free(command);
  return (result);
}
