/*
** throw_error.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/error/throw_error.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Sat May 27 16:58:40 2017 Anas Buyumad
** Last update Sat May 27 16:58:40 2017 Anas Buyumad
*/

#include	<stdio.h>
#include	"common/error.h"

void		throw_error(const char *sys_caller,
				const char *func_caller,
				bool *operational,
				enum e_error_type type)
{
  fprintf(stderr, "Error thrown from %s : ", func_caller);
  perror(sys_caller);
  if (type == CRITICAL)
    *operational = false;
}