/*
** handle_args.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/server/args_handler/handle_args.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat May 27 17:09:18 2017 Anas Buyumad
** Last update Sat May 27 17:09:19 2017 Anas Buyumad
*/

#include	<limits.h>
#include	<memory.h>
#include	<stdlib.h>
#include	"server/args_handler.h"
#include	"common/misc.h"

bool		handle_args(int argc, const char *argv[])
{

  if (argc != 2 ||
    (strcmp(argv[1], "--help") == 0 ||
      (!is_number(argv[1]) || atoi(argv[1]) > USHRT_MAX)))
  {
    display_usage();
    return (false);
  }
  return (true);
}