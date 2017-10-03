/*
** args_handler.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/server/args_handler.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat May 27 17:22:15 2017 Anas Buyumad
** Last update Sat May 27 17:22:15 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_SERVER_ARGS_HANDLER_H
# define PSU_2016_MYIRC_SERVER_ARGS_HANDLER_H

# include	<stdbool.h>

bool		handle_args(int argc, const char *argv[]);
void		display_usage(void);

#endif /* !PSU_2016_MYIRC_ARGS_HANDLER_H */