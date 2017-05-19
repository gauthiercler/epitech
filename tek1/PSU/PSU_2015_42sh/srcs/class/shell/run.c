/*
** run.c for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/srcs/class/shell/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May  9 21:31:00 2016 Vincent Dusautoir
** Last update Sun Jun  5 19:19:28 2016 Gauthier Cler
*/

#include	"libc.h"

/*
** Run the shell
** @params self
** @return void
*/
int		shell_run(t_shell *self)
{
  t_command	*command;
  t_io		io;
  int		status;

  status = 256;
  self->signal_handler->unset(self->signal_handler);
  while (status >= 256 && self->prompt(self)->get_instruction(self) != FALSE)
    {
      if ((command = self->parser->generate(self->parser, self->history_manager,
					    self->instruction)))
      {
	set_io(&io, 0, 1);
	status = command->run(command, self, &io);
	command->destruct(command);
      }
      else
	status = 257;
      self->instruction_destroy(self);
      self->signal_handler->unset(self->signal_handler);
    }
  return (status);
}
