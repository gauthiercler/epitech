/*
** malloc.h for Malloc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/Malloc/includes/malloc.h
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Jan 24 22:54:45 2017 Anas Buyumad
** Last update Thu Jan 26 22:57:24 2017 Gauthier Cler
*/

#ifndef MALLOC_MALLOC_H
# define MALLOC_MALLOC_H

#include			<stdbool.h>
#include			<stddef.h>
#include			<string.h>
#include			<unistd.h>
#include			<pthread.h>
#include			<stdio.h>

# ifndef ALIGNMENT
#  define ALIGNMENT (sizeof(void *))
# endif

# ifndef SBRK_FAIL
#  define SBRK_FAIL ((void *) -1)
# endif

# ifndef CHUNK_SIZE
#  define CHUNK_SIZE (sizeof(t_chunk))
# endif

# ifndef MAGIC_NUMBER
#  define MAGIC_NUMBER (0xdeadbeef)
# endif

typedef struct	s_chunk		t_chunk;
typedef struct	s_malloc	t_malloc;

extern t_malloc			global;

struct				s_chunk
{
  unsigned int			magic_number;
  size_t			size;
  bool				free;
  t_chunk			*previous;
  t_chunk			*next;
};

struct				s_malloc
{
  t_chunk			*head;
  t_chunk			*handle;
  pthread_mutex_t		mutex;
  bool				is_locked;
  pthread_cond_t		mutex_cond;
};

void				*malloc(size_t size);
void				show_alloc_mem();
void				free(void *pointer);
t_chunk				*is_chunk(void *pointer);
void				*realloc(void *pointer, size_t size);
void				*calloc(size_t num_elements, size_t size);
void				mutex_lock();
void				mutex_unlock();
t_chunk				*split_chunk(t_chunk *chunk, size_t size);
t_chunk				*merge_chunks(t_chunk *chunk);

#endif //MALLOC_MALLOC_H
