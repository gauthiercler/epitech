/*
** merge_chunks.c for Malloc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_malloc/sources/merge_chunks.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jan 26 16:03:33 2017 Anas Buyumad
** Last update Sun Feb 12 23:20:31 2017 Gauthier Cler
*/

#include		"malloc.h"

t_chunk			*merge_chunks(t_chunk *chunk)
{
  if (chunk->next && chunk->next->free)
    {
      chunk->size += (CHUNK_SIZE + chunk->next->size);
      chunk->next = chunk->next->next;
    }
  if (chunk->next)
    chunk->next->previous = chunk;
  return (chunk);
}
