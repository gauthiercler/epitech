/*
** loading.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/objdump/src/loading.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Feb 16 21:34:49 2017 Gauthier Cler
** Last update Mon Feb 20 18:09:19 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<sys/mman.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<malloc.h>
#include	<errno.h>
#include	<string.h>
#include	"objdump.h"

static int	load_file(int *fd, const char *filename)
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

static bool	load_map(void **map, int fd)
{
  *map = mmap(NULL, (size_t)lseek(fd, 0, SEEK_END),
	      PROT_READ, MAP_SHARED, fd, 0);
  if (*map == MAP_FAILED)
    return (display_error(""));
  return (true);
}

static bool	is_valid_elf(const char	*ident, const char *filename)
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

bool		init_struct(t_data *data, const char *filename)
{
  Elf64_Ehdr	*tmp;

  if (!load_file(&((_data)data)->fd, filename))
    return (false);
  if (!load_map(&data->map, data->fd))
    return (false);
  tmp = (Elf64_Ehdr *)data->map;
  if (!is_valid_elf((const char *)tmp->e_ident, filename))
    return (false);
  data->arch = (tmp->e_ident[EI_CLASS] == ELFCLASS32) ? false : true;
  data->elf = (data->arch) ? malloc(sizeof(t_elf_64))
			   : malloc(sizeof(t_elf_32));
  if (!data->elf)
    return (false);
  if (!init_archi(data, filename))
    return (false);
  return (true);
}
