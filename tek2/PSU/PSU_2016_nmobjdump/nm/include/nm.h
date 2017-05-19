/*
** nm.h for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm_project/include/nm.h
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 14 10:28:27 2017 Gauthier Cler
** Last update Tue Feb 14 10:28:27 2017 Gauthier Cler
*/

#ifndef PSU_2016_NMOBJDUMP_NM_H
# define PSU_2016_NMOBJDUMP_NM_H

# include			<stdbool.h>
# include			<elf.h>
# define RET_ERROR		(-1)

typedef struct			s_data
{
  bool				arch;
  char				*filename;
  int				fd;
  unsigned int			flags;
  void				*map;
  char				*sections_names;
  char				*sym_names;
  long int			nb_sym;
  void				*elf;
}				t_data;

typedef struct			s_sym_64
{
  char				*name;
  Elf64_Sym			sym;
}				t_sym_64;

typedef struct			s_sym_32
{
  char				*name;
  Elf32_Sym			sym;
}				t_sym_32;

typedef struct			s_elf_64
{
  t_sym_64			*syms;
  Elf64_Ehdr			*header;
  Elf64_Shdr			*sections;
  Elf64_Shdr			*sym_tab;
  Elf64_Shdr			*str_tab;
}				t_elf_64;

typedef struct			s_elf_32
{
  t_sym_32			*syms;
  Elf32_Ehdr			*header;
  Elf32_Shdr			*sections;
  Elf32_Shdr			*sym_tab;
  Elf32_Shdr			*str_tab;
}				t_elf_32;

extern char			*binary;

typedef t_elf_64*		_64;
typedef t_elf_32*		_32;

bool				nm(const char *filename, bool single_arg);
bool				display_error(const char *error_message);
bool				init_struct(t_data *data,
						const char *filename);
Elf32_Shdr			*get_section_header_32(const char *name,
						      t_data *data);
Elf64_Shdr			*get_section_header_64(const char *name,
						      t_data *data);
bool				clean_struct(t_data *data);
int				compare_64(const void *first,
					      const void *second);
int				compare_32(const void *first,
					      const void *second);
int				load_file(int *fd, const char *filename);
bool				load_map(void **map, int fd);
bool				is_valid_elf(const char	*ident,
						 const char *filename);
char				*get_symbol_name(void *symbol, t_data *data);
Elf32_Sym			*get_symbol_32(int index, t_data *data);
Elf64_Sym			*get_symbol_64(int index, t_data *data);
void				print_sym(t_data *data);
char				get_type_32(Elf32_Sym *symbol,
						Elf32_Shdr *section);
char				get_type_64(Elf64_Sym *symbol,
						Elf64_Shdr *section);
bool				finish_with(char *string, char *pattern);
bool				check_type(uint64_t value, char type);
bool				init_tabs_64(t_data *data);
bool				init_tabs_32(t_data *data);

#endif /* !PSU_2016_NMOBJDUMP_NM_H */