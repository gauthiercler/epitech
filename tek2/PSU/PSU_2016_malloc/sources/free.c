/*
** free.c for Malloc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/Malloc/sources/free.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Jan 25 00:06:53 2017 Anas Buyumad
** Last update Sun Feb 12 23:19:19 2017 Gauthier Cler
*/

#include		"malloc.h"

t_chunk			*is_chunk(void *pointer)
{
  t_chunk		*chunk;
  char			*jump;

  if ((void *)(global.head) < pointer && pointer < sbrk(0))
    {
      jump = pointer;
      jump -= CHUNK_SIZE;
      chunk = (t_chunk *)jump;
      if (chunk->magic_number == MAGIC_NUMBER)
	return (chunk);
    }
  return (NULL);
}

void			free(void *pointer)
{
  t_chunk		*chunk;

  mutex_lock();
  if ((chunk = is_chunk(pointer)))
    {
    chunk->free = true;
    if (chunk->previous && chunk->previous->free)
      chunk = merge_chunks(chunk->previous);
    if (chunk->next){
      global.handle = chunk;
      merge_chunks(chunk);
    }
    else
      {
	if (chunk->previous)
	  {
	    chunk->previous->next = NULL;
	    global.handle = global.head;
	  }
	else
	  global.head = NULL;
	sbrk(-((intptr_t)(CHUNK_SIZE + chunk->size)));
      }
  }
  mutex_unlock();
}
