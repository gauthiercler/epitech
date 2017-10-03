/*
** server.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/server/server.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat May 27 17:44:10 2017 Anas Buyumad
** Last update Sat May 27 17:44:10 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_SERVER_H
# define PSU_2016_MYIRC_SERVER_H

# include	<stdbool.h>
# include	<stdint.h>
# include	"server/structures.h"

bool		run_server(uint16_t port);
void		initialize_server(t_server *server, uint16_t port);
void		initialize_watcher(t_client_mgr *manager,
				       t_watcher *watcher,
				       int server_fd);
void		watch(t_watcher *watcher);
void		retrieve_commands(t_cmd_buffer *buffer,
				      t_client_mgr *manager,
				      t_watcher *watcher);
void		watch_connections(t_client_mgr *manager,
				      t_watcher *watcher,
				      int server_fd);

#endif /* !PSU_2016_MYIRC_SERVER_H */