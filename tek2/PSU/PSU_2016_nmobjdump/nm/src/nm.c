/*
** nm.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm/src/nm.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Sun Feb 19 18:05:11 2017 Gauthier Cler
** Last update Sun Feb 19 18:05:11 2017 Gauthier Cler
*/

#include	<stddef.h>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"nm.h"

bool		finish_with(char *string, char *pattern)
{
  if (strstr(string, pattern) == NULL)
    return (true);
  return (false);
}

bool		malloc_tab(t_data *data)
{
  if (data->arch)
  {
    if (!(((_64)data->elf)->syms = malloc(sizeof(t_sym_64) * (data->nb_sym))))
      return (false);
  }
  else
  {
    if (!(((_32)data->elf)->syms = malloc(sizeof(t_sym_32) * (data->nb_sym))))
      return (false);
  }
  return (true);
}

void		create_sym_tab(t_data *data)
{
  int		iterator;

  iterator = 0;
  while (iterator < data->nb_sym)
  {
    if (data->arch)
    {
      ((_64)data->elf)->syms[iterator].sym = *get_symbol_64(iterator, data);
      ((_64)data->elf)->syms[iterator].name =
	get_symbol_name(get_symbol_64(iterator, data), data);
    }
    else
    {
      ((_32)data->elf)->syms[iterator].sym = *get_symbol_32(iterator, data);
      ((_32)data->elf)->syms[iterator].name =
	get_symbol_name(get_symbol_32(iterator, data), data);
    }
    iterator += 1;
  }
}

bool		check_type(uint64_t value, char type)
{
  if (type == 'U')
    return (true);
  if (value == 0 && (type == 'u' || type == 'i' || type == 'I' || type == 'w'))
    return (true);
  return (false);
}

bool		nm(const char *filename, bool single_arg)
{
  t_data	data;

  if (!init_struct(&data, filename))
    return (false);
  if (!malloc_tab(&data))
    return (false);
  create_sym_tab(&data);
  if (data.arch)
    qsort(((_64)data.elf)->syms, (size_t)data.nb_sym, sizeof(t_sym_64),
	  compare_64);
  else
    qsort(((_32)data.elf)->syms, (size_t)data.nb_sym, sizeof(t_sym_32),
	  compare_32);
  if (single_arg)
    printf("\n%s:\n", filename);
  print_sym(&data);
  if (!clean_struct(&data))
    return (false);
  return (true);
}
