/*
** misc.h for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/include/client/misc.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Jun 01 09:51:37 2017 Gauthier Cler
** Last update Thu Jun 01 09:51:37 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYIRC_CLIENT_MISC_H
# define PSU_2016_MYIRC_CLIENT_MISC_H

# include	"structures.h"

void		close_connection(t_client *client);
void		display_time();
void		change_user(t_client *client, const char *new_name);

#endif /* !PSU_2016_MYIRC_CLIENT_MISC_H */