/*
** lexer.c for asm in /home/keyrise/Work/Repositories/Epitech/CPE/CPE_2015_corewar/asm/srcs/lexer/
**
** Made by Buyumad Anas
** Login   <buyuma_a@anas.buyumad@epitech.eu>
**
** Started on  Wed Mar 23 16:21:08 2016 Buyumad Anas
** Last update Sun Mar 27 18:56:29 2016 Gauthier Cler
*/

#include	"asm.h"

int		arg_lexer(t_instruction *instructions, t_arg *arg,
			  int nb_ins, int nb_arg)
{
  int		type_arg;
  int		i;

  i = 0;
  if (arg->type == DLAB)
    type_arg = DIR;
  else if (arg->type == ILAB)
    type_arg = IND;
  else
    type_arg = arg->type;
  while (instructions[nb_ins].tab[nb_arg][i])
    {
      if (instructions[nb_ins].tab[nb_arg][i] == type_arg + 48)
	return (SUCCESS);
      i += 1;
    }
  return (ERROR);
}

int		line_lexer(t_instruction *instructions, t_line *line)
{
  int		i;

  i = 1;
  while (i < line->nb_args)
    {
      if (line->args[i].type != BAD)
	if (arg_lexer(instructions, &line->args[i],
		      line->args[0].value, i - 1) == ERROR)
	  return (format(2, "Parameter %s isn't of valid type : line %d\n",
			 line->args[i].name, line->nb_line));
      i += 1;
    }
  return (SUCCESS);
}
