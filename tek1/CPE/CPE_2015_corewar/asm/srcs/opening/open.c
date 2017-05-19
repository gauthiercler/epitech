/*
** open.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/open/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Mon Mar 21 11:01:30 2016 Buyumad Anas
** Last update Mon Mar 21 11:30:58 2016 Gauthier Cler
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"asm.h"

int		get_fd(char *filename)
{
  int		fd;

  fd = open(filename, O_RDONLY);
  if (fd == -1)
    {
      put_fd(2, "Couldn't open the file ");
      put_fd(2, filename);
      put_fd(2, ".\n");
    }
  return (fd);
}
