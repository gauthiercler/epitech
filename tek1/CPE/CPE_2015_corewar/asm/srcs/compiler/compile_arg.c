/*
** compile_arg.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/compiler/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Fri Mar 25 13:10:59 2016 Buyumad Anas
** Last update Sun Mar 27 17:08:47 2016 Buyumad Anas
*/

#include	"asm.h"

int		compile_register(int fd, int value)
{
  compile_octects(fd, 1, value);
  return (SUCCESS);
}

int		compile_direct(t_arg *arg, t_label *labels, int *tab)
{
  int		label_address;
  int		octets;

  octets = arg->o_size;
  if (arg->type == DIR)
    compile_octects(tab[0], octets, arg->value);
  else if (arg->type == DLAB)
    {
      find_label_address(arg->label_name, labels, &label_address);
      if (tab[1] == 8 || tab[1] == 11 || tab[1] == 14)
	label_address = label_address - arg->address;
      compile_octects(tab[0], octets, label_address);
    }
  return (SUCCESS);
}

int		compile_indirect(int fd, t_arg *arg, t_label *labels)
{
  int		label_address;

  if (arg->type == IND)
    compile_octects(fd, IND_SIZE, arg->value);
  else if (arg->type == ILAB)
    {
      find_label_address(arg->label_name, labels, &label_address);
      label_address = label_address - arg->address;
      compile_octects(fd, IND_SIZE, label_address);
    }
  return (SUCCESS);
}

int		compile_arg(t_arg *arg, t_label *labels, int *tab)
{
  if (arg->type == REG)
    compile_register(tab[0], arg->value);
  if (arg->type == DIR || arg->type == DLAB)
    compile_direct(arg, labels, tab);
  else if (arg->type == IND || arg->type == ILAB)
    compile_indirect(tab[0], arg, labels);
  return (SUCCESS);
}
