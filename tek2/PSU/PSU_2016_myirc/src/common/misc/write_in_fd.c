/*
** write.c for PSU_2016_myirc in /home/gogo/rendu/tek2/PSU_2016_myirc/src/common/socket/write.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue May 30 23:14:12 2017 Gauthier Cler
** Last update Tue May 30 23:14:13 2017 Gauthier Cler
*/

#include	<stdbool.h>
#include	<stdio.h>
#include	<stdarg.h>
#include	"common/structures.h"

bool		write_in_fd(int fd, const char *format, ...)
{
  va_list	list;

  if (operational)
  {
    va_start(list, format);
    if (vdprintf(fd, format, list) < 0)
      return (false);
    va_end(list);
  }
  return (true);
}