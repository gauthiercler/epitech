/*
** commands.h for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/include/commands.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat May 20 18:16:40 2017 Gauthier Cler
** Last update Sat May 20 18:16:40 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYFTP_COMMANDS_H
# define PSU_2016_MYFTP_COMMANDS_H

# include			<stdbool.h>
# include			"structures.h"

void				active_mode(t_client *client);
void				change_directory(t_client *client);
void				delete(t_client *client);
void				download_file(t_client *client);
void				help_message(t_client *client);
void				list_files(t_client *client);
void				noop(t_client *client);
void				parent_directory(t_client *client);
void				passive_mode(t_client *client);
void				password_auth(t_client *client);
void				print_directory(t_client *client);
void				quit(t_client *client);
void				upload_file(t_client *client);
void				user_auth(t_client *client);

#endif /* !PSU_2016_MYFTP_COMMANDS_H */