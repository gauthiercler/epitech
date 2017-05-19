/*
** schema.h for PSU_2015_42sh in /home/foret_a/lab/PSU_2015_42sh/includes/class/schema.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Mon May 30 15:21:32 2016 Antoine FORET
** Last update Sun Jun  5 13:26:13 2016 Gauthier Cler
*/

#ifndef SCHEMA_H_
# define SCHEMA_H_

typedef			struct s_schema t_schema;

# include		"bool.h"
# include		"class/command.h"
# include		"class/parser.h"

t_schema		*new_schema(const char *token,
				    t_command *(*generate)(t_schema *self,
							   t_parser *parser,
							   char **request,
						t_io *io),
				    t_bool (*find_in)(t_schema *self,
						      char **request));
void			schema_destructor(t_schema *self);
t_bool			schema_find_in(t_schema *self, char **request);
unsigned int		schema_get_occurance(t_schema *self, char **request);
t_bool			extract_name(t_command *command, t_parser *parser,
				     char **request, unsigned int index);
t_bool			exec_find_in(t_schema *self, char **request);
t_command		*simple_right_generate(t_schema *self, t_parser *parser,
						char **request, t_io *io);
t_command		*simple_left_generate(t_schema *self, t_parser *parser,
					       char **request, t_io *io);
t_command		*semicolon_generate(t_schema *self, t_parser *parser,
					     char **request, t_io *io);
t_command		*pipe_generate(t_schema *self, t_parser *parser,
					char **request, t_io *io);
t_command		*or_generate(t_schema *self, t_parser *parser,
				      char **request, t_io *io);
t_command		*exec_generate(t_schema *self, t_parser *parser,
					char **request, t_io *io);
t_command		*double_right_generate(t_schema *self, t_parser *parser,
						char **request, t_io *io);
t_command		*double_left_generate(t_schema *self, t_parser *parser,
					       char **request, t_io *io);
t_command		*and_generate(t_schema *self, t_parser *parser,
				       char **request, t_io *io);

struct			s_schema
{
  const char		*token;
  t_command		*(*generate)(t_schema *self, t_parser *parser,
					char **request, t_io *io);
  t_bool		(*find_in)(t_schema *self, char **request);
  unsigned int		(*get_occurence)(t_schema *self, char **request);
  void			(*destruct)(t_schema *self);
};

#endif /* !SCHEMA_H_ */
