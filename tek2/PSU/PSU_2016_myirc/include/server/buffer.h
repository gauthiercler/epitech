/*
** buffer.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/server/buffer.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat May 27 17:56:52 2017 Anas Buyumad
** Last update Sat May 27 17:56:52 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_SERVER_BUFFER_H
# define PSU_2016_MYIRC_SERVER_BUFFER_H

# include	"server/structures.h"

void		initialize_buffer(t_cmd_buffer *buffer);
bool		buffer_pop(t_cmd_buffer *buffer, t_command *command);
bool		buffer_push(t_cmd_buffer *buffer, t_command *command);
bool		buffer_is_empty(t_cmd_buffer *buffer);
bool		buffer_is_full(t_cmd_buffer *buffer);

#endif /* !PSU_2016_MYIRC_SERVER_BUFFER_H */