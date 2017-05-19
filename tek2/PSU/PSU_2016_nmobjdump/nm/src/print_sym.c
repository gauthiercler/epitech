/*
** print_sym.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm/src/print_sym.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 21 15:45:47 2017 Gauthier Cler
** Last update Tue Feb 21 15:45:47 2017 Gauthier Cler
*/

#include	<stdio.h>
#include	"string.h"
#include	"nm.h"

void		print_sym_64(t_data *data)
{
  int		i;
  char		type;

  i = 0;
  while (i < data->nb_sym)
  {
    type = get_type_64(&((_64)data->elf)->syms[i].sym,
		       ((_64)data->elf)->sections);
    if (strlen(get_symbol_name(&((_64)data->elf)->syms[i].sym, data))
	> 0 && finish_with(get_symbol_name(&((_64)data->elf)->
      syms[i].sym, data), ".c"))
    {
      if (check_type(((_64)data->elf)->syms[i].sym.st_value, type))
	printf("%*s ", 16, "");
      else
	printf("%016x ", (unsigned int)((_64)data->elf)->syms[i].
	  sym.st_value);
      printf("%c %s\n",  get_type_64(&((_64)data->elf)->syms[i].sym,
				     ((_64)data->elf)->sections),
	     get_symbol_name(&((_64)data->elf)->syms[i].sym, data));
    }
    i += 1;
  }
}

void		print_sym_32(t_data *data)
{
  int		i;
  char		type;

  i = 0;
  while (i < data->nb_sym)
  {
    type = get_type_32(&((_32)data->elf)->syms[i].sym,
		       ((_32)data->elf)->sections);
    if (strlen(get_symbol_name(&((_32)data->elf)->syms[i].sym, data))
	> 0 && finish_with(get_symbol_name(&((_32)data->elf)->
      syms[i].sym, data), ".c"))
    {
      if (check_type(((_32)data->elf)->syms[i].sym.st_value, type))
	printf("%*s ", 8, "");
      else
	printf("%08x ", (unsigned int)((_32)data->elf)->syms[i].
	  sym.st_value);
      printf("%c %s\n",  get_type_32(&((_32)data->elf)->syms[i].sym,
				     ((_32)data->elf)->sections),
	     get_symbol_name(&((_32)data->elf)->syms[i].sym, data));
    }
    i += 1;
  }
}

void		print_sym(t_data *data)
{
  if (data->arch)
    print_sym_64(data);
  else
    print_sym_32(data);
}