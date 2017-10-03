/*
** split_block.c for Malloc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_malloc/sources/split_block.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jan 26 10:16:59 2017 Anas Buyumad
** Last update Thu Jan 26 10:16:59 2017 Anas Buyumad
*/

#include		"malloc.h"

t_chunk			*split_chunk(t_chunk *chunk, size_t size)
{
  t_chunk		*new_chunk;
  t_chunk		*chunk_save;
  size_t		new_chunk_size;
  void			*jump;

  new_chunk_size = chunk->size - size - CHUNK_SIZE;
  chunk->size = size;
  chunk->free = false;
  jump = (void *)chunk;
  jump += CHUNK_SIZE + chunk->size;
  new_chunk = (t_chunk *)jump;
  new_chunk->magic_number = MAGIC_NUMBER;
  new_chunk->size = new_chunk_size;
  new_chunk->free = true;
  chunk_save = chunk->next;
  chunk->next = new_chunk;
  new_chunk->previous = chunk;
  new_chunk->next = chunk_save;
  (chunk_save) ? chunk_save->previous = new_chunk : 0;
  global.handle = new_chunk;
  mutex_unlock();
  return (chunk);
}