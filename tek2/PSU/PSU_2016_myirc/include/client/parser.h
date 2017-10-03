/*
** parser.h for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/include/client/parser.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 31 13:34:01 2017 Gauthier Cler
** Last update Wed May 31 13:34:01 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYIRC_PARSER_H
# define PSU_2016_MYIRC_PARSER_H

# include	"common/structures.h"
# include	"structures.h"

bool		build_command(t_command *command);
void		clean_command(t_command *command);
bool		build_buffer_command(t_client *client);
void		read_input_data(t_client *client);
bool		parse_response(t_response *response, char *bytes);

#endif /* !PSU_2016_MYIRC_PARSER_H */