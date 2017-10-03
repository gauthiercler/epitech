/*
** realloc.c for Malloc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/Malloc/sources/realloc.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Jan 25 00:56:52 2017 Anas Buyumad
** Last update Sun Feb 12 23:20:59 2017 Gauthier Cler
*/

#include		"malloc.h"

static void		*alloc_new_chunk(void *pointer, size_t size)
{
  t_chunk		*new_chunk;
  t_chunk		*chunk;
  size_t		copy_size;

  new_chunk = malloc(size);
  if (pointer && new_chunk)
  {
    if ((chunk = is_chunk(pointer)))
      {
	copy_size = (chunk->size > size) ? size : chunk->size;
	mutex_lock();
	memcpy(new_chunk, pointer, copy_size);
	mutex_unlock();
	free(pointer);
      }
  }
  return (new_chunk);
}

void			*realloc(void *pointer, size_t size)
{
  if (!pointer)
    return (malloc(size));
  if (size == 0)
    {
      free(pointer);
      return (pointer);
    }
  return (alloc_new_chunk(pointer, size));
}
