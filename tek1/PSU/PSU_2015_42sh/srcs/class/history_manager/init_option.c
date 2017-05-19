/*
** init_option.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/init_option.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 22:45:33 2016 Antoine FORET
** Last update Sun Jun  5 20:53:07 2016 Gauthier Cler
*/

#include	<malloc.h>
#include	"class/history_manager.h"
#include	"libc.h"

/*
** Initialize options for the history command
** @params self, env manager
** @return void
*/
void		history_manager_init_option(t_history_manager *self,
					    t_env_manager *env)
{
  self->options.clear = FALSE;
  self->options.reverse = TRUE;
  self->options.simple = FALSE;
  self->options.to_show = -1;
  self->options.export = FALSE;
  self->options.import = FALSE;
  self->options.merge = FALSE;
  if (self->options.file != NULL)
    free(self->options.file);
  if (env != NULL && env->find(env, "HOME") != NULL)
    self->options.file = strcat_ret_only(env->find(env, "HOME")->value,
					 ".history", '/');
  else
    self->options.file = NULL;
}
