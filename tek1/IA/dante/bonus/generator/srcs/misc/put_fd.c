/*
** put_fd.c for perfection in /home/skyrise/Work/Repositories/Epitech/IA/dante/generation/perfection/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Apr 26 15:49:22 2016 Buyumad Anas
** Last update Tue Apr 26 16:08:36 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	"perfection.h"

int		put_fd(int fd, char *string)
{
  if (string == NULL)
    return (ERROR);
  write(fd, string, str_len(string));
  if (fd == 2)
    return (ERROR);
  return (SUCCESS);
}
