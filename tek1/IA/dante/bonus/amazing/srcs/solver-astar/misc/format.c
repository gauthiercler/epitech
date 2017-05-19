/*
** format.c for solver in /home/gogo/rendu/dante/profondeur/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:11:24 2016 Gauthier Cler
** Last update Wed Apr 27 23:11:26 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdarg.h>
#include	"solver.h"

void		format_flags(int fd, char current, va_list va)
{
  if (current == 'd')
    put_nb(fd, va_arg(va, int));
  else if (current == 's')
    put_fd(fd, va_arg(va, char *));
  else
    write(fd, &current, 1);
}

int		format(int fd, char *str, ...)
{
  int		i;
  va_list	va;

  i = 0;
  if (str == NULL)
    return (ERROR);
  va_start(va, str);
  while (str[i])
    {
      if (str[i] == '%')
	{
	  i += 1;
	  format_flags(fd, str[i], va);
	}
      else
	write(fd, &str[i], 1);
      i += 1;
    }
  va_end(va);
  if (fd == 2)
    return (ERROR);
  return (SUCCESS);
}
