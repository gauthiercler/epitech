/*
** put_fd.c for solver in /home/gogo/rendu/dante/profondeur/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Wed Apr 27 23:11:00 2016 Gauthier Cler
** Last update Wed Apr 27 23:11:07 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"solver.h"

int		put_fd(int fd, char *string)
{
  if (string == NULL)
    return (ERROR);
  write(fd, string, str_len(string));
  if (fd == 2)
    return (ERROR);
  return (SUCCESS);
}
