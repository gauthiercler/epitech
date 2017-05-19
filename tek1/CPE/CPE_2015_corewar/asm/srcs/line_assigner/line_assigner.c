/*
** line_assigner.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Tue Mar 22 20:50:49 2016 Buyumad Anas
** Last update Sun Mar 27 18:40:34 2016 Gauthier Cler
*/

#include	<stdlib.h>
#include	"asm.h"

int		arg_assigner(t_label *labels, t_instruction *instructions,
			     t_arg *arg, int nb_args)
{
  arg->label_name = NULL;
  arg->type = get_type(instructions, arg->name);
  if (arg->type == BAD)
    return (format(2, "Incorrect Type for %s", arg->name));
  if (arg->type != DLAB && arg->type != ILAB)
    arg->value = get_value(instructions, arg->name, arg->type);
  else
    {
      if (get_label_name(arg) == ERROR)
	return (format(2, "Couldn't perform malloc"));
      if (arg->label_name != NULL)
	{
	  if (does_label_exists(labels, arg->label_name) == ERROR)
	    return (format(2, "The Label %s doesn't exist", arg->label_name));
	}
    }
  if (arg->type == INS && arg->value < 0 && arg->value > 15)
    return (format(2, "The Instruction %s isn't correct", arg->name));
  if (arg->type == INS && instructions[arg->value].nb_args != (nb_args - 1))
    return (format(2, "The Instruction %s has an invalid number of arguments"
		   , arg->name));
  return (SUCCESS);
}

int		line_assigner(t_label *labels, t_instruction *instructions,
			      t_line *line)
{
  int		i;

  i = 0;
  while (i < line->nb_args)
    {
      if (arg_assigner(labels, instructions,
		       &line->args[i], line->nb_args) == ERROR)
	return (format(2, " ; line %d\n", line->nb_line));
      i += 1;
    }
  return (SUCCESS);
}
