/*
** constructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_manager/constructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 16:39:30 2016 Antoine FORET
** Last update Sun Jun  5 20:52:06 2016 Gauthier Cler
*/

#include		<malloc.h>
#include		"class/history_manager.h"

/*
** Initialize methods from the history manager object
** @params self
** @return void
*/
static void		history_manager_methods(t_history_manager *self)
{
  self->destruct = history_manager_destructor;
  self->display = history_manager_display;
  self->get = history_manager_get;
  self->insert = history_manager_insert;
  self->add = history_manager_add;
  self->clear = history_manager_clear;
  self->sort = history_manager_sort_by;
  self->init_options = history_manager_init_option;
  self->export = history_manager_export;
  self->import = history_manager_import;
  self->merge = history_manager_merge;
  self->get_unique = history_manager_get_unique;
  self->run = history_manager_run;
  self->add_request = history_manager_add_request;
}

/*
** Create a new history manager object
** @params void
** @return success -> history manager object, failure -> NULL
*/
t_history_manager	*new_history_manager()
{
  t_history_manager	*history_manager;

  if ((history_manager = malloc(sizeof(t_history_manager))) == NULL)
    return (NULL);
  history_manager->current_command = 1;
  history_manager->entries = NULL;
  history_manager->size = 0;
  history_manager_methods(history_manager);
  history_manager->options.file = NULL;
  history_manager->init_options(history_manager, NULL);
  return (history_manager);
}
