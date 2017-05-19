/*
** get_section_header.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm/src/get_section_header.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 21 15:47:20 2017 Gauthier Cler
** Last update Tue Feb 21 15:47:20 2017 Gauthier Cler
*/

#include	<stddef.h>
#include	<string.h>
#include	"nm.h"

Elf64_Shdr	*get_section_header_64(const char *name, t_data *data)
{
  int		iterator;

  if (((_64)data->elf)->header->e_shnum < ((_64)data->elf)->header->e_shstrndx)
    return (NULL);
  iterator = 0;
  while (iterator < ((_64)data->elf)->header->e_shnum)
  {
    if (strcmp(name, data->sections_names +
		     ((_64)data->elf)->sections[iterator].sh_name) == 0)
      return (&((_64)data->elf)->sections[iterator]);
    iterator += 1;
  }
  return (NULL);
}

Elf32_Shdr	*get_section_header_32(const char *name, t_data *data)
{
  int		iterator;

  if (((_32)data->elf)->header->e_shnum < ((_32)data->elf)->header->e_shstrndx)
    return (NULL);
  iterator = 0;
  while (iterator < ((_32)data->elf)->header->e_shnum)
  {
    if (strcmp(name, data->sections_names +
		     ((_32)data->elf)->sections[iterator].sh_name) == 0)
      return (&((_32)data->elf)->sections[iterator]);
    iterator += 1;
  }
  return (NULL);
}
