/*
** libc.h for PSU_2015_42sh in /home/dusautv/rendu/PSU/PSU_2015_42sh/includes/
**
** Made by Vincent Dusautoir
** Login   <dusaut_v@epitech.eu>
**
** Started on  Mon May  9 17:31:39 2016 Vincent Dusautoir
** Last update Sun Jun  5 13:24:28 2016 Vincent Dusautoir
*/

#ifndef READ_SIZE
# define READ_SIZE (4096)
#endif

#ifndef LIBC_H_
# define LIBC_H_

# include	<stddef.h>
# include	"class/command.h"
# include	"bool.h"
# include	"io.h"

char		*get_next_line(const int fd);
size_t		count(char **tab);
void		destroy_array(char **tab);
char		*array_row_cpy(char *src);
char		**array_cpy(char **src);
char		**array_dup(char **src);
t_bool		in_string(char c, char *str);
t_bool		split(char *ref, char **saver, char *separator);
t_bool		is_numeric(char *string);
t_bool		is_alpha_cd(char request);
int             get_number(char *string);
char		*purge(char *string);
void		set_io(t_io *io, int in, int out);
t_bool		strnkcmp(char *s1, char *s2, size_t index, size_t length);
void		isolate_tab(char **tab, unsigned int size);
void		up_tab(char **tab, unsigned int offset);
t_command	*ambiguous_redirect(t_bool in);
char		*extract(char *src, char delimiter,
			     unsigned int offset);
char		*strcat_ret_only(const char *start, const char *end,
				     char separator);
t_bool		in_array(char **array, char *needed);
void		swap(void **elem1, void **elem2);
char		**merge_array(char **src, char **new, unsigned int index);
char		*string_from_tab(char **array);

#endif /* !LIBC_H_ */
