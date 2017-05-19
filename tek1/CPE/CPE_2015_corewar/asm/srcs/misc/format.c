/*
** format.c for format in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Sat Mar 26 11:17:41 2016 Gauthier Cler
** Last update Sat Mar 26 11:35:18 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	<stdarg.h>
#include	"asm.h"

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
