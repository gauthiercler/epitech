/*
** constructor.c for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/srcs/class/parser/constructor.c
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 13:27:53 2016 Antoine FORET
** Last update Sun Jun  5 18:50:40 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"class/parser.h"

/*
** Assign signals
** @params self
** @return void
*/
static void	parser_explode_token(t_parser *self)
{
  self->tokens[0] = SEMICOLON_TOKEN;
  self->tokens[1] = OR_TOKEN;
  self->tokens[2] = AND_TOKEN;
  self->tokens[3] = PIPE_TOKEN;
  self->tokens[4] = DOUBLE_RIGHT_TOKEN;
  self->tokens[5] = SIMPLE_RIGHT_TOKEN;
  self->tokens[6] = DOUBLE_LEFT_TOKEN;
  self->tokens[7] = SIMPLE_LEFT_TOKEN;
  self->tokens[8] = NULL;
}

/*
** define parser methods
** @params parser
** @return void
*/
static void	parser_methods(t_parser *parser)
{
  parser->destruct = parser_destructor;
  parser->generate = parser_generate;
  parser->import = parser_import;
  parser->explode = parser_explode;
  parser->get_schema = parser_get_schema;
}

/*
** define schema for parser
** @params parser
** @return void
*/
static void	parser_schema(t_parser *parser)
{
  parser->schema[0] = new_schema(SEMICOLON_TOKEN, semicolon_generate, NULL);
  parser->schema[1] = new_schema(AND_TOKEN, and_generate, NULL);
  parser->schema[2] = new_schema(OR_TOKEN, or_generate, NULL);
  parser->schema[3] = new_schema(PIPE_TOKEN, pipe_generate, NULL);
  parser->schema[4] = new_schema(DOUBLE_RIGHT_TOKEN,
				 double_right_generate, NULL);
  parser->schema[5] = new_schema(SIMPLE_RIGHT_TOKEN,
				 simple_right_generate, NULL);
  parser->schema[6] = new_schema(DOUBLE_LEFT_TOKEN, double_left_generate, NULL);
  parser->schema[7] = new_schema(SIMPLE_LEFT_TOKEN, simple_left_generate, NULL);
  parser->schema[8] = new_schema("", exec_generate, exec_find_in);
}

/*
** check schemas in parser
** @params parser
** @return success -> TRUE error -> FALSE
*/
static t_bool	check_schema(t_parser *parser)
{
  unsigned int	index;

  index = 0;
  while (index < NB_TOKENS)
    {
      if (parser->schema[index] == NULL)
	{
	  return (FALSE);
	}
      index++;
    }
  return (TRUE);
}

/*
** Generate new object parser
** @params void
** @return success -> parser object error -> NULL
*/
t_parser	*new_parser()
{
  t_parser	*parser;

  if ((parser = malloc(sizeof(t_parser))) == NULL)
    return (NULL);
  parser->alias_manager = new_alias_manager();
  parser_methods(parser);
  parser_schema(parser);
  parser_explode_token(parser);
  if (!check_schema(parser) || parser->alias_manager == NULL)
    {
      parser->destruct(parser);
      return (NULL);
    }
  return (parser);
}
