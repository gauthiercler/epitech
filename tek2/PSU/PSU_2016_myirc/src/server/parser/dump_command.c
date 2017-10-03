/*
** dump_command.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/parser/dump_command.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 15:41:14 2017 Anas Buyumad
** Last update Thu Jun 01 15:41:14 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"server/structures.h"

void		dump_command(t_command *command)
{
  size_t	iterator;

  iterator = 0;
  fprintf(stdout, "[Command Dump]\n");
  fprintf(stdout, "Client ID -> %d\n", command->client_id);
  fprintf(stdout, "Type -> %d\n", command->type);
  if (command->nb_args)
  {
    while (iterator < command->nb_args)
    {
      fprintf(stdout, "Arg (%lu) -> %s\n",
	      iterator + 1, command->args[iterator]);
      iterator += 1;
    }
  }
  fprintf(stdout, "Number Args -> %d\n", command->nb_args);
  fprintf(stdout, "Raw Input -> %s\n\n", command->raw_input);
}