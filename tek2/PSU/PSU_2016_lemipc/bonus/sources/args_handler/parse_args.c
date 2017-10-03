/*
** parse_args.c for PSU_2016_lemipc in /home/gogo/rendu/tek2/PSU_2016_lemipc/sources/args_handler/parse_args.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed Mar 22 14:04:25 2017 Gauthier Cler
** Last update Wed Mar 22 14:04:25 2017 Gauthier Cler
*/

#include	<ctype.h>
#include	<string.h>
#include	"lem_ipc.h"

bool		is_digit(const char *str)
{
  int		iterator;

  iterator = 0;
  while (str[iterator])
  {
    if (!isdigit(str[iterator]))
      return (false);
    iterator += 1;
  }
  return (true);
}

bool		parse_args(const char *team_string)
{
  if (!is_digit(team_string))
    return (custom_error("Invalid number format"));
  if (strlen(team_string) != 1)
    return (custom_error("team number [0-9]"));
  return (true);
}