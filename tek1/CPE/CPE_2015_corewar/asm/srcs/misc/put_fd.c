/*
** my_putstr.c for my_putstr in /home/gogo/rendu/CPE_2015_corewar/asm/src/misc
** 
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
** 
** Started on  Mon Mar 21 11:03:31 2016 Gauthier Cler
** Last update Sat Mar 26 11:38:11 2016 Gauthier Cler
*/

#include       	<unistd.h>
#include	"asm.h"

int		put_fd(int fd, char *str)
{
  if (str == NULL)
    return (ERROR);
  write(fd, str, my_strlen(str));
  if (fd == 2)
    return (ERROR);
  return (SUCCESS);
}
