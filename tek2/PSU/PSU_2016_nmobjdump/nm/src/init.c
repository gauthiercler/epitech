/*
** init.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm/src/init.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 21 15:40:27 2017 Gauthier Cler
** Last update Tue Feb 21 15:40:27 2017 Gauthier Cler
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"nm.h"

static bool	init_tabs(t_data *data)
{
  if (data->arch)
  {
    ((_64)data->elf)->str_tab = get_section_header_64(".strtab", data);
    ((_64)data->elf)->sym_tab = get_section_header_64(".symtab", data);
    if (!((_64)data->elf)->str_tab || !((_64)data->elf)->sym_tab)
    {
      fprintf(stderr, "%s: %s: no symbols\n", binary, data->filename);
      return (false);
    }
  }
  else
  {
    ((_32)data->elf)->str_tab = get_section_header_32(".strtab", data);
    ((_32)data->elf)->sym_tab = get_section_header_32(".symtab", data);
    if (!((_32)data->elf)->str_tab || !((_32)data->elf)->sym_tab)
    {
      fprintf(stderr, "%s: %s: no symbols\n", binary, data->filename);
      return (false);
    }
  }
  return (true);
}

bool		init_64(t_data *data)
{
  ((_64)data->elf)->header = (Elf64_Ehdr *)data->map;
  ((_64)data->elf)->sections = (Elf64_Shdr *)(data->
    map + ((_64)data->elf)->header->e_shoff);
  data->sections_names =
    (char *)data->map + ((_64)data->elf)->
      sections[((_64)data->elf)->header->e_shstrndx].sh_offset;
  if (!init_tabs(data))
    return (false);
  data->sym_names = data->map + ((_64)data->elf)->str_tab->sh_offset;
  data->nb_sym = ((_64)data->elf)->sym_tab->sh_size / ((_64)data->elf)->
    sym_tab->sh_entsize;
  return (true);
}

bool		init_32(t_data *data)
{
  ((_32)data->elf)->header = (Elf32_Ehdr *)data->map;
  ((_32)data->elf)->sections = (Elf32_Shdr *)(data->
    map + ((_32)data->elf)->header->e_shoff);
  data->sections_names =
    (char *)data->map + ((_32)data->elf)->
      sections[((_32)data->elf)->header->e_shstrndx].sh_offset;
  if (!init_tabs(data))
    return (false);
  data->sym_names = data->map + ((_32)data->elf)->str_tab->sh_offset;
  data->nb_sym = ((_32)data->elf)->sym_tab->sh_size / ((_32)data->elf)->
    sym_tab->sh_entsize;
  return (true);
}

bool		init_struct(t_data *data, const char *filename)
{
  Elf64_Ehdr	*tmp;

  data->filename = (char *)filename;
  if (!load_file(&data->fd, filename))
    return (false);
  if (!load_map(&data->map, data->fd))
    return (false);
  tmp = (Elf64_Ehdr *)data->map;
  if (!(data->elf = malloc(sizeof(t_elf_64))))
    return (false);
  if (!is_valid_elf((const char *)tmp->e_ident, filename))
    return (false);
  data->arch = (tmp->e_ident[EI_CLASS] == ELFCLASS32) ? false : true;
  if (data->arch)
    return (init_64(data));
  return (init_32(data));
}
