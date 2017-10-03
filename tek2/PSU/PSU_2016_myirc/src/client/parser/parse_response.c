/*
** parse_response.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/client/parser/parse_response.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Jun 04 17:50:55 2017 Gauthier Cler
** Last update Sun Jun 04 17:50:55 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<memory.h>
#include	"common/error.h"
#include	"common/misc.h"
#include	"common/parser.h"
#include	"client/structures.h"

static char	*get_prefix(t_response *response, char *input)
{
  if (*input == ':')
  {
    response->prefix = strtok(input + 1, " ");
    return (strtok(NULL, ""));
  }
  return (input);
}

static char	*get_trailing_message(t_response *response, char *input)
{
  char		*args;

  if (strstr(input, ":") != NULL)
  {
    args = strtok(input, ":");
    response->message = strtok(NULL, ":");
    return (args);
  }
  else
    response->message = NULL;
  return (input);
}

bool		parse_response(t_response *response, char *input)
{
  strip_crlf(input);
  if ((input = get_prefix(response, input)) == NULL ||
      (input = get_trailing_message(response, input)) == NULL)
    return (false);
  if ((response->args = split(input, " ")) == NULL)
  {
    throw_error("realloc", __func__, &operational, CRITICAL);
    return (false);
  }
  response->nb_args = (uint8_t)(response->args[0] && response->args[1] ?
			       array_length(response->args) - 1 : 0);
  return (true);
}