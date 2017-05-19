/*
** section.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/objdump/src/section.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Thu Feb 16 21:39:17 2017 Gauthier Cler
** Last update Thu Feb 16 21:39:17 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	<ctype.h>
#include	"objdump.h"

static void	display_section_ascii(unsigned int section_line,
					 unsigned char *array,
					 uint64_t section_size)
{
  unsigned int	iterator;
  unsigned char	character;

  iterator = 0;
  fprintf(stdout, " ");
  while (iterator < HEXA_BASE)
  {
    if (iterator + section_line >= section_size)
      fprintf(stdout, " ");
    else
    {
      character = array[iterator + section_line];
      fprintf(stdout, "%c", (isprint(character)) ? character : '.');
    }
    iterator += 1;
  }
}

static void	display_section_hexa(unsigned int section_line,
					 unsigned char *array,
					 uint64_t section_size)
{
  unsigned int	iterator;

  iterator = 0;
  while (iterator < HEXA_BASE)
  {
    if (iterator + section_line >= section_size)
      fprintf(stdout, "  ");
    else
      fprintf(stdout, "%02x", array[iterator + section_line]);
    if ((iterator + 1) % 4 == 0)
      fprintf(stdout, " ");
    iterator += 1;
  }
}

void		display_section_64(Elf64_Shdr *section, void *map)
{
  unsigned int	iterator;
  unsigned char	*array;

  iterator = 0;
  array = (unsigned char *)((char *)map + section->sh_offset);
  while (iterator < section->sh_size)
  {
    fprintf(stdout, " %04x ", (unsigned int)section->sh_addr + iterator);
    display_section_hexa(iterator,
			 array,
			 section->sh_size);
    display_section_ascii(iterator, array, section->sh_size);
    fprintf(stdout, "\n");
    iterator += 16;
  }
}

void		display_section_32(Elf32_Shdr *section, void *map)
{
  unsigned int	iterator;
  unsigned char	*array;

  iterator = 0;
  array = (unsigned char *)((char *)map + section->sh_offset);
  while (iterator < section->sh_size)
  {
    fprintf(stdout, " %04x ", (unsigned int)section->sh_addr + iterator);
    display_section_hexa(iterator,
			 array,
			 section->sh_size);
    display_section_ascii(iterator, array, section->sh_size);
    fprintf(stdout, "\n");
    iterator += 16;
  }
}
