/*
** build_command.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/parser/build_command.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 31 13:28:22 2017 Gauthier Cler
** Last update Wed May 31 13:28:22 2017 Gauthier Cler
*/

#include	<memory.h>
#include	<stdlib.h>
#include	"common/misc.h"
#include	"client/commands.h"
#include	"common/error.h"
#include	"common/parser.h"

void		clean_command(t_command *command)
{
  if (command->args)
  {
    free(command->args);
    command->args = NULL;
  }
  memset(command->raw_input, 0, MSG_MAX_SIZE + 1);
}

bool		build_command(t_command *command)
{
  static char	tmp_buffer[MSG_MAX_SIZE + 1];

  if (command->raw_input == NULL || strlen(command->raw_input) == 0)
    return (false);
  memset(tmp_buffer, 0, MSG_MAX_SIZE + 1);
  memcpy(tmp_buffer, command->raw_input, strlen(command->raw_input));
  if (!(command->args = split(tmp_buffer, " ")))
  {
    throw_error("split", __func__, &operational, CRITICAL);
    return (false);
  }
  command->type = assess_command(command->args[0]);
  command->nb_args = (uint8_t)(command->args[1] ?
			       array_length(command->args) - 1 : 0);
  return (true);
}