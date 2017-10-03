/*
** strip_crlf.c for PSU_2016_myirc in /home/rubysh/Work/Repositories/Epitech/SecondYear/PSU/PSU_2016_myirc/src/common/parser/strip_crlf.c
**
** Made by Anas Buyumad
** Login   <anas.buyumad@epitech.eu>
**
** Started on  Thu Jun 01 15:38:22 2017 Anas Buyumad
** Last update Thu Jun 01 15:38:22 2017 Anas Buyumad
*/

#include	<stddef.h>
#include	"common/parser.h"

void		strip_crlf(char *string)
{
  size_t	iterator;

  iterator = 0;
  while (string[iterator])
  {
    if (string[iterator] == CR || string[iterator] == LF)
      string[iterator] = '\0';
    iterator += 1;
  }
}