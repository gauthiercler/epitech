/*
** malloc_dump.c for Malloc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/Malloc/sources/malloc_dump.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Tue Jan 24 23:59:35 2017 Anas Buyumad
** Last update Sun Feb 12 23:20:20 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	"malloc.h"

void		show_alloc_mem()
{
  t_chunk	*chunk;

  chunk = global.head;
  setbuf(stdout, NULL);
  printf("break : %p\n", sbrk(0));
  while (chunk)
    {
      if (chunk->next)
	printf("%p - %p : %lu bytes\n", chunk, chunk->next, chunk->size);
      else
	printf("%p - %p : %lu bytes\n", chunk, sbrk(0), chunk->size);
      chunk = chunk->next;
    }
}
