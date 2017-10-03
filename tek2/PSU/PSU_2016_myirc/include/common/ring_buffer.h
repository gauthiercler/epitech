/*
** ring_buffer.h for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/include/common/ring_buffer.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Mon May 29 19:21:16 2017 Anas Buyumad
** Last update Mon May 29 19:21:17 2017 Anas Buyumad
*/

#ifndef PSU_2016_MYIRC_COMMON_RING_BUFFER_H
# define PSU_2016_MYIRC_COMMON_RING_BUFFER_H

# include			<stdint.h>
# include			<stdbool.h>
# include			"common/config.h"

# define INVALID_INPUT		(-1)
# define NON_CONFORM		(-2)

typedef struct s_ring_buffer	t_ring_buffer;

struct				s_ring_buffer
{
  uint8_t 			buffer[RING_BUFFER_SIZE];
  uint8_t			*head;
  uint8_t			*tail;
};

void				initialize_ring_buffer(t_ring_buffer
							   *buffer);
bool				ring_buffer_is_empty(t_ring_buffer
							 *buffer);
bool				ring_buffer_is_full(t_ring_buffer *buffer);
bool				ring_buffer_push(t_ring_buffer *buffer,
						     uint8_t byte);
bool				ring_buffer_pop(t_ring_buffer *buffer,
						    uint8_t *byte);
uint16_t			get_ring_buffer_free_space(t_ring_buffer
							   *buffer);
void				ring_buffer_discard_data(t_ring_buffer
							     *buffer);
bool				push_bytes(t_ring_buffer *buffer,
					       char *bytes, uint16_t size);
bool				pop_bytes(t_ring_buffer *buffer,
					      uint16_t nb_bytes,
					      char bytes[RING_BUFFER_SIZE]);
int16_t				ring_buffer_get_input_size(t_ring_buffer
								  *buffer);

#endif /* !PSU_2016_MYIRC_RING_BUFFER_H */