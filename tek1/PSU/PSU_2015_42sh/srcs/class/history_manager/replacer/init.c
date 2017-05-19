/*
** init.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/replacer/init.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sun Jun 05 18:36:55 2016 Antoine FORET
** Last update Sun Jun 05 18:36:55 2016 Antoine FORET
*/

#include	"class/history.h"

/*
** Initialize values for replacer object
** @params self, history manager, parser request
** @return void
*/
void		init_history_manager_replacer(t_history_replacer *self,
					      t_history_manager *manager,
					      t_parser *parser,
					      char **request)
{
  self->request = request;
  self->parser = parser;
  self->id = 0;
  self->manager = manager;
  self->updated = FALSE;
  self->run = history_manager_replacer_run;
  self->set = history_replacer_set;
}

