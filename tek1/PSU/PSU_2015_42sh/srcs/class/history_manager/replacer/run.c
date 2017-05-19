/*
** run.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/replacer/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 18:29:28 2016 Antoine FORET
** Last update Sun Jun  5 20:51:26 2016 Gauthier Cler
*/

#include		<malloc.h>
#include		"libc.h"

/*
** Insert an entry into a command array
** @params request to update, parse, entry, index to insert
** @return new request updated
*/
static char		**insert_in_cmd(char **request, t_parser *parser,
					t_history_entry *entry,
					unsigned int index)
{
  char			**sub_array;
  char			**new_request;

  if ((sub_array = parser->explode(parser, entry->command)) == NULL)
    return (request);
  free(request[index]);
  new_request = merge_array(request, sub_array, index);
  if (new_request != NULL)
    free(request);
  else
    new_request = request;
  free(sub_array);
  return (new_request);
}

/*
** Run the replacement process.
** @params self, index to update
** @return success -> TRUE, failure -> FALSE
*/
t_bool			history_manager_replacer_run(t_history_replacer *self,
						     unsigned int index)
{
  t_history_entry	*entry;

  self->updated = FALSE;
  if ((entry = self->manager->get(self->manager, self->id)) == NULL)
    {
      dprintf(2, "%d: Event not found.\n", self->id);
      return (FALSE);
    }
  self->request = insert_in_cmd(self->request, self->parser, entry, index);
  return (TRUE);
}
