/*
** unloading.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm/src/unloading.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 21 13:38:25 2017 Gauthier Cler
** Last update Tue Feb 21 13:38:25 2017 Gauthier Cler
*/

#include	<sys/mman.h>
#include	<unistd.h>
#include	<malloc.h>
#include	"nm.h"

static bool	unload_map(void **map, int fd)
{
  if (munmap(*map, (size_t)lseek(fd, 0, SEEK_END)) == RET_ERROR)
    return (display_error(NULL));
  return (true);
}

static bool	unload_file(int *fd)
{
  if (close(*fd) == RET_ERROR)
    return (display_error(NULL));
  return (true);
}

bool		clean_struct(t_data *data)
{
  if (!unload_map(&data->map, data->fd))
    return (false);
  if (!unload_file(&data->fd))
    return (false);
  if (data->arch)
    free(((_64)data->elf)->syms);
  else
    free(((_32)data->elf)->syms);
  free(data->elf);
  return (true);
}