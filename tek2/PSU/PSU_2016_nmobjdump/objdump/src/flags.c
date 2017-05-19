/*
** flags.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/objdump/src/flags.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Fri Feb 17 13:53:16 2017 Gauthier Cler
** Last update Fri Feb 17 13:53:16 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<string.h>
#include	"objdump.h"

static bool	has_sym_section(t_data *data)
{
  int		iterator;
  char		*section_name;
  uint16_t 	shnum;

  shnum = (data->arch) ? ((_64)data->elf)->header->e_shnum :
	  ((_32)data->elf)->header->e_shnum;
  iterator = 0;
  while (iterator < shnum)
  {
      section_name = (data->arch) ?
	&data->sections_names[((_64)data->elf)->sections[iterator].sh_name] :
		     &data->sections_names[((_32)data->elf)->
		       sections[iterator].sh_name];
    if (strcmp(section_name, ".symtab") == 0
	|| strcmp(section_name, ".dynsym") == 0)
      return (true);
    iterator += 1;
  }
  return (false);
}

static bool	check_reloc_flag(t_data *data)
{
  int		iterator;
  uint16_t	shnum;

  iterator = 0;
  shnum = (data->arch) ? ((_64)data->elf)->header->e_shnum
		       : ((_32)data->elf)->header->e_shnum;
  while (iterator < shnum)
  {
    if (data->arch)
    {
      if (((_64)data->elf)->sections[iterator].sh_type == SHT_RELA
	  || ((_64)data->elf)->sections[iterator].sh_type == SHT_REL)
	return (true);
    }
    else
    {
      if (((_32)data->elf)->sections[iterator].sh_type == SHT_RELA
	  || ((_32)data->elf)->sections[iterator].sh_type == SHT_REL)
	return (true);
    }
    iterator += 1;
  }
  return (false);
}

void		init_flags(t_data *data)
{
  uint16_t	type;

  type = (data->arch) ? ((_64)data->elf)->header->e_type
		      : ((_32)data->elf)->header->e_type;
  (has_sym_section(data)) ? data->flags += HAS_SYMS : 0;
  (type == ET_EXEC) ? data->flags += EXEC_P : 0;
  (type == ET_DYN) ? data->flags += DYNAMIC : 0;
  (type == EXEC_P || type == ET_DYN) ?
    data->flags += D_PAGED : 0;
  if (type != ET_EXEC && type != ET_DYN && (check_reloc_flag(data)))
    data->flags += HAS_RELOC;
}

static void	display_flag(unsigned int flags, unsigned int flag,
				 char *str_flag, bool *first)
{
  if (flag & flags)
  {
    fprintf(stdout, "%s%s", (*first) ? ", " : "", str_flag);
    *first = true;
  }
}

void		display_flags(t_data *data)
{
  bool		first;

  first = false;
  display_flag(data->flags, HAS_RELOC, "HAS_RELOC", &first);
  display_flag(data->flags, EXEC_P, "EXEC_P", &first);
  display_flag(data->flags, HAS_SYMS, "HAS_SYMS", &first);
  display_flag(data->flags, DYNAMIC, "DYNAMIC", &first);
  display_flag(data->flags, D_PAGED, "D_PAGED", &first);
  fprintf(stdout, "\n");
}