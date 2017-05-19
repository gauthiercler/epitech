/*
** ambigious.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/libc/error/ambigious.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed Jun 01 20:40:44 2016 Antoine FORET
** Last update Wed Jun 01 20:40:44 2016 Antoine FORET
*/

#include	"class/command.h"

/*
** Output message for an ambiguous redirection
** @params is thrown by an input
*/
t_command	*ambiguous_redirect(t_bool in)
{
  fprintf(stderr, "Ambiguous %s redirect.\n", ((in) ? "input" : "output"));
  return (NULL);
}
