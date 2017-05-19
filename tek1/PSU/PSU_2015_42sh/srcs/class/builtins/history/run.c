/*
** run.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/builtins/history/run.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 20:19:42 2016 Antoine FORET
** Last update Sun Jun  5 20:50:47 2016 Gauthier Cler
*/

#include		<string.h>
#include		<stdlib.h>
#include		"libc.h"
#include		"class/history.h"

/*
** Check if to check only contain authorized chars
** @params o check string, list of authorized chars
** @return success -> TRUE, failure -> FALSE
*/
static t_bool		authorized_chars(const char *to_check, char *authorized)
{
  unsigned int		index;

  index = 0;
  while (to_check[index] != '\0')
    {
      if (!in_string(to_check[index], authorized))
	return (FALSE);
      index++;
    }
  return (TRUE);
}

/*
** Parse a parameter to update enabled options
** @params self, param
** @return success -> TRUE, failure -> FALSE
*/
static t_bool		history_parse_param(t_history_manager *self,
					    char *param)
{
  if (self->options.merge || self->options.export || self->options.import)
    {
      if (self->options.file != NULL)
	free(self->options.file);
      self->options.file = strdup(param);
    }
  else if (is_numeric(param) && get_number(param) >= 0)
    {
      if (self->options.to_show != -1)
	return (FALSE);
      self->options.to_show = get_number(param);
    }
  else if (param[0] == '-' && authorized_chars(&param[1], "chrSLMT"))
    {
      self->options.clear = in_string('c', param);
      self->options.reverse = in_string('r', param);
      self->options.simple = in_string('h', param);
      self->options.export = in_string('S', param);
      self->options.import = in_string('L', param);
      self->options.merge = in_string('M', param);
    }
  else
    return (TRUE);
  return (FALSE);
}

/*
** Gather options on activate them based on parameters
** @params self, env manager request
** @return success -> TRUE, failure -> FALSE
*/
static t_bool		get_options(t_history_manager *self, t_env_manager *env,
				    char **request)
{
  t_bool		error;

  self->init_options(self, env);
  if (count(request) > 3)
    {
      dprintf(2, "history: Too many arguments.\n");
      return (FALSE);
    }
  error = FALSE;
  if (request[1] != NULL)
    {
      error = history_parse_param(self, request[1]);
      if (request[2] != NULL && !error)
	error = history_parse_param(self, request[2]);
    }
  if (error)
    dprintf(2, "Usage: history [-chrSLMT] [# number of events].\n");
  return (error);
}

/*
** Run the history bultin (gather options and run them)
** @params self, request, shell, io to use
** @return exit status
*/
int			history_run(t_builtin_base *builtin, char **request,
				       t_shell *shell, t_io *io)
{
  char			*file;
  t_history_manager	*self;

  self = shell->history_manager;
  if (get_options(shell->history_manager, shell->env, request))
    return (BUILTIN_ERROR);
  file = shell->history_manager->options.file;
  if (self->options.clear)
    self->clear(self);
  if (self->options.merge)
    self->merge(self, file);
  else if (self->options.import)
    self->import(self, file);
  if (self->options.export)
    self->export(self, file);
  else if (!self->options.import && !self->options.merge)
    self->display(self, io->out);
  return (BUILTIN_SUCCESS);
  (void)builtin;
}
