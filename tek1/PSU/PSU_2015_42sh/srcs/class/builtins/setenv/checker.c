/*
** checker.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/setenv/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Mon May 30 22:50:03 2016 Gauthier Cler
** Last update Sun Jun  5 20:44:24 2016 Gauthier Cler
*/

#include	"class/setenv.h"
#include	"libc.h"

/*
** Check if setenv args are corrects
** @params request tab
** @return success -> TRUE, failure -> FALSE
*/
t_bool		setenv_checker(char **request)
{
  size_t	nb_args;

  if ((nb_args = count(request)) == 1)
    return (TRUE);
  if (nb_args > 3)
    {
      fprintf(stderr, "setenv: Too many arguments.\n");
      return (FALSE);
    }
  if (in_string('=', request[1]) == TRUE)
    {
      if (request[1][0] == '=')
	fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
      else
	fprintf(stderr,
		"setenv: Variable name must contain alphanumeric characters.\n");
	return (FALSE);
    }
  else if (is_alpha_cd(request[1][0]) == FALSE)
    {
      fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
      return (FALSE);
    }
  return (TRUE);
}
