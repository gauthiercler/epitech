/*
** construct.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/history_entry/construct.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Sat Jun 04 19:20:03 2016 Antoine FORET
** Last update Sun Jun  5 20:51:00 2016 Gauthier Cler
*/

#include		<malloc.h>
#include		<time.h>
#include		<string.h>
#include		"class/history_entry.h"

/*
** Define history entry methods
** @params self
** @return void
*/
static void		history_entry_methods(t_history_entry *history_entry)
{
  history_entry->destruct = history_entry_destructor;
  history_entry->display = history_entry_display;
  history_entry->export = history_entry_export;
}

/*
** Generate an new history entry object
** @params id, command string
** @return success -> history entry object, failure -> NULL
*/
t_history_entry		*new_history_entry(unsigned int id, const char *command)
{
  t_history_entry	*history_entry;

  if ((history_entry = malloc(sizeof(t_history_entry))) == NULL)
    return (NULL);
  history_entry_methods(history_entry);
  if (time(&history_entry->timestamp) == -1)
    {
      history_entry->destruct(history_entry);
      return (NULL);
    }
  history_entry->command = strdup(command);
  history_entry->id = id;
  return (history_entry);
}
