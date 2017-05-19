/*
** constructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/command/constructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 19:37:45 2016 Antoine FORET
** Last update Sun Jun  5 19:37:23 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/command.h"
#include	"libc.h"

/*
** define methods for command object
** @params commmand
** @return void
*/
static void	command_methods(t_command *command)
{
  command->is_relative = command_is_relative;
  command->exec = command_exec;
  command->run = command_run;
  command->search_path = command_search_path;
  command->destruct = command_destructor;
}

/*
** generate new command object
** @params params tab
** @return success -> command object, error -> NULL
*/
t_command	*new_command(char **params)
{
  t_command	*command;

  if ((command = malloc(sizeof(t_command))) == NULL)
    return (NULL);
  command->params = ((params == NULL) ? NULL : array_cpy(params));
  command->right = NULL;
  command->left = NULL;
  command->terminate = NULL;
  command_methods(command);
  return (command);
}
