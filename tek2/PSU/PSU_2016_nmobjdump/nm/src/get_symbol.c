/*
** get_symbol.c for PSU_2016_nmobjdump in /home/gogo/rendu/tek2/PSU_2016_nmobjdump/nm/src/get_symbol.c
**
** Made by Gauthier Cler
** Login   <gauthier.cler@epitech.eu>
**
** Started on  Tue Feb 21 15:48:18 2017 Gauthier Cler
** Last update Tue Feb 21 15:48:18 2017 Gauthier Cler
*/

#include	<stddef.h>
#include	"nm.h"

char		*get_symbol_name(void *symbol, t_data *data)
{
  char		*symbol_name;

  if (data->arch)
  {
    symbol_name = data->map + ((_64)data->elf)->str_tab->sh_offset;
    return (symbol_name + ((Elf64_Sym *)symbol)->st_name);
  }
  symbol_name = data->map + ((_32)data->elf)->str_tab->sh_offset;
  return (symbol_name + ((Elf32_Sym *)symbol)->st_name);
}

Elf64_Sym	*get_symbol_64(int index, t_data *data)
{
  Elf64_Sym	*symbol;

  if (index >= data->nb_sym)
    return (NULL);
  symbol = (Elf64_Sym *)(data->map + ((_64)data->elf)->sym_tab->sh_offset
			 + index * ((_64)data->elf)->sym_tab->sh_entsize);
  return (symbol);
}

Elf32_Sym	*get_symbol_32(int index, t_data *data)
{
  Elf32_Sym	*symbol;

  if (index >= data->nb_sym)
    return (NULL);
  symbol = (Elf32_Sym *)(data->map + ((_32)data->elf)->sym_tab->sh_offset
			 + index * ((_32)data->elf)->sym_tab->sh_entsize);
  return (symbol);
}