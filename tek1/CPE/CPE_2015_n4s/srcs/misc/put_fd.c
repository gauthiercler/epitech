/*
** put_fd.c for ia in /home/gogo/rendu/CPE_2015_n4s/srcs/misc/
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Tue Apr 26 22:05:59 2016 Gauthier Cler
** Last update Tue Apr 26 22:06:09 2016 Gauthier Cler
*/

#include	<unistd.h>
#include	"ia.h"

int		put_fd(int fd, char *string)
{
  if (string == NULL)
    return (ERROR);
  write(fd, string, str_len(string));
  if (fd == 2)
    return (ERROR);
  return (SUCCESS);
}
