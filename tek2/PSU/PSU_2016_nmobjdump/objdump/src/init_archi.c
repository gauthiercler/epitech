/*
** init_archi.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/objdump/src/init_archi.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Mon Feb 20 18:18:19 2017 Gauthier Cler
** Last update Mon Feb 20 18:18:19 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	"objdump.h"

bool		init_32(t_data *data, const char *filename)
{
  ((_32)data->elf)->header = (Elf32_Ehdr *)data->map;
  if (((_32)data->elf)->header->e_type != ET_REL
      && ((_32)data->elf)->header->e_type != ET_EXEC
      && ((_32)data->elf)->header->e_type != ET_DYN)
  {
    fprintf(stderr, "%s: %s: File format not recognized\n", binary, filename);
    return (false);
  }
  ((_32)data->elf)->sections =
    (Elf32_Shdr *)(data->map + ((_32)data->elf)->header->e_shoff);
  data->sections_names =
    (char *)data->map +
    ((_32)data->elf)->sections[((_32)data->elf)->header->e_shstrndx].sh_offset;
  return (true);
}

static bool	init_64(t_data *data, const char *filename)
{
  ((_64)data->elf)->header = (Elf64_Ehdr *)data->map;
  if (((_64)data->elf)->header->e_type != ET_REL
      && ((_64)data->elf)->header->e_type != ET_EXEC
      && ((_64)data->elf)->header->e_type != ET_DYN)
  {
    fprintf(stderr, "%s: %s: File format not recognized\n", binary, filename);
    return (false);
  }
  ((_64)data->elf)->sections =
    (Elf64_Shdr *)(data->map + ((_64)data->elf)->header->e_shoff);
  data->sections_names =
    (char *)data->map +
    ((_64)data->elf)->sections[((_64)data->elf)->header->e_shstrndx].sh_offset;
  return (true);
}

bool		init_archi(t_data *data, const char *filename)
{
  if (data->arch)
    return (init_64(data, filename));
  return (init_32(data, filename));
}