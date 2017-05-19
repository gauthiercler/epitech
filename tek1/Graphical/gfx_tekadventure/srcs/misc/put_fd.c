/*
** put_fd.c for adventure in /home/keyrise/Work/Repositories/Epitech/GFX/gfx_tekadventure/srcs/misc/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Apr 13 12:30:22 2016 Buyumad Anas
** Last update Wed Apr 13 12:30:24 2016 Buyumad Anas
*/

#include	<unistd.h>
#include	"adventure.h"

int		put_fd(int fd, char *string)
{
  if (string == NULL)
    return (ERROR);
  write(fd, string, str_len(string));
  if (fd == 2)
    return (ERROR);
  return (SUCCESS);
}
