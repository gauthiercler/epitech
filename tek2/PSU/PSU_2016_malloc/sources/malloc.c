/*
** malloc.c for Malloc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/Malloc/sources/malloc.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Jan 24 23:00:38 2017 Anas Buyumad
** Last update Fri Feb 10 22:41:13 2017 Gauthier Cler
*/

#include			<stdlib.h>
#include			"malloc.h"

t_malloc			global =
  {
    NULL,
    NULL,
    PTHREAD_MUTEX_INITIALIZER,
    false,
    PTHREAD_COND_INITIALIZER
  };

static size_t			align_chunk_size(size_t size)
{
  return ((size + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1));
}

t_chunk				*find_chunk(t_chunk **chunks, size_t size)
{
  t_chunk			*chunk;

  chunk = (*chunks);
  while (chunk)
    {
      (*chunks) = chunk;
      if (chunk->free && chunk->size >= size)
	{
	  chunk->free = false;
	  mutex_unlock();
	  return (chunk);
	}
      chunk = chunk->next;
    }
  return (chunk);
}

t_chunk				*add_chunk(t_chunk *last_chunk,
					   size_t size)
{
  t_chunk			*chunk;
  void				*ret;

  chunk = sbrk(0);
  ret = sbrk(size);
  if (ret == SBRK_FAIL ||  ret == sbrk(0))
    {
      mutex_unlock();
      return (NULL);
    }
  chunk->magic_number = MAGIC_NUMBER;
  chunk->size = size - CHUNK_SIZE;
  chunk->free = false;
  chunk->next = NULL;
  (last_chunk) ? (chunk->previous = last_chunk) : (chunk->previous = NULL);
  (!global.head) ? (global.handle = chunk) : 0;
  (last_chunk) ? (last_chunk->next = chunk) : (global.head = chunk);
  mutex_unlock();
  return (chunk);
}

void				*malloc(size_t size)
{
  t_chunk			*chunks;
  t_chunk			*chunk;

  if ((intptr_t)size < 0 || size > 0xFFFFFFFF)
    return (NULL);
  mutex_lock();
  if (!(chunks = global.head))
    {
      if (!(chunk = add_chunk(chunks, align_chunk_size(size + CHUNK_SIZE))))
	return (NULL);
    }
  else
    {
      chunks = global.handle;
      if (!(chunk = find_chunk(&chunks, align_chunk_size(size))))
	{
	  if (!(chunk = add_chunk(chunks, align_chunk_size(size + CHUNK_SIZE))))
	    return (NULL);
	}
    }
  return (chunk + 1);
}