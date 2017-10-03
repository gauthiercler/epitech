/*
** display.c for PSU_2016_lemipc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_lemipc/sources/arena/display.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Mar 23 22:11:32 2017 Anas Buyumad
** Last update Thu Mar 23 22:11:32 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"lem_ipc.h"

void		display_arena(char *arena)
{
  size_t	index;

  index = 0;
  while (index < ARENA_SIZE)
  {
    ((index % ARENA_SS) == 0) ? write(1, "\n", 1) : 0;
    write(1, &arena[index], 1);
    index += 1;
  }
  write(1, "\n", 1);
}