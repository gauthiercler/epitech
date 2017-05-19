/*
** run.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 17:19:12 2016 Antoine FORET
** Last update Sun Jun  5 21:27:25 2016 Gauthier Cler
*/

#include		<string.h>
#include		<malloc.h>
#include		"libc.h"

/*
** Check if a string is a !! (first back history)
** @params string to test
** @return success -> TRUE, faillure -> FALSE
*/
static t_bool		is_first_back(char *elem)
{
  if (strcmp(elem, "!!") == 0)
    return (TRUE);
  else
    return (FALSE);
}

/*
** Check if a string is a !-x (x back history)
** @params string to test
** @return success -> TRUE, faillure -> FALSE
*/
static t_bool		is_number_back(char *elem)
{
  if (elem[0] == '!' && is_numeric(&elem[1]) && get_number(&elem[1]) <  0)
    return (TRUE);
  else
    return (FALSE);
}

/*
** Check if a string is a !x (x history)
** @params string to test
** @return success -> TRUE, faillure -> FALSE
*/
static t_bool		is_number_front(char *elem)
{
  if (elem[0] == '!' && is_numeric(&elem[1]) && get_number(&elem[1]) >=  0)
    return (TRUE);
  else
    return (FALSE);
}

/*
** Replace all !! !-x !x by there values
** @params self, parser, request
** @return treated request
*/
char 			**history_manager_run(t_history_manager *self,
					      t_parser *parser,
					      char **request)
{
  unsigned int		index;

  index = 0;
  init_history_manager_replacer(&self->replacer, self, parser, request);
  while (self->replacer.request != NULL &&
	 self->replacer.request[index] != NULL)
    {
      self->replacer.id = 0;
      if (is_first_back(self->replacer.request[index]))
	self->replacer.set(&self->replacer, self->current_command - 1);
      else if (is_number_back(self->replacer.request[index]))
	self->replacer.set(&self->replacer, self->current_command +
			   get_number(&self->replacer.request[index][1]));
      else if (is_number_front(self->replacer.request[index]))
	self->replacer.set(&self->replacer, self->current_command
			   - self->size + get_number(&self->replacer.
						  request[index][1]) - 1);
      if (self->replacer.updated && !self->replacer.run(&self->replacer, index))
	{
	  destroy_array(self->replacer.request);
	  return (NULL);
	}
      index++;
    }
  return (self->replacer.request);
}
