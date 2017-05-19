/*
** checker.c for exit in /home/skyrise/Work/Repositories/Epitech/PSU/42sh/PSU_2015_42sh/srcs/class/builtins/exit/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon May 30 14:02:09 2016 Buyumad Anas
** Last update Sun Jun  5 20:45:23 2016 Gauthier Cler
*/

#include	<stdio.h>
#include	"class/exit.h"
#include	"libc.h"

/*
** Checks wether the command is valid or not
** @param command
** @return BOOL
*/
t_bool		exit_checker(char **command)
{
  size_t	elements;

  elements = count(command);
  if (elements > 2)
    {
      fprintf(stderr, "exit: Expression Syntax.\n");
      return (FALSE);
    }
  else if (elements == 2)
    {
      if (!is_numeric(command[1]))
	{
	  if (command[1][0] >= '0' && command[1][0] <= '9')
	    fprintf(stderr, "exit: Badly formed number.\n");
	  else
	    fprintf(stderr, "exit: Expression Syntax.\n");
	  return (FALSE);
	}
    }
  return (TRUE);
}
