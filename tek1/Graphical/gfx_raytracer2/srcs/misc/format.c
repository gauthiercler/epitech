/*
** format.c for format in /home/montag_v/rendu/gfx_raytracer2
** 
** Made by montag_v
** Login   <montag_v@epitech.net>
** 
** Started on  Wed May  4 14:40:59 2016 montag_v
** Last update Wed May  4 15:38:18 2016 montag_v
*/

#include	<unistd.h>
#include	<stdarg.h>
#include	"raytracer.h"

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
