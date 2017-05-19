/*
** checker.c for 42sh in /home/gogo/rendu/PSU_2015_42sh/srcs/class/builtins/which/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Sat Jun  4 00:41:40 2016 Gauthier Cler
** Last update Sun Jun  5 20:38:19 2016 Gauthier Cler
*/

#include		"class/which.h"
#include		"libc.h"

/*
** Check number of args for which object
** @params command
** @return success -> TRUE, error -> FALSE
*/
t_bool			which_checker(char **command)
{
  if (count(command) < 2)
    {
      fprintf(stderr, "which: Too few arguments.\n");
      return (FALSE);
    }
  return (TRUE);
}
