/*
** circular_buffer.h for PSU_2016_myirc in /home/foret_a/Lab/PSU_2016_myirc/lib/cextended/includes/circular_buffer.h
**
** Made by Antoine FORET
** Login   <antoine.foret@epitech.eu>
**
** Started on  Wed May 31 15:49:13 2017 Antoine FORET
** Last update Wed May 31 15:49:13 2017 Antoine FORET
*/

#ifndef CIRCULAR_BUFFER_H_
# define CIRCULAR_BUFFER_H_

# include		<stddef.h>
# include		<stdbool.h>
# include		<sys/types.h>

typedef			struct s_circular_buffer	t_circular_buffer;

struct			s_circular_buffer
{
  char			*buff;

  size_t		size;
  unsigned int		read_pos;
  unsigned int		write_pos;

  size_t		(*get_size)(t_circular_buffer *self);
  size_t		(*get_remaining_space)(t_circular_buffer *self);
  size_t		(*get_remaining_read)(t_circular_buffer *self);
  ssize_t		(*get_pos)(t_circular_buffer *self,
				    const char *delimiter);
  bool			(*is_full)(t_circular_buffer *self);

  void			(*clear)(t_circular_buffer *self);
  void			(*skip)(t_circular_buffer *self,
				      size_t to_skip);
  ssize_t		(*read)(t_circular_buffer *self,
				 char *buff,
				 size_t size);
  ssize_t		(*write)(t_circular_buffer *self,
				  const char *buff,
				  size_t size);

  ssize_t		(*size_before)(t_circular_buffer *self, char token);

  void			(*destroy)(t_circular_buffer *self);
};

t_circular_buffer	*new_circular_buffer(size_t size);
void			circular_buffer_destroy(t_circular_buffer *self);

size_t			circular_buffer_get_size(t_circular_buffer *self);
size_t			circular_buffer_get_remaining_space(
  t_circular_buffer *self);
size_t			circular_buffer_get_remaining_read(
  t_circular_buffer *self);
bool			circular_buffer_is_full(t_circular_buffer *self);
ssize_t			circular_buffer_get_pos(t_circular_buffer *self,
						       const char *delimiter);

void			circular_buffer_clear(t_circular_buffer *self);
void			circular_buffer_skip(t_circular_buffer *self,
						 size_t to_skip);
ssize_t			circular_buffer_read(t_circular_buffer *self,
						    char *buff,
						    size_t size);
ssize_t			circular_buffer_write(t_circular_buffer *self,
						     const char *buff,
						     size_t size);

ssize_t			circular_buffer_size_before(t_circular_buffer *self,
							   char token);

#endif /* !CIRCULAR_BUFFER_H_ */
