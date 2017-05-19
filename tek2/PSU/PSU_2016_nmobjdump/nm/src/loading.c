/*
** loading.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm/src/loading.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Feb 19 18:09:35 2017 Gauthier Cler
** Last update Sun Feb 19 18:09:35 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/mman.h>
#include	<sys/types.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<string.h>
#include	"nm.h"

int		load_file(int *fd, const char *filename)
{
  *fd = open(filename, O_RDONLY);
  if (*fd == RET_ERROR)
  {
    if (errno == ENOENT)
      fprintf(stderr, "%s: '%s': No such file\n", binary, filename);
    else
      fprintf(stderr, "%s: %s: %s\n", binary, filename, strerror(errno));
    return (false);
  }
  return (true);
}

bool		load_map(void **map, int fd)
{
  *map = mmap(NULL, (size_t)lseek(fd, 0, SEEK_END),
	      PROT_READ, MAP_SHARED, fd, 0);
  if (*map == MAP_FAILED)
    return (display_error(""));
  return (true);
}

bool		is_valid_elf(const char	*ident, const char *filename)
{
  if (ident[EI_MAG0] == ELFMAG0
    && ident[EI_MAG1] == ELFMAG1
    && ident[EI_MAG2] == ELFMAG2
    && ident[EI_MAG3] == ELFMAG3
    && ident[EI_DATA] == ELFDATA2LSB
    && ident[EI_VERSION] == EV_CURRENT)
    return (true);
  fprintf(stderr, "%s: %s: File format not recognized\n", binary, filename);
  return (false);
}
