/*
** calloc.c for Malloc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_malloc/sources/calloc.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Wed Jan 25 16:06:17 2017 Anas Buyumad
** Last update Wed Jan 25 16:06:17 2017 Anas Buyumad
*/

#include		"malloc.h"

void			*calloc(size_t num_elements, size_t size)
{
  t_chunk		*chunk;
  size_t		chunk_size;

  chunk_size = num_elements * size;
  if (!(chunk = malloc(chunk_size)))
    return (NULL);
  bzero(chunk, chunk_size);
  return (chunk);
}