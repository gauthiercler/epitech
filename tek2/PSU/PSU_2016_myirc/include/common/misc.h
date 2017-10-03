/*
** misc.h for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/include/common/misc.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Wed May 31 13:47:49 2017 Gauthier Cler
** Last update Wed May 31 13:47:49 2017 Gauthier Cler
*/

#ifndef PSU_2016_MYIRC_MISC_H
# define PSU_2016_MYIRC_MISC_H

# include	<stdint.h>
# include	<stdbool.h>

uint8_t		array_length(char **array);
bool		write_in_fd(int fd, const char *format, ...);
void		free_ptr(void **ptr);
void		free_array(char **array);
bool		is_number(const char *string);

#endif /* !PSU_2016_MYIRC_MISC_H */