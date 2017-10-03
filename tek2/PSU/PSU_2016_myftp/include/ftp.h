/*
** ftp.h for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/include/ftp.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon May 08 14:05:34 2017 Gauthier Cler
** Last update Mon May 08 14:05:34 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYFTP_FTP_H
# define PSU_2016_MYFTP_FTP_H

# include			<stdbool.h>
# include			"structures.h"

bool				ftp_server(uint16_t port);
bool				handle_command(t_client *client);
char				*get_command_at_idx(size_t idx);
bool				update_pwd(t_client *client);
bool				move_dir(const char *path);

#endif /* !PSU_2016_MYFTP_FTP_H */
