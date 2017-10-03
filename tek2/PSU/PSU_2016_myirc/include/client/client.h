/*
** client.h for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/include/client/client.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 29 17:24:16 2017 Gauthier Cler
** Last update Mon May 29 17:24:16 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYIRC_CLIENT_H
# define PSU_2016_MYIRC_CLIENT_H

# include	<stdbool.h>
# include	"structures.h"

bool		run_client();
void		initialize_client(t_client *client);
void		initialize_watcher(t_client *client);
void		watch(t_watcher *watcher);
void		retrieve_commands(t_client *client);

#endif /* !PSU_2016_MYIRC_CLIENT_H */