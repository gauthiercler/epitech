/*
** get_sym_type.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm/src/get_sym_type.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 21 15:46:40 2017 Gauthier Cler
** Last update Tue Feb 21 15:46:40 2017 Gauthier Cler
*/

#include	"nm.h"

char		get_type_section_32(Elf32_Sym *symbol, Elf32_Shdr *section)
{
  char		type;

  type = '?';
  if (section[symbol->st_shndx].sh_type == SHT_NOBITS
      && section[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    type = 'B';
  else if (section[symbol->st_shndx].sh_type == SHT_PROGBITS
	   && section[symbol->st_shndx].sh_flags == SHF_ALLOC)
    type = 'R';
  else if (section[symbol->st_shndx].sh_type == SHT_PROGBITS
	   && section[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    type = 'D';
  else if ((section[symbol->st_shndx].sh_type == SHT_PROGBITS
	   || section[symbol->st_shndx].sh_type == SHT_FINI_ARRAY
	   || section[symbol->st_shndx].sh_type == SHT_INIT_ARRAY)
	   && (section[symbol->st_shndx].sh_flags ==
	       (SHF_ALLOC | SHF_EXECINSTR)
	       || section[symbol->st_shndx].sh_flags ==
		  (SHF_ALLOC | SHF_WRITE)))
    type = 'T';
  else if (section[symbol->st_shndx].sh_type == SHT_DYNAMIC)
    type = 'D';
  return (type);
}

char		get_type_32(Elf32_Sym *symbol, Elf32_Shdr *section)
{
  int		type;

  type = '?';
  if (ELF32_ST_BIND(symbol->st_info) == STB_GNU_UNIQUE)
    type = 'u';
  else if (ELF32_ST_BIND(symbol->st_info) == STB_WEAK)
    type = (symbol->st_shndx == SHN_UNDEF) ? 'w' : 'W';
  else if (ELF32_ST_BIND(symbol->st_info) == STB_WEAK
	   && ELF32_ST_TYPE(symbol->st_info) == STT_OBJECT)
    type = (symbol->st_shndx == SHN_UNDEF) ? 'v' : 'V';
  else if (symbol->st_shndx == SHN_UNDEF)
    type = 'U';
  else if (symbol->st_shndx == SHN_ABS)
    type = 'A';
  else if (symbol->st_shndx == SHN_COMMON)
    type = 'C';
  else
    type = get_type_section_32(symbol, section);
  if (ELF32_ST_BIND(symbol->st_info) == STB_LOCAL && type != '?')
    type += 32;
  return ((char)type);
}

char		get_type_section_64(Elf64_Sym *symbol, Elf64_Shdr *section)
{
  char		type;

  type = '?';
  if (section[symbol->st_shndx].sh_type == SHT_NOBITS
      && section[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    type = 'B';
  else if (section[symbol->st_shndx].sh_type == SHT_PROGBITS
	   && section[symbol->st_shndx].sh_flags == SHF_ALLOC)
    type = 'R';
  else if (section[symbol->st_shndx].sh_type == SHT_PROGBITS
	   && section[symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
    type = 'D';
  else if ((section[symbol->st_shndx].sh_type == SHT_PROGBITS
	    || section[symbol->st_shndx].sh_type == SHT_FINI_ARRAY
	    || section[symbol->st_shndx].sh_type == SHT_INIT_ARRAY)
	   && (section[symbol->st_shndx].sh_flags ==
	       (SHF_ALLOC | SHF_EXECINSTR)
	       || section[symbol->st_shndx].sh_flags ==
		  (SHF_ALLOC | SHF_WRITE)))
    type = 'T';
  else if (section[symbol->st_shndx].sh_type == SHT_DYNAMIC)
    type = 'D';
  return (type);
}

char		get_type_64(Elf64_Sym *symbol, Elf64_Shdr *section)
{
  int		type;

  type = '?';
  if (ELF64_ST_BIND(symbol->st_info) == STB_GNU_UNIQUE)
    type = 'u';
  else if (ELF64_ST_BIND(symbol->st_info) == STB_WEAK
	   && ELF64_ST_TYPE(symbol->st_info) == STT_OBJECT)
    type = (symbol->st_shndx == SHN_UNDEF) ? 'v' : 'V';
  else if (ELF64_ST_BIND(symbol->st_info) == STB_WEAK)
    type = (symbol->st_shndx == SHN_UNDEF) ? 'w' : 'W';
  else if (symbol->st_shndx == SHN_UNDEF)
    type = 'U';
  else if (symbol->st_shndx == SHN_ABS)
    type = 'A';
  else if (symbol->st_shndx == SHN_COMMON)
    type = 'C';
  else
    type = get_type_section_64(symbol, section);
  if (ELF64_ST_BIND(symbol->st_info) == STB_LOCAL && type != '?')
    type += 32;
   return ((char)type);
}