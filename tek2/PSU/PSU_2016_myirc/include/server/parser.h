/*
** parser.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/server/parser.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 15:29:11 2017 Anas Buyumad
** Last update Thu Jun 01 15:29:12 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_SERVER_PARSER_H
# define PSU_2016_MYIRC_SERVER_PARSER_H

# include		"server/structures.h"

void			retrieve_command(t_cmd_buffer *buffer,
					     t_client *client);
void			build_command(t_cmd_buffer *buffer,
					  t_client *client,
					  char *command);
bool			build_buffer_command(t_cmd_buffer *buffer,
						 t_client *client);
enum e_cmd_type		assess_command(char *command);
void			dump_command(t_command *command);

#endif /* !PSU_2016_MYIRC_SERVER_PARSER_H */