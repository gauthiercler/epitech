/*
** process_commands.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/engine/process_commands.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 17:55:39 2017 Anas Buyumad
** Last update Thu Jun 01 17:55:40 2017 Anas Buyumad
*/

#include	"server/buffer.h"
#include	"server/engine.h"

void		process_commands(t_server *server)
{
  t_command	command;

  while (!buffer_is_empty(&server->buffer))
  {
    buffer_pop(&server->buffer, &command);
    run_command(server, &command);
  }
}