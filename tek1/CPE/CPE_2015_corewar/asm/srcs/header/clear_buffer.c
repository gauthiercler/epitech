/*
** clear_buffer.c for clear_buffer in /home/gogo/rendu/CPE_2015_corewar/asm/srcs/header
**
** Made by Gauthier Cler
** Login   <cler_g@epitech.eu>
**
** Started on  Fri Mar 25 11:22:17 2016 Gauthier Cler
** Last update Sat Mar 26 17:42:39 2016 Buyumad Anas
*/

#include	<stdlib.h>
#include	"asm.h"

int             clear_buffer(int fd, char *old_line, int status)
{
  char          *line;

  if (old_line != NULL)
    free(old_line);
  while ((line = get_next_line(fd)) != NULL)
    free(line);
  return (status);
}
