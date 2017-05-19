/*
** objdump.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/objdump/src/objdump.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Feb 16 13:40:50 2017 Gauthier Cler
** Last update Thu Feb 16 13:40:50 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<string.h>
#include	"objdump.h"

static bool	is_valid_section(uint32_t type, char *section_name)
{
  if (type != SHT_NULL
      && type != SHT_NOBITS
      && strcmp(section_name, ".shstrtab") != 0
      && strcmp(section_name, ".symtab") != 0
      && strcmp(section_name, ".rela.text") != 0
      && strcmp(section_name, ".rela.eh_frame") != 0
      && strcmp(section_name, ".rel.text") != 0
      && strcmp(section_name, ".rel.eh_frame") != 0
      && strcmp(section_name, ".strtab") != 0)
    return (true);
  return (false);
}

static void	print_header(const char *filename, t_data *data)
{
  int 		architecture;

  architecture = (((_64)data->elf)->header->e_ident[EI_CLASS] == ELFCLASS32)
		 ? 32 : 64;
  fprintf(stdout, "\n");
  fprintf(stdout, "%s:     file format %s\n", filename,
	  (architecture == 64) ? "elf64-x86-64" : "elf32-i386");
  init_flags(data);

  fprintf(stdout, "architecture: %s, flags 0x%08x:\n",
	  (architecture == 64) ? "i386:x86-64" : "i386", data->flags);
  display_flags(data);
  fprintf(stdout, "start address 0x%0*x\n", (data->arch) ? 16 : 8,
	  (unsigned int)((_64)data->elf)->header->e_entry);
  fprintf(stdout, "\n");
}

void		objdump_32(t_data *data, uint16_t shnum)
{
  t_elf_32	*elf;
  int		iterator;

  iterator = 0;
  elf = ((_32)data->elf);
  while (iterator < shnum)
  {
    if (is_valid_section(elf->sections[iterator].sh_type,
			 &data->sections_names[elf->
			   sections[iterator].sh_name]))
    {
      fprintf(stdout, "Contents of section %s:\n",
	      &data->sections_names[elf->sections[iterator].sh_name]);
      display_section_32(&elf->sections[iterator], data->map);
    }
    iterator += 1;
  }
}

void		objdump_64(t_data *data, uint16_t shnum)
{
  t_elf_64	*elf;
  int		iterator;

  iterator = 0;
  elf = ((_64)data->elf);
  while (iterator < shnum)
  {
    if (is_valid_section(elf->sections[iterator].sh_type,
			 &data->sections_names[elf->
			   sections[iterator].sh_name]))
    {
      fprintf(stdout, "Contents of section %s:\n",
	      &data->sections_names[elf->sections[iterator].sh_name]);
      display_section_64(&elf->sections[iterator], data->map);
    }
    iterator += 1;
  }
}

bool		objdump(const char *filename)
{
  t_data	data;
  uint16_t 	shnum;

  if (!init_struct(&data, filename))
    return (false);
  print_header(filename, &data);
  shnum = (data.arch) ? ((_64)data.elf)->header->e_shnum :
	  ((_32)data.elf)->header->e_shnum;
  if (data.arch)
    objdump_64(&data, shnum);
  else
    objdump_32(&data, shnum);
  if (!clean_struct(&data))
    return (false);
  return (true);
}
