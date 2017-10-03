/*
** misc.h for PSU_2016_myftp in /home/gogo/rendu/tek2/PSU_2016_myftp/include/misc.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sat May 20 18:16:49 2017 Gauthier Cler
** Last update Sat May 20 18:16:49 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYFTP_MISC_H
# define PSU_2016_MYFTP_MISC_H

# include			<stdbool.h>
# include			<stdio.h>
# include			"structures.h"

void				print_usage(const char *binary_name);
bool				arguments_checking(const char *port,
						       const char *path);
bool				close_fd(int fd);
bool				close_filestream(FILE *stream);
void				free_ptr(char **input);
char				*string_replace(char *str, char find,
						    char replace);
char				*concat(const char *first,
					    const char *second);
bool				display_error(const char *caller,
						  const char *error);
bool				is_valid_file(const char *path);
bool				replace_root(t_client *client);
bool				is_below_root(const char *base_path,
						  const char *arg);
bool				get_abs_path(char **path);
void				free_tab(char **tab);

#endif /* !PSU_2016_MYFTP_MISC_H */
