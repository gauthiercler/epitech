/*
** parser.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/class/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May  9 19:14:31 2016 Vincent Dusautoir
** Last update Sun Jun 05 19:57:03 2016 Antoine FORET
*/

#ifndef PARSER_H_
# define PARSER_H_

typedef			struct s_parser t_parser;

# include		"config.h"
# include		"class/command.h"
# include		"class/schema.h"
# include		"class/alias_manager.h"
# include		"class/history_manager.h"

t_parser		*new_parser();
void			parser_destructor(t_parser *self);
char			**parser_explode(t_parser *, char *);
t_command		*parser_generate(t_parser *self,
					  t_history_manager *history,
					  char *command);
t_command		*parser_import(t_parser *self, char **request,
					t_io *io);
t_schema		*parser_get_schema(t_parser *self, const char *token);

struct			s_parser
{
  t_schema		*schema[NB_TOKENS];
  char			*tokens[NB_TOKENS];
  t_alias_manager	*alias_manager;
  void			(*destruct)(t_parser *);
  char			**(*explode)(t_parser *, char *);
  t_command		*(*generate)(t_parser *self, t_history_manager *history,
					char *command);
  t_command		*(*import)(t_parser *self, char **command, t_io *io);
  t_schema		*(*get_schema)(t_parser *self, const char *token);
};

#endif /* PARSER_H_ */
