/*
** Parser.h for PSU_2016_zappy in /home/montag-v/rendu/PSU_2016_zappy/server/include/Parser.h
**
** Made by Montagne Valentin
** Login   <valentin.montagne@epitech.eu>
**
** Started on  Thu Jun 22 10:33:14 2017 Montagne Valentin
** Last update Thu Jun 22 10:33:14 2017 Montagne Valentin
*/

#ifndef PSU_2016_ZAPPY_PARSER_H
# define PSU_2016_ZAPPY_PARSER_H

typedef			struct s_parser		t_parser;

# include 				<stdbool.h>
# include				"config.h"
# include                                "command.h"

typedef enum				e_error
{
  NOTHING,
  LERROR,
  CRITICAL
}					t_error;

typedef enum				e_parsing_type
{
  AI,
  GRAPHICAL
}					t_parsing_type;

struct					s_parser
{

  t_error				(*parse_arguments)(int ac,
							    char **av,
							    t_config *conf);

  t_error				(*parse_stream)(t_parsing_type type,
							 char *stream,
							 t_command *r);

  void					(*destroy)(t_parser *self);

};

t_parser				*new_parser();

void					destroy_parser(t_parser *self);

t_error					parse_arguments(int ac,
							 char **av,
							 t_config *conf);

t_error					parse_stream(t_parsing_type type,
							    char *stream,
							    t_command
							    *r);

t_error					print_error(t_error error,
						     char *msg, ...);

void					print_usage(char *binary_name);

bool					is_digits(char *str);

char 					*tab_to_str(char **cells);

#endif /* !PSU_2016_ZAPPY_PARSER_H */
