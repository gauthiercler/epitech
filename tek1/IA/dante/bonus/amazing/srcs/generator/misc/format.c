/*
** format.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 16:08:02 2016 Buyumad Anas
** Last update Tue Apr 26 16:08:05 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	<stdarg.h>
#include	"perfection.h"

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
