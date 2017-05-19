/*
** objdump.h for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/objdump_project/include/objdump.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 14 10:28:54 2017 Gauthier Cler
** Last update Tue Feb 14 10:28:54 2017 Gauthier Cler
*/

#ifndef PSU_2016_NMOBJDUMP_OBJDUMP_H
# define PSU_2016_NMOBJDUMP_OBJDUMP_H

# include			<elf.h>
# include			<stdbool.h>
# define RET_ERROR		(-1)
# define HEXA_BASE		(16)
# define NO_FLAGS		0x00
# define HAS_RELOC		0x01
# define EXEC_P			0x02
# define HAS_LINENO		0x04
# define HAS_DEBUG		0x08
# define HAS_SYMS		0x10
# define HAS_LOCALS		0x20
# define DYNAMIC		0x40
# define WP_TEXT		0x80
# define D_PAGED		0x100
# define BFD_IS_RELAXABLE	0x200
# define HAS_LOAD_PAGE		0x1000

typedef struct			s_data
{
  bool				arch;
  int				fd;
  unsigned int			flags;
  void				*map;
  char				*sections_names;
  void				*elf;
}				t_data;

typedef struct			s_elf_64
{
  Elf64_Ehdr			*header;
  Elf64_Shdr			*sections;
}				t_elf_64;

typedef struct			s_elf_32
{
  Elf32_Ehdr			*header;
  Elf32_Shdr			*sections;
}				t_elf_32;

typedef t_elf_64*		_64;
typedef t_elf_32*		_32;
typedef t_data*			_data;

extern char			*binary;

bool				objdump(const char *filename);
bool				display_error(const char *error_message);
bool				init_struct(t_data *data,
						const char *filename);
bool				clean_struct(t_data *data);
void				display_section_64(Elf64_Shdr *section,
						       void *map);
void				display_section_32(Elf32_Shdr *section,
						       void *map);
bool				init_archi(t_data *data, const char *filename);
void				init_flags(t_data *data);
void				display_flags(t_data *data);

#endif /* !PSU_2016_NMOBJDUMP_OBJDUMP_H */
